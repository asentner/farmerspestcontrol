<?php

class BlockBuilder {
    protected $block_custom;
    protected $block_node_type;
    protected $block_role;
    protected $block_custom_map;
    protected $multiblock;
    protected $multiblock_map;
    protected $block;
    protected $theme;
    protected $uuid_map;
    protected $menu_block;

    function __construct()
    {
        $this->block_custom = array();
        $this->block_node_type = array();
        $this->block_role = array();
        $this->block_custom_map = array();
        $this->multiblock = array();
        $this->multiblock_map = array();
        $this->block = array();
        $this->uuid_map = array();
        $this->menu_block = array();
    }


    function row_exists($table, $row, $id_field = null) {
        $row_names = array_keys($row);
        if(empty($id_field)) {
            $id_field = $row_names[0];
        }

        $where = array();
        $values = array();
        foreach($row_names as $column) {
            $where[] = "$column = :$column";
            $values[":$column"] = $row[$column];
        }

        $sql = "
            SELECT $id_field
            FROM $table
            WHERE ";
        $sql .= implode(" AND ", $where);

        return db_query($sql, $values)->fetchField();
    }

    function writeBlockCustom(){
        foreach($this->block_custom as $current_row) {
            $test = $current_row;
            unset($test['bid']);
            unset($test['body']);
            unset($test['format']);
            if(!$bid = $this->row_exists('block_custom', $current_row, 'bid')) {
                $i = 1;
                while($this->row_exists('block_custom', $test)) {
                    $info = $current_row['info'];
                    if(!empty($this->theme)) {
                        $info .= " ({$this->theme})";
                    }

                    if($i > 1){
                        $current_row['info'] = $info . "($i)";
                    }
                    else {
                        $current_row['info'] = $info;
                    }

                    $test = $current_row;
                    unset($test['bid']);
                    unset($test['body']);
                    unset($test['format']);
                    ++$i;
                }

                $row = $current_row;
                unset($row['bid']);

                try {
                    $bid = db_insert('block_custom')->fields($row)->execute();
                    $this->block_custom_map[$current_row['bid']] = $bid;
                } catch (Exception $e) {
                    watchdog_exception('Sprowt BlockBuilder', $e);
                }
            }
            else {
                $this->block_custom_map[$current_row['bid']] = $bid;
            }
        }
    }

    function writeBlockNodeType() {
        foreach($this->block_node_type as $type) {
            if(!$this->row_exists('block_node_type', $type, 'delta')) {
                try {
                    db_insert('block_node_type')->fields($type)->execute();
                }
                catch (Exception $e) {
                    watchdog_exception('Sprowt BlockBuilder',$e);
                }
            }
        }
    }

    function writeBlockRole() {
        foreach($this->block_role as $role) {

            if(!$this->row_exists('block_role', $role, 'delta')) {
                try {
                    db_insert('block_role')->fields($role)->execute();
                }
                catch (Exception $e) {
                    watchdog_exception('Sprowt BlockBuilder',$e);
                }
            }
        }
    }

    function writeMultiblock() {
        foreach($this->multiblock as $current_row) {
            if(!$this->row_exists('multiblock', $current_row)) {
                $row = $current_row;
                unset($row['delta']);

                try {
                    $delta = db_insert('multiblock')->fields($row)->execute();
                    $this->multiblock_map[$current_row['delta']] = $delta;
                } catch (Exception $e) {
                    watchdog_exception('Sprowt BlockBuilder', $e);
                }
            }
            else {
                $this->multiblock_map[$current_row['delta']] = $current_row['delta'];
            }
        }
    }

