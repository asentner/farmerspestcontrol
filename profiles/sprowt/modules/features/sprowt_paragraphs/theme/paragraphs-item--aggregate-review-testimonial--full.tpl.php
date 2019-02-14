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
<div <?php print $attributes; ?>>
    <?php print render($title_prefix); ?>
    <?php print render($title_suffix); ?>
    <div class="content"<?php print $content_attributes; ?>>
        <?php if(!empty($rating) || !empty($review_count) || !empty($icon_class)): ?>
            <header class="review-header">
                <?php if(!empty($icon_class)): ?>
                    <div class="icon-wrap">
                        <i class="fa <?php echo implode(' ', $icon_class); ?>"></i>
                    </div>
                <?php endif; ?>
                <?php if(!empty($rating) || !empty($review_count)): ?>
                    <div class="rating-wrap">
                        <div class="stars-wrap">
                            <?php if(!empty($rating)): ?>
                                <div class="stars">
                                    <?php for($i = 0; $i <= 4; ++$i): ?>
                                        <?php if($i < $rating): ?>
                                            <?php if(($i + 0.5) < $rating): ?>
                                                <i class="fa fa-star"></i>
                                            <?php else: ?>
                                                <i class="fa fa-star-half-o"></i>
                                            <?php endif; ?>
                                        <?php else: ?>
                                            <i class="fa fa-star-o"></i>
                                        <?php endif; ?>
                                    <?php endfor; ?>
                                </div>
                            <?php endif; ?>
                            <?php if(!empty($review_count)): ?>
                                <div class="review-count">
                                    <?php echo $review_count; ?> votes
                                </div>
                            <?php endif; ?>
                        </div>
                        <?php if(!empty($rating)): ?>
                            <div class="rating">
                                Rating: <?php echo $rating; ?>
                            </div>
                        <?php endif; ?>
                    </div>
                <?php endif; ?>

            </header>
        <?php endif; ?>
        <?php if(!empty($testimonial)): ?>
            <div class="testimonial">
                <?php echo $testimonial; ?>
            </div>
        <?php endif; ?>
    </div>
</div>