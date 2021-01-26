<?php
$ebooking = false;
if(!empty($node->field_ebooking) && $node->field_ebooking['und'][0]['value'] == 'yes') {
  $ebooking = true;
};
?>

<div class="l-page">

  <header class="l-header">
    <div class="header-first-wrap">
      <?php print render($page['header_first']); ?>
    </div>
    <?php print render($page['header_second']); ?>
    <div class="header-third-wrap">
      <?php print render($page['header_third']); ?>
    </div>
    <div class="header-fourth-wrap">
      <?php print render($page['header_fourth']); ?>
    </div>
  </header>

  <div class="l-preface">
    <?php print render($page['preface_first']); ?>
    <?php print render($page['preface_second']); ?>
    <?php print render($page['preface_third']); ?>
    <?php print render($page['preface_fourth']); ?>
  </div>

  <!-- <?php if(!$ebooking): ?>
    <div class="l-breadcrumb">
      <?php print $breadcrumb; ?>
    </div>
  <?php endif; ?> -->

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

    <!-- <?php if(!$ebooking) {
      print render($page['sidebar']);
    };
    ?> -->
  </div>

  <div class="l-postscript">
    <?php print render($page['postscript_first']); ?>
    <div class="l-wrap--postscript-second">
      <?php print render($page['postscript_second']); ?>
    </div>
    <?php print render($page['postscript_third']); ?>
    <div class="postscript-fourth-wrap">
      <?php print render($page['postscript_fourth']); ?>
    </div>
    <?php print render($page['postscript_fifth']); ?>
  </div>

  <footer class="l-footer">
    <div class="footer-wrap">
      <?php print render($page['footer_first']); ?>
      <?php print render($page['footer_second']); ?>
    </div>
    <?php print render($page['footer_third']); ?>
    <?php print render($page['footer_fourth']); ?>
  </footer>

</div>
