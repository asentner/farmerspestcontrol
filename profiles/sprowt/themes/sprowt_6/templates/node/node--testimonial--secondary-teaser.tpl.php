<div<?php print $attributes; ?>>

    <?php print render($content['field_icon_file']); ?>
  <div<?php print $content_attributes; ?> itemscope itemtype="http://schema.org/Review">
      <h2>Testimonials</h2>
      <?php print $itemreviewed_structured_data; ?>
    

    <div itemprop="reviewRating" itemscope itemtype="http://schema.org/Rating">
      <meta itemprop="worstRating" content="1">
      <meta itemprop="ratingValue" content="5" class="rating">
      <meta itemprop="bestRating" content="5">
    </div>

    <div itemprop="description" class="description">
      <?php print render($content['body']); ?>
    </div>

      <div class="reviewer">
          <div class="field--title" itemprop="author">
              <?php print $title; ?>
          </div>
          <?php print render($content['field_market']); ?>
      </div>

    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>



  </div>

</div>
