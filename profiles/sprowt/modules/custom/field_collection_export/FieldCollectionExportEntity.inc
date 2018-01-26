<?php

class FieldCollectionExportEntity extends FieldCollectionItemEntity {

    static function __set_state($array)
    {
        $obj = new self;
        foreach ($array as $prop => $val) {
            $obj->{$prop} = $val;
        }

        return $obj;
    }

}