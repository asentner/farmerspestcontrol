<?php if ($request_review): ?>

    <p>If you want to tell the world about your great experience, here are some links to where you can leave us a
        review. We would really appreciate it!</p>
    <p>For your convenience, your helpful review is provided below:</p>
    <blockquote>
        %comments
    </blockquote>

    <p>
        %review_links
    </p>
    <p>Have a great day.<br>%company_name<br>%street %street2<br>%locality, %province %postal_code<br>%company_phone</p>



<?php else: ?>
    <p>We work on improving our services every day, and your feedback helps us immensely.</p>

    <p>If you’d like to contact us with any further questions, please email <a href="mailto:%admin_email">%admin_email</a>.</p>

    <p>Sincerely,<br>%company_name<br>%street %street2<br>%locality, %province %postal_code<br>%company_phone</p>

<?php endif ?>
