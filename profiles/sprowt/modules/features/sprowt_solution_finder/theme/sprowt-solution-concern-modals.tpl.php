<div class="solution-concern-modals" id="<?php print $scmID; ?>">
    <ul class="scm-links">
        <?php foreach($concerns as $concern): ?>
            <li><a href="#<?php print $scmID; ?>--<?php print $concern->nid; ?>" class="scm-link"><?php print $concern->title; ?></a></li>
        <?php endforeach;?>
    </ul>
    <div class="scm-modals hidden">
        <?php foreach($concerns as $key => $concern): ?>
            <?php
                $node_view = node_view($concern, 'modal');
                $first = ($key == 0);
                $last = ($key == (count($concerns) - 1));
                $onlyOne = (count($concerns) == 1);
            ?>
            <div class="scm-modal" id="<?php print $scmID; ?>--<?php print $concern->nid; ?>">
                <?php print drupal_render($node_view); ?>
            </div>
        <?php endforeach;?>
    </div>
</div>