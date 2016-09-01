<?php
?>

<div class="choose_theme_radio_field">
    <?php if(!empty($logo)) { ?>
    <div class="theme_logo">
        <img src="<?php print $logo; ?>">
    </div>
    <?php } ?>
    <div class="theme_content">
        <h3><?php print $theme['name']; ?></h3>
        <div class="theme_description">
            <?php print $theme['description']; ?>
        </div>
    </div>
</div>