<div class="<?php print $classes; ?> "<?php print $attributes; ?>>

    <?php
    if(isset($content['title']) & isset($content['title']['#value']) && $content['title']['#value']!='')
    {
      unset($content['title']['#access']);
      print '<div class="title">'.render($content['title']).'</div>';
    }
    ?>

  <div class="text">
      <?php print render($content['field_text']); ?>
  </div>
</div>

