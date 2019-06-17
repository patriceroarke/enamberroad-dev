<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 * @see html.tpl.php
 */
?>
<header id="header" class="header" role="header">
  <div class="container">
    <div class="col-md-3">
      <?php
      global $base_url;
      if(strpos($base_url, 'evolve')){
        $url = 'http://www.amberroad.com';
      } else {
        $url = $base_url;
      }
      ?>

      <a href="<?php echo $url; ?>"><img src="/sites/all/themes/ar_theme/assets/images/amberroad-logo.png" alt="Amber Road - Global Trade Management Software"></a>
    </div>
    <div class="col-md-7">
      <div class="header-language">
        <span id='select'><?php echo t('Languages'); ?></span>
        <ul class='list-unstyled' id="language-option">
          <?php
          $amberroad_site = variable_get('amberroad_site');
          if($amberroad_site == 'fr'): ?>
            <li><a href="https://www.amberroad.com/">English</a></li>
            <li><a href="https://de.amberroad.com/">German</a></li>
            <li><a href="http://cn.amberroad.com/">Chinese</a></li>
          <?php elseif($amberroad_site == 'us'): ?>
            <li><a href="https://fr.amberroad.com/"><?php echo t('French'); ?></a></li>
            <li><a href="https://de.amberroad.com/"><?php echo t('German'); ?></a></li>
            <li><a href="http://cn.amberroad.com/"><?php echo t('Chinese'); ?></a></li>
          <?php elseif($amberroad_site == 'de'): ?>
            <li><a href="https://www.amberroad.com/"><?php echo t('English'); ?></a></li>
            <li><a href="https://fr.amberroad.com/"><?php echo t('French'); ?></a></li>
            <li><a href="http://cn.amberroad.com/"><?php echo t('Chinese'); ?></a></li>
          <?php elseif($amberroad_site == 'it'): ?>
            <li><a href="https://www.amberroad.com/"><?php echo t('English'); ?></a></li>
            <li><a href="https://www.amberroad.de/"><?php echo t('German'); ?></a></li>
            <li><a href="http://cn.amberroad.com/"><?php echo t('Chinese'); ?></a></li>
            <li><a href="https://fr.amberroad.com/"><?php echo t('French'); ?></a></li>
          <?php endif; ?>
        </ul>
      </div>
      <div class="clearfix"></div>
      <div id="block-menu-menu-header">
        <?php
        $block = module_invoke('menu', 'block_view', 'menu-header');
        print render($block['content']);
        ?>
      </div>
    </div>
    <div class="col-md-2">
      <div id="block-search-form">
        <?php
        $block = module_invoke('search', 'block_view', 'form');
        print render($block['content']);
        ?>
      </div>
    </div>
  </div>
  <div class="container-full" id="main-menu">
    <div class="container">
      <div class="nav-logo" style="display:none;">
        <a href="/"><img src="/sites/all/themes/ar_theme/assets/images/amberroad-logo.png"></a>
      </div>
      <?php
      //$block = module_invoke('tb_megamenu', 'block_view', 'amberroad-main-menu');
      //print render($block['content']);
      $block = module_invoke('superfish', 'block_view', '1');
      print render($block['content']);
      ?>
    </div> <!-- /.container -->

    </div>
  <div class="container" id="main-menu-mobile">
    <div class="nav-logo" style="display:none;">
      <a href="/"><img src="/sites/all/themes/ar_theme/assets/images/amberroad-logo.png"></a>
    </div>
    <?php
    $block = module_invoke('menu', 'block_view', 'amberroad-main-menu');
    print render($block['content']);
    ?>
  </div>
</header>
<div id="main-wrapper">
  <div id="main" class="main">
    <div class="container">
<!--      <?php /*if ($breadcrumb && current_path() != 'front'): */?>
        <div id="breadcrumb" class="visible-desktop">
          <?php /*print $breadcrumb; */?>
        </div>
      --><?php /*endif; */?>
      <?php if ($messages): ?>
        <div id="messages">
          <?php print $messages; ?>
        </div>
      <?php endif; ?>
      <div id="page-header">
<!--        <?php /*if ($title): */?>
          <div class="page-header">
            <h1 class="title"><?php /*print $title; */?></h1>
          </div>
        <?php /*endif; */?>
        <?php /*if ($tabs): */?>
          <div class="tabs">
            <?php /*print render($tabs); */?>
          </div>
        --><?php /*endif; */?>
        <?php if ($action_links): ?>
          <ul class="action-links">
            <?php print render($action_links); ?>
          </ul>
        <?php endif; ?>
      </div>
    </div>
    <div id="content">
      <?php print render($page['content']); ?>
    </div>
  </div> <!-- /#main -->
</div> <!-- /#main-wrapper -->

<footer id="footer" class="footer" role="footer">
  <div class="container">
      <div id="content">
        <?php print render($page['footer']); ?>
      </div>
    <!--<small class="pull-right"><a href="#"><?php print t('Back to Top'); ?></a></small>-->
      <div class="row">
        <div class="container">
          <div class="horizontal-menu">
            <?php
            $menu_items = menu_tree_output(menu_tree_all_data('menu-footer-bottom'));
            print render($menu_items);
            ?>
          </div>
        </div> <!-- container -->
        <div class="container">
          <?php global $base_url; ?>
          <div class="social-links">
            <a href="https://www.linkedin.com/company/amber-road/" title=""><img width="24" src="<?php echo $base_url.'/'.drupal_get_path('theme', 'ar_theme'); ?>/img/linked_in_64px.png" alt="Follow Amber Road on LinkedIn" ></a>
            <a href="http://twitter.com/GTMBestPractice" title=""><img width="24" src="<?php echo $base_url.'/'.drupal_get_path('theme', 'ar_theme'); ?>/img/twitter_64px.png" alt="Follow Amber Road on Twitter"></a>
            <a href="http://www.youtube.com/user/GTMBestPractices" title=""><img width="24" src="<?php echo $base_url.'/'.drupal_get_path('theme', 'ar_theme'); ?>/img/youtube64px.png" alt="Subscribe to Amber Road’s Channel on YouTube"></a>
            <a href="http://www.amberroad.com/html/rl_blogs.shtml" title=""><img width="24" src="<?php echo $base_url.'/'.drupal_get_path('theme', 'ar_theme'); ?>/img/rss_64px.png" alt="Subscribe to Amber Road’s RSS Feed"></a>
            <a href="http://www.facebook.com/pages/Amber+Road/507641042664548" title=""><img width="24" src="<?php echo $base_url.'/'.drupal_get_path('theme', 'ar_theme'); ?>/img/facebook_64px.png" alt="Like Amber Road on Facebook"></a>
            <a href="https://www.pinterest.com/gtmbestpractice" title=""><img width="24" src="<?php echo $base_url.'/'.drupal_get_path('theme', 'ar_theme'); ?>/img/pinterest_64px.png" alt="Follow Amber Road on Pinterest"></a>
          </div>
          <div class="copyright"><span>&#169; 2019 Amber Road, Inc.</span></div>
        </div>
      </div>
  </div>
</footer>
<?php print $amberroad_structure_data ?>
