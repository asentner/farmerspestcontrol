<?php
/**
 * Available fields:
 *
 * $field_locality
 * $field_phone_number
 * $field_postal_code
 * $field_state
 * $field_street_address
 *
 */
hide($content['field_phone_number']); ?>
<div<?php print $attributes; ?> itemscope itemtype="http://schema.org/LocalBusiness">
  <h2 itemprop="name" class="node__title"><?php print $title; ?></h2>

  <span class="bullet">&bull;</span>

  <div<?php print $content_attributes; ?> itemprop="address" itemscope itemtype="http://schema.org/PostalAddress">
    <span class="field-street-address" itemprop="streetAddress"><?php
    $addresses = array();
    foreach($field_street_address as $a) {
      $addresses[] = "<span class='field-street-address-line'>". $a['value'] ."</span> <span class='bullet'>&bull;</span> ";
    }
    print implode(" ", $addresses); ?></span>
    <span class="field-locality" itemprop="addressLocality"><?php print $field_locality[0]['value']; ?></span>,
    <span class="field-state" itemprop="addressRegion"><?php print $field_state[0]['value']; ?></span>
    <span class="field-postal-code" itemprop="postalCode"><?php print $field_postal_code[0]['value']; ?></span>
  </div>

   <span class="bullet">&bull;</span>

  <?php if (isset($content['field_phone_number'])): ?>
    <div class="field-phone-number" itemprop="telephone">
      <a href="tel:<?php print $field_phone_number[0]['value']; ?>"><?php print $field_phone_number[0]['value']; ?></a>
    </div>
  <?php endif; ?>
  
</div>
