<?php
  $service_tid = $node->field_service['und'][0]['tid'];
  $service_term = taxonomy_term_load($service_tid);
  $service_name = $service_term->name;

  $market_tid = $node->field_market['und'][0]['tid'];
  $market_term = taxonomy_term_load($market_tid);
  $market_name = $market_term->name;
 ?>

<div<?php print $attributes; ?> itemscope itemtype="http://schema.org/Service">
  <?php if ($page): ?>
    <header>
      <?php if (isset($content['field_display_title'])): ?>
        <?php print render($content['field_display_title']); ?>
        <?php print render($content['field_intro']); ?>
        <?php print render($content['field_image']); ?>
        <?php if (isset($content['field_seo_title'])): ?>
          <?php print render($content['field_seo_title']); ?>
        <?php else: ?>
          <h1 class="field--name-field-seo-title"><?php print $title; ?></h1>
        <?php endif; ?>
      <?php else: ?>
        <h1><?php print $title; ?></h1>
      <?php endif; ?>
    </header>
    <meta itemprop="serviceType" content="<?php print $service_name; ?>">
    <span itemprop="provider" itemscope itemtype="http://schema.org/LocalBusiness">
      <meta itemprop="name" content="<?php print variable_get('site_name'); ?>">
    </span>
    <span itemprop="areaServed" itemscope itemtype="http://schema.org/City">
      <meta itemprop="name" content="<?php print $market_name; ?>">
    </span>
  <?php endif; ?>

  <?php if ($display_submitted): ?>
    <footer class="node__submitted">
      <?php print $user_picture; ?>
      <p class="submitted"><?php print $submitted; ?></p>
    </footer>
  <?php endif; ?>

  <div<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>
  </div>

  <?php print render($content['links']); ?>
  <?php print render($content['comments']); ?>
</div>
