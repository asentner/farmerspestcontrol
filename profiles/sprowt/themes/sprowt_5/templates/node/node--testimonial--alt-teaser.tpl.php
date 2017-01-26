<div<?php print $attributes; ?>>

  <div<?php print $content_attributes; ?> itemscope itemtype="http://schema.org/Review">

    <span itemprop="itemReviewed" itemscope itemtype="http://schema.org/LocalBusiness">
      <meta itemprop="name" content="<?php print variable_get('site_name'); ?>">
    </span>

    <div itemprop="reviewRating" itemscope itemtype="http://schema.org/Rating">
      <meta itemprop="worstRating" content="1">
      <span itemprop="ratingValue" content="5" class="rating"></span>
      <meta itemprop="bestRating" content="5">
    </div>

    <div itemprop="description">
      <?php print render($content['body']); ?>
    </div>

    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      // print render($content);
    ?>

    <div class="field--title" itemprop="author">
      <?php print $title; ?>
      <?php if(isset($content['field_market'])): ?>
        <span class="field--market">, <?php print $content['field_market'][0]['#title']; ?></span>
      <?php endif; ?>
    </div>

  </div>

</div>
