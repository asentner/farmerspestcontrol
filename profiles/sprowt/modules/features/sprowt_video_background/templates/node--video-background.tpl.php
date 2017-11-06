
<article<?php print $attributes; ?>>
  <div class="video-container">

    <div class="filter"></div> <!-- use this if adding an overlay or filter for quality masking; z-index 2 -->

    <video autoplay loop class="fillWidth video-js"> <!-- hide on tablet/mobile; z-index 1 -->
      <?php if(!empty($content['field_webm_file'][0]['#markup'])): ?>
        <source data-src="<?php echo $content['field_webm_file'][0]['#markup']; ?>" type="video/webm" />
      <?php endif; ?>
      <?php if(!empty($content['field_ogg_file'][0]['#markup'])): ?>
        <source data-src="<?php echo $content['field_ogg_file'][0]['#markup']; ?>"  type="video/ogg" />
      <?php endif; ?>
      <?php if(!empty($content['field_mp4_file'][0]['#markup'])): ?>
        <source data-src="<?php echo $content['field_mp4_file'][0]['#markup']; ?>" type="video/mp4" />
      <?php endif; ?>

        Your browser does not support the video tag. Please upgrade your browser.
    </video>

    <div class="image-bg" style="background-image: url('<?php echo trim($image_url_field_image); ?>');"></div> <!-- for static image background if video doesn't work, show on mobile/tablet; z-index 0 -->

    <div class="content-wrap">
      <div class="content"> <!-- top layer text content; z-index 3 -->
        <h1<?php print $title_attributes; ?>><?php print $title; ?></h1>
        <?php print render($content['field_subtitle']); ?>
        <?php print render($content['field_button']); ?>
      </div>
    </div>

    <?php
      hide($content['comments']);
      hide($content['links']);
      hide($content['field_mp4_file']);
      hide($content['field_webm_file']);
      hide($content['field_ogg_file']);
    ?>
  </div>
</article>
