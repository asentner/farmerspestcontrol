<?php
$filters = array(
    'survey_score' => 'Survey Rating',
    'survey_completed' => 'Survey Completed',
    'survey_sent' => 'Survey Sent',
    'service_date' => 'Service Date',
    'branch' => 'Branch',
    'technician' => 'Technician',
    'sales' => 'Sales Person',
    'service' => 'Service',
    'customer_id' => 'Customer ID',
    'first_name' => 'Customer First Name',
    'last_name' => 'Customer Last Name'
);
?>
<div class="top-wrap">
    <div class="all-filter-wrap">
        <h2>Filters</h2>
        <div id="current-filters"></div>
        <div class="filter-select">
            <select id="filter-select">
                <option value="none">None</option>
                <?php foreach($filters as $key => $text): ?>
                    <option value="<?php print $key; ?>"><?php print $text; ?></option>
                <?php endforeach; ?>
            </select>
            <input type="hidden" id="current-filters-hidden" value="[]">
        </div>
        <div class="filters" style="display:none;">
            <?php foreach($filters as $key => $text): ?>
            <div id="filter-<?php print $key; ?>" data-filter="<?php print $key; ?>" class="filter-wrap" style="display:none;">
                <strong class="title"><?php print $text; ?>:</strong>
                <?php switch($key){
                    case 'survey_completed':
                    case 'survey_sent':
                    case 'service_date': ?>
                        <div data-filter-type="date" class="filter-val">
                            <select class="date-type">
                                <option value="all">All Time</option>
                                <option value="7">Last 7 Days</option>
                                <option value="30">Last 30 Days</option>
                                <option value="custom">Custom</option>
                            </select>
                            <div class="custom-range" style="display:none;">
                                <label>
                                    <strong>From: </strong>
                                    <input type="text" class="datepick form-text from">
                                </label>
                                <label>
                                    <strong>To: </strong>
                                    <input type="text" class="datepick form-text to">
                                </label>
                            </div>
                         </div>
                        <?php break; ?>
                    <?php case 'survey_score': ?>
                        <div data-filter-type="score" class="filter-val">
                            <select class="op-type">
                                <option value="eq">Equal To</option>
                                <option value="gt">Greater Than</option>
                                <option value="lt">Less Than</option>
                                <option value="gte">Greater Than Or Equal To</option>
                                <option value="lte">Less Than Or Equal To</option>
                            </select>
                            <div style="margin-left: 10px;">
                                <input type="number" class="form-text">
                            </div>
                        </div>
                        <?php break; ?>
                    <?php default: ?>
                        <div data-filter-type="text" class="filter-val">
                            <input type="text" class="form-text">
                        </div>
                <?php } ?>
            </div>
            <?php endforeach; ?>
            <button type="button" class="button" id="add-filter">Filter</button>
        </div>
    </div>

    <div class="totals">
        <ul>
            <li><strong>Total: </strong> <?php print $totals['filtered'] ?></li>
            <li><strong>All Surveys (completed/sent):</strong> <?php print $totals['completed'].'/'.$totals['sent']; ?></li>
            <li><strong>Average Score:</strong> <?php print $totals['average_score'] ?></li>
        </ul>
    </div>
</div>

<?php print $table; ?>
<div class="show-results">
    <label for="result-count" style="display: inline;">Show: </label>
    <select id="result-count">
        <option value="10">10</option>
        <option value="25">25</option>
        <option value="50">50</option>
        <option value="100">100</option>
    </select>
    <span> Results</span>
</div>
<?php print $pager; ?>