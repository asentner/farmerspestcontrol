<?php
    $shown_concerns = array();
    $hidden_concerns = array();

    foreach($concerns as $concern) {
        if($shown) {
            $shown_concerns[] = $concern;
            --$shown;
        }
        else {
            $hidden_concerns[] = $concern;
        }
    }
?>
<form id="<?php print $form_id; ?>" class="solution-finder-form" action="/solution-finder">
    <div id="shown" class="concerns-wrapper">
        <?php foreach($shown_concerns as $concern): ?>
            <div class="concern-wrap">
                <label for="concern-<?php print $concern['nid']; ?>">
                    <input type="checkbox" name="concerns[]" id="concern-<?php print $concern['nid']; ?>" value="<?php print $concern['nid']; ?>">
                    <?php print render($concern['icon']); ?>
                    <div class="name"><?php print $concern['name']; ?></div>
                </label>
            </div>
        <?php endforeach; ?>
    </div>
    <?php if (!empty($hidden_concerns)): ?>
        <div id="hidden" class="concerns-wrapper" style="display:none;">
            <?php foreach($hidden_concerns as $concern): ?>
                <div class="concern-wrap">
                    <label for="concern-<?php print $concern['nid']; ?>">
                        <input type="checkbox" name="concerns[]" id="concern-<?php print $concern['nid']; ?>" value="<?php print $concern['nid']; ?>">
                        <?php print render($concern['icon']); ?>
                        <div class="name"><?php print $concern['name']; ?></div>
                    </label>
                </div>
            <?php endforeach; ?>
        </div>
    <?php endif; ?>
    <div class="actions">
        <?php if (!empty($hidden_concerns)): ?>
            <button type="button" class="show-hide-button button">More Options</button>
        <?php endif; ?>
        <button type="submit" class="submit-button button">Get My Solution</button>
    </div>
</form>