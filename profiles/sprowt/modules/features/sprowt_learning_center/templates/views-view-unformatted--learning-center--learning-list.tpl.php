<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<div class="views-row">
    <?php if (!empty($title)): ?>
        <div class="header">
            <?php print $title; ?>
        </div>
    <?php endif; ?>
    <div class="issue-wrap">
        <?php foreach ($rows as $id => $row): ?>
            <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
                <?php print $row; ?>
            </div>
        <?php endforeach; ?>
    </div>
</div>
