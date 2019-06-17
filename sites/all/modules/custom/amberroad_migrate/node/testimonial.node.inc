<?php

/**
 * @file
 * Tetsimonial migration support for Amberroad.
 */
/**
 * Mappings for "Node" content migration fields.
 */
module_load_include('inc', 'amberroad_migrate', 'source_parser');

class AmberroadMigrateTestimonialNodeMigration extends Migration implements SourceParser {

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
      'name' => t('Name'),
      'testimonial' => t('Testimonial'),
      'logo' => t('Logo'),
      'challenge' => t('Challenge'),
      'solution' => t('Solution'),
      'benefits' => t('Benefits'),
      'pdf' => t('PDF'),
      'uid' => t('User id'),
    );

    // Since the base directory of the HTML files can change depending on the
    // environment, we keep it in a variable. There is no interface for this,
    // set it using drush vset.
    $this->base_dir = '../www.amberroad.com/html/case/';

    // Match HTML files.
    $regex = '/.*\.shtml/';

    // The source of the migration is HTML files from the old site.
    $list_files = new MigrateListFiles(array($this->base_dir), $this->base_dir, $regex);

    $item_file = new MigrateItemFile($this->base_dir);
    $this->source = new MigrateSourceList($list_files, $item_file, $fields);
    // The destination is the mynode content type.
    $this->destination = new MigrateDestinationNode('testimonial');

    // Map the fields, pretty straightforward in this case.
    $this->addFieldMapping('uid', 'uid');
    $this->addFieldMapping('title', 'name');
    $this->addFieldMapping('field_event_logo', 'logo');
    $this->addFieldMapping('field_event_logo:destination_dir')
      ->defaultValue('public://Client_logo/');
    $this->addFieldMapping('field_event_logo:source_dir')
      ->defaultValue("../www.amberroad.com/images/logos/customers/");
    $this->addFieldMapping('field_testimonial', 'testimonial');
    $this->addFieldMapping('field_testimonial:format')->defaultValue('full_html');
    $this->addFieldMapping('field_challenge', 'challenge');
     $this->addFieldMapping('field_challenge:format')->defaultValue('full_html');
    $this->addFieldMapping('field_solution', 'solution');
     $this->addFieldMapping('field_solution:format')->defaultValue('full_html');
    $this->addFieldMapping('field_benefits', 'benefits');
     $this->addFieldMapping('field_benefits:format')->defaultValue('full_html');
    $this->addFieldMapping('field_resource_link', 'pdf');
    $this->addFieldMapping('status')->defaultValue(1);
  }

  /**
   * Prepare a row.
   */
  public function prepareRow($row) {
    // Create a new SourceParser to handle HTML content.
    $this->init(substr($row->sourceid, 1), $row->filedata);
      // Set to admin for now.
      $row->uid = 1;
      $row->logo = $this->getClientLogo();

      // Set page title.
      $row->name = $this->getClientName($row->sourceid);
      //$this->getAdImages();

      // Set Testimonial.
      $row->testimonial = $this->getClientTestimonial();

      // Set challenge.
      $row->challenge = $this->getChallenges();

      // Set solution.
      $row->solution = $this->getSolution();

      // Set benefits.
      $row->benefits = $this->getBenefits();

      // Get PDF
      $row->pdf = $this->getClientPDF();
  }

   /**
   * Prepare node object.
   */
  public function prepare($node, stdClass $row) {

    $node->title = preg_replace('/[^A-Za-z0-9\-" "]/', '', trim($node->title));
    $node->path = array('alias' => 'html/case' . $row->sourceid);
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
  public function getClientLogo() {
    $main_table = $this->qp->top('body')->find('table[id="main"]');
    $src = FALSE;
    foreach ($main_table->find('table[id="main"] > tr') as $i => $tr) {
      if ($i == 2) {

        $table = $this->htmlqp($tr->children()->children('table')->innerHTML())->top();
        foreach ($table->find('table') as $j => $tbl) {
          if ($j == 3) {
            $img = $tbl->find('tr:first')->find('p:nth-child(1)')->find('img');
            $src = basename($img->attr('src'));
            break;
          }
        }
      }
    }
    return trim($src);
  }

  /**
   * Return the Page title.
   */
  public function getClientName($path = NULL) {
    $clients = array ();

    $main_table = $this->qp->top('body')->find('table[id="main"]');
    $src = FALSE;
    foreach ($main_table->find('table[id="main"] > tr') as $i => $tr) {
      if ($i == 2) {

        $table = $this->htmlqp($tr->children()->children('table')->innerHTML())->top();
        foreach ($table->find('table') as $j => $tbl) {
          if ($j == 3) {
            $anchors = $tbl->find('tr:first')->find('span')->find('a');
            foreach ($anchors as $anchor) {
              $clients[$anchor->attr('href')] = $anchor->text();
            }
            break;
          }
        }
      }
    }
    return $clients[substr($path, 1)];
  }

  /**
   * finds all images in html and update the src value.
   */
  public function findAllImages($html) {
    global $base_path;
    $base_dir = str_replace("html/", "", $this->base_dir);
    $images = $this->htmlqp($html)->top()->find('img');

    foreach ($images as $img) {
      $src = $img->attr('src');
      $file_name = basename($src);
      $path = "sites/default/files/images";
      $uri = file_build_uri($path);
      $url = parse_url($src);

      if (strstr($url['path'], '../')) {
        $url['path'] = str_replace("../", '', $url['path']);
      }
      else {
        $url['path'] = substr($url['path'], 1, strlen($url['path']));
      }

      if (file_exists($base_dir . $url['path'])) {
        $image = file_get_contents($base_dir . $url['path']);
        $file = file_save_data($image, "public://images/" . $file_name);
        $img->attr('src', file_create_url("public://images/" . $file_name));
      }
    }
    $htm = $images->top('body')->innerHTML();
    return ($images->size()>0)?$htm:$html;
  }

  /**
   * Return the Page Banner.
   */
  public function getClientTestimonial() {
    $main_table = $this->qp->top('body')->find('table[id="main"]');
    $testimonial = FALSE;
    $flag = FALSE;
    foreach ($main_table->find('table[id="main"] > tr') as $i => $tr) {
      if ($i == 2) {

        $table = $this->htmlqp($tr->children()->children('table')->innerHTML())->top();
        foreach ($table->find('table') as $j => $tbl) {
          if ($j == 3) {
            $trs = $tbl->find('tr');
            foreach ($trs as $i => $tr) {
              if ($flag) {
                $span = $tr->find('span');
                $testimonial = $span->text();
                $testimonial = preg_replace('/[\n\r\t]+/', '', $testimonial);
                break;
              }

              $span = $tr->find('span');
              if ($span->text() == "Testimonial") {
                $flag = TRUE;
              }
            }
          }
        }
      }
    }

    return $testimonial;
  }

  /**
   * Return the Solution.
   */
  public function getSolution() {
    $main_table = $this->qp->top('body')->find('table[id="main"]');
    $solution = FALSE;
    $flag = FALSE;
    foreach ($main_table->find('table[id="main"] > tr') as $i => $tr) {
      if ($i == 2) {

        $table = $this->htmlqp($tr->children()->children('table')->innerHTML())->top();
        foreach ($table->find('table') as $j => $tbl) {
          if ($j == 3) {
            $tr = $tbl->find('tr:nth-child(7)');
            $span = $tr->find('span');
            $solution = $span->text();
            $solution = preg_replace('/[\n\r\t]+/', '', $solution);
            break;
          }
        }
      }
    }
    return $solution;
  }

  /**
   * Return the Challenges.
   */
  public function getChallenges() {
    $main_table = $this->qp->top('body')->find('table[id="main"]');
    $challenges = FALSE;
    $flag = FALSE;
    foreach ($main_table->find('table[id="main"] > tr') as $i => $tr) {
      if ($i == 2) {

        $table = $this->htmlqp($tr->children()->children('table')->innerHTML())->top();
        foreach ($table->find('table') as $j => $tbl) {
          if ($j == 3) {
            $tr = $tbl->find('tr:nth-child(5)');
            $span = $tr->find('span');
            $challenges = $span->text();
            $challenges = preg_replace('/[\n\r\t]+/', '', $challenges);
            break;
          }
        }
      }
    }
    return $challenges;
  }

  /**
   * Return the Benefits.
   */
  public function getBenefits() {
    $main_table = $this->qp->top('body')->find('table[id="main"]');
    $benefits = FALSE;
    $flag = FALSE;
    foreach ($main_table->find('table[id="main"] > tr') as $i => $tr) {
      if ($i == 2) {

        $table = $this->htmlqp($tr->children()->children('table')->innerHTML())->top();
        foreach ($table->find('table') as $j => $tbl) {
          if ($j == 3) {
            $tr = $tbl->find('tr:nth-child(9)');
            $benefits = $tr->html();
            $benefits = preg_replace('/[\n\r\t]+/', '', $benefits);
            break;
          }
        }
      }
    }
    return $benefits;
  }

    /**
   * Return the PDF.
   */
  public function getClientPDF() {
    $main_table = $this->qp->top('body')->find('table[id="main"]');
    $src = FALSE;
    foreach ($main_table->find('table[id="main"] > tr') as $i => $tr) {
      if ($i == 2) {

        $table = $this->htmlqp($tr->children()->children('table')->innerHTML())->top();
        foreach ($table->find('table') as $j => $tbl) {
          if ($j == 3) {
            $a = $tbl->find('tr:first')->find('p:nth-child(2)')->find('a');
            $src = $a->attr('href');
            break;
          }
        }
      }
    }
    return trim($src);
  }

}
