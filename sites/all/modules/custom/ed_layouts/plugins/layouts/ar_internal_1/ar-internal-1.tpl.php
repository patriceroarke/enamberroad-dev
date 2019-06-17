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

/*if (!empty($content['sidebar'])) {
  $class = 'col-md-9';
  $sidebar = TRUE;
} else {
  $class = 'col-md-12';
  $sidebar = FALSE;
}*/

$class = 'col-md-12';

?>
<div class="panel-display ar-internal-1 clearfix <?php if (!empty($classes)) { print $classes; } ?><?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
<!-- Test -->
  <div class="container-full">
    <?php print $content['header']; ?>
  </div>

  <div class="container main-container">

    <?php
    $right_column_class = 'right-true';
    $content_class = 'col-md-9 right-true';
    if($content['row1-sidebar']=='') {
      $content_class = 'col-md-12 right-false';
      $right_column_class = 'right-false';
    }
    ?>

    <div class="row row1 <?php echo $right_column_class; ?>">
      <div class="<?php echo $content_class; ?> content">
        <div class="panel-panel-inner">
          <?php print $content['row1-content']; ?>
        </div>
      </div>
      <?php if($content['row1-sidebar']!==''): ?>
      <div class="col-md-3 right-sidebar">
        <div class="panel-panel-inner">
          <?php print $content['row1-sidebar']; ?>
        </div>
      </div>
      <?php endif; ?>
    </div>

    <?php if($content['row2']!== '') : ?>
    <div class="row row2">
      <div class="col-md-12 content">
        <div class="panel-panel-inner">
          <?php print $content['row2']; ?>
        </div>
      </div>
    </div>
    <?php endif; ?>

    <?php if($content['row2-2col2']!== '' && $content['row2-2col1']!== '') : ?>
      <div class="row row2-2col">
        <div class="col-md-6 left col-sm-12  col-xs-12 nopadding">
          <div class="panel-panel-inner">
            <?php print $content['row2-2col1']; ?>
          </div>
        </div>
        <div class="col-md-6 right col-sm-12  col-xs-12 nopadding">
          <div class="panel-panel-inner">
            <?php print $content['row2-2col2']; ?>
          </div>
        </div>
      </div>
    <?php endif; ?>

    <?php if($content['row3-main']!== '' && $content['row3-right1']!=='' && $content['row3-right2'] !== '') : ?>
      <div class="row row3">
        <div class="col-md-6 main col-sm-12  col-xs-12">
          <div class="panel-panel-inner">
            <?php print $content['row3-main']; ?>
          </div>
        </div>
        <div class="col-md-3  col-sm-6 col-xs-12 right1">
          <div class="panel-panel-inner">
            <?php print $content['row3-right1']; ?>
          </div>
        </div>
        <div class="col-md-3  col-sm-6 col-xs-12 right2">
          <div class="panel-panel-inner">
            <?php print $content['row3-right2']; ?>
          </div>
        </div>
      </div>
    <?php endif; ?>

    <?php if($content['row3-short-main']!== '' && $content['row3-short-right1']!=='' && $content['row3-short-right2'] !== '') : ?>
      <div class="row row3-short">
        <div class="col-md-6 main col-sm-12  col-xs-12">
          <div class="panel-panel-inner">
            <?php print $content['row3-short-main']; ?>
          </div>
        </div>
        <div class="col-md-3  col-sm-6 col-xs-12 right1">
          <div class="panel-panel-inner">
            <?php print $content['row3-short-right1']; ?>
          </div>
        </div>
        <div class="col-md-3  col-sm-6 col-xs-12 right2">
          <div class="panel-panel-inner">
            <?php print $content['row3-short-right2']; ?>
          </div>
        </div>
      </div>
    <?php endif; ?>

    <?php if($content['row4-full']!== '') : ?>
      <div class="row row4">
        <div class="col-md-12 content">
          <div class="panel-panel-inner">
            <?php print $content['row4-full']; ?>
          </div>
        </div>
      </div>
    <?php endif; ?>

    <?php if($content['row4-content']!== '' || $content['row4-left']!== '') : ?>
    <div class="row row4-2col">
      <div class="col-md-3">
        <div class="panel-panel-inner">
          <?php print $content['row4-left']; ?>
        </div>
      </div>
      <div class="col-md-9">
        <div class="panel-panel-inner">
          <?php print $content['row4-content']; ?>
        </div>
      </div>
    </div>
    <?php endif; ?>


    <?php if($content['row5-2col2']!== '' && $content['row5-2col1']!== '') : ?>
      <div class="row row5-2col">
        <div class="col-md-6 left col-sm-12  col-xs-12 nopadding">
          <div class="panel-panel-inner">
            <?php print $content['row5-2col1']; ?>
          </div>
        </div>
        <div class="col-md-6 right col-sm-12  col-xs-12 nopadding">
          <div class="panel-panel-inner">
            <?php print $content['row5-2col2']; ?>
          </div>
        </div>
      </div>
    <?php endif; ?>



  </div>
    
</div><!-- /.brenham-flipped -->