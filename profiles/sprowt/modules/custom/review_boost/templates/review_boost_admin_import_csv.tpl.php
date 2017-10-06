<h1>Review Boost Import CSV</h1>
<p>The ReviewBoost module allows you to upload your CSV of service calls and have customer survey emails automatically generated and sent to your customers.</p>
<h2>How it works:</h2>
<p><strong>Step 1:</strong> Upload your CSV of the latest service calls. We recommend uploading them daily, but the CSV can cover any time period. The columns need to match these exactly:</p>
<ol>
    <li>customer_id</li>
    <li>customer_first_name</li>
    <li>customer_last_name</li>
    <li>customer_email</li>
    <li>customer_phone</li>
    <li>technician</li>
    <li>sales</li>
    <li>branch</li>
    <li>service</li>
    <li>service_date</li>
</ol>

<p>An example CSV can be found here. It includes the column headers and a row of example data.</p>

<p><strong>Step 2:</strong> The customer surveys will be sent out within the hour (if the CSV is especially large, it may take an extra hour or two). The customer survey is a single question that asks the customer to rate the quality of their service on a scale of one to five.</p>

<p><strong>Step 3:</strong> If they respond with a rating of 3 or higher, they will be taken to a page with links to your local review sites and will be asked to leave a review. If they respond with a rating less than that, they will be shown a message that says they will be contacted in the next 24 hours by the business to resolve their concerns.</p>

<p><strong>Step 4:</strong> Whenever a survey is completed, the business owner will receive an email with a copy of it. They can reach out to the customer if the survey was not positive, or just keep it for their records.</p>

<?php print drupal_render($form); ?>
<?php echo drupal_render(drupal_get_form('_review_boost_admin_send_surveys_form')); ?>