    function writeBlock() {
        $nid_map = db_query("
            SELECT uuid, nid
            FROM node
        ")->fetchAllKeyed();
        $trans = array();
        foreach($this->block as $current_row) {
            $row = $current_row;
            unset($row['bid']);
            switch ($row['module']) {
                case 'block':
                    $row['delta'] = $this->block_custom_map[$current_row['delta']];
                    $row['css_class'] .= ' sprowt-block-imported';
                    break;
                case 'multiblock':
                    $row['delta'] = $this->multiblock_map[$current_row['delta']];
                    $row['css_class'] .= ' sprowt-block-imported';
                    break;
                case 'sprowt_block_cta':
                    $nid = str_replace('sprowt_block_cta_', '', $row['delta']);
                    $uuid = empty($this->uuid_map[$nid]) ? 0 : $this->uuid_map[$nid];
                    if (!empty($nid_map[$uuid])) {
                        $row['css_class'] .= ' sprowt-block-imported block--sprowt-block-cta-sprowt-block-cta-' . $nid;
                        $row['delta'] = 'sprowt_block_cta_' . $nid_map[$uuid];

                    } else {
                        $row['delta'] = '';
                    }
                    break;
            }

            $test = array(
                'module' => $row['module'],
                'delta' => $row['delta'],
                'theme' => $row['theme']
            );

            $exists = $this->row_exists('block', $test, 'bid');

            if(!$exists) {
                if(!empty($row['delta'])) {
                    $trans[] = db_insert('block')->fields($row);
                }
                else {
                    watchdog('Sprowt BlockBuilder', 'Block not inserted. Missing delta map for block: <pre>%block</pre>', array(
                        '%block' => print_r($current_row, true)
                    ));
                }
            }
            else {
                $trans[] = db_update('block')->fields($row)->condition('bid', $exists);
            }
        }

        if(!empty($trans)) {
            $t = db_transaction();

            foreach($trans as $tran) {
                try {
                    $tran->execute();
                }
                catch(Exception $e) {
                    $t->rollback();
                    watchdog_exception('Sprowt BlockBuilder', $e);
                }
            }
        }
    }

    function setNids() {
        $uuid_map = $this->uuid_map;

        $nid_map = db_query("
            SELECT uuid, nid
            FROM node
        ")->fetchAllKeyed();

        $placements = db_query("
            SELECT bid, pages
            FROM block
            WHERE pages LIKE '%node/%'
        ")->fetchAllKeyed();

        $trans = array();
        foreach($placements as $bid => $pages) {
            $pages = explode("\n", $pages);
            $updated = false;
            foreach($pages as $key=>$page) {
                if(preg_match('/node\/([\d]+)/', $page, $m)) {
                    $old_nid = $m[1];
                    $uuid = (!empty($uuid_map[$old_nid])) ? $uuid_map[$old_nid] : null;
                    if(!empty($uuid)) {
                        $new_nid = (!empty($nid_map[$uuid])) ? $nid_map[$uuid] : null;
                    }

                    if(!empty($new_nid)) {
                        $pages[$key] = "node/$new_nid";
                        if(!$updated) {
                            $updated = true;
                        }
                    }
                }
            }
            if($updated) {
                $trans[] = db_update('block')
                        ->fields(array('pages' => implode("\n", $pages)))
                        ->condition('bid', $bid);
            }
        }

        if(!empty($trans)) {
            $t = db_transaction();

            foreach($trans as $tran) {
                try {
                    $tran->execute();
                }
                catch(Exception $e) {
                    $t->rollback();
                    watchdog_exception('Sprowt BlockBuilder', $e);
                }
            }
        }
    }

    function handleWebformBlocks(){
        $nid_map = db_query("
            SELECT uuid, nid
            FROM node
        ")->fetchAllKeyed();

        foreach($this->block as $k => $row) {
            if($row['module'] == 'webform') {
                $delta_parts = explode('-', $row['delta']);
                $nid = array_pop($delta_parts);
                $uuid = $this->uuid_map[$nid];
                $delta_parts[] = $nid_map[$uuid];
                $row['delta'] = implode('-', $delta_parts);
                $this->block[$k] = $row;
            }
        }

        foreach($this->multiblock as $k => $row) {
            if($row['module'] == 'webform') {
                $delta_parts = explode('-', $row['orig_delta']);
                $nid = array_pop($delta_parts);
                $uuid = $this->uuid_map[$nid];
                $delta_parts[] = $nid_map[$uuid];
                $row['orig_delta'] = implode('-', $delta_parts);
                $this->multiblock[$k] = $row;
            }
        }
    }

    function writeMenublock(){
        $nid_map = db_query("
            SELECT uuid, nid
            FROM node
        ")->fetchAllKeyed();
        foreach($this->menu_block as $k => $v) {
            if(strpos($k,'_parent') !== false) {
                $parts = explode(':',$v['orig']);
                $menu = $parts[0];
                $mlid = $parts[1];
                if($mlid == 0 || empty($nid_map[$v['uuid']])) {
                    $v = $v['orig'];
                }
                else {
                    $nid = $nid_map[$v['uuid']];
                    $mlid = db_query("
                        SELECT mlid
                        FROM menu_links
                        WHERE link_path = 'node/$nid'
                        AND menu_name = '$menu'
                    ")->fetchField();
                    if(!empty($mlid)) {
                        $v = "$menu:$mlid";
                    }
                    else {
                        $v = $v['orig'];
                    }
                }
            }

            variable_set($k,$v);
        }
    }

    function setFromDb($theme){

        $array = array();

        $array['block_custom'] = db_query("SELECT * FROM block_custom")->fetchAll(PDO::FETCH_ASSOC);
        $array['block_node_type'] = db_query("SELECT * FROM block_node_type")->fetchAll(PDO::FETCH_ASSOC);
        $array['block_role'] = db_query("SELECT * FROM block_role")->fetchAll(PDO::FETCH_ASSOC);
        if(db_table_exists('multiblock')) {
            $array['multiblock'] = db_query("SELECT * FROM multiblock")->fetchAll(PDO::FETCH_ASSOC);
        }


        $array['block'] = db_query("
            SELECT *
            FROM block
            WHERE theme = :theme
        ", array(':theme' => $theme))
            ->fetchAll(PDO::FETCH_ASSOC);

        $array['uuid_map'] = db_query("
            SELECT nid, uuid
            FROM node
        ")->fetchAllKeyed();

        $array['menu_block'] = db_query("
            SELECT name, value
            FROM variable
            WHERE name LIKE 'menu_block%'
        ")->fetchAllKeyed();

        foreach($array['menu_block'] as $k=>$v) {
            $v = unserialize($v);
            if(strpos($k,'_parent') !== false) {
                $parts = explode(':',$v);
                $mlid = $parts[1];
                if($mlid == 0) {
                    $v = array(
                        'orig' => $v,
                        'uuid' => $mlid
                    );
                }
                else {
                    $nid = db_query("
                        SELECT link_path
                        FROM menu_links
                        WHERE mlid = $mlid
                    ")->fetchField();
                    $nid = str_replace('node/','',$nid);
                    $v = array(
                        'orig' => $v,
                        'uuid' => (!empty($array['uuid_map'][$nid])) ? $array['uuid_map'][$nid] : 0,
                    );
                }
            }

            $array['menu_block'][$k] = $v;
        }



        $this->setFromArray($array);
    }

    function setFromArray($array) {
        foreach($array as $prop => $value) {
            if(!empty($value)) {
                $this->$prop = $value;
            }
        }
    }

    function setFromJson($json) {
        $this->setFromArray(json_decode($json, true));
    }

    function setTheme($theme) {
        $this->theme = $theme;
        foreach($this->block as $i => $row) {
            $this->block[$i]['theme'] = $theme;
        }
    }

    function import($array, $theme = null) {
        $this->setFromArray($array);
        if(!empty($theme)) {
            $this->setTheme($theme);
        }

        $this->handleWebformBlocks();
        $this->writeBlockCustom();
        $this->writeBlockNodeType();
        $this->writeBlockRole();
        $this->writeMultiblock();
        $this->writeBlock();
        $this->setNids();
        $this->writeMenublock();
    }

    function importJson($json, $theme = null) {
        $this->import(json_decode($json, true), $theme);
    }

    function export($theme) {
        $this->setFromDb($theme);

        $array = array(
            'block' => $this->block,
            'block_custom' => $this->block_custom,
            'block_node_type' => $this->block_node_type,
            'block_role' => $this->block_role,
            'multiblock' => $this->multiblock,
            'uuid_map' => $this->uuid_map,
            'menu_block' => $this->menu_block
        );

        return $array;
    }

    function exportJson($theme) {
        return json_encode($this->export($theme));
    }

    function exportToFile($theme, $filepath = null) {
        if(empty($filepath)) {
            $filepath = DRUPAL_ROOT . '/block_export.json';
        }

        $handle = fopen($filepath, 'w+');
        fwrite($handle, $this->exportJson($theme));
        fclose($handle);
    }

    function importFromFile($filepath, $theme = null) {
        $json = file_get_contents($filepath);
        $array = json_decode($json, true);
        if(empty($array)) {
            watchdog('Sprowt BlockBuilder', 'File does not contain JSON data: %filepath', array('%filepath' => $filepath));
            return false;
        }

        $this->import($array, $theme);
    }
}