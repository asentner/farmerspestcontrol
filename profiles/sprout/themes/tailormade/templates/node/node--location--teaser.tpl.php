<div<?php print $attributes; ?>>

  <div<?php print $content_attributes; ?>>
    <div class="address">
      <?php print render($content['field_street_address']); ?>
      &bull;
      <?php print render($content['field_locality']); ?>
      <?php print render($content['field_state']); ?>
      <?php print render($content['field_postal_code']); ?>
    </div>
    <?php print render($content['field_phone_number']); ?>
  </div>

</div>
