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
?>
<div<?php print $attributes; ?>>
  <div<?php print $content_attributes; ?>>
    <h4 itemprop="name"><?php print $title; ?></h4>
    <span class="field-street-address"><?php
    $addresses = array();
    foreach($field_street_address as $a) {
      $addresses[] = $a['value'];
    }
    print implode(" ", $addresses); ?></span>
    <br>
    <span class="field-locality"><?php print $field_locality[0]['value']; ?></span>,
    <span class="field-state"><?php print $field_state[0]['value']; ?></span>
    <span class="field-postal-code"><?php print $field_postal_code[0]['value']; ?></span>
  </div>

  <div class="field-phone-number ctm-no-swap">
    <a href="tel:<?php print $field_phone_number[0]['value']; ?>" ><?php print $field_phone_number[0]['value']; ?></a>
  </div>
    <?php print render($content['json_ld']); ?>
</div>
