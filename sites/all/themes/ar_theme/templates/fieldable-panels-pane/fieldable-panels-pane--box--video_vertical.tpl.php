<div class="container <?php print $classes; ?> "<?php print $attributes; ?>>
    <div class="video">
      <?php
      //print render($content['field_video_file']);

      $video_width = $content['field_video_width'][0]['#markup'];
      $video =  $content['field_video'][0]['#markup'];
      $video_js = str_replace('-','$',$video);
      ?>
      <script type='text/javascript' id='vidyard_embed_code_<?php echo $video; ?>' src='//play.vidyard.com/<?php echo $video; ?>.js? width=1280&height=721&v=3.1.1&type=lightbox'></script>
      <div class='outer_vidyard_wrapper'>
        <div class='vidyard_wrapper' onclick='fn_vidyard_<?php echo $video_js; ?>();'>
          <img alt="<?php echo $content['title']['#value'] ?>" width="<?php echo $video_width; ?>" src="//play.vidyard.com/<?php echo $video; ?>.jpg?" />
          <div class="vidyard_play_button"><a href="javascript:void(0);"></a></div>
        </div>
      </div>
    </div>
    <div class="text">
      <?php if(isset($content['title'])) print render($content['title']); ?>
      <?php print render($content['field_text']); ?>
    </div>
</div>