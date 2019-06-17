<?php

/**
 * @file
 * Amberroad Menu migration support for Amberroad.
 */
/**
 * Mappings for "Menu" content migration fields.
 */
module_load_include('inc', 'amberroad_migrate', 'source_parser');

class AmberroadMenusMigration extends Migration implements SourceParser {

  public $base_dir;
  protected $id;
  protected $html;
  protected $qp;

  /**
   * Constructor.
   */
  public function __construct($arguments) {

    parent::__construct($arguments);

    // the csv file contains the header.
    $dir = drupal_get_path('module', 'amberroad_migrate') . "/menu";
    if (!file_exists("$dir/amberroad_menu.csv")) {
      $this->generate_amberroad_menu_csv($dir);
    }
    $this->source = new MigrateSourceCSV("$dir/amberroad_menu.csv", array(), array('header_rows' => 1));


    // The destination is the menu.
    $this->destination = new MigrateDestinationMenuLinks();

    $this->map = new MigrateSQLMap($this->machineName, array(
      'mlid' => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
        'description' => 'ID of destination link',
      ),
            ), MigrateDestinationMenuLinks::getKeySchema()
    );


    // Map the fields, pretty straightforward in this case.
    $this->addFieldMapping('menu_name')->defaultValue('amberroad-main-menu'); // Always Main menu
    $this->addFieldMapping('plid', 'ref_parent')->sourceMigration($this->getMachineName());
    $this->addFieldMapping('link_path', 'path');          // path of the link
    $this->addFieldMapping('router_path')->defaultValue('node/%');
    $this->addFieldMapping('link_title', 'title');        // Title of the menu item
    $this->addFieldMapping('external')->defaultValue('0'); // Internal
    $this->addFieldMapping('expanded')->defaultValue('0');
    $this->addFieldMapping('customized')->defaultValue('1'); // not customized
    $this->addFieldMapping('has_children')->defaultValue('0');  // Will be overridden automatically
    $this->addFieldMapping('depth')->defaultValue('1'); // Will be overridden automatically

    $this->addUnmigratedDestinations(array('module', 'hidden', 'options', 'p1', 'p2', 'p3', 'p4', 'p5', 'p6', 'p7', 'p8', 'p9', 'updated'));
  }

  /**
   * Prepare a row.
   */
  public function prepareRow($row) {
    // Convert the alias to the node path.
    $node_path = drupal_lookup_path('source', $row->path);
    if($node_path === FALSE && !drupal_valid_path($row->path)) {
      $row->path = "<front>";
    }
    elseif($node_path !== FALSE) {
      $row->path = $node_path;
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
   * Generate Menu csv file for migration.
   */
  private function generate_amberroad_menu_csv($dir = NULL) {
    $csv = "mlid,ref_parent,path,title,Level\n";
    $file_path = "../www.amberroad.com/index.html";
    // Read HTMl File
    $html = file_get_contents($file_path);
    $qp_options = array(
      'convert_to_encoding' => 'utf-8',
      'convert_from_encoding' => 'utf-8',
      'strip_low_ascii' => FALSE,
    );
    $qp = htmlqp($html, NULL, $qp_options);
    $main_menu = $qp->find('.megamenu');

    $parents = $main_menu->children('li')->siblings('li');

    $mlid = 1;
    $pid = 0;
    foreach ($parents as $i => $parent) {
      $title = strtolower($parent->children('a')->innerHTML());
      $title = trim(strip_tags($title));

      $path = $parent->parent()->children('a')->attr('href');
      $path = str_replace("../", "", $path);

      $csv .= "$mlid,$pid,$path,$title,0\n";

      $l1_pid = $mlid;
      $level1_as = $parent->find('.level_1');// First Level
      foreach ($level1_as as $k => $a) {
        $mlid++;
          $title = $a->innerHTML();
          $title = trim(strip_tags($title));

          $path = $a->attr('href');
          $path = str_replace("../", "", $path);

          $csv .= "$mlid,$l1_pid,$path,$title,1\n";
          $ul = $a->parent('li')->parent('ul')->children('ul');
          $level_2_as = $ul->find('a');
          $l2_pid = $mlid;

          foreach ($level_2_as as $a) {
            if ($a->attr('class') != 'level_3') {
              $mlid++;
              $title = $a->innerHTML();
              $title = trim(strip_tags($title));

              $path = $a->attr('href');
              $path = str_replace("../", "", $path);

              $csv .= "$mlid,$l2_pid,$path,$title,2\n";

              $l3_pid = $mlid;

              $li_level3 = $a->parent('li')->nextALL();

              foreach ($li_level3 as $li) {
                $a = $li->children('a');
                if ($a->attr('class') == 'level_3') {
                    $mlid++;
                    $title = $a->innerHTML();
                    $title = trim(strip_tags($title));

                    $path = $a->attr('href');
                    $path = str_replace("../", "", $path);

                    $csv .= "$mlid,$l3_pid,$path,$title,3\n";
                }
              }
            }
          }
        }
      $mlid++;
    }
    // remove special chars.
    $csv = str_replace("&#13;", '', $csv);
    // Write the output to the csv file.
    file_put_contents($dir . "/amberroad_menu.csv",$csv);
  }

  /**
   * Creates a stub menu link, for when a child is imported before its parent
   *
   * @param $migration
   *  The source migration
   * @return
   *  int $mlid on success
   *  FALSE on failure
   */
  protected function createStub($migration) {
    // if ref_parent is 0, that means it has no parent, so don't create a stub
    if (!$migration->sourceValues->ref_parent) {
      return FALSE;
    }
    $menu_link = array (
      'menu_name' => $migration->sourceValues->menu_name,
      'link_path' => 'stub-path',
      'router_path' => 'stub-path',
      'link_title' => t('Stub title'),
    );
    $mlid = menu_link_save($menu_link);
    if ($mlid) {
      return array($mlid);
    }
    else {
      return FALSE;
    }
  }
}
