<div class="l-page">
  <header class="l-header">
    <?php print render($page['header_first']); ?>
  </header>
  <div class="l-main">
    <div class="l-content">
      <a id="main-content"></a>
      <?php print $messages; ?>
      <?php print render($tabs); ?>
      <?php if ($action_links): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <?php print render($page['content']); ?>
      <?php print $feed_icons; ?>
    </div>
  </div>

  <div class="l-postscript">
    <div class="l-wrap--postscript-first">
      <?php if (drupal_is_front_page() && isset($background_image)): ?>
        <div class="l-background--postscript-first" style="background-image:url('<?php print $background_image; ?>');"></div>
      <?php endif; ?>
      <?php print render($page['postscript_first']); ?>
    </div>
    <?php print render($page['postscript_second']); ?>
    <?php print render($page['postscript_third']); ?>
    <?php print render($page['postscript_fourth']); ?>
  </div>

  <div class="l-footer-wrap">
    <footer class="l-footer">
      <?php print render($page['footer_first']); ?>
      <?php print render($page['footer_second']); ?>
      <?php print render($page['footer_third']); ?>
    </footer>
  </div>

</div>
