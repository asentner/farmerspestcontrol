<?php
    hide($page['content']['system_main']['nodes'][$node->nid]['field_header_paragraph']);
    hide($page['content']['system_main']['nodes'][$node->nid]['field_footer_paragraph']);
?>
<?php print render($tabs); ?>
<?php if ($action_links): ?>
    <ul class="action-links"><?php print render($action_links); ?></ul>
<?php endif; ?>
<?php print $messages; ?>
<div class="l-page">
  <header class="l-header">
      <?php print _sprowt_settings_shortcode_replace(render($page['content']['system_main']['nodes'][$node->nid]['field_header_paragraph'])); ?>
  </header>

  <div class="l-main">
    <div class="l-content">
      <a id="main-content"></a>
      <?php print render($page['content']); ?>
      <?php print $feed_icons; ?>
    </div>
  </div>

  <footer class="l-footer">
    <?php print _sprowt_settings_shortcode_replace(render($page['content']['system_main']['nodes'][$node->nid]['field_footer_paragraph'])); ?>
  </footer>
</div>
