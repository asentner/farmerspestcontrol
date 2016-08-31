<div class="l-page">
  <header class="l-header" style="background-image:url('<?php print file_create_url($node->field_image['und'][0]['uri']); ?>');">
    <?php print render($page['header_first']); ?>
    <?php print render($page['header_second']); ?>
    <?php print render($page['header_third']); ?>
  </header>

  <div class="l-preface">
    <?php print render($page['preface_first']); ?>
    <?php print render($page['preface_second']); ?>
    <?php print render($page['preface_third']); ?>
  </div>

  <div class="breadcrumb-wrap"><?php print $breadcrumb; ?></div>

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

    <?php print render($page['sidebar']); ?>
  </div>

  <div class="l-postscript">
    <?php print render($page['postscript_first']); ?>
    <?php print render($page['postscript_second']); ?>
    <?php print render($page['postscript_third']); ?>
  </div>

  <footer class="l-footer">
    <?php print render($page['footer_first']); ?>
    <?php print render($page['footer_second']); ?>
    <?php print render($page['footer_third']); ?>
  </footer>
</div>
