<?php
hide($content['field_display_title']);
hide($content['field_intro']);
?>
<div<?php print $attributes; ?> itemscope itemtype="http://schema.org/Service">
  <header>
    <?php if($intro_title): ?>
      <?php print render($content['field_display_title']); ?>
      <?php print render($content['field_intro']); ?>
    <?php endif; ?>

    <?php if(!empty($content['field_seo_title'][LANGUAGE_NONE][0]) || !empty($content['field_seo_title'][0])): ?>
      <?php print render($content['field_seo_title']); ?>
      <meta itemprop="serviceType" content="<?php print $title; ?>">
    <?php else: ?>
      <h1<?php print $title_attributes; ?> itemprop="serviceType"><?php print $title; ?></h1>
    <?php endif; ?>
  </header>
  <span itemprop="provider" itemscope itemtype="http://schema.org/LocalBusiness">
    <meta itemprop="name" content="<?php print variable_get('site_name'); ?>">
  </span>
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
