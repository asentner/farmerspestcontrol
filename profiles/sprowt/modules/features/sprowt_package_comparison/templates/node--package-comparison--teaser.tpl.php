<?php
  // load the packages to be compared
  $package_ids = array();
  foreach ($node->field_packages['und'] as $package) {
    $package_ids[] = $package['value'];
  };
  $packages = field_collection_item_load_multiple($package_ids);

  // build the buttons for the bottom of the table if ebooking_link is provided
  if(!empty($content['field_ebooking_link'][0]['#element']['url'])) {
    $ebooking_link = $content['field_ebooking_link'][0]['#element'];
    $ebooking_link_url = $ebooking_link['url'];
    $ebooking_link_title = 'Get Your Price';
    $ebooking_button = '<a class="button" href="'.$ebooking_link_url.'">'.$ebooking_link_title.'</a>';
  };


  //reorganize tagged features by term weight
    $tagged_features = array();
    foreach ($node->field_features['und'] as $feature) {
        $term = taxonomy_term_load($feature['tid']);
        $weight = $term->weight;
        while(!empty($tagged_features[$weight])) {
            $weight += 0.0001;
        }
        $tagged_features[$weight] = $feature;
    }

    ksort($tagged_features);

?>

<div<?php print $attributes; ?>>
  <div<?php print $content_attributes; ?>>
    <table>
      <thead>
        <tr>
          <th scope="row" rowspan="2">
            <span class="select-package">Select the package that best suits your needs.</span>
          </th>
          <?php
            foreach ($packages as $package) {
              $package_title = $package->field_package['und'][0]['entity']->title;
              $package_id = $package->field_package['und'][0]['target_id'];
              $package_url = drupal_get_path_alias('node/'.$package_id);
              print('<th scope="col">'.$package_title.'</th>');
            };
          ?>
        </tr>
        <tr>
          <?php
            foreach ($packages as $package) {
              print('<td>');
              if(!empty($package->field_package['und'][0]['entity']->field_starting_price['und'][0]['value'])) {
                $package_price = $package->field_package['und'][0]['entity']->field_starting_price['und'][0]['value'];
                print('<span><span class="package-price">'.$package_price.'</span>/per month!</span>');
              };
              if(!empty($package->field_package['und'][0]['entity']->field_initial_fee['und'][0]['value'])) {
                $initial_fee = $package->field_package['und'][0]['entity']->field_initial_fee['und'][0]['value'];
                print('<span class="initial-fee">'.$initial_fee.'</span>');
              };
              print('</td>');
            };
          ?>
        </tr>
      </thead>
      <tbody>
        <?php
          // build feature comparison rows
          foreach ($tagged_features as $feature) {
            print('<tr><td class="row-heading">'.$feature['taxonomy_term']->name.'</td>');
            // loop through each package to see if it has this feature selected
            $feature_tid = $feature['tid'];
            foreach ($packages as $package) {
              $has_package = FALSE;
              if(!empty($package->field_package['und'][0]['entity']->field_package_features['und'])) {
                foreach($package->field_package['und'][0]['entity']->field_package_features['und'] as $package_feature) {
                  if($feature_tid == $package_feature['tid']) { $has_package = TRUE; };
                };
              };
              if($has_package) { print('<td><i class="fa fa-check"></i></td>'); }
              else { print('<td><i class="fa fa-times"></i></td>'); };
            };
            print('</tr>');
          };
        ?>
        <tr class="package-buttons">
          <td></td>
          <?php
            // if package table links/titles are provided, use them for the buttons
            // else link to package content
            foreach ($packages as $package) {
              $package_id = $package->field_package['und'][0]['target_id'];
              $button_url = drupal_get_path_alias('node/'.$package_id);
              $button_title = '';
              if(!empty($package->field_package['und'][0]['entity']->field_table_link['und'][0]['url'])
                && $package->field_package['und'][0]['entity']->field_table_link['und'][0]['url'] != '[node:url]') {
                $button_url = $package->field_package['und'][0]['entity']->field_table_link['und'][0]['url'];
              };
              if(!empty($package->field_package['und'][0]['entity']->field_table_link['und'][0]['title'])) {
                $button_title = $package->field_package['und'][0]['entity']->field_table_link['und'][0]['title'];
              };
              if(!empty($button_title)) {
                  print('<td><a class="button" href="' . $button_url . '">' . $button_title . '</a></td>');
              }
              else {
                  print '<td></td>';
              }
            };
          ?>
        </tr>
      </tbody>
    </table>

  </div>

</div>
