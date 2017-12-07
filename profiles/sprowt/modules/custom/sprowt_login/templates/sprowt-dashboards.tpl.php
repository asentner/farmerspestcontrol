<div id="dashboards">
    <nav id="tab-links">
        <ul>
            <?php foreach($nodes as $node): ?>
                <?php $node->title_id = drupal_html_id($node->title); ?>
                <li><a href="#<?php print $node->title_id; ?>"><?php print $node->title; ?></a></li>
            <?php endforeach; ?>
        </ul>
    </nav>
    <?php if(!empty($nodes)): ?>
    <div id="tabs">
        <?php foreach($nodes as $node): ?>
            <div class="tab" id="<?php print $node->title_id; ?>" style="display:none;">
                <?php
                    $node_view = node_view($node);
                    print render($node_view);
                ?>
            </div>
        <?php endforeach; ?>
    </div>
    <?php else: ?>
    <div class="not-found">
        <h1>No Dashboards Found At This Time</h1>
        <h2>Please add a dashboard</h2>
    </div>
    <?php endif; ?>
</div>