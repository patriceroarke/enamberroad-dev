<div class="<?php print $classes; ?> "<?php print $attributes; ?>>
  <div class="wrapper">
    <div class="image">
      <?php print render($content['field_basic_image_image']); ?>
    </div>
    <div class="title">
      <?php if(isset($content['title'])) print render($content['title']); ?>
    </div>
    <div class="text">
      <?php print render($content['field_text']); ?>
    </div>
    <div class="button">
      <?php print render($content['field_button']); ?>
    </div>
  </div>
</div>

