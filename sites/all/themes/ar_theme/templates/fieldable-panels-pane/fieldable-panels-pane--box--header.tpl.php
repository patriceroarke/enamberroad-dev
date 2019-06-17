<div class="<?php print $classes; ?> "<?php print $attributes; ?>>
  <div class="wrapper">
    <div class="image">
      <?php print render($content['field_basic_image_image']); ?>
    </div>
    <div class="container text-wrapper">
      <div class="title">
        <?php if(isset($content['title'])) print render($content['title']); ?>
      </div>
    </div>
  </div>
</div>

