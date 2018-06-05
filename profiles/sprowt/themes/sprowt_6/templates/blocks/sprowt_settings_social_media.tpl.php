<ul>
  <?php if ($fbook = variable_get('sprowt_settings_facebook_url', FALSE)) : ?>
  <li>
    <a class="facebook" href="<?php print $fbook; ?> " target="_blank">
      <i class="fa fa-fw fa-facebook"></i>
      <span class="social-description social-description-facebook">
        <?php
          print variable_get('sprowt_settings_facebook_description', FALSE) ? variable_get('sprowt_settings_facebook_description', FALSE) : "Facebook";
        ?>
      </span>
    </a>
  </li>
  <?php endif; ?>
  <?php if ($twitter = variable_get('sprowt_settings_twitter_handle', FALSE)) : ?>
  <li>
    <a class="twitter" href="http://www.twitter.com/<?php print $twitter; ?> " target="_blank">
      <i class="fa fa-fw fa-twitter"></i>
      <span class="social-description social-description-twitter">
        <?php
          print variable_get('sprowt_settings_twitter_description', FALSE) ? variable_get('sprowt_settings_twitter_description', FALSE) : "Twitter";
        ?>
      </span>
    </a>
  </li>
  <?php endif; ?>
    <?php if ($instagram= variable_get('sprowt_settings_instagram_handle', FALSE)) : ?>
        <li>
            <a class="instagram" href="http://www.instagram.com/<?php print $instagram; ?> " target="_blank">
                <i class="fa fa-fw fa-instagram"></i>
                <span class="social-description social-description-instagram">
        <?php
        print variable_get('sprowt_settings_instagram_description', FALSE) ? variable_get('sprowt_settings_instagram_description', FALSE) : "Twitter";
        ?>
      </span>
            </a>
        </li>
    <?php endif; ?>
  <?php if ($gplus = variable_get('sprowt_settings_gplus_url', FALSE)) : ?>
    <li>
      <a class="gplus" href="<?php print $gplus; ?> " target="_blank">
        <i class="fa fa-fw fa-google-plus"></i>
        <span class="social-description social-description-gplus">
          <?php
            print variable_get('sprowt_settings_gplus_description', FALSE) ? variable_get('sprowt_settings_gplus_description', FALSE) : "Google+";
          ?>
        </span>
      </a>
    </li>
  <?php endif; ?>
  <?php if ($linkedin = variable_get('sprowt_settings_linkedin_url', FALSE)) : ?>
  <li>
    <a class="linkedin" href="<?php print $linkedin; ?> " target="_blank">
      <i class="fa fa-fw fa-linkedin"></i>
      <span class="social-description social-description-linkedin">
        <?php
          print variable_get('sprowt_settings_linkedin_description', FALSE) ? variable_get('sprowt_settings_linkedin_description', FALSE) : "LinkedIn";
        ?>
      </span>
    </a>
  </li>
  <?php endif; ?>
</ul>
