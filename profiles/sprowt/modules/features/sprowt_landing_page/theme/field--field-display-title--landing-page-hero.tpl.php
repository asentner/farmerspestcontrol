<?php
    $text = '';
    foreach ($items as $delta => $item) {
            $text .= render($item);
    }
?>
<h1 class="<?php print $classes; ?>"<?php print $attributes; ?>><?php print $text; ?></h1>