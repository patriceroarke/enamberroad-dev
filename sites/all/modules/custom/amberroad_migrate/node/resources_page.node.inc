<?php

/**
 * @file
 * Press Coverage migration support for Amberroad.
 */
/**
 * Mappings for "Node" content migration fields.
 */
module_load_include('inc', 'amberroad_migrate', 'source_parser');

class AmberroadMigrateResourceNodeMigration extends Migration implements SourceParser {

  public $base_dir;
  protected $id;
  protected $html;
  protected $qp;

  /**
   * Constructor.
   */
  public function __construct($arguments) {

    parent::__construct($arguments);

    // A map of source HTML filename -> destination node id.
    $this->map = new MigrateSQLMap($this->machineName, array(
      'sourceid' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => TRUE,
      )
            ), MigrateDestinationNode::getKeySchema()
    );

    // The source fields.
    $fields = array(
      'title' => t('Title'),
      'body' => t('Body'),
      'link' => t('Link'),
      'uid' => t('User id'),
    );

    // Since the base directory of the HTML files can change depending on the
    // environment, we keep it in a variable. There is no interface for this,
    // set it using drush vset.
    $this->base_dir = '../www.amberroad.com/html/';

    // Match HTML files.
    $regex = '/^rl_ebooks.shtml|rl_case_studies.shtml|rl_brochures.shtml|rl_analyst_reports.shtml|rl_white_papers.shtml|rl_product_tours.shtml/';

    // The source of the migration is HTML files from the old site.
    $list_files = new MigrateListFiles(array($this->base_dir), $this->base_dir, $regex);

    $item_file = new MigrateItemFile($this->base_dir);
    $this->source = new MigrateSourceList($list_files, $item_file, $fields);
    // The destination is the mynode content type.
    $this->destination = new MigrateDestinationNode('resource');

