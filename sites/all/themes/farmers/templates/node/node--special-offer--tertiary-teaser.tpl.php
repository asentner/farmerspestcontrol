<article<?php print $attributes; ?>>
  <?php hide($content['title']); ?>

  <a href="<?php print $button_url; ?>" class="offer-link"></a>

  <?php print render($content['field_featured_icon']); ?>

  <div<?php print $content_attributes; ?>>

    <?php print render($content['field_offer_headline']); ?>
    <?php print render($content['field_offer_subheadline']); ?>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      hide($content['field_expiration_date']);
      hide($content['field_featured_offer']);
      print render($content);
    ?>

    <div class="logo">
      <?php if (!empty($featured)): ?>
        <img src="/<?php print  path_to_theme(); ?>/images/logo-special-offer-reverse@2x.png" alt="<?php print variable_get('site_name'); ?>">
      <?php else: ?>
        <img src="<?php print theme_get_setting('logo'); ?>" alt="<?php print variable_get('site_name'); ?>">
      <?php endif; ?>
    </div>


    <?php print render($content['field_expiration_date']); ?>

  </div>

</article>
