<?php 
hide($content['field_expiration_date']); 
hide($content['field_image']); 

// extract numbers
$original = filter_var(render($content['field_original_price']), FILTER_SANITIZE_NUMBER_INT);
$offer = filter_var(render($content['field_offer_price']), FILTER_SANITIZE_NUMBER_INT);
?>
<article<?php print $attributes; ?>>
  <?php print render($content['field_image']); ?>
  <div class="node-content-wrap">
    <?php if (!empty($title_prefix) || !empty($title_suffix) || !$page): ?>
      <header>
        <?php print render($title_prefix); ?>
        <?php if (!$page): ?>
          <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
        <?php endif; ?>
        <?php print render($title_suffix); ?>
      </header>
    <?php endif; ?>

    <?php if ($display_submitted): ?>
      <footer class="node__submitted">
        <?php print $user_picture; ?>
        <p class="submitted"><?php print $submitted; ?></p>
      </footer>
    <?php endif; ?>

    <div<?php print $content_attributes; ?>>
      <?php
        // We hide the comments and links now so that we can render them later.
        hide($content['comments']);
        hide($content['links']);
        print render($content);
      ?>
      <?php // special offer pricing, difference, etc. ?>

      <div class="offer-pricing">
        <?php if($content['field_original_price'][0]): ?>
          <div class="offer-pricing-original">
            <del>$<?php print $original; ?></del>
          </div>
        <?php endif; ?>
        <?php if($content['field_offer_price'][0]): ?>
          <div class="offer-pricing-offer">
            $<?php print $offer; ?>
          </div>
        <?php endif; ?>
        <?php if($content['field_original_price'][0] && $content['field_offer_price'][0]): ?>
          <div class="offer-pricing-savings">
            $<?php print ($original - $offer); ?> off
          </div>
        <?php endif; ?>
      </div>
      <?php // only show exp. date if it's filled out; otherwise, show end of month ?>
      <?php if(isset($content['field_expiration_date'][0])): ?>
        <div class="field--name-field-expiration-date">
          <?php print render($content['field_expiration_date']); ?>
        </div>
      <?php else: ?>
        <div class="field--name-field-expiration-date">
          Expires: <?php print date("F t, Y"); ?>
        </div>
      <?php endif; ?>
    </div>

    <?php print render($content['links']); ?>
    <?php print render($content['comments']); ?>
  </div>
</article>
