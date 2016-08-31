<div itemscope itemtype="http://schema.org/LocalBusiness">
  <h2><span itemprop="name"><?php print variable_get('leadbuilder_settings_company_name', ''); ?></span></h2>
  <div itemprop="address" itemscope itemtype="http://schema.org/PostalAddress">
    <span itemprop="streetAddress">
    <?php print variable_get('leadbuilder_settings_address_street', ''); ?>
    <?php if ($addr2 = variable_get('leadbuilder_settings_address_additional', FALSE)) : ?>
      <br /><?php print $addr2; ?>
    <?php endif; ?>
    </span><br />
    <span itemprop="addressLocality"><?php print variable_get('leadbuilder_settings_address_locality', ''); ?></span>,
    <span itemprop="addressRegion"><?php print variable_get('leadbuilder_settings_address_province', ''); ?></span>
    <span itemprop="postalCode"><?php print variable_get('leadbuilder_settings_address_postal_code', ''); ?></span>
  </div>
  <span itemprop="telephone"><?php print leadbuilder_settings_get_phone_number(); ?></span>
</div>
