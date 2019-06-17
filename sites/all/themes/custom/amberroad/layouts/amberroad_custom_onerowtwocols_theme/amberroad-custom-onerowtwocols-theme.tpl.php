  <?php
  /**
   * @file
   * Template for Radix Brenham Flipped.
   *
   * Variables:
   * - $css_id: An optional CSS id to use for the layout.
   * - $content: An array of content, each item in the array is keyed to one
   * panel of the layout. This layout supports the following sections:
   */
  ?>
  <?php

  if ($content['content_sidebar'] !== '') {
    $class = 'col-md-9';
    $sidebar = TRUE;
  } else {
    $class = 'col-md-12';
    $sidebar = FALSE;
  }

  ?>
  <div class="panel-display brenham-flipped clearfix <?php if (!empty($classes)) { print $classes; } ?><?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

    <div class="container-full">
      <div class="row">
        <div class="col-md-12 radix-layouts-header panel-panel">
          <div class="panel-panel-inner">
            <?php print $content['content_banner']; ?>
          </div>
        </div>
      </div>
      <div class="container">
        <div class="row">
          <div class="col-md-12 radix-layouts-header panel-panel">
            <div class="panel-panel-inner">
              <?php print $content['content_top']; ?>
            </div>
          </div>
        </div>

      <div class="row">
        <div class="<?php echo $class; ?> radix-layouts-content panel-panel">
          <div class="panel-panel-inner">
            <?php print $content['content_main']; ?>
          </div>
        </div>
        <?php if ($sidebar) : ?>
          <div class="col-md-3 radix-layouts-sidebar panel-panel content-sidebar">
            <div class="panel-panel-inner">
              <?php print $content['content_sidebar']; ?>
            </div>
          </div>
        <?php endif; ?>
      </div>
    </div>

  </div><!-- /.brenham-flipped -->