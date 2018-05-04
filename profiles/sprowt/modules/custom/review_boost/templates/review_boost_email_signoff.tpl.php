<?php
print $company_name . "<br>";
$address = false;
    if(!empty($street)
    || !empty($street2)
    || (!empty($locality)
        && !empty($province)
        && !empty($postal_code))
    ) {
        $address = true;
    }
if($address) {
    print $street . "<br>";
    if (!empty($street2)) {
        print $street2 . "<br>";
    }
    print $locality . ', ' . $province . ' ' . $postal_code;
    if (!empty($phone_number)):
        print "<br>";
    endif;
}
    if(!empty($phone_number)) {
        print $phone_number;
    }
?>