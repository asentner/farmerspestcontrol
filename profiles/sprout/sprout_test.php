<?php


include_once('sproutbuilder.php');

include_once('modules/contrib/devel/krumo/class.krumo.php');

$SP = new SproutBuilder();

$object = new stdClass();
$object->variable = 'test variable';

//$SP->getData();

//krumo($SP->data);

//$SP->addUsers();

//$SP->addBranding();

$SP->addMarketsServices();

//$SP->addNodes();

//$SP->addLocations();

/*
print "; Contrib Modules<br>";
foreach(glob('profiles/sprout/modules/contrib/*') as $module){
    $module = str_replace('profiles/sprout/modules/contrib/', '', $module);
    print "dependencies[] = $module<br>";
}

print "<br><br>; Custom Modules<br>";


foreach(glob('profiles/sprout/modules/custom/*') as $module){
    $module = str_replace('profiles/sprout/modules/custom/', '', $module);
    print "dependencies[] = $module<br>";
}
*/