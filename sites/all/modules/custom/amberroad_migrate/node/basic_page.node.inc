<?php

/**
 * @file
 * Basic Page migration support for Amberroad.
 */
/**
 * Mappings for "Node" content migration fields.
 */
module_load_include('inc', 'amberroad_migrate', 'source_parser');

class AmberroadMigrateBasicPagesNodeMigration extends Migration implements SourceParser {

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
      'banner_image' => t('Banner Image'),
      'blog' => t('Related Blog Posts'),
      'uid' => t('User id'),
    );

    // Since the base directory of the HTML files can change depending on the
    // environment, we keep it in a variable. There is no interface for this,
    // set it using drush vset.
    $this->base_dir = '../www.amberroad.com/html/';

    // Match HTML files.
    $regex = '/^(?!press_coverage|rl_pod|careers|testimonials|webinars|seminars|press|awards|press_releases|rl_ebooks.shtml|rl_case_studies.shtml|rl_brochures.shtml|rl_analyst_reports.shtml|rl_white_papers.shtml|rl_product_tours.shtml|rl_webinars.shtml|industry_events.shtml)(.*\.shtml)/';

    // The source of the migration is HTML files from the old site.
    $list_files = new MigrateListFiles(array($this->base_dir), $this->base_dir, $regex);

    $item_file = new MigrateItemFile($this->base_dir);
    $this->source = new MigrateSourceList($list_files, $item_file, $fields);
    // The destination is the mynode content type.
    $this->destination = new MigrateDestinationNode('page');

    // Map the fields, pretty straightforward in this case.
    $this->addFieldMapping('uid', 'uid');
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('body:format')->defaultValue('full_html');
    $this->addFieldMapping('field_header_image', 'banner_image');
    $this->addFieldMapping('field_header_image:destination_dir')
      ->defaultValue('public://header_images/');
    $this->addFieldMapping('field_header_image:source_dir')
      ->defaultValue("../www.amberroad.com/images/flash_box/");
    $this->addFieldMapping('field_related_blog_post', 'blog');
    $this->addFieldMapping('workbench_moderation_state_new')->defaultValue('published');
  }

  /**
   * Prepare a row.
   */
  public function prepareRow($row) {
    // Create a new SourceParser to handle HTML content.
    $this->init(substr($row->sourceid, 1), $row->filedata);
    if (strrpos($row->sourceid, 'press/') !== FALSE || strrpos($row->sourceid, 'case/') !== FALSE || strrpos($row->sourceid, 'legal/') !== FALSE || strrpos($row->sourceid, 'a/') !== FALSE) {
      return FALSE;
    }
    $body = $this->getBody();
    if ($body !== FALSE) {
      // Set to admin for now.
      $row->uid = 1;
      $row->body = $body;

      // Set page title.
      $row->title = $this->getTitle();
      // Set Banner Image.
      $row->banner_image = $this->getBannerImage();
      $row->blog = $this->getRelatedBlogs();
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
    $main_table = $this->qp->top('body')->find('table[id="main"]');
    $body = FALSE;
    foreach ($main_table->find('table[id="main"] > tr') as $i => $tr) {
      if ($i == 2) {

        $table = $this->htmlqp($tr->children()->children('table')->html())->top();
        foreach ($table->find('table') as $j => $tbl) {
          if ($j == 3) {
            $body = $tbl->html();
            $body = preg_replace('/[\n\r\t]+/', '', $body);
          }
        }
      }
    }
    if ($body !== FALSE) {
      $body = $this->findAllImages($body);
      $body = $this->findSolutionAreaContent($body);
      $body = $this->fixAllAnchortags($body);
      $body = preg_replace('/[\n\r\t]+/', '', $body);
    }
    return $body;
  }

  /**
   * Return the Page title.
   */
  public function getTitle() {
    $main_table = $this->qp->top('body')->find('table[id="main"]');
    $title = "";
    foreach ($main_table->find('table[id="main"] > tr') as $i => $tr) {
      if ($i == 2) {

        $tables = $this->htmlqp($tr->children()->children('table')->innerHTML())->top();
        foreach ($tables->find('table') as $k => $tbl) {
          if ($k == 2) {
            $table = $tbl->innerHTML();
            $title = $this->htmlqp($table)->find('p.content2')->find('span:first')->text();
            $title = trim(preg_replace("/&#?[a-z0-9]{2,8};/i", "", strip_tags($title))," ");
            if (strlen($title) < 4) {
              $title = $this->htmlqp($table)->find('p.content2')->find('span:nth(2)')->text();
            }
          }
        }
      }
    }
    $title = trim(preg_replace("/&#?[a-z0-9]{2,8};/i", "", strip_tags($title))," ");
    $title = preg_replace('/[\n\r\t]+/', '', $title);
    if ($pos = strpos($title, 'Home')) {
      $title = substr($title, 0, $pos);
    }
    return $title;
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

  /**
   * Return the Page Related Blogs.
   */
  public function getRelatedBlogs() {
    $related_blog_box = $this->qp->top('body')->find('.box2');
    $script = $related_blog_box->children('script');
    $src = $script->attr('src');
    return $src;
  }

  /**
   * Return the parent menu.
   */
  public function getParentMenuItem() {
    $breadcrumb = $this->qp->top('body')->find('p.content2');
    $parent = '';
    foreach ($breadcrumb as $item) {
      $anchor = $item->children('font')->children('span')->children('a');
      $size  = $anchor->size();

      foreach ($anchor as $i => $item) {
        if ($i == ($size - 1)) {
          $parent = trim($item->text());
        }
      }
      break;
    }
    return $parent;
  }

  /**
   * Find out solution area content.
   */
  public function findSolutionAreaContent($body) {
    $related_content_table = $this->htmlqp($body)->find('table[id="Table_01"]');
    $basic_page = $body;
    if ($related_content_table->length !== 0) {
      $basic_page = FALSE;
    }
    return $basic_page;
  }

  /**
   * Fixes all anchor tags in html and update the href value.
   */
  public function fixAllAnchortags($html) {
    $anchors = $this->htmlqp($html)->top()->find('a');
    foreach ($anchors as $anchor) {
      $href = $anchor->attr('href');

      if (strpos($href, 'http') != FALSE) {
        $href = '/' . $href;
      }
      elseif (strpos($href, '../../') !== FALSE) {
        $href = str_replace('../../', '/', $href);
      }
      elseif (strpos($href, '../') !== FALSE) {
        $href = str_replace('../', '/', $href);
      }
      elseif (strpos($href, 'case') !== FALSE || strpos($href, '/') === FALSE) {
        $href = '/html/' . $href ;
      }

      $anchor->attr('href', $href);
    }

    $htm = $anchors->top('body')->innerHTML();
    return ($anchors->size()>0)?$htm:$html;
  }
}
