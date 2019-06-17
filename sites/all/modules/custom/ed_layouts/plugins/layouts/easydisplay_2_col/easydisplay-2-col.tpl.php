<?php
/**
 * @file
 * Template for Radix Sutro Double.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 * panel of the layout. This layout supports the following sections:
 */
?>

<div class="panel-display easydisplay-4-columns clearfix <?php if (!empty($classes)) { print $classes; } ?><?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <!-- container-full md-12 -->
  <div class="container-fluid">
    <div class="row">
      <div class="container">

        <div class="col-xs-12 col-sm-6 col1">
          <div class="panel-panel-inner">
            <?php print $content['col1']; ?>
          </div>
        </div>
        <div class="col-xs-12 col-sm-6 col2">
          <div class="panel-panel-inner">
            <?php print $content['col2']; ?>
          </div>
        </div>

      </div>
    </div>
  </div>

</div><!-- /.sutro-double -->
