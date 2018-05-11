<?php

class ApPrep extends MigrationBase {
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
            'blog',
            'service',
            'market',
            'region',
            'localtarget'
        );
        self::displayMessage(t('Deleting nodes of type(s): ['. implode(', ', $types).']'), 'warning');

        $nids = db_query("
            SELECT nid
            FROM node
            WHERE type IN (:types)
        ", array(
            ':types' => $types
        ))->fetchCol();

        node_delete_multiple($nids);

        $vocabs = array(
            'markets',
            'regions',
            'services'
        );


        self::displayMessage(t('Deleting terms in the vocabularies: ['. implode(', ', $vocabs).']'), 'warning');
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


class ApFinish extends MigrationBase {
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
            if (ApPrep::$wasEnabled) {
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


        $this->generateTaxonomyNodes();

        return Migration::RESULT_COMPLETED;
    }

    public function generateTaxonomyNodes() {
        $marketVocab = taxonomy_vocabulary_machine_name_load('markets');
        $regionVocab = taxonomy_vocabulary_machine_name_load('regions');

        $markets = taxonomy_get_tree($marketVocab->vid, 0, null, true);
        $regions = taxonomy_get_tree($regionVocab->vid, 0, null, true);

        $taxonomies = array(
            $markets,
            $regions
        );

        foreach($taxonomies as $taxonomy) {
            foreach ($taxonomy as $term) {
                sprowt_taxonomy_engine_taxonomy_term_insert($term);
            }
        }
    }
}