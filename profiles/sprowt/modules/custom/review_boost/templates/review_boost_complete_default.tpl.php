<?php if ($request_review): ?>

    <p>If you want to tell the world about your great experience, here are some links to where you can leave us a
        review. We would really appreciate it!</p>
    <p>For your convenience, your helpful review is provided below:</p>
    <blockquote>
        %comments
    </blockquote>

    <p>
        <?php if(!empty($gplus_url)): ?>
            <a href="<?php echo $gplus_url.'?review=1'; ?>">Google+</a><br/>
        <?php endif; ?>
        <?php if(!empty($bbb_url)): ?>
            <a href="<?php echo $bbb_url; ?>">Better Business Bureau</a>
        <?php endif; ?>
    </p>
    <p>Have a great day.<br>%company_name<br>%street %street2<br>%locality, %province %postal_code<br>%company_phone</p>



<?php else: ?>
    <p>We work on improving our services every day, and your feedback helps us immensely.</p>

    <p>If you’d like to contact us with any further questions, please email <a href="mailto:%site_email">%site_email</a>.</p>

    <p>Sincerely,<br>%company_name<br>%street %street2<br>%locality, %province %postal_code<br>%company_phone</p>

<?php endif ?>
