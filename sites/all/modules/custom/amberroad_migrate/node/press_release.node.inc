<?php

/**
 * @file
 * Basic Page migration support for Amberroad.
 */
/**
 * Mappings for "Node" content migration fields.
 */
module_load_include('inc', 'amberroad_migrate', 'source_parser');

class AmberroadMigratePressRelaseNodeMigration extends Migration implements SourceParser {

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
      'date' => t('Date'),
      'uid' => t('User id'),
    );

    // Since the base directory of the HTML files can change depending on the
    // environment, we keep it in a variable. There is no interface for this,
    // set it using drush vset.
    $this->base_dir = '../www.amberroad.com/html/press/';

    // Match HTML files.
    $regex = '/.*\.shtml/';

    // The source of the migration is HTML files from the old site.
    $list_files = new MigrateListFiles(array($this->base_dir), $this->base_dir, $regex);

    $item_file = new MigrateItemFile($this->base_dir);
    $this->source = new MigrateSourceList($list_files, $item_file, $fields);
    // The destination is the mynode content type.
    $this->destination = new MigrateDestinationNode('press_release');

    // Map the fields, pretty straightforward in this case.
    $this->addFieldMapping('uid', 'uid');
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_press_release_date', 'date');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('body:format')->defaultValue('full_html');
    $this->addFieldMapping('status')->defaultValue(1);
  }

  /**
   * Prepare a row.
   */
  public function prepareRow($row) {
    // Create a new SourceParser to handle HTML content.
    $this->init(substr($row->sourceid, 1), $row->filedata);
    $body = $this->getBody();
    $date = $this->getPressReleaseDate();
    if ($body !== FALSE && !empty($date)) {
      // Set to admin for now.
      $row->uid = 1;
      $row->body = $body;

      // Set page title.
      $row->title = $this->getTitle();
      //$this->getAdImages();

      // Set Date.
      $row->date = $date;
    }
    else {
      return FALSE;
    }
  }

   /**
   * Prepare node object.
   */
  public function prepare($node, stdClass $row) {

    $node->title = preg_replace('/[^A-Za-z0-9\-" "]/', '', trim($node->title));
    $node->path = array('alias' => 'html' . $row->sourceid);
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
   * Init.
   * @param $html
   *  The full HTML data as loaded from the file.
   */
  public function htmlqp($html) {
    $html = str_replace(chr(13), '', $html);
    $enc = mb_detect_encoding($html, 'UTF-8', TRUE);
    if (!$enc) {
      $html = mb_convert_encoding($html, 'UTF-8', 'WINDOWS-1252');
    }
    $tmp = $html;
    // We add surrounding <html> and <head> tags.
    $html = '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">';
    $html .= '<html xmlns="http://www.w3.org/1999/xhtml"><head><meta http-equiv="Content-Type" content="text/html; charset=utf-8" /></head><body>';
    $html .= $tmp;
    $html .= '</body></html>';
    $qp_options = array(
      'convert_to_encoding' => 'utf-8',
      'convert_from_encoding' => 'utf-8',
      'strip_low_ascii' => FALSE,
    );

    return $qp = htmlqp($html, NULL, $qp_options);
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
  public function getBody() {
    $tr = $this->qp->top('body')->find('table[id="main"]')->find('tr:nth-child(3)');
    $body = "";
    $tables = $this->htmlqp($tr->children()->children('table')->innerHTML())->top();
    foreach ($tables->find('table') as $i => $tbl) {
      if ($i == 3) {
        $tbl->remove("tr:first");
        break;
      }
    }

    foreach ($tables->find('table') as $i => $tbl) {
      if ($i == 3) {
        $body = $tbl->html();
        break;
      }
    }
    $body = preg_replace('/[\n\r\t]+/', '', $body);
    return $body;
  }

  /**
   * Return the press release date.
   */
  public function getPressReleaseDate() {
    $tr = $this->qp->top('body')->find('table[id="main"]')->find('tr:nth-child(3)');
    $date = "";
    $tables = $this->htmlqp($tr->children()->children('table')->innerHTML())->top();
    foreach ($tables->find('table') as $i => $tbl) {
      if ($i == 3) {
        $date = strtotime($tbl->find('tr:first')->find('td:first')->find('span')->text());
        break;
      }
    }

    return $date;
  }

  /**
   * Return the Page title.
   */
  public function getTitle() {
    $tr = $this->qp->top('body')->find('table[id="main"]')->find('tr:nth-child(3)');
    $title = "";
    $tables = $this->htmlqp($tr->children()->children('table')->innerHTML())->top();
    foreach ($tables->find('table') as $i => $tbl) {
      if ($i == 2) {
        $td = $tbl->find('tr:nth-child(2)')->find('td:first');
        $title = $td->text();
        break;
      }
    }
    $title = trim(preg_replace("/&#?[a-z0-9]{2,8};/i", "", strip_tags($title))," ");
    return $title;
  }

  /**
   * Return the Page Banner.
   */
  public function getBannerImage() {
    $main_table = $this->qp->top('body')->find('table[id="main"]');
    $banner = "";
    foreach ($main_table->find('table[id="main"] > tr') as $i => $tr) {
      if ($i == 2) {

        $tables = $this->htmlqp($tr->children()->children('table')->innerHTML())->top();
        foreach ($tables->find('table') as $k => $tbl) {
          if ($k == 1) {
            $img = $tbl->find('img');
            $src = $img->attr('src');
            $banner = basename($src);
            break;
          }
        }
      }
    }
    $banner = trim($banner);
    return $banner;
  }
}
