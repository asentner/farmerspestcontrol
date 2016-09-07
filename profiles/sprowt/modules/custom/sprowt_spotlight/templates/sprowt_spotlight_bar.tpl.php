<div class="spot-bar">
    <div class="spot-bar-content">
        <div class="logo spot-item">
            <i class="cm-logo"></i>
            <span class="label">
                <span class="head">
                    sprowt&trade; REPORT
                </span>
                <span class="sub">
                    30 day lookback
                </span>
            </span>
        </div>
        <div class="sessions spot-item">
            <i class="fa fa-smile-o"></i>
            <span class="label">
                <span class="head data data-sessions">
                    <?php print number_format($data['sessions']['total']); ?>
                </span>
                <span class="sub">
                    Sessions
                </span>
            </span>
        </div>
        <div class="pageviews spot-item">
            <span class="fa-stack">
                <i class="fa fa-file-o fa-flip-horizontal"></i>
                <i class="fa fa-file-o fa-flip-horizontal"></i>
            </span>
            <span class="label">
                <span class="head data data-pageviews">
                    <?php print number_format($data['pageViews']['total']); ?>
                </span>
                <span class="sub">
                    Pageviews
                </span>
            </span>
        </div>
        <div class="leads spot-item">
            <i class="fa fa-trophy"></i>
            <span class="label">
                <span class="head data data-leads">
                    <?php print number_format($data['leads']['total']['total']); ?>
                </span>
                <span class="sub">
                    Leads
                </span>
            </span>
        </div>
        <div class="coversion-rate spot-item">
            <i class="fa fa-pie-chart"></i>
            <span class="label">
                <span class="head data data-conversion-rate">
                    <?php print $data['conversionRates']['total']; ?>
                </span>
                <span class="sub">
                    Conversion Rate
                </span>
            </span>
        </div>
        <div class="cost-per-lead spot-item">
            <i class="fa fa-usd "></i>
            <span class="label">
                <span class="head data data-cost-per-lead">
                    <?php print $data['costPerLead']['total']; ?>
                </span>
                <span class="sub">
                    Cost Per Lead
                </span>
            </span>
        </div>
    </div>
</div>