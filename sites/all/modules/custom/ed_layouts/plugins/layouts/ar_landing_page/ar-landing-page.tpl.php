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
<div class="panel-display rke-lp clearfix <?php if (!empty($classes)) { print $classes; } ?><?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <div class="container-full">
    <?php print $content['header']; ?>
  </div>

  <div class="container main-container">

    <div class="row row1">
      <div class="col-md-12 content">
        <div class="panel-panel-inner">
          <?php print $content['row1-content']; ?>
        </div>
      </div>
      <div class="col-md-6 left col-sm-12 col-xs-12">
        <div class="panel-panel-inner">
          <?php print $content['row1-2col1']; ?>
        </div>
      </div>
      <div class="col-md-6 right col-sm-12  col-xs-12">
        <div class="panel-panel-inner">
          <?php print $content['row1-2col2']; ?>
        </div>
      </div>
    </div>
    </div>

    <?php if($content['row2']!== '') : ?>
</div>
    <div class="container-full bg bg-lightgray">
    <div class="container container-call-to-action">
    <div class="row row2">
      <div class="col-md-12 content">
        <div class="panel-panel-inner">
          <?php print $content['row2']; ?>
        </div>
      </div>
      </div>
    </div>
    </div>
    <div class="container main-container">
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
        <div class="col-md-6 left col-sm-12  col-xs-12">
          <div class="panel-panel-inner">
            <?php print $content['row5-2col1']; ?>
          </div>
        </div>
        <div class="col-md-6 right col-sm-12  col-xs-12">
          <div class="panel-panel-inner">
            <?php print $content['row5-2col2']; ?>
          </div>
        </div>
      </div>
    <?php endif; ?>

    <?php if($content['row6']!== '') : ?>
</div>
    <div class="container-full bg bg-white">
    <div class="container">
    <div class="row row6">
      <div class="col-md-12 content">
        <div class="panel-panel-inner">
          <?php print $content['row6']; ?>
        </div>
      </div>
      </div>
    </div>
    </div>
    <?php endif; ?>

   

    <?php if($content['row6-2col2']!== '' && $content['row6-2col1']!== '') : ?>
    <div class="container-full bg bg-white">
    <div class="container">
      <div class="row row6-2col">
        <div class="col-md-6 left col-sm-12  col-xs-12">
          <div class="panel-panel-inner">
            <?php print $content['row6-2col1']; ?>
          </div>
        </div>
        <div class="col-md-6 right col-sm-12  col-xs-12">
          <div class="panel-panel-inner">
            <?php print $content['row6-2col2']; ?>
          </div>
        </div>
      </div>
</div>
</div>
    <?php endif; ?>



    <?php if($content['row2']!== '' || $content['row6']!== '' ): ?>
  </div> 
  <?php endif; ?>
</div><!-- /.brenham-flipped -->