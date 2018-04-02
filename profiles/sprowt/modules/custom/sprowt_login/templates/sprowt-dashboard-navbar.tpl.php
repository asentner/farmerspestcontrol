<?php
$logo_parts = explode('.', basename($logo));
$ext = array_pop($logo_parts);
if($ext == 'svg') {
    $logo_html = file_get_contents(DRUPAL_ROOT . $logo);
}
else {
    $logo_html = '<img src="'.$logo.'" alt="Sprowt">';
}
?>
<div id="sprowt-dashboard-nav">
    <div class="interior">
        <div class="logo">
            <?php print $logo_html; ?>
        </div>
        <?php if(!empty($nav_links)): ?>

            <nav class="sprowt-dashboard-nav">
                <a href="#" class="sprowt-dashboard-nav-mobile-toggle"><i class="fa fa-bars"></i><span class="sr-only">Menu</span></a>
                <ul>
                <?php foreach($nav_links as $link): ?>
                    <?php if(!empty($link['url_attr'])) {
                        $url = url($link['url'], $link['url_attr']);
                    }
                    else {
                        $url = url($link['url']);
                    }

                    $attr = '';
                    if(!empty($link['attr'])) {
                        $attr = array();
                        foreach($link['attr'] as $k => $v) {
                            $attr[] = "$k=\"$v\"";
                        }
                        $attr = " " . implode(" ", $attr);
                    }
                    ?>
                    <li><a href="<?php print $url; ?>"<?php print $attr; ?>><?php print $link['title']; ?></a></li>
                <?php endforeach; ?>
                </ul>
            </nav>
        <?php endif; ?>
    </div>
</div>