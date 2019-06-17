<div class="<?php print $classes; ?> "<?php print $attributes; ?>>
  <div class="title">
    <?php
    if(isset($content['title']))
    {
      unset($content['title']['#access']);
      print render($content['title']);
    }
    ?>
  </div>
  <div class="text">
      <?php print render($content['field_basic_text_text']); ?>
  </div>
</div>

