<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
    <?php $rating = 0;
    foreach ($items as $delta => $item) {
        $item = render($item);
        $rating += $item;
    }
    
    ?>
  <?php if (!$label_hidden): ?>
    <div class="field-label"<?php print $title_attributes; ?>><?php print $label ?>:&nbsp;</div>
  <?php endif; ?>
  <div class="field-items"<?php print $content_attributes; ?>>
      <div class="star-label">
          <span itemprop="ratingValue"><?php print $rating; ?></span> Star Rating
      </div>
      <div class="stars">
          <?php $starRating = $rating; ?>
          <?php for($i = 1; $i <= 5; ++$i): ?>
            <?php if($starRating > 0): ?>
                <?php if($starRating < 1): ?>
                  <?php if($starRating <= 0.74): ?>
                        <i class="fa fa-star-half"></i>
                  <?php else: ?>
                      <i class="fa fa-star"></i>
                  <?php endif; ?>
                <?php else: ?>
                    <i class="fa fa-star"></i>
                <?php endif; ?>
            <?php endif; ?>
            <?php $starRating = $starRating - 1; ?>
          <?php endfor; ?>
      </div>
  </div>
</div>