<div class="l-page">
  <div class="header-wrap">
    <header class="l-header" role="banner">
      <div class="l-branding">
        <?php if ($logo): ?>
          <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="site-logo"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" /></a>
        <?php endif; ?>
    
        <?php if ($site_name || $site_slogan): ?>
          <?php if ($site_name): ?>
            <h1 class="site-name">
              <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
            </h1>
          <?php endif; ?>
    
          <?php if ($site_slogan): ?>
            <h2 class="site-slogan"><?php print $site_slogan; ?></h2>
          <?php endif; ?>
        <?php endif; ?>
    
        <?php print render($page['branding']); ?>
      </div>
    
      <?php print render($page['header_first']); ?>
      <?php print render($page['header_second']); ?>
      <?php print render($page['header_third']); ?>
    
      <?php print render($page['navigation']); ?>
    </header>
  </div>

  <div class="l-preface">
    <?php print render($page['preface_first']); ?>
    <?php print render($page['preface_second']); ?>
    <?php print render($page['preface_third']); ?>
  </div>

  <div class="l-breadcrumb">
    <?php print $breadcrumb; ?>
  </div>

  <div class="l-main">
    <div class="l-content" role="main">
      <a id="main-content"></a>
      <?php print $messages; ?>
      <?php print render($tabs); ?>
      <?php if ($action_links): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <?php print render($page['content']); ?>
      <?php print $feed_icons; ?>
    </div>

    <?php print render($page['sidebar_first']); ?>
    <?php print render($page['sidebar_second']); ?>
  </div>

  <div class="l-postscript">
    <?php print render($page['postscript_first']); ?>
    <?php print render($page['postscript_second']); ?>
    <?php print render($page['postscript_third']); ?>
  </div>

  <footer class="l-footer" role="contentinfo">
    <div class="l-region--footer-first--wrap"><?php print render($page['footer_first']); ?></div>
    <div class="l-region--footer-second--wrap"><?php print render($page['footer_second']); ?></div>
    <div class="l-region--footer-third--wrap"><?php print render($page['footer_third']); ?></div>
  </footer>
</div>