    // Map the fields, pretty straightforward in this case.
    $this->addFieldMapping('uid', 'uid');
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('body:format')->defaultValue('full_html');
    $this->addFieldMapping('status')->defaultValue(1);
    $this->addFieldMapping('field_resource_link', 'link');
  }

  /**
   * Prepare a row.
   */
  public function prepareRow($row) {
    // Create a new SourceParser to handle HTML content.
    $this->init(substr($row->sourceid, 1), $row->filedata);
    $body = $this->getBody($row->sourceid);
    if ($body !== FALSE) {
      // Set to admin for now.
      $row->uid = 1;
      $row->body = $body[0];
      $row->title = 'Deleted Resource';
    }
    else {
      return FALSE;
    }
  }

  /**
   * Init.
   *
   * @param $id
   *  The filename, e.g. pm7205.html
   * @param $html
   *  The full HTML data as loaded from the file.
   */
  public function init($id, $html) {
    $this->id = $id;
    $this->html = $html;

    $this->charTransform();
    $this->fixEncoding();
    $this->wrapHTML();
    $this->initQP();
    $this->stripComments();
  }

  /**
   * Replace characters.
   */
  public function charTransform() {
    // We need to strip the Windows CR characters, because otherwise we end up
    // with &#13; in the output.
    // http://technosophos.com/content/querypath-whats-13-end-every-line
    $this->html = str_replace(chr(13), '', $this->html);
  }

  /**
   * Deal with encodings.
   */
  public function fixEncoding() {
    // If the content is not UTF8, we assume it's WINDOWS-1252. This fixes
    // bogus character issues. Technically it could be ISO-8859-1 but it's safe
    // to convert this way.
    // http://en.wikipedia.org/wiki/Windows-1252
    $enc = mb_detect_encoding($this->html, 'UTF-8', TRUE);
    if (!$enc) {
      $this->html = mb_convert_encoding($this->html, 'UTF-8', 'WINDOWS-1252');
    }
  }

  /**
   * Wrap an HTML fragment in the correct head/meta tags so that UTF-8 is
   * correctly detected, and for the parsers and tidiers.
   */
  public function wrapHTML() {
    // We add surrounding <html> and <head> tags.
    $html = '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">';
    $html .= '<html xmlns="http://www.w3.org/1999/xhtml"><head><meta http-equiv="Content-Type" content="text/html; charset=utf-8" /></head><body>';
    $html .= $this->html;
    $html .= '</body></html>';
    $this->html = $html;
  }

  /**
   * Create the QueryPath object.
   */
  public function initQP() {
    $qp_options = array(
      'convert_to_encoding' => 'utf-8',
      'convert_from_encoding' => 'utf-8',
      'strip_low_ascii' => FALSE,
    );
    $this->qp = htmlqp($this->html, NULL, $qp_options);
  }

  /**
   * Remove the comments from the HTML.
   */
  public function stripComments() {
    foreach ($this->qp->top()->xpath('//comment()')->get() as $comment) {
      $comment->parentNode->removeChild($comment);
    }
  }

  /**
   * Return the HTML.
   */
  public function getBody($source_id) {
    $tr = $this->qp->top('body')->find('table[id="main"]')->find('tr:nth-child(3)');
    $body = array();
    $rows = array();
    $tables = htmlqp($tr->children()->children('table')->innerHTML(), NULL)->top();
    foreach ($tables->find('table') as $i => $tbl) {
      if ($i == 3) {
        $rows = $tbl->find('table');
        break;
      }
    }

    if ($source_id == '/rl_case_studies.shtml') {
      $title = $this->getTitle();
    }
    foreach ($rows as $i => $row) {
      if ($i >= 1) {
        if ($source_id !== '/rl_case_studies.shtml') {
          $text = $row->find('tr:nth(2)')->text();
        }
        else {
          $text = $row->find('tr:nth(1)')->find('td:nth(2)')->text();
          $text = preg_replace('/' . $title[$i-1] . '/', '', $text, 1);
        }
        $text = preg_replace('/[\n\r\t]+/', '', trim($text));
        $body[] = $text;
      }
    }
    return $body;
  }

  /**
   * Return the Page title.
   */
  public function getTitle() {
    $tr = $this->qp->top('body')->find('table[id="main"]')->find('tr:nth-child(3)');
    $title = array();
    $rows = array();
    $tables = htmlqp($tr->children()->children('table')->innerHTML(), NULL)->top();
    foreach ($tables->find('table') as $i => $tbl) {
      if ($i == 3) {
        $rows = $tbl->find('table');
        break;
      }
    }
    foreach ($rows as $i => $row) {
      if ($i >= 1) {
        $text = $row->find('tr:nth(1)')->find('td:nth(2)')->find('a')->text();
        $text = preg_replace('/[^A-Za-z0-9\-" "]/', '', trim(strip_tags($text)));
        $title[] = $text;
      }
    }
    return $title;
  }

  /**
   * Return the Page extrnal link.
   */
  public function getResourceLink() {
    $tr = $this->qp->top('body')->find('table[id="main"]')->find('tr:nth-child(3)');
    $link = array();
    $rows = array();
    $tables = htmlqp($tr->children()->children('table')->innerHTML(), NULL)->top();
    foreach ($tables->find('table') as $i => $tbl) {
      if ($i == 3) {
        $rows = $tbl->find('table');
        break;
      }
    }
    foreach ($rows as $i => $row) {
      if ($i >= 1) {
        $link[] = $row->find('tr:nth(1)')->find('td:nth(2)')->find('a')->attr('href');
      }
    }
    return $link;
  }

  /**
   * Create press coverage nodes.
   */
  private function create_resource_node(stdClass $row = NULL, $index = 0) {
    $title = $this->getTitle();
    $links = $this->getResourceLink();
    $body = $this->getBody($row->sourceid);
    foreach ($title as $i => $value) {
      // Create an Entity
      $node = entity_create('node', array('type' => 'resource'));
      // Specify the author
      $node->uid = 1;
      $node->status = 1;


      // Create a Entity Wrapper of that new Entity
      $entity = entity_metadata_wrapper('node', $node);
      // Specify the title
      $entity->title->set($title[$i]);

      // Add field data... SO MUCH BETTER!
      $entity->body->set(array('value' => $body[$i], 'format' => 'full_html'));
      $entity->field_resource_link->set(array('url' => $links[$i]));
      // Find out resource type.
      switch ($row->sourceid) {
        case '/rl_ebooks.shtml':
          $term = taxonomy_get_term_by_name('eBooks', 'resource_type');
          break;

        case '/rl_case_studies.shtml':
          $term = taxonomy_get_term_by_name('Case Studies ', 'resource_type');
          break;

        case '/rl_brochures.shtml':
          $term = taxonomy_get_term_by_name('Brochures', 'resource_type');
          break;

        case '/rl_analyst_reports.shtml':
          $term = taxonomy_get_term_by_name('Analyst & Industry Reports', 'resource_type');
          break;

        case '/rl_white_papers.shtml':
          $term = taxonomy_get_term_by_name('White Papers', 'resource_type');
          break;

        case '/rl_product_tours.shtml':
          $term = taxonomy_get_term_by_name('Product Tours', 'resource_type');
          break;
      }
      $entity->field_resource_type->set(key($term));
      // Save the node.
      $entity->save();
    }
  }

  /**
   * Prepare node object.
   */
  public function complete($node, stdClass $row) {
      $this->create_resource_node($row);
  }

}
