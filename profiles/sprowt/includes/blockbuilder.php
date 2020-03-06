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
    protected $webform_block_settings = [];
    public $bids;

    function __construct($bids = array())
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
        $this->menu_block = array();
        $this->bean = array();
        $this->bids = $bids;
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
                    if (strpos($row['css_class'], 'sprowt-block-imported') === false) {
                        $row['css_class'] .= ' sprowt-block-imported';
                    }
                    break;
                case 'multiblock':
                    $row['delta'] = $this->multiblock_map[$current_row['delta']];
                    if (strpos($row['css_class'], 'sprowt-block-imported') === false) {
                        $row['css_class'] .= ' sprowt-block-imported';
                    }
                    break;
                case 'sprowt_block_cta':
                    $nid = str_replace('sprowt_block_cta_', '', $row['delta']);
                    $uuid = empty($this->uuid_map[$nid]) ? 0 : $this->uuid_map[$nid];
                    if (!empty($nid_map[$uuid])) {
                        if (strpos($row['css_class'], 'sprowt-block-imported') === false) {
                            $row['css_class'] .= ' sprowt-block-imported';
                        }
                        $row['css_class'] .= ' block--sprowt-block-cta-sprowt-block-cta-' . $nid;
                        $row['delta'] = 'sprowt_block_cta_' . $nid_map[$uuid];
                    }
                    else {
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

            if (!$exists) {
                if (!empty($row['delta'])) {
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

            //update all block rows with new info
            $update_row = $row;
            unset($update_row['theme']);
            unset($update_row['region']);
            $trans[] = db_update('block')->fields($update_row)->condition('module', $row['module'])->condition('delta', $row['delta']);
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
        $blockSettings = $this->webform_block_settings;
        $blockSettingsChanged = false;
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
                $newDelta = implode('-', $delta_parts);
                if(!empty($blockSettings[$row['delta']])) {
                    $blockSettingsChanged = true;
                    $blockSettings[$newDelta] = $blockSettings[$row['delta']];
                    unset($blockSettings[$row['delta']]);
                }
                $row['delta'] = $newDelta;
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
            if($row['module'] == 'sprowt_block_cta') {
                $delta_parts = explode('_', $row['orig_delta']);
                $nid = array_pop($delta_parts);
                $uuid = $this->uuid_map[$nid];
                $delta_parts[] = $nid_map[$uuid];
                $row['orig_delta'] = implode('_', $delta_parts);
                $this->block_node_type[$k] = $row;
            }
        }

        foreach($this->block_node_type as $k => $row) {
            if($row['module'] == 'webform') {
                $delta_parts = explode('-', $row['delta']);
                $nid = array_pop($delta_parts);
                $uuid = $this->uuid_map[$nid];
                $delta_parts[] = $nid_map[$uuid];
                $row['delta'] = implode('-', $delta_parts);
                $this->block_node_type[$k] = $row;
            }
            if($row['module'] == 'sprowt_block_cta') {
                $delta_parts = explode('_', $row['delta']);
                $nid = array_pop($delta_parts);
                $uuid = $this->uuid_map[$nid];
                $delta_parts[] = $nid_map[$uuid];
                $row['delta'] = implode('_', $delta_parts);
                $this->block_node_type[$k] = $row;
            }
        }

        if(!empty($blockSettingsChanged)) {
            variable_set('webform_blocks', $blockSettings);
        }

    }

    function handleContexts() {
        $nid_map = db_query("
            SELECT uuid, nid
            FROM node
        ")->fetchAllKeyed();
        if(module_exists('context')) {
            $contexts = context_load(NULL, TRUE);
            foreach($contexts as $context_name => $context) {
                $context_changed = false;
                if(!empty($context->reactions) && !empty($context->reactions['block']['blocks'])) {
                    foreach($context->reactions['block']['blocks'] as $key => $block) {
                        switch ($block['module']) {
                            case 'block':
                                $block['delta'] = $this->block_custom_map[$block['delta']];
                                unset($context->reactions['block']['blocks'][$key]);
                                $context->reactions['block']['blocks'][$block['module'] .'-' . $block['delta']] = $block;
                                $context_changed = true;
                                break;
                            case 'multiblock':
                                $block['delta'] = $this->multiblock_map[$block['delta']];
                                unset($context->reactions['block']['blocks'][$key]);
                                $context->reactions['block']['blocks'][$block['module'] .'-' . $block['delta']] = $block;
                                $context_changed = true;
                                break;
                            case 'sprowt_block_cta':
                                $nid = str_replace('sprowt_block_cta_', '', $block['delta']);
                                $uuid = empty($this->uuid_map[$nid]) ? 0 : $this->uuid_map[$nid];
                                unset($context->reactions['block']['blocks'][$key]);
                                if (!empty($nid_map[$uuid])) {
                                    $block['delta'] = 'sprowt_block_cta_' . $nid_map[$uuid];
                                    $context->reactions['block']['blocks'][$block['module'] .'-' . $block['delta']] = $block;
                                }
                                $context_changed = true;
                                break;
                            case 'webform':
                                $delta_parts = explode('-', $block['delta']);
                                $nid = array_pop($delta_parts);
                                $uuid = $this->uuid_map[$nid];
                                $delta_parts[] = $nid_map[$uuid];
                                $block['delta'] = implode('-', $delta_parts);
                                unset($context->reactions['block']['blocks'][$key]);
                                $context->reactions['block']['blocks']['webform-' . $block['delta']] = $block;
                                $context_changed = true;
                                break;
                        }
                    }
                }

                if(!empty($context->conditions['path']['values'])) {
                    foreach($context->conditions['path']['values'] as $key => $path) {
                        if(strpos($path, 'node/') === 0) {
                            $nid = str_replace('node/', '', $path);
                            $uuid = empty($this->uuid_map[$nid]) ? 0 : $this->uuid_map[$nid];
                            if(!empty($nid_map[$uuid])) {
                                $context->conditions['path']['values'][$key] = "node/{$nid_map[$uuid]}";
                                $context_changed = true;
                            }
                            else {
                                unset($context->conditions['path']['values'][$key]);
                                $context_changed = true;
                            }
                        }
                    }
                    if(empty($context->conditions['path']['values'])) {
                        unset($context->conditions['path']);
                        $context_changed = true;
                    }
                }

                if($context_changed) {
                    context_save($context);
                }
            }
            $contexts = context_load(NULL, TRUE);
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

    function addReferencestoEntity(&$entity, $entity_type, $bundle) {
        $instances = field_info_instances($entity_type, $bundle);
        foreach($instances as $bundle_field_name => $instance) {
            $info = field_info_field($bundle_field_name);

            switch($info['type']) {
                case 'entityreference':
                    if(!empty($entity->{$bundle_field_name})) {
                        foreach($entity->{$bundle_field_name} as $lang => &$items) {
                            foreach($items as $item_delta => &$item) {
                                $target_id = entity_get_id_by_uuid($info['settings']['target_type'], array($item['uuid']));
                                if(!empty($target_id)) {
                                    foreach($target_id as $id) {
                                        if(!empty($id)) {
                                            $target_id = $id;
                                            break;
                                        }
                                    }
                                    if(!empty($target_id)) {
                                        $item = array(
                                            'target_id' => $target_id
                                        );
                                    }
                                    else {
                                        unset($items[$item_delta]);
                                    }
                                }
                                else {
                                    unset($items[$item_delta]);
                                }
                            }
                        }
                        if(empty($items)) {
                            unset($entity->{$bundle_field_name}[$lang]);
                        }
                    }
                    break;
            }
        }
    }

    function addTermstoEntity(&$entity, $entity_type, $bundle) {
        $instances = field_info_instances($entity_type, $bundle);
        foreach($instances as $bundle_field_name => $instance) {
            $info = field_info_field($bundle_field_name);

            switch($info['type']) {
                case 'taxonomy_term_reference':
                    if(!empty($entity->{$bundle_field_name})) {
                        foreach($entity->{$bundle_field_name} as $lang => &$items) {
                            foreach($items as $item_delta => &$item) {
                                $term = entity_get_id_by_uuid('taxonomy_term', array($item['uuid']));
                                if(!empty($term)) {
                                    $tid = array_pop($term);
                                    $item = array(
                                        'tid' => $tid
                                    );
                                }
                                else {
                                    unset($items[$item_delta]);
                                }
                            }
                        }
                        if(empty($items)) {
                            unset($entity->{$bundle_field_name}[$lang]);
                        }
                    }
                    break;
            }
        }
    }

    function addParagraphsToEntityFromExportArray($entity, $entity_type, $array) {
        if(!empty($array['paragraph_fields'])) {
            foreach ($array['paragraph_fields'] as $field_name => $langs) {
                foreach($langs as $lang => $items) {
                    foreach($items as $entity_array) {
                        $instances = field_info_instances('paragraphs_item', $entity_array['bundle']);
                        $paragraph = entity_create('paragraphs_item', array(
                            'bundle' => $entity_array['bundle'],
                            'uuid' => $entity_array['uuid']
                        ));

                        foreach($instances as $bundle_field_name => $instance) {
                            if(!empty($entity_array[$bundle_field_name])) {
                                $paragraph->{$bundle_field_name} = $entity_array[$bundle_field_name];
                            }
                        }

                        $this->addTermstoEntity($paragraph, 'paragraphs_item', $entity_array['bundle']);

                        $paragraph->field_name = $field_name;
                        $paragraph->setHostEntity($entity_type, $entity);
                        $paragraph->save();
                        $this->addParagraphsToEntityFromExportArray($paragraph, 'paragraphs_item', $entity_array);
                    }
                }
            }
        }
    }

    function writeBean() {
        $exclude = array(
            'bid',
            'vid',
            'uuid',
            'vuuid',
            'default_revision',
            'revisions',
            'log',
            'paragraph_fields'
        );
        foreach($this->bean as $delta => $beanArray) {
            $bean = entity_uuid_load('bean', array($beanArray['uuid']));
            if(!empty($bean)) {
                $bean = array_pop($bean);
            }
            else {
                $bean = entity_create('bean', array(
                    'type' => $beanArray['type']
                ));
                $bean->uuid = $beanArray['uuid'];
            }

            foreach($beanArray as $key => $val) {
                if(!in_array($key, $exclude)) {
                    $bean->{$key} = $val;
                }
            }

            $this->addReferencestoEntity($bean, 'bean', $beanArray['type']);
            $this->addTermstoEntity($bean, 'bean', $beanArray['type']);

            $original = clone $bean;
            _bean_export_file_field_import($bean, $original);

            $bean->save();
            $this->addParagraphsToEntityFromExportArray($bean, 'bean', $beanArray);
        }
    }

    function getModuleDeltaWhere($module_deltas) {
        $sqlargs = array();
        $args = array();
        foreach($module_deltas as $k => $md) {
            $sqlargs[] = "(module = :module{$k} AND delta = :delta{$k})";
            $args[":module{$k}"] = $md['module'];
            $args[":delta{$k}"] = $md['delta'];
        }
        return array(
            'sql' => implode("\nOR ", $sqlargs),
            'args' => $args
        );

    }

    function exportEntity($entity, $entity_type, $bundle, $extract = true) {
        $instances = field_info_instances($entity_type, $bundle);
        foreach($instances as $field_name => $instance) {
            $info = field_info_field($field_name);
            switch($info['type']) {
                case 'taxonomy_term_reference':
                    if(!empty($entity->{$field_name})) {
                        foreach($entity->{$field_name} as $lang => &$items) {
                            foreach($items as $item_delta => &$item) {
                                $term = taxonomy_term_load($item['tid']);
                                $item['uuid'] = $term->uuid;
                            }
                        }
                    }
                    break;
                case 'entityreference':
                    if(!empty($entity->{$field_name})) {
                        foreach($entity->{$field_name} as $lang => &$items) {
                            foreach($items as $item_delta => &$item) {
                                $target = entity_load($info['settings']['target_type'], array($item['target_id']));
                                if(!empty($target)) {
                                    $target = array_pop($target);
                                }
                                $item['uuid'] = $target->uuid;
                            }
                        }
                    }
                    break;
            }
        }

        $original = clone $entity;
        if($extract) {
            paragraphs_export_extract_paragraphs($entity, $original, $entity_type);
        }

        if(!empty($entity->paragraph_fields)) {
            foreach($entity->paragraph_fields as $field_name => $p_langs) {
                foreach($p_langs as $p_lang => $p_items) {
                    foreach($entity->paragraph_fields[$field_name][$p_lang] as &$e) {
                        $this->exportEntity($e, 'paragraphs_item', $e->bundle, false);
                    }
                }
            }
        }

        _bean_export_file_field_export($entity, $original);

        return json_decode(json_encode($entity), true);
    }

    function exportBean($delta) {
        $bean = bean_load_delta($delta);
        return $this->exportEntity($bean, 'bean', $bean->type);
    }

    function setFromDb($theme){

        $array = array();

        if(!empty($this->bids)) {
            $block_query = "
                SELECT *
                FROM block
                WHERE theme = :theme
                AND bid IN (:bids)
            ";
            $block_args = array(
                ':theme' => $theme,
                ':bids' => $this->bids
            );
            $array['block'] = db_query($block_query, $block_args)->fetchAll(PDO::FETCH_ASSOC);
            $modules = array();
            $deltas = array();
            $module_deltas = array();
            foreach($array['block'] as $row) {
                $deltas[] = $row['delta'];
                if(!in_array($row['module'], $modules)) {
                    $modules[] = $row['module'];
                }
                $module_deltas[] = array(
                    'module' => $row['module'],
                    'delta' => $row['delta']
                );
            }

            $mdsql = $this->getModuleDeltaWhere($module_deltas);

            $bc_deltas = array();
            foreach($module_deltas as $md) {
                if($md['module'] == 'block') {
                    $bc_deltas[] = $md['delta'];
                }
            }
            $array['block_custom'] = [];
            if(!empty($bc_deltas)) {
                $array['block_custom'] = db_query("
                    SELECT *
                    FROM block_custom
                    WHERE bid in (:deltas)
                    ", array(
                        ':deltas' => $bc_deltas
                ))->fetchAll(PDO::FETCH_ASSOC);
            }

            $array['block_node_type'] = db_query("
                  SELECT *
                  FROM block_node_type
                  WHERE 1 = 1
                  AND {$mdsql['sql']}
              ", $mdsql['args']
            )->fetchAll(PDO::FETCH_ASSOC);
            $array['block_role'] = db_query("
                  SELECT *
                  FROM block_role
                  WHERE 1 = 1
                  AND {$mdsql['sql']}
              ", $mdsql['args']
            )->fetchAll(PDO::FETCH_ASSOC);
            if(db_table_exists('multiblock')) {
                $array['multiblock'] = db_query("
                        SELECT *
                        FROM multiblock
                  WHERE 1 = 1
                  AND ".str_replace(':orig_delta', ':delta', str_replace('delta', 'orig_delta', $mdsql['sql']))."
              ", $mdsql['args']
                )->fetchAll(PDO::FETCH_ASSOC);
            }

            if(in_array('menu_block', $modules)) {
                $args =  array();
                foreach($module_deltas as $md) {
                    if($md['module'] == 'menu_block') {
                        $args[] = "name LIKE 'menu\\_block\\_{$md['delta']}\\_%'";
                    }
                }

                if(!empty($args)) {
                    $sql = "
                    SELECT name, value
                    FROM variable
                    WHERE " . implode("\nOR ", $args) . "
                ";

                    $array['menu_block'] = db_query($sql)->fetchAllKeyed();
                }
                else {
                    $array['menu_block'] = array();
                }
            }
            else {
                $array['menu_block'] = array();
            }

            $array['bean'] = array();
            if(in_array('bean', $modules)) {
                foreach($module_deltas as $md) {
                    if($md['module'] == 'bean') {
                        $array['bean'][$md['delta']] = $this->exportBean($md['delta']);
                    }
                }
            }

        }
        else {
            $array['block_custom'] = db_query("SELECT * FROM block_custom")->fetchAll(PDO::FETCH_ASSOC);
            $array['block_node_type'] = db_query("SELECT * FROM block_node_type")->fetchAll(PDO::FETCH_ASSOC);
            $array['block_role'] = db_query("SELECT * FROM block_role")->fetchAll(PDO::FETCH_ASSOC);
            if (db_table_exists('multiblock')) {
                $array['multiblock'] = db_query("SELECT * FROM multiblock")->fetchAll(PDO::FETCH_ASSOC);
            }


            $array['block'] = db_query("
                SELECT *
                FROM block
                WHERE theme = :theme
            ", array(':theme' => $theme))
                ->fetchAll(PDO::FETCH_ASSOC);

            $array['menu_block'] = db_query("
                SELECT name, value
                FROM variable
                WHERE name LIKE 'menu_block%'
            ")->fetchAllKeyed();

            $bean_deltas = db_query("
                SELECT delta
                FROM block
                WHERE module = 'bean'
                GROUP BY delta
            ")->fetchCol();

            $array['bean'] = array();
            foreach ($bean_deltas as $delta) {
                $array['bean'][$delta] = $this->exportBean($delta);
            }

        }

        $array['uuid_map'] = db_query("
            SELECT nid, uuid
            FROM node
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

        $array['webform_block_settings'] = variable_get('webform_blocks', []);



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

    function setFromFile($filepath) {
        $json = file_get_contents($filepath);
        $this->setFromJson($json);
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
        $this->writeBean();
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
            'menu_block' => $this->menu_block,
            'bean' => $this->bean,
            'webform_block_settings' => $this->webform_block_settings
        );

        return $array;
    }

    function exportJson($theme) {
        return json_encode($this->export($theme), JSON_PRETTY_PRINT);
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


/**
 * Handle exporting file fields.
 * Copy of node_export_file_field_export adapted for paragraphs_items
 */
function _bean_export_file_field_export(&$entity, $original_entity) {

    if(!(is_a($entity, 'Bean'))) {
        return false;
    }

    $entity_info = array(
        'type' => 'bean',
        'bundle' => $entity->type
    );

    $types = array_filter(variable_get('node_export_file_types', array()));
    if ($entity_info['type'] != 'node' || in_array($entity->type, $types)) {
        $assets_path = variable_get('node_export_file_assets_path', '');
        $export_mode = 'inline';

        switch ($export_mode) {
            case 'local':
                $export_var = 'node_export_file_path';
                break;
            case 'remote':
                $export_var = 'node_export_file_url';
                break;
            default:
            case 'inline':
                $export_var = 'node_export_file_data';
                break;
        }

        // get all fields from this node type
        $fields = field_info_instances($entity_info['type'],
            $entity_info['bundle']);
        foreach($fields as $field_instance) {
            // load field infos to check the type
            $field = &$entity->{$field_instance['field_name']};
            $info = field_info_field($field_instance['field_name']);

            $supported_fields = array_map('trim', explode(',', variable_get('node_export_file_supported_fields', 'file, image')));

            // check if this field should implement file import/export system
            if (in_array($info['type'], $supported_fields)) {

                // we need to loop into each language because i18n translation can build
                // fields with different language than the node one.
                foreach($field as $language => $files) {
                    if (is_array($files)) {
                        foreach($files as $i => $file) {

                            // convert file to array to stay into the default node_export_file format
                            $file = (object) $file;

                            // media field type doesn't load file the whole file on node_load
                            // it loads only fid, title and data associated with file, so in this case we need
                            // to load it by ourselves.
                            if (empty($file->uri) && !empty($file->fid) && $file = file_load($file->fid)) {
                                $field[$language][$i] = (array) $file;
                            }

                            // Check the file
                            if (!isset($file->uri) || !is_file($file->uri)) {
                                drupal_set_message(t("File field found on node, but file doesn't exist on disk? '!path'", array('!path' => $file->uri)), 'error');
                                continue;
                            }

                            if ($export_mode == 'local') {
                                if ($assets_path) {
                                    $export_data = $assets_path . '/' . basename($file->uri);
                                    if (!copy($file->uri, $export_data)) {
                                        drupal_set_message(t("Export file error, could not copy '%filepath' to '%exportpath'.", array('%filepath' => $file->uri, '%exportpath' => $export_data)), 'error');
                                        return FALSE;
                                    }
                                }
                                else {
                                    $export_data = $file->uri;
                                }
                            }
                            // Remote export mode
                            elseif ($export_mode == 'remote') {
                                // NOTE: This is patched with info from https://drupal.org/node/2046431
                                $export_data = file_create_url($file->uri);
                            }
                            // Default is 'inline' export mode
                            else {
                                $export_data = base64_encode(file_get_contents($file->uri));
                            }

                            // build the field again, and remove fid to be sure that imported node
                            // will rebuild the file again, or keep an existing one with a different fid
                            $field[$language][$i]['fid'] = NULL;
                            $field[$language][$i][$export_var] = $export_data;

                        }
                    }
                }
            }
        }
    }
}

/**
 * Handle importing file fields.
 *
 * @param $entity
 *   Node or field_collection_item object.
 * @param $original_entity
 *   Unused...
 */
function _bean_export_file_field_import(&$entity, $original_entity) {
    if(!(is_a($entity, 'Bean'))) {
        return false;
    }

    $entity_info = array(
        'type' => 'bean',
        'bundle' => $entity->type
    );

    // Get all fields from this node type.
    $fields = field_info_instances($entity_info['type'], $entity_info['bundle']);
    foreach($fields as $field_instance) {
        // Load field info to check the type.
        $field = &$entity->{$field_instance['field_name']};
        $info = field_info_field($field_instance['field_name']);

        $supported_fields = array_map('trim', explode(',', variable_get('node_export_file_supported_fields', 'file, image')));

        // Check if this field should implement file import/export system.
        if (in_array($info['type'], $supported_fields)) {

            // We need to loop into each language because i18n translation can build
            // fields with different language than the node one.
            foreach($field as $language => $files) {
                if (is_array($files)) {
                    foreach($files as $i => $field_value) {

                        $file = (object) $field_value;

                        $result = _node_export_file_field_import_file($file);

                        // The file was saved successfully, update the file field (by reference).
                        if ($result == TRUE && isset($file->fid)) {
                            // Retain any special properties from the original field value.
                            $field[$language][$i] = array_merge($field_value, (array) $file);
                        }
                    }
                }
            }
        }
    }
}
