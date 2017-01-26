<?php

class MenuBuilder {
    protected $menu_links;
    protected $uuid_map;

    function __construct() {
        $this->menu_links = array();
        $this->uuid_map = array();
        $this->base_url = 'http://dev-inter-theme.pantheon.io';
    }

    function writeFromDb($menu) {
        $tree = menu_tree_all_data($menu);

        $links = array();

        $this->addLinktoArrayFromTree($links, $tree);

        $this->uuid_map = db_query("
            SELECT nid, uuid
            FROM node
        ")->fetchAllKeyed();


    }

    function addLinktoArrayFromTree(&$links, $tree){
        $link_int = array(
            'link_path',
            'link_title',
            'menu_name',
            'weight',
            'expanded',
            'mlid',
            'plid',
            'router_path',
            'options',
            'hidden'
        );
        
        foreach($tree as $data) {
            $orig = $data['link'];
            $link = array();

            foreach($link_int as $int) {
                $link[$int] = $orig[$int];
            }

            $this->menu_links[] = $link;

            if(!empty($data['below'])) {
                $this->addLinktoArrayFromTree($links, $data['below']);
            }
        }
    }

    function writeFromArray($array) {
        $this->menu_links = $array['menu_links'];
        $this->uuid_map = $array['uuid_map'];
    }

    function translateNodes(){
        $nid_map = db_query("
            SELECT uuid, nid
            FROM node
        ")->fetchAllKeyed();
        foreach($this->menu_links as $k=>$link) {
            if(preg_match('/node\/([\d]+)/', $link['link_path'], $m)) {
                $nid = $m[1];
                $uuid = $this->uuid_map[$nid];
                $link['link_path'] = 'node/' . $nid_map[$uuid];
                $this->menu_links[$k] = $link;
            }
        }
    }

    function getFiles(){
        foreach($this->menu_links as $link) {
            if(!empty($link['options']['menu_icon'])) {
                $path = $link['options']['menu_icon']['path'];
                $url = $this->base_url . '/' . str_replace(DRUPAL_ROOT, '', drupal_realpath($path));
                $dest = str_replace(basename($path), '', $path);
                file_prepare_directory($dest, FILE_CREATE_DIRECTORY);
                $file = system_retrieve_file($url, $dest, TRUE, FILE_EXISTS_REPLACE);
            }
        }
    }

    function writeMenuLinks(){
        $mlid_map = array();
        foreach($this->menu_links as $link) {
            $old_mlid = $link['mlid'];
            unset($link['mlid']);
            unset($link['plid']);
            if(!empty($link['options']['attributes']['class'])) {
                foreach($link['options']['attributes']['class'] as $k => $class) {
                    if(preg_match('/menu-([\d+])/', $class, $m)) {
                        unset($link['options']['attributes']['class'][$k]);
                    }
                }
            }

            $new_mlid =  menu_link_save($link);
            $mlid_map[$old_mlid] = $new_mlid;
        }

        foreach($this->menu_links as $link) {
            $link['mlid'] = $mlid_map[$link['mlid']];
            if(!empty($link['plid'])) {
                $link['plid'] = $mlid_map[$link['plid']];
            }
            $menu_class = false;
            if(!empty($link['options']['attributes']['class'])) {
                foreach($link['options']['attributes']['class'] as $k => $class) {
                    if(preg_match('/menu-([\d+])/', $class, $m)) {
                        unset($link['options']['attributes']['class'][$k]);
                        break;
                    }
                }
            }

            $link['options']['attributes']['class'][] = 'menu-' . $link['mlid'];
            menu_link_save($link);
        }

        if(function_exists('menu_icons_css_generate')) {
            menu_icons_css_generate();
        }
    }

    function importFromArray($array) {
        $this->writeFromArray($array);
        $this->getFiles();
        $this->translateNodes();
        $this->writeMenuLinks();
    }

    function exportToArray($menu){
        $this->writeFromDb($menu);

        $array = array(
            'menu_links' => $this->menu_links,
            'uuid_map' => $this->uuid_map
        );

        return $array;
    }

    function importFromJson($json) {
        $this->importFromArray(json_decode($json, true));
    }

    function exportToJson($menu){
        $array = $this->exportToArray($menu);
        return json_encode($array);
    }

    function importFromFile($filepath) {
        $json = file_get_contents($filepath);
        $array = json_decode($json, true);
        if(empty($array)) {
            watchdog('Sprowt MenuBuilder', 'File does not contain JSON data: %filepath', array('%filepath' => $filepath));
            return false;
        }

        $this->importFromArray($array);
    }

    function exportToFile($menu, $filepath = null) {
        if(empty($filepath)) {
            $filepath = DRUPAL_ROOT . '/block_export.json';
        }

        $handle = fopen($filepath, 'w+');
        fwrite($handle, $this->exportToJson($menu));
        fclose($handle);
    }

}