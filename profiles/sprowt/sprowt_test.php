<?php


include_once('sprowtbuilder.php');

include_once('modules/contrib/devel/krumo/class.krumo.php');

//$SP = new SprowtBuilder();
//
//$object = new stdClass();
//$object->variable = 'test variable';

//$SP->getData();

//krumo($SP->data);

//$SP->addUsers();

//$SP->addBranding();

//$SP->addMarketsServices();

//$SP->addNodes();

//$SP->addLocations();

/*
print "; Contrib Modules<br>";
foreach(glob('profiles/sprowt/modules/contrib/*') as $module){
    $module = str_replace('profiles/sprowt/modules/contrib/', '', $module);
    print "dependencies[] = $module<br>";
}

print "<br><br>; Custom Modules<br>";


foreach(glob('profiles/sprowt/modules/custom/*') as $module){
    $module = str_replace('profiles/sprowt/modules/custom/', '', $module);
    print "dependencies[] = $module<br>";
}
*/
function importPrivacyPolicy(){
  $fName = 'profiles/sprowt/privacypolicy.txt';

  $handle = fopen($fName,'r');
  $data = fread($handle,filesize($fName));

  node_export_import($data);
}