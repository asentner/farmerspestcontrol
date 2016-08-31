<?php 
hide($content['field_expiration_date']); 
hide($content['field_button']);

// extract numbers
$print_pricing = FALSE;
if (isset($content['field_original_price']['#items'][0]['value']) && isset($content['field_offer_price']['#items'][0]['value'])) {
  hide($content['field_original_price']);
  hide($content['field_offer_price']);
  $print_pricing = TRUE;
  $original = $content['field_original_price']['#items'][0]['value'];
  $offer = $content['field_offer_price']['#items'][0]['value'];
  $savings = $original - $offer;
}

?>
<article<?php print $attributes; ?>>
  <div class="node-content-wrap">
    <header>
      <?php print render($title_prefix); ?>
      <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
      <?php print render($title_suffix); ?>
    </header>
    <div<?php print $content_attributes; ?>>
      <div class="node-content-inner-wrap">
  
        <?php
          // We hide the comments and links now so that we can render them later.
          hide($content['comments']);
          hide($content['links']);
          print render($content);
        ?>
        <?php // special offer pricing, difference, etc. ?>

        <?php if ($print_pricing):  ?>
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
        <?php endif; ?>

        <?php print render($content['field_button']); ?>
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

      </div>
    </div>
  </div>
</article>
