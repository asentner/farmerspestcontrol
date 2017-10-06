<table>
    <thead>
        <tr>
            <th>Field Name</th>
            <th>Value</th>
        </tr>
    </thead>
    <tbody>
        <?php $i = 0; foreach($fields as $name => $value): ?>
            <tr class="<?php print ($i % 2 == 0) ? 'even' : 'odd';  ++$i?>">
                <td><strong><?php print $name; ?></strong></td>
                <td><pre><?php print $value; ?></pre></td>
            </tr>
        <?php endforeach; ?>
    </tbody>
</table>
<form action="/admin/survey/<?php print $token; ?>/delete">
    <div class="form-actions form-wrapper" id="edit-actions">
        <input id="edit-delete" name="op" value="Delete" class="form-submit" type="submit">
    </div>
</form>