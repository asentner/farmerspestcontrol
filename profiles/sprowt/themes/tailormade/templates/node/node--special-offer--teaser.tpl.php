<?php 
hide($content['field_expiration_date']); 
hide($content['field_image']); 
hide($content['field_button']);
hide($content['field_original_price']);
hide($content['field_offer_price']);
// extract numbers
$original = (!empty($content['field_original_price']['#items'][0]['value'])) ? $content['field_original_price']['#items'][0]['value'] : 0;
$offer = (!empty($content['field_offer_price']['#items'][0]['value'])) ? $content['field_offer_price']['#items'][0]['value'] : 0;
$savings = $original - $offer;
?>
<article<?php print $attributes; ?>>
  <div class="node-content-wrap">
    <header>
      <?php print render($title_prefix); ?>
      <?php if (!$page): ?>
        <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
    </header>
    <div<?php print $content_attributes; ?>>
      <?php if(menu_get_object()->nid != 145): ?>
        <img src="<?php print theme_get_setting('logo'); ?>" alt="<?php print variable_get('site_name', 'Tailor Made Lawns'); ?>">
      <?php endif; ?>
      <?php
        // We hide the comments and links now so that we can render them later.
        hide($content['comments']);
        hide($content['links']);
        print render($content);
      ?>
      <?php // special offer pricing, difference, etc. ?>

      <div class="offer-pricing">
        <?php if(!empty($field_original_price)): ?>
          <div class="offer-pricing-original">
            <del>$<?php print $original; ?></del>
          </div>
        <?php endif; ?>
        <?php if(!empty($field_offer_price)): ?>
          <div class="offer-pricing-offer">
            $<?php print $offer; ?>
          </div>
        <?php endif; ?>
        <?php if(!empty($field_original_price) && !empty($field_offer_price)): ?>
          <div class="offer-pricing-savings">
            $<?php print $savings; ?> off
          </div>
        <?php endif; ?>
      </div>
      <?php // only show exp. date if it's filled out; otherwise, show end of month ?>
      <?php if(!empty($field_expiration_date)):
        if(!empty($field_expiration_date[LANGUAGE_NONE])){
          $field_expiration_date = $field_expiration_date[LANGUAGE_NONE];
        }
        $edate = new DateTime($field_expiration_date[0]['value'], new DateTimeZone($field_expiration_date[0]['timezone_db']));
        $edate->setTimezone(new DateTimeZone($field_expiration_date[0]['timezone']));
      
      ?>
        <div class="field--name-field-expiration-date">
          Expires: <?php print $edate->format("F d, Y"); ?>
        </div>
      <?php else: ?>
        <div class="field--name-field-expiration-date">
          Expires: <?php print date("F t, Y"); ?>
        </div>
      <?php endif; ?>
      <?php print render($content['field_button']); ?>
    </div>
  </div>
</article>