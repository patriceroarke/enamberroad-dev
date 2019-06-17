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

<div class="panel-display sutro-double clearfix <?php if (!empty($classes)) { print $classes; } ?><?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <!-- header -->
  <?php if($content['header_top'] !== ''): ?>
  <div class="container-full ab-header-top">
    <div class="row">
      <div class="col-md-12 panel-panel">
        <div class="panel-panel-inner">
          <?php print $content['header_top']; ?>
        </div>
      </div>
    </div>
  </div> <!-- //end of header -->
  <?php endif; ?>


  <div class="container-full ab-header">
    <div class="row">
      <div class="col-md-12 panel-panel">
        <div class="panel-panel-inner">
          <?php print $content['header']; ?>
        </div>
      </div>
    </div>
  </div> <!-- //end of header -->


  <!-- section1 -->
  <div class="container-full  ab-section1">
    <!-- section1 header -->
    <div class="row section1-header">
      <div class="col-md-12 panel-panel">
        <div class="panel-panel-inner">
          <?php print $content['section1_header']; ?>
        </div>
      </div>
    </div>
    <!-- section1 3cols-1 -->
    <div class="row section1-3cols1">
      <div class="container">
        <div class="col-md-4 panel-panel">
          <div class="panel-panel-inner">
            <?php print $content['section1_3cols1_1']; ?>
          </div>
        </div>
        <div class="col-md-4 panel-panel">
          <div class="panel-panel-inner">
            <?php print $content['section1_3cols1_2']; ?>
          </div>
        </div>
        <div class="col-md-4 panel-panel">
          <div class="panel-panel-inner">
            <?php print $content['section1_3cols1_3']; ?>
          </div>
        </div>
      </div>
    </div>
    <!-- section1 Main -->
    <?php if($content['section1_main'] !== ''): ?>
      <div class="row section1-main">
        <div class="col-md-12 panel-panel">
          <div class="panel-panel-inner">
            <?php print $content['section1_main']; ?>
          </div>
        </div>
      </div>
    <?php endif; ?>
    <!-- section1 3cols-2 -->
    <div class="row section1-3cols2">
      <div class="container">
        <div class="col-md-4 panel-panel">
          <div class="panel-panel-inner">
              <?php print $content['section1_3cols2_1']; ?>
          </div>
        </div>
        <div class="col-md-4 panel-panel">
          <div class="panel-panel-inner">
            <?php print $content['section1_3cols2_2']; ?>
          </div>
        </div>
        <div class="col-md-4 panel-panel">
          <div class="panel-panel-inner">
            <?php print $content['section1_3cols2_3']; ?>
          </div>
        </div>
      </div>
    </div>    <!-- section1 2cols -->
    <?php if($content['section1_2cols1']!== '' && $content['section1_2cols2'] !== ''): ?>
    <div class="row section1-2cols">
      <div class="container">
        <div class="col-md-6 panel-panel">
          <div class="panel-panel-inner">
            <?php print $content['section1_2cols1']; ?>
          </div>
        </div>
        <div class="col-md-6 panel-panel">
          <div class="panel-panel-inner">
            <?php print $content['section1_2cols2']; ?>
          </div>
        </div>
      </div>
    </div>
    <?php endif; ?>
    <!-- section1 footer -->
    <?php if($content['section1_footer'] !== ''): ?>
    <div class="row section1-footer">
      <div class="col-md-12 panel-panel">
        <div class="panel-panel-inner">
          <?php print $content['section1_footer']; ?>
        </div>
      </div>
    </div>
    <?php endif; ?>
  </div> <!-- // end of section1 -->


  <!-- section2 -->
  <?php if(!empty($content['section2'])) : ?>
  <div class="container-full ab-section2">
    <!-- section2 2cols -->
    <div class="row">
        <div class="col-md-12 panel-panel">
          <div class="panel-panel-inner">
            <?php print $content['section2']; ?>
          </div>
        </div>
    </div>
  </div> <!-- // end of section2 -->
  <?php endif; ?>

  <!-- section3 -->
  <div class="container-full ab-section3">
    <!-- section3 header -->
      <div class="row">
        <div class="container">
        <div class="col-md-12 panel-panel">
          <div class="panel-panel-inner">
            <?php print $content['section3_header']; ?>
          </div>
        </div>
      </div>
    </div>
    <!-- section3 2cols -->
    <div class="row">
      <div class="container">
        <div class="col-md-6 panel-panel">
          <div class="panel-panel-inner">
            <?php print $content['section3_2cols1']; ?>
          </div>
        </div>
        <div class="col-md-6 panel-panel">
          <div class="panel-panel-inner">
            <?php print $content['section3_2cols2']; ?>
          </div>
        </div>
      </div>
    </div>
    <!-- section3 3cols -->
    <div class="row">
      <div class="container">
        <div class="col-md-4 panel-panel">
          <div class="panel-panel-inner">
            <?php print $content['section3_3cols1']; ?>
          </div>
        </div>
        <div class="col-md-4 panel-panel">
          <div class="panel-panel-inner">
            <?php print $content['section3_3cols2']; ?>
          </div>
        </div>
        <div class="col-md-4 panel-panel">
          <div class="panel-panel-inner">
            <?php print $content['section3_3cols3']; ?>
          </div>
        </div>
      </div>
    </div>
    <!-- section3 footer -->
    <div class="row">
      <div class="col-md-12 panel-panel">
        <div class="panel-panel-inner">
          <?php print $content['section3_footer']; ?>
        </div>
      </div>
    </div>
  </div> <!-- // end of section3 -->

  <!-- section4 -->
  <div class="container-full ab-section4">
    <div class="row">
      <div class="col-md-12 panel-panel">
        <div class="panel-panel-inner">
          <?php print $content['section4']; ?>
        </div>
      </div>
    </div>
  </div> <!-- // end of section4 -->


  <!-- section5 -->
  <div class="container-full ab-section5">
    <!-- section5 2cols -->
    <div class="row">
      <div class="container">
        <div class="col-md-6 panel-panel">
          <div class="panel-panel-inner">
            <?php print $content['section5_2cols1']; ?>
          </div>
        </div>
        <div class="col-md-6 panel-panel">
          <div class="panel-panel-inner">
            <?php print $content['section5_2cols2']; ?>
          </div>
        </div>
      </div>
    </div>
  </div> <!-- // end of section5 -->

</div>