<div<?php print $attributes; ?> itemscope itemtype="http://schema.org/PostalAddress">

  <div<?php print $content_attributes; ?>>
  	<div class="node--address-line">
  		<?php print render($content['field_street_address']); ?>
  	</div>
  	<div class="node--address-line">
  		<?php print render($content['field_locality']); ?>
  		<?php print render($content['field_state']); ?>
  		<?php print render($content['field_postal_code']); ?>
  	</div>
  	<div class="node--address-line">
  		<?php print render($content['field_phone_number']); ?>
  	</div>
  </div>

</div>
