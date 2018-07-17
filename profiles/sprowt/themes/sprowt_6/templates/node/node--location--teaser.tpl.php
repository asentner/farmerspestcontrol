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

  <h2><?php print $title; ?></h2>

  <div<?php print $content_attributes; ?>>
    <span class="field-street-address"><?php
    $addresses = array();
    foreach($field_street_address as $a) {
      $addresses[] = $a['value'];
    }
    print implode(" ", $addresses); ?></span>,
    <span class="field-locality"><?php print $field_locality[0]['value']; ?></span>,
    <span class="field-state"><?php print $field_state[0]['value']; ?></span>
    <span class="field-postal-code"><?php print $field_postal_code[0]['value']; ?></span>
  </div>

  <?php if (isset($field_phone_number[0]['value'])): ?>
    <div class="field-phone-number ctm-no-swap">
      <span>Tel:</span><a href="tel:<?php print $field_phone_number[0]['value']; ?>"><?php print $field_phone_number[0]['value']; ?></a>
    </div>
  <?php endif; ?>
<?php print render($content['json_ld']); ?>
</div>
