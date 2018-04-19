<?php

class SproutPrep extends MigrationBase {
    public static $wasEnabled = FALSE;

    public function __construct($arguments) {
        parent::__construct($arguments);
        $this->description = t('Some prep before migration. CAUTION: This will delete nodes.');
    }

    public function isComplete() {
        // If Auto Node Title is disabled, other migrations are free to go
        if (module_exists('sprowt_taxonomy_engine')) {
            return FALSE;
        }
        else {
            return TRUE;
        }
    }

    public function import() {
        if (module_exists('sprowt_taxonomy_engine')) {
            self::$wasEnabled = TRUE;
            module_disable(array('sprowt_taxonomy_engine'));
            self::displayMessage(t('Disabled sprowt_taxonomy_engine module'), 'success');
        }
        else {
            self::$wasEnabled = FALSE;
            self::displayMessage(t('sprowt_taxonomy_engine is already disabled'), 'success');
        }

        $types = array(
            'affiliation',
            'benefit',
        );
        self::displayMessage(t('Deleting nodes of type(s): ['. implode(', ', $types).']'));

        $nids = db_query("
            SELECT nid
            FROM node
            WHERE type IN (:types)
        ", array(
            ':types' => array(
                'affiliation'
            )
        ))->fetchCol();

        node_delete_multiple($nids);

        $vocabs = array(
            'markets',
            'regions',
            'services'
        );


        self::displayMessage(t('Deleting terms in the vocabularies: ['. implode(', ', $vocabs).']'));
        foreach($vocabs as $vocabName) {
            $v = taxonomy_vocabulary_machine_name_load($vocabName);
            $tree = taxonomy_get_tree($v->vid);
            foreach($tree as $term) {
                taxonomy_term_delete($term->tid);
            }
        }

        // import() must return one of the MigrationBase RESULT constants.
        return MigrationBase::RESULT_COMPLETED;
    }
}


class SproutFinish extends MigrationBase {
    public static $wasEnabled = FALSE;

    public function __construct($arguments) {
        parent::__construct($arguments);
        $this->description = t('Some wrap up code.');
    }

    public function isComplete() {
        // There is no incomplete state for this operation.
        return TRUE;
    }

    public function import() {
        if (!module_exists('sprowt_taxonomy_engine')) {
            if (SproutPrep::$wasEnabled) {
                module_enable(array('sprowt_taxonomy_engine'));
                self::displayMessage(t('Re-enabled sprowt_taxonomy_engine module'), 'success');
            }
            else {
                self::displayMessage(t('sprowt_taxonomy_engine was not originally enabled'),
                    'success');
            }
        }
        else {
            self::displayMessage(t('sprowt_taxonomy_engine module already enabled'),
                'success');
        }
        return Migration::RESULT_COMPLETED;
    }
}