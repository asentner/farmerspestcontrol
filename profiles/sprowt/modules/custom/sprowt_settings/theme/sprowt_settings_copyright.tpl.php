<?php
    switch(variable_get('sprowt_settings_company_type')) {
        case 'pest_control':
            $intro = 'Pest Control Marketing +';
            break;
        case 'lawn_care':
            $intro = 'Lawn Care Websites +';
            break;
        case 'home_services':
            $intro = 'Home Services +';
            break;
        default:
            $intro = '<a href="http://www.getsprowt.com" target="_blank">Sprowt<span>&trade;</span></a> website design and Drupal development by';
    }
?>
<p>&copy; [current-year] [company-name]. All rights reserved.
	<?php print $intro; ?> <a href="http://www.coalmarch.com" target="_blank">Coalmarch Productions, Raleigh NC</a></p>
