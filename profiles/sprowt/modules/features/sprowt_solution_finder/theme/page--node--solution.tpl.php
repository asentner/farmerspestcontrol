<?php
?>

<div class="l-page">
    
    <?php print render($tabs); ?>
    <?php if ($action_links): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
    <?php endif; ?>
    
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
    <div class="preface-third-wrap">
      <?php print render($page['preface_third']); ?>
    </div>
    <?php print render($page['preface_fourth']); ?>
  </div>

  <div class="l-main">
    <div class="l-content">
      <a id="main-content"></a>
        <?php print $messages; ?>
      <?php print render($page['content']); ?>
      <?php print $feed_icons; ?>
    </div>

    <?php if(!$ebooking) {
      print render($page['sidebar']);
    };
    ?>
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
    <div class="l-footer-wrap">
      <?php print render($page['footer_first']); ?>
      <div class="footer-wrap">
        <?php print render($page['footer_second']); ?>
        <?php print render($page['footer_third']); ?>
      </div>
    </div>
    <?php print render($page['footer_fourth']); ?>
  </footer>


</div>
