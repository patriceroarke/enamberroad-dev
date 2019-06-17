<?php

/**
 * @file
 * Basic Page migration support for Amberroad.
 */
/**
 * Mappings for "Node" content migration fields.
 */
module_load_include('inc', 'amberroad_migrate', 'source_parser');

class AmberroadMigrateMidMarketPagesNodeMigration extends Migration implements SourceParser {

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
    $this->base_dir = '../www.amberroad.com/mid-market/';

    // Match HTML files.
    $regex = '/.*\.shtml|\.html/';

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
    $this->addFieldMapping('status')->defaultValue(1);
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

    // Remove index.html source to set required path.
    $path = $row->sourceid;
    if (strpos($path,'.shtml') === false) {
      $path = substr($path, 0, -11);
      $node->path = array('alias' => 'mid-market' .$path . '.shtml');
    }
    else {
      $node->path = array('alias' => 'mid-market' . $path);
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
    $tables = $this->htmlqp($tr->children()->children('table')->html())->top();
    $body = FALSE;
    foreach ($tables->find('table') as $i => $tbl) {
      if ($i == 4) {
        $body = $tbl->html();
        break;
      }
    }
    if ($body !== FALSE) {
      $body = $this->findAllImages($body);
      $body = $this->findSolutionAreaContent($body);
      $body = preg_replace('/[\n\r\t]+/', '', $body);
    }
    return $body;
  }

  /**
   * Return the Page title.
   */
  public function getTitle() {
    $tr = $this->qp->top('body')->find('table[id="main"]')->find('tr:nth-child(3)');
    $tables = $this->htmlqp($tr->children()->children('table')->innerHTML())->top();
    $title = "";
    foreach ($tables->find('table') as $k => $tbl) {
      if ($k == 4 || $k == 3 || $k == 2) {
        $table = $tbl->innerHTML();
        if ($this->htmlqp($table)->find('p.content2:first')->length != 0) {
          $title = $this->htmlqp($table)->find('p.content2:first')->find('span:nth(2)')->innerHTML();
          if (strlen($title) < 5) {
            $title = $this->htmlqp($table)->find('p.content2:first')->find('span:nth(1)')->text();
          }
          break;
        }
      }
    }
    $title = trim(preg_replace("/&#?[a-z0-9]{2,8};/i", "", strip_tags($title))," ");
    if ($pos = strpos($title, 'Home')) {
      $title = substr($title, 0, $pos);
    }
    return $title;
  }

  /**
   * finds all images in html and update the src value.
   */
  public function findAllImages($html) {
    $base_dir = str_replace("mid-market/", "", $this->base_dir);
    $images = $this->htmlqp($html)->top()->find('img');

    foreach ($images as $img) {
      $src = $img->attr('src');
      $file_name = basename($src);
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
        $img->attr('src', file_create_url($file->uri));
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
   * Map the field collection.
   */
  public function complete($entity, $row) {
    $elements = $this->getAdImages();

    // load the newly created node (just in case entity isn't fully populated).
    $node = node_load($entity->nid);
    // loop values to add as field collection items (assumes you have them in a $values array).
    foreach ($elements['img'] as $i => $value) {
      if (!isset($elements['link'][$i])) {
        $elements['link'][$i] = '';
      }
      $values = array(
        'field_name' => 'field_rhs_ad_blocks',
        'field_ad_image' => array(LANGUAGE_NONE => array($value)),
        'field_ad_link' => array(LANGUAGE_NONE => array(array('url' => $elements['link'][$i]))),
      );
      // create the field collection item entity
      $item = entity_create('field_collection_item', $values);

      // attach it to the node loaded above
      $item->setHostEntity('node', $node);
      $item->save();
    }
  }

  /**
   * Return advertise images.
   */
  public function getAdImages() {
    $elements = array(
      'link' => array(),
      'img' => array(),
    );
    $tables = $this->qp->top()->find('table[width="223"]');

    if ($tables->length != 0) {
      foreach ($tables as $table) {}
      $anchors = $table->find('a');

      foreach ($tables as $table) {}
      $images = $table->find('img');

      $i = 0;
      foreach ($anchors as $anchor) {
        $html = $this->htmlqp($anchor->html());
        if ($i == 2) {
          $i++;
        }
        $elements['link'][$i] = $html->top('a')->attr('href');
        $elements['img'][$i] = basename($html->top()->find('img')->attr('src'));
        $i++;
      }

      foreach ($images as $img) {
        if (!in_array(basename($img->attr('src')), $elements['img'])) {
          $elements['img'][2] = basename($img->attr('src'));
        }
      }
    }

    ksort($elements['img']);
    ksort($elements['link']);

    // Save images to drupal file system.
    foreach ($elements['img'] as $i => $image_name) {
      $base_dir = str_replace("mid-market/", "images/", $this->base_dir);
      $url = parse_url($image_name);
      if (file_exists($base_dir . $url['path'])) {
        $image = file_get_contents($base_dir . $url['path']);
        $file = file_save_data($image, "public://block_image/" . $image_name);
      }
      else {
        $base_dir = str_replace("mid-market/", "images/graphics/", $this->base_dir);
        $url = parse_url($image_name);
        if (file_exists($base_dir . $url['path'])) {
          $image = file_get_contents($base_dir . $url['path']);
          $file = file_save_data($image, "public://block_image/" . $image_name);
        }
      }
      $elements['img'][$i] = (array) $file;
    }

    return $elements;
  }
}
