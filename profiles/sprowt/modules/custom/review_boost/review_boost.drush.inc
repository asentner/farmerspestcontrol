<?php

function review_boost_drush_command() {
    $items = array();

    $access = ($_SERVER['REMOTE_ADDR'] == '127.0.0.1');
    if($access) {
        $items['review-boost-result-generate'] = array(
            'description' => 'Export blocks and theme block settings to a file in the json format.',
            'arguments' => array(
                'count' => 'number of results to generate'
            ),
            'examples'    => array(
                'drush review-boost-result-generate 5',
                'drush rbrg 10',
            ),
            'aliases'     => array('rbrg'),
        );
        $items['review-boost-result-generate-delete'] = array(
            'description' => 'Deletes generated results',
            'arguments' => array(),
            'examples'    => array(
                'drush review-boost-result-generate-delete5',
                'drush rbrgd',
            ),
            'aliases'     => array('rbrgd'),
        );
    }

    return $items;
}

function drush_review_boost_result_generate($count) {
    $services = array();
    $sales = array();
    $technicians = array();
    $branches = array();
    for($i = 0; $i <= 5; $i++) {
        $sales[] = "sales_$i";
        $services[] = "service_$i";
        $technicians[] = "tech_$i";
        $branches[] = "branch_$i";
    }

    for($i = 0; $i <= $count; $i++) {
        $int = new DateInterval('P' . rand(0,365) . 'D');
        $randDate = new DateTime();
        $randDate->sub($int);
        $name = explode(' ', _review_boost_rand_words(2));

        $customer_info = array(
            'token' => _review_boost_generate_token(),
            'customer_id' => 'rbrg--' . rand(0,99999),
            'first_name' => ucwords($name[0]),
            'last_name' => ucwords($name[1]),
            'email' => $name[0] . "@" . $name[1] . ".com",
            'tech' => $technicians[rand(0,4)],
            'sales' => $sales[rand(0,4)],
            'branch' => $branches[rand(0,4)],
            'service' => $services[rand(0,4)],
            'service_date' => $randDate->getTimestamp(),
            'creation_date' => time(),
        );


        $tid = db_insert('review_boost_token')
            ->fields($customer_info)
            ->execute();

        db_insert('review_boost_result')
            ->fields(array(
                'tid' => $tid,
                'service_rating' => (rand(0,10)/2),
                'service_comments' => _review_boost_rand_words(rand(5,50), false),
                'creation_date' => time(),
            ))
            ->execute();
    }
}

function drush_review_boost_result_generate_delete() {
    $tids = db_query("
        SELECT tid
        FROM review_boost_token
        WHERE customer_id LIKE 'rbrg--%'
    ")->fetchCol();

    db_delete('review_boost_token')
        ->condition('tid', $tids, 'IN')
        ->execute();

    db_delete('review_boost_result')
        ->condition('tid', $tids, 'IN')
        ->execute();
}