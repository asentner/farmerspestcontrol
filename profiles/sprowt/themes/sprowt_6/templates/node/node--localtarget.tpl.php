<?php
  $service_tid = $node->field_service['und'][0]['tid'];
  $service_term = taxonomy_term_load($service_tid);
  $service_name = $service_term->name;

  $market_tid = $node->field_market['und'][0]['tid'];
  $market_term = taxonomy_term_load($market_tid);
  $market_name = $market_term->name;
 ?>

<div<?php print $attributes; ?> itemscope itemtype="http://schema.org/Service">

    <header>
      <?php if (isset($content['field_display_title'])): ?>
        <?php print render($content['field_display_title']); ?>
      <?php else: ?>
        <h2><?php print $title; ?></h2>
      <?php endif; ?>

        <?php print render($content['field_intro']); ?>

    </header>
    <meta itemprop="serviceType" content="<?php print $service_name; ?>">
    <span itemprop="provider" itemscope itemtype="http://schema.org/LocalBusiness">
      <meta itemprop="name" content="<?php print variable_get('site_name'); ?>">
    </span>
    <span itemprop="areaServed" itemscope itemtype="http://schema.org/City">
      <meta itemprop="name" content="<?php print $market_name; ?>">
    </span>

  <div<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      hide($content['field_seo_title']);
      hide($content['field_image']);
      print render($content);
    ?>
  </div>
</div>
