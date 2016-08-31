<div class="progressing">
    <?php

    print '<h2>Copying <img class="throbber" src="/'.drupal_get_path('module','leadbuilder_theme_copy') . '/ajax-loader.gif'.'"></h2>';

    ?>
</div>

<div class="done" style="display:none;">
    <h2>All Done!</h2>
    <a href="/admin/appearance" class="button">Back to Themes</a>
</div>

<div class="theme-exists" style="display:none;">
    <h2>Theme Exists!</h2>
    <div class="messages messages-error error">
        It looks like the directory for <?php print $theme_name; ?> at '<?php print $new_path; ?>' already exists.
    </div>
    <div class="understand">
        <label>
            <input type="checkbox" id="i-understand">
            <span>Overwrite the theme at '<?php print $new_path; ?>' <strong>WARNING: THIS WILL DELETE THE OLD THEME</strong></span>
        </label>
    </div>
    <div class="buttons" style="margin-top:20px;">
        <a href="#" class="button" id="try-again">Try Again</a>
        <a href="/admin/appearance/theme-copy" class="button">Back to Theme Copy</a>
    </div>
</div>