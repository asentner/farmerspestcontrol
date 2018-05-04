<?php
$headers = array(
    'customer_id',
    'customer_first_name',
    'customer_last_name',
    'customer_email',
    'customer_phone',
    'technician',
    'sales',
    'branch',
    'service',
    'service_date'
);
?>
<h1>Review Boost Import CSV</h1>
<p>Here is a preview of the data being imported:</p>
<table id="import-confirm-table" class="sticky-enabled table-select-processed tableheader-processed sticky-table">
    <thead>
    <tr>
        <?php foreach($headers as $header): ?>
            <th><?php print $header; ?></th>
        <?php endforeach; ?>
    </tr>
    </thead>
    <tbody id="table-body">
        <?php foreach($test_data as $row): ?>
            <tr>
                <?php foreach($headers as $header): ?>
                    <?php if($header != 'service_date'): ?>
                        <td><?php print $row[$header]; ?></td>
                    <?php else: ?>
                        <td><?php print $row[$header]->format('m/d/Y'); ?></td>
                    <?php endif; ?>
                <?php endforeach; ?>
            </tr>
        <?php endforeach; ?>
    </tbody>
</table>

<h2>Would you like to continue with the import?</h2>
<?php print drupal_render($form); ?>