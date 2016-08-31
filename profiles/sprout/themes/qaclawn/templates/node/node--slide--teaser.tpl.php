<?php 
hide($content['field_color']);
hide($content['field_image']);

$style = "";
if (isset($content['field_color'][0]['#markup'])) {
  $style .= "background-color: ". $content['field_color'][0]['#markup'] .";";
}
if (isset($content['field_image'][0]['#item']['uri'])) {
  $style .= "background-image: url('". file_create_url($content['field_image'][0]['#item']['uri']) ."');";
}
?>

<div<?php print $attributes; ?> style="<?php print $style; ?>">

  <div<?php print $content_attributes; ?>>

      <header>
        <?php print render($title_prefix); ?>
        <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
        <?php print render($title_suffix); ?>
      </header>

    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>
  </div>

</div>
