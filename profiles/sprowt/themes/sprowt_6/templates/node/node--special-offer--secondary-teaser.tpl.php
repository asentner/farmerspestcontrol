<article<?php print $attributes; ?>>

  <a href="<?php print $button_url; ?>" class="offer-link"></a>
  <div<?php print $content_attributes; ?>>

    <?php print render($content['field_offer_headline']); ?>
    <?php print render($content['field_offer_subheadline']); ?>

    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      hide($content['field_expiration_date']);
      print render($content);
    ?>

  </div>

  <?php print render($content['field_expiration_date']); ?>

  <div class="logo">
    <img src="/sites/all/themes/sprowt_6/images/coupons-logo@2x.png" alt="Placeholder Company Name">
  </div>

</article>
