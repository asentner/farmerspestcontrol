<?php
    $text = '';
    foreach ($items as $delta => $item){
        $text .= render($item);
    }
?>

<a class="<?php print $classes; ?>"<?php print $attributes; ?> href="<?php print $text; ?>"><span class="sr-only">Learn More</span></a>
