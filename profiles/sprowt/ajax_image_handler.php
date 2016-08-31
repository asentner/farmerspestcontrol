<?php

$user_id = $_POST['user_id'];

if(empty($user_id)){
    echo "ERROR: no user id!";
    die;
}

$basedir = getcwd() . "/images/$user_id";

if(is_dir($basedir)){
    $files = glob($basedir . "/*");
    foreach($files as $file){
        unlink($file);
    }
    rmdir($basedir);
}

if($_POST['action'] == 'removeImage'){
    echo "success";
}
else {
    mkdir($basedir);
    
    move_uploaded_file($_FILES["image"]["tmp_name"], $basedir . "/" . $_FILES["image"]["name"]);
    
    echo "/profiles/sprowt/images/$user_id/" . $_FILES["image"]["name"];
}