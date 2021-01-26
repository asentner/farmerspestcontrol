<article<?php print $attributes; ?>>
  <div class="location-wrap">
    <h2 class="location-title">
      <?php print(variable_get('site_name')); ?> - <?php print $title ?>
      <?php if(!empty($content['field_state'][0]['#markup'])): ?>
        <span class="state"> <?php print $content['field_state'][0]['#markup']; ?> </span>
      <?php endif; ?>
    </h2>
    <div class="location-content">
      <div class="location-info">
        <h3 class="address-heading">Address</h3>
        <?php
          print render($content['field_street_address']);
          print render($content['field_locality']);
          print render($content['field_state']);
          print render($content['field_postal_code']);
        ?>
        <?php if(!empty($content['field_phone_number']['#items'][0]['value'])): ?>
          <h3 class="phone-heading">Phone</h3>
        <?php endif; ?>
        <?php
          print render($content['field_phone_number']);
          print render($content['field_button']);
        ?>
      </div>
      <div class="location-map">
        <?php print render($content['field_map_code']); ?>
      </div>
    </div>
  </div>
  <?php if(!empty($content['field_social_reviews'])): ?>
    <div class="reviews-wrap">
      <h2 class="reviews-title">Read Our Reviews</h2>
      <div class="reviews-links">
        <?php print render($content['field_social_reviews']); ?>
      </div>
    </div>
  <?php endif; ?>
    <?php print render($content['json_ld']); ?>
</article>
