<?php
  hide($content['field_market']);
  if (isset($content['field_market'][0]['#markup'])) {
    $location = $content['field_market'][0]['#markup'];
  }
?>
<div<?php print $attributes; ?>>

  <div<?php print $content_attributes; ?> itemscope itemtype="http://schema.org/Review">

    <span itemprop="itemReviewed" itemscope itemtype="http://schema.org/LocalBusiness">
      <meta itemprop="name" content="<?php print variable_get('site_name'); ?>">
    </span>

    <div itemprop="reviewRating" itemscope itemtype="http://schema.org/Rating">
      <meta itemprop="worstRating" content="1">
      <span itemprop="ratingValue" content="5" class="rating">
        <i class="fa fa-star"></i>
        <i class="fa fa-star"></i>
        <i class="fa fa-star"></i>
        <i class="fa fa-star"></i>
        <i class="fa fa-star"></i>
      </span>
      <meta itemprop="bestRating" content="5">
    </div>

    <div itemprop="description">
      <?php print render($content['body']); ?>
    </div>

    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>

    <div class="testimonial-meta">
      <?php if (isset($location)): ?>
        <span class="field--title" itemprop="author"><?php print $title; ?></span>,
        <span class="field--location" itemprop="contentLocation"><?php print $location; ?></span>
      <?php else: ?>
        <span class="field--title" itemprop="author"><?php print $title; ?></span>
      <?php endif; ?>
    </div>
    

  </div>
  
</div>
