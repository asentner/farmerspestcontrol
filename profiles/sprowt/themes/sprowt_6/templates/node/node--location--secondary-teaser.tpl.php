<?php

?>

<article <?php print $attributes; ?>>
    <div class="location-info">
      <h3><?php print variable_get('sprowt_settings_company_name'); ?></h3>
      <h2 <?php print $title_attributes; ?>><?php print $title; ?></h2>

      <div class="location-details">
        <div class="address-block">
          <?php print render($content['field_address_label']); ?>
          <?php print render($content['field_street_address']); ?>
          <div class="locality-block">
            <?php print render($content['field_locality']) ?>
            <?php print render($content['field_state']); ?>
            <?php print render($content['field_postal_code']); ?>
          </div>
        </div>

        <div class="hours-block">
          <?php print render($content['field_hours_label']); ?>
          <?php print render($content['field_hours']); ?>
        </div>
      </div>

      <?php print render($content['field_call_out']); ?>

    </div>


  <?php print render($content['field_map_code']) ?>

  <?php
    hide($content['field_phone_label']);
    hide($content['field_phone_number']);
   ?>
    <?php print render($content['json_ld']); ?>
</article>
