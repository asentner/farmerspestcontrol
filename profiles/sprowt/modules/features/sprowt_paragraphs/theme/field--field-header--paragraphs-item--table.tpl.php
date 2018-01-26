<?php
    $text = '';
    foreach ($items as $delta => $item) {
            $text .= render($item);
    }
?>
<div class="<?php print $classes; ?>"<?php print $attributes; ?>><?php print $text; ?></div>