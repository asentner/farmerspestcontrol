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

    $items['queue-delete'] = array(
        'description' => "Deletes all items from the queue with a given name",
        'arguments' => array(
            'queue' => 'Name of the queued item',
        ),
        'examples' => array(
            'drush queue-delete review_boost_email_worker',
        ),
    );

    return $items;
}

function drush_review_boost_queue_delete($queue) {
    $count = db_query("
        SELECT count(*) as 'count' FROM queue WHERE name = :queue;
    ", array(
        ':queue' => $queue
    ))->fetchField();


    $delete = db_delete('queue')
        ->condition('name',$queue)
        ->execute();
    drush_print("$count items deleted from queue with name $queue");
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
            'customer_phone' => generateRandomPhone(),
            'tech' => $technicians[rand(0,4)],
            'sales' => $sales[rand(0,4)],
            'branch' => $branches[rand(0,4)],
            'service' => $services[rand(0,4)],
            'service_date' => $randDate->getTimestamp(),
            'creation_date' => time(),
            'email_sent' => rand(0,1),
            'text_sent' => rand(0,1)
        );
        $customer_info['hash'] = generateHash($customer_info);
        if($customer_info['email_sent'] === 0){
          $customer_info['text_sent'] = 1;
        }elseif($customer_info['email_sent'] === 1){
          $customer_info['text_sent'] = 0;
        }
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
//hash the data
function generateHash($data) {
  $row = array(
    'email' => $data['email'],
    'tech' => $data['tech'],
    'sales' => $data['sales'],
    'branch' => $data['branch'],
    'service' => $data['service'],
    'service_date' => $data['service_date'],
    'customer_phone' => $data['customer_phone']
  );

  $json = json_encode($row);
  return md5($json);
}
//Generate random invalid phone based on 555 prefix
function generateRandomPhone(){
  $prefix = 555;
  $areaCode = rand(100,999);
  $lineNum = rand(1000,9999);
  return $areaCode . $prefix . $lineNum;
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