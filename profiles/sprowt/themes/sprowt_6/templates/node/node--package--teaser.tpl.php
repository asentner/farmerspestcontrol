<?php
  $highlighted = FALSE;
  if ($content['field_highlight'][0]['#markup'] == 'Yes') {
    $highlighted = TRUE;
  };
?>
<?php if($highlighted): ?>
  <div class="node-wrap highlighted">
<?php else: ?>
  <div class="node-wrap">
<?php endif; ?>
  <div<?php print $attributes; ?>>
    <div class="icon-wrap">
      <?php print render($content['field_icon']); ?>
    </div>
    <div class="content-wrap">
      <h3<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>" rel="bookmark"><?php print $title; ?></a></h3>
      <?php
        // We hide the comments and links now so that we can render them later.
        hide($content['comments']);
        hide($content['links']);
        hide($content['field_highlight']);
        hide($content['field_highlight_icon']);
        print render($content);
      ?>
    </div>
    <?php if($highlighted) {
        print render($content['field_highlight_icon']);
      };
    ?>
  </div>
</div>
