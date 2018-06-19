<?php
  $highlighted = FALSE;
  if ($content['field_highlight'][0]['#markup'] == 'Yes') {
    $highlighted = TRUE;
  };

  if(!empty($content['field_package_colors'][0]['#markup'])) {
    $color = $content['field_package_colors'][0]['#markup'];
  };

?>

<a href="<?php print $block_link_url; ?>" class="package-link"></a>

<?php if($highlighted): ?>
  <div class="node-wrap highlighted">
<?php else: ?>
  <div class="node-wrap">
<?php endif; ?>
  <div<?php print $attributes; ?>>

    <?php if(!empty($content['field_package_colors'][0]['#markup'])): ?>
      <header style="background-color: <?php print $color ?>">
    <?php else: ?>
      <header>
    <?php endif; ?>
      <h3<?php print $title_attributes; ?>><?php print $title; ?></h3>
    </header>

    <h4 class='highlighted-text'><span>Most Popular</span></h4>

    <div class="content-wrap">
      <?php print render($content['body']); ?>

      <?php if(!empty($field_starting_price)): ?>
        <div class="starting-price">
          <div class="pricing">
            <?php print render($content['field_starting_price']); ?>
            <?php print render($content['field_price_suffix']); ?>
          </div>
        </div>
      <?php else: ?>
        <div class="space"></div>
      <?php endif; ?>

      <div class="block-link" style="background-color: <?php print $color ?>">
        <?php print render($content['field_block_link']); ?>
      </div>

      <?php print render($content['field_initial_fee']); ?>
      <?php
        // We hide the comments and links now so that we can render them later.
        hide($content['comments']);
        hide($content['links']);
        hide($content['field_highlight']);
        hide($content['field_highlight_icon']);
        hide($content['field_package_colors']);
        print render($content);
      ?>
    </div>
  </div>
</div>
