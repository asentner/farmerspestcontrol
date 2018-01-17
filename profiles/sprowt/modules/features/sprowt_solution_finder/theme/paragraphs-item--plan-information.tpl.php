<?php

/**
 * @file
 * Default theme implementation for a single paragraph item.
 *
 * Available variables:
 * - $content: An array of content items. Use render($content) to print them
 *   all, or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity
 *   - entity-paragraphs-item
 *   - paragraphs-item-{bundle}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened into
 *   a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
?>
<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="content"<?php print $content_attributes; ?>>
      <div class="header">
          <?php print render($content['field_icon_file']); ?>
          <div class="header-intro">
              <?php print render($content['field_header']); ?>
              <?php print render($content['field_intro']); ?>
          </div>
      </div>
      <div class="body-content">
          <?php print render($content['body_text']); ?>
          <?php if(!empty($field_plan_features_header) || !empty($field_plan_features)): ?>
              <div class="features">
                  <?php print render($content['field_plan_features_header']); ?>
                  <?php print render($content['field_plan_features']); ?>
              </div>
          <?php endif; ?>
      </div>
    <?php print render($content); ?>
  </div>
</div>