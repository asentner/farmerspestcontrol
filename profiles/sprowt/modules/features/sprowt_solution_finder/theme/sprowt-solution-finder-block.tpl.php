<?php
    $shown_terms = array();
    $hidden_terms = array();

    foreach($terms as $term) {
        if($shown) {
            $shown_terms[] = $term;
            --$shown;
        }
        else {
            $hidden_terms[] = $term;
        }
    }
?>
<form id="<?php print $form_id; ?>" class="solution-finder-form" action="/solution-finder">
    <div id="shown" class="terms-wrapper">
        <?php foreach($shown_terms as $term): ?>
            <div class="term-wrap">
                <label for="term-<?php print $term['tid']; ?>">
                    <input type="checkbox" name="concerns[]" id="term-<?php print $term['tid']; ?>" value="<?php print $term['tid']; ?>">
                    <?php print render($term['icon']); ?>
                    <div class="name"><?php print $term['name']; ?></div>
                </label>
            </div>
        <?php endforeach; ?>
    </div>
    <?php if (!empty($hidden_terms)): ?>
        <div id="hidden" class="terms-wrapper" style="display:none;">
            <?php foreach($hidden_terms as $term): ?>
                <div class="term-wrap">
                    <label for="term-<?php print $term['tid']; ?>">
                        <input type="checkbox" name="concerns[]" id="term-<?php print $term['tid']; ?>" value="<?php print $term['tid']; ?>">
                        <?php print render($term['icon']); ?>
                        <div class="name"><?php print $term['name']; ?></div>
                    </label>
                </div>
            <?php endforeach; ?>
        </div>
    <?php endif; ?>
    <div class="actions">
        <?php if (!empty($hidden_terms)): ?>
            <a href="#" class="show-hide-button button">More Options</a>
        <?php endif; ?>
        <input type="submit" class="submit-button button" value="Get My Solution">
    </div>
</form>