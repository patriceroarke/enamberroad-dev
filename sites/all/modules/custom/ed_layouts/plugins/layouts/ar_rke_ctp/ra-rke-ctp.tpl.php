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


$class = 'col-md-12';

?>

  <div class="panel-display rke-lp clearfix <?php if (!empty($classes)) { print $classes; } ?>">

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
        <div class="col-md-12 content">
          <div class="panel-panel-inner d-flex">
            <?php print $content['row1-flex']; ?>
          </div>
        </div>
        <div class="col-md-12 content">
          <div class="panel-panel-inner">
            <?php print $content['row1-full']; ?>
          </div>
        </div>
      </div>
    </div>
    <div class="container-full bg bg-lightgray">
      <div class="container container-call-to-action">
        <div class="row row2">
          <div class="col-md-12 content">
            <div class="panel-panel-inner">
              <?php print $content['row2-full']; ?>
            </div>
          </div>
        </div>
      </div>
    </div>

    <div class="container main-container">
      <div class="row row3">
        <div class="col-md-12 content">
          <div class="panel-panel-inner">
            <?php print $content['row3-full']; ?>
          </div>
        </div>
        <div class="col-md-6 left col-sm-12 col-xs-12">
          <div class="panel-panel-inner">
            <?php print $content['row3-2col1']; ?>
          </div>
        </div>
        <div class="col-md-6 right col-sm-12  col-xs-12">
          <div class="panel-panel-inner">
            <?php print $content['row3-2col2']; ?>
          </div>
        </div>
      </div>
    </div>


    <div class="container-full bg bg-white">
      <div class="container">
        <div class="row row4">
          <div class="col-md-12 content">
            <div class="panel-panel-inner">
              <?php print $content['row4-full']; ?>
            </div>
          </div>
        </div>
      </div>
    </div>


    <div class="container-full bg bg-white contact-sec">
      <div class="container">
        <div class="row row5">
          <div class="col-md-6 left col-sm-12 col-xs-12">
            <div class="panel-panel-inner">
              <?php print $content['row5-2col1']; ?>
            </div>
          </div>
          <div class="col-md-6 right col-sm-12 col-xs-12">
            <div class="panel-panel-inner">
              <?php print $content['row5-2col2']; ?>
            </div>
          </div>
        </div>
      </div>
    </div>


  </div>
  <!-- /.brenham-flipped -->