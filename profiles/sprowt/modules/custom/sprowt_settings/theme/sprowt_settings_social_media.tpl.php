<?php $accounts = _sprowt_settings_get_social_media_accounts(); ?>
<ul>
    <?php foreach($accounts as $account): ?>
        <?php if($account['type'] == 'twitter'): ?>
            <li>
                <a class="twitter" href="http://www.twitter.com/<?php print $account['link']; ?> " target="_blank">
                    <i class="fa fa-fw fa-twitter"></i>
                    <span class="social-description social-description-twitter">
                        <?php
                            print !empty($account['description']) ? $account['description'] : $account['name'];
                        ?>
                    </span>
                </a>
            </li>
        <?php elseif ($account['type'] == 'instagram'): ?>
            <li>
                <a class="instagram" href="http://www.instagram.com/<?php print $account['link']; ?> " target="_blank">
                    <i class="fa fa-fw fa-instagram"></i>
                    <span class="social-description social-description-instagram">
                        <?php
                            print !empty($account['description']) ? $account['description'] : $account['name'];
                        ?>
                    </span>
                </a>
            </li>
        <?php else: ?>
            <li>
                <a class="<?php print $account['machineName']; ?>" href="<?php print url($account['link']); ?> " target="_blank">
                    <i class="fa fa-fw fa-<?php print !empty($account['iconClass']) ? $account['iconClass'] : 'link'; ?>"></i>
                    <span class="social-description social-description-<?php print $account['machineName']; ?>">
                        <?php
                            print !empty($account['description']) ? $account['description'] : $account['name'];
                        ?>
                    </span>
                </a>
            </li>
        <?php endif; ?>
    <?php endforeach; ?>
</ul>
