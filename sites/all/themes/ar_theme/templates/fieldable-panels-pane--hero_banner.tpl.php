
  <?php $background_image = (file_create_url($content['field_hero_banner_bg_image'][0]["file"]["#item"]["uri"])) ?>
<div class="rke-homepage-hero" style="background-image: linear-gradient(rgba(0, 0, 0, 0.4), rgba(0, 0, 0, 0.4)),  url('<?php echo $background_image; ?>')";>

<div class="overlay">
<div class="container">
<?php print render($content['field_hero_banner_body']); ?>
<?php print render($content['field_hero_banner_btn']); ?>
</div>
</div>
</div>


