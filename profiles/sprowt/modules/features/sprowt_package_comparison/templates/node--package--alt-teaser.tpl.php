<?php
  $features = array();
  if (!empty($content['field_package_features'][0]['#markup'])) {
    foreach ($node->field_package_features['und'] as $feature) {
      $features[] = $feature['taxonomy_term']->name;
    };
  };

  if(count($features) >= 5) {
    $features = array_slice($features, 0, 4);
    $features[4] = 'Plus More';
  };

  if(!empty($content['field_package_colors'][0]['#markup'])) {
    $color = $content['field_package_colors'][0]['#markup'];
  };

  $link_title = 'Learn More';
  if(!empty($content['field_block_link']['#items'][0]['title'])) {
    $link_title = $content['field_block_link']['#items'][0]['title'];
  }
  if(!empty($content['field_block_link']['#items'][0]['url'])) {
    $node_url = $content['field_block_link']['#items'][0]['url'];
  };
?>

<?php if(!empty($node->field_highlight['und'][0]['value'] && $node->field_highlight['und'][0]['value'] == 'on')): ?>
  <div class="highlighted">
<?php endif; ?>
  <article<?php print $attributes; ?>>
    <div<?php print $content_attributes; ?>>
      <?php if(!empty($content['field_package_colors'][0]['#markup'])): ?>
        <header style="background-color: <?php print $color ?>">
      <?php else: ?>
        <header>
      <?php endif; ?>
        <?php print render($content['field_icon']); ?>
        <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
        <?php print render($content['field_starting_price']); ?>
        <?php print render($content['field_initial_fee']); ?>
        <div class="banner-wrap"></div>
      </header>
      <div class="content-wrap">
        <?php
          // We hide the comments and links now so that we can render them later.
          hide($content['comments']);
          hide($content['links']);
          print render($content['body']);
          // print render($content['field_package_features']);
        ?>

        <?php if(FALSE): ?>
          <div class="feature-list">
            <?php foreach ($features as $feature): ?>
              <span class="feature"><?php print $feature ?></span>
            <?php endforeach; ?>
          </div>
        <?php endif; ?>

        <?php if(!empty($content['field_package_colors'][0]['#markup'])): ?>
          <a class="button overridden" href="<?php print $node_url; ?>" style="background-color: <?php print $color ?>"><?php print $link_title ?></a>
        <?php else: ?>
          <a class="button" href="<?php print $node_url; ?>"><?php print $link_title ?></a>
        <?php endif; ?>
      </div>
    </div>
  </article>
<?php if(!empty($node->field_highlight['und'][0]['value'] && $node->field_highlight['und'][0]['value'] == 'on')): ?>
  </div>
<?php endif; ?>
