<?php

function _sprowt_taxonomy_engine_generate_aliases() {
    drupal_set_title('Regenerate Aliases');

    $form = array();

    $options = db_query("
        SELECT type, name
        FROM node_type
    ")->fetchAllKeyed();

    $form['types'] = array(
        '#type' => 'checkboxes',
        '#options' => $options,
        '#title' => 'Content Types',
        '#description' => 'Content Types you\'d like to regenerate aliases for.'
    );

    $form['actions'] = array(
        'submit' => array(
            '#type' => 'submit',
            '#value' => 'Submit'
        )
    );

    return $form;
}

function _sprowt_taxonomy_engine_generate_aliases_submit($form, &$form_state) {
    $values = $form_state['values'];
    if(!empty($values['types'])) {
        $nids = db_query("
        SELECT nid
        FROM node
        WHERE type IN (:types)
    ", array(
            ':types' => $values['types']
        ))->fetchCol();

        foreach(node_load_multiple($nids) as $node) {
            $node->path['pathauto'] = true;
            node_save($node);
        }
        drupal_set_message(t('%d Nodes Updated!', array('%d' => count($nids))));
    }
}