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

<div class="panel-display ar-double clearfix <?php if (!empty($classes)) { print $classes; } ?><?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <!-- header -->
  <?php if($content['header_top'] !== ''): ?>
  <div class="container-full ar-header-top">
    <div class="row">
      <div class="col-md-12 panel-panel">
        <div class="panel-panel-inner">
          <?php print $content['header_top']; ?>
        </div>
      </div>
    </div>
  </div> <!-- //end of header -->
  <?php endif; ?>


  <div class="container-full ar-header">
    <div class="row">
      <div class="col-md-12 panel-panel">
        <div class="panel-panel-inner">
          <?php print $content['header']; ?>
        </div>
      </div>
    </div>
  </div> <!-- //end of header -->


	  <!-- section1 -->
  <div class="container-full  ar-section1">
    <!-- section1 header -->
    <div class="row section1-header">
      <div class="col-md-12 panel-panel">
        <div class="panel-panel-inner">
          <?php print $content['section1_header']; ?>
        </div>
      </div>
    </div>

	  
  <!-- section1 -->
  <div class="container-full  ar-section1">
    <!-- section1 header -->
    <div class="row section1-header">
      <div class="col-md-12 panel-panel">
        <div class="panel-panel-inner">
          <?php print $content['section1_header']; ?>
        </div>
      </div>
    </div>
	  
	  	  
	   <!-- section2 -->
  <div class="container-full ar-section2 bg-color4">
    <!-- section2 header -->
      <div class="row">
        <div class="container">
        <div class="col-md-12 panel-panel">
          <div class="panel-panel-inner">
            <?php print $content['section2_header']; ?>
          </div>
        </div>
      </div>
    </div>
    <!-- section2 2cols -->
    <div class="row">
      <div class="container">
        <div class="col-md-6 panel-panel">
          <div class="panel-panel-inner">
            <?php print $content['section2_2cols1']; ?>
          </div>
        </div>
        <div class="col-md-6 panel-panel">
          <div class="panel-panel-inner">
            <?php print $content['section2_2cols2']; ?>
          </div>
        </div>
      </div>
    </div>
    <!-- section2 3cols -->
    <div class="row">
      <div class="container">
        <div class="col-md-4 panel-panel">
          <div class="panel-panel-inner">
            <?php print $content['section2_3cols1']; ?>
          </div>
        </div>
        <div class="col-md-4 panel-panel">
          <div class="panel-panel-inner">
            <?php print $content['section2_3cols2']; ?>
          </div>
        </div>
        <div class="col-md-4 panel-panel">
          <div class="panel-panel-inner">
            <?php print $content['section2_3cols3']; ?>
          </div>
        </div>
      </div>
    </div>
    <!-- section2 footer -->
    <div class="row">
      <div class="col-md-12 panel-panel">
        <div class="panel-panel-inner">
          <?php print $content['section2_footer']; ?>
        </div>
      </div>
    </div>
  </div> <!-- // end of section2 -->
	  
	   <!-- section3 -->
  <div class="container-full ar-section3 bg-color2">
    <!-- section2 header -->
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
  <div class="container-full ar-section3 bg-color4">
    <!-- section4 header -->
      <div class="row">
        <div class="container">
        <div class="col-md-12 panel-panel">
          <div class="panel-panel-inner">
            <?php print $content['section4_header']; ?>
          </div>
        </div>
      </div>
    </div>
    <!-- section4 2cols -->
    <div class="row">
      <div class="container">
        <div class="col-md-6 panel-panel">
          <div class="panel-panel-inner">
            <?php print $content['section4_2cols1']; ?>
          </div>
        </div>
        <div class="col-md-6 panel-panel">
          <div class="panel-panel-inner">
            <?php print $content['section4_2cols2']; ?>
          </div>
        </div>
      </div>
    </div>
    <!-- section4 3cols -->
    <div class="row">
      <div class="container">
        <div class="col-md-4 panel-panel">
          <div class="panel-panel-inner">
            <?php print $content['section4_3cols1']; ?>
          </div>
        </div>
        <div class="col-md-4 panel-panel">
          <div class="panel-panel-inner">
            <?php print $content['section4_3cols2']; ?>
          </div>
        </div>
        <div class="col-md-4 panel-panel">
          <div class="panel-panel-inner">
            <?php print $content['section4_3cols3']; ?>
          </div>
        </div>
      </div>
    </div>
    <!-- section4 footer -->
    <div class="row">
      <div class="col-md-12 panel-panel">
        <div class="panel-panel-inner">
          <?php print $content['section4_footer']; ?>
        </div>
      </div>
    </div>
  </div> <!-- // end of section4 -->


  <!-- section6 -->
  <div class="container-full ar-section6 bg-color2">
    <!-- section6 2cols -->
    <div class="row">
      <div class="container">
        <div class="col-md-6 panel-panel">
          <div class="panel-panel-inner">
            <?php print $content['section6_2cols1']; ?>
          </div>
        </div>
        <div class="col-md-6 panel-panel">
          <div class="panel-panel-inner">
            <?php print $content['section6_2cols2']; ?>
          </div>
        </div>
      </div>
    </div>
  </div> <!-- // end of section6 -->

</div>