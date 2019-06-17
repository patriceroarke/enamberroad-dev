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



?>
<div class="panel-display rke-blog clearfix <?php if (!empty($classes)) { print $classes; } ?><?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
<!-- Test -->
  <div class="container-full">
    <?php print $content['header']; ?>
  </div>
  <div class="container-full">
  <div class="container rke-container">
    <div class="row row1">
      <div class="col-md-12 content">
        <div class="panel-panel-inner">
          <?php print $content['row1-content']; ?>
        </div>
      </div>
    </div>
</div>

  </div>
    
</div><!-- /.brenham-flipped -->