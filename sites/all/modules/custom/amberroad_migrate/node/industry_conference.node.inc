<?php

/**
 * @file
 * Industry conference migration support for Amberroad.
 */
/**
 * Mappings for "Node" content migration fields.
 */
module_load_include('inc', 'amberroad_migrate', 'source_parser');

class AmberroadMigrateConferenceNodeMigration extends Migration implements SourceParser {

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
      'link' => t('Link'),
      'logo' => t('Event Logo'),
      'city' => t('City'),
      'uid' => t('User id'),
    );

    // Since the base directory of the HTML files can change depending on the
    // environment, we keep it in a variable. There is no interface for this,
    // set it using drush vset.
    $this->base_dir = '../www.amberroad.com/html/';

    // Match HTML files.
    $regex = '/^industry_events\.shtml/';

    // The source of the migration is HTML files from the old site.
    $list_files = new MigrateListFiles(array($this->base_dir), $this->base_dir, $regex);

    $item_file = new MigrateItemFile($this->base_dir);
    $this->source = new MigrateSourceList($list_files, $item_file, $fields);
    // The destination is the mynode content type.
    $this->destination = new MigrateDestinationNode('page');

    // Map the fields, pretty straightforward in this case.
    $this->addFieldMapping('uid', 'uid');
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_event_date', 'date');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('body:format')->defaultValue('full_html');
    $this->addFieldMapping('status')->defaultValue(1);
    $this->addFieldMapping('field_event_link', 'link');
    $this->addFieldMapping('field_event_logo', 'logo');
    $this->addFieldMapping('field_event_city_and_state', 'city');
  }

  /**
   * Prepare a row.
   */
  public function prepareRow($row) {
    // Create a new SourceParser to handle HTML content.
    $this->init(substr($row->sourceid, 1), $row->filedata);
    $row->title = "Deleted Industry Events";
  }

  /**
   * Prepare node object.
   */
  public function prepare($node, stdClass $row) {

    $node->title = preg_replace('/[^A-Za-z0-9\-" "]/', '', trim(strip_tags($node->title)));
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
  public function getBody() {
    $tr = $this->qp->top('body')->find('table[id="main"]')->find('tr:nth-child(3)');
    $body = array();
    $html = "";
    $tables = $tr->find('table');

    foreach ($tables as $i => $tbl) {
      if ($i == 2) {
        $event_tables = $tbl->find("tr:first")->find("td:first")->find('table');
        break;
      }
    }

    foreach ($tables as $i => $tbl) {
      if ($i == 2) {
        $event_tables = $tbl->find("tr:first")->find("td:first")->find('table');
        break;
      }
    }

    foreach ($event_tables as $i => $tbl) {
      $html = $tbl->find('tr:nth-child(2)')->find('td:first')->children('p.content2:nth-child(1)');
      $htm = $html->html();
      $pos = strpos($htm, '<p', 2);
      $htm = substr($htm, 0, $pos);
      $body[] = preg_replace('/[\n\r\t]+/', '', $htm);
    }

    return $body;
  }

  /**
   * Return the event date.
   */
  public function getEventDate() {
    $tr = $this->qp->top('body')->find('table[id="main"]')->find('tr:nth-child(3)');
    $date = array();
    $html = "";
    $tables = $tr->find('table');

    foreach ($tables as $i => $tbl) {
      if ($i == 2) {
        $event_tables = $tbl->find("tr:first")->find("td:first")->find('table');
        break;
      }
    }

    foreach ($event_tables as $i => $tbl) {
      $string = strip_tags($tbl->find('tr:nth-child(2)')->find('td:first')->find('span')->html(), '<br></br><br />');

      $date[] = $this->clean_date_string($string);
    }

    return $date;
  }

  /**
   * Return the Page title.
   */
  public function getTitle() {
    $tr = $this->qp->top('body')->find('table[id="main"]')->find('tr:nth-child(3)');
    $title = array();
    $html = "";
    $tables = $tr->find('table');

    foreach ($tables as $i => $tbl) {
      if ($i == 2) {
        $event_tables = $tbl->find("tr:first")->find("td:first")->find('table');
        break;
      }
    }

    foreach ($event_tables as $i => $tbl) {
      $text = $tbl->find('tr:nth-child(2)')->find('td:first')->find('a')->text();
      $title[] = trim($text);
    }

    return $title;
  }

  /**
   * Return the Page extrnal link.
   */
  public function getExternalLink() {
    $tr = $this->qp->top('body')->find('table[id="main"]')->find('tr:nth-child(3)');
    $link = array();
    $html = "";
    $tables = $tr->find('table');

    foreach ($tables as $i => $tbl) {
      if ($i == 2) {
        $event_tables = $tbl->find("tr:first")->find("td:first")->find('table');
        break;
      }
    }

    foreach ($event_tables as $i => $tbl) {
      $link[] = $tbl->find('tr:nth-child(2)')->find('td:first')->find('a')->attr('href');
    }

    return $link;
  }

  /**
   * Return the Page Event Logo.
   */
  public function getEventLogo() {
    $tr = $this->qp->top('body')->find('table[id="main"]')->find('tr:nth-child(3)');
    $logo = array();
    $html = "";
    $tables = $tr->find('table');

    foreach ($tables as $i => $tbl) {
      if ($i == 2) {
        $event_tables = $tbl->find("tr:first")->find("td:first")->find('table');
        break;
      }
    }

    foreach ($event_tables as $i => $tbl) {
      $logo[] = $tbl->find('tr:first')->find('td:first')->find('img')->attr('src');
    }

    return $logo;
  }

  /**
   * Return the event date.
   */
  public function getEventCity() {
    $tr = $this->qp->top('body')->find('table[id="main"]')->find('tr:nth-child(3)');
    $city = array();
    $html = "";
    $tables = $tr->find('table');

    foreach ($tables as $i => $tbl) {
      if ($i == 2) {
        $event_tables = $tbl->find("tr:first")->find("td:first")->find('table');
        break;
      }
    }

    foreach ($event_tables as $i => $tbl) {
      $string = strip_tags($tbl->find('tr:nth-child(2)')->find('td:first')->find('span')->html(), '<br></br><br />');

      $city[] = $this->clean_city_string($string);
    }

    return $city;
  }

  /**
   * clean a date string.
   */
  private function clean_date_string($string = NULL) {
    $date = array();

    $stripped_date = substr($string, strpos($string, "<br />") + 6, strlen($string));
    $stripped_date = substr($stripped_date, strpos($stripped_date, "<br />") + 6, strlen($stripped_date));
    $stripped_date = trim(substr($stripped_date, 0, strpos($stripped_date, "<br />")));

    // Check if date has an end date value
    if (strpos($stripped_date, "-")) {
      $dates = explode('-', $stripped_date);
      $end_date = explode(",", $dates[1]);
      $date['start'] = strtotime(trim($dates[0]) . " " . trim($end_date[1]));
      $date['end'] = strtotime(trim($end_date[0]) . " " . trim($end_date[1]));
    }
    else {
      $date['start'] = strtotime($stripped_date);
      $date['end'] = NULL;
    }

    return $date;
  }

  /**
   * clean a date string.
   */
  private function clean_city_string($string = NULL) {
    $city = "";

    $stripped_city = substr($string, strpos($string, "<br />") + 6, strpos($string, "<br />"));
    $explode = explode("<br />", $stripped_city);
    $city = trim($explode[0]);

    return $city;
  }

  /**
   * Create press coverage nodes.
   */
  private function create_industry_event_node(stdClass $row = NULL) {
    $title = $this->getTitle();
    $body = $this->getBody();
    $link = $this->getExternalLink();
    $date = $this->getEventDate();
    $city = $this->getEventCity();
    $logo = $this->getEventLogo();

    foreach ($title as $i => $value) {
      // Create an Entity
      $node = entity_create('node', array('type' => 'industry_conference'));
      // Specify the author
      $node->uid = 1;
      $node->status = 1;

      // Create a Entity Wrapper of that new Entity
      $entity = entity_metadata_wrapper('node', $node);
      // Specify the title
      $entity->title->set($title[$i]);
      // Add field data... SO MUCH BETTER!
      $entity->field_event_date->value->set($date[$i]['start']);
      if ($date[$i]['end'] != NULL) {
        $entity->field_event_date->value2->set($date[$i]['end']);
      }
      $entity->field_event_link->set(array('url' => $link[$i]));
      $entity->field_event_city_and_state->set($city[$i]);

      // Get the Logo image
      $base_dir = str_replace("html/", "", $this->base_dir);
      $path = $logo[$i];

      if (strstr($path, '../')) {
        $path = str_replace("../", '', $path);
      }
      else {
        $path = substr($path, 1, strlen($path));
      }

      if (file_exists($base_dir . $path)) {
        $file_name = explode('/', $path);
        $image = file_get_contents($base_dir . $path);
        $file = file_save_data($image, "public://images/" . $file_name[3]);
        $entity->field_event_logo->file->set($file);
      }

      $entity->body->set(array('value' => $body[$i], 'format' => 'full_html'));
      // Save the node.
      $entity->save();
    }
  }

  /**
   * Prepare node object.
   */
  public function complete($node, stdClass $row) {
    $this->create_industry_event_node($row);
  }

}
