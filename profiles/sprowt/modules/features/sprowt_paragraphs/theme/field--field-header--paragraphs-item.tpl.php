<?php
    $text = '';
    foreach ($items as $delta => $item) {
            $text .= render($item);
    }
?>
<h2 class="<?php print $classes; ?>"<?php print $attributes; ?>><?php print $text; ?></h2>