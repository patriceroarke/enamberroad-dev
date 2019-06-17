<div class="<?php print $classes; ?> "<?php print $attributes; ?>>
  <div class="wrapper">
    <div class="title">
      <?php if(isset($content['title'])) print render($content['title']); ?>
    </div>
    <div class="image">
      <?php
      $content['field_button'][0]['#element']['title'] = render($content['field_basic_image_image']);
      print render($content['field_button']);
      ?>
    </div>
    <div class="text">
      <?php print render($content['field_text']); ?>
    </div>
    <div class="button">
    </div>
  </div>
</div>