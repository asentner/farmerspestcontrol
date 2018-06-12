<script id="newRegion" type="text/x-jsrender">
    <li class="region" id="{{:id}}">
        <input data-regionId="{{:id}}" class="regionName form-text" type="text" placeholder="Region Name" value="{{:regionName}}">
        <button type="button" class="addMarket button" data-regionid="{{:id}}">Add Market</button>
        <button type="button" class="addMarketBulk button" data-regionid="{{:id}}">Bulk Add Markets</button>
        <div class="marketBulkWrap" style="display:none;">
            <h3>Add Markets. One per line.</h3>
            <div><textarea rows="10" class="marketBulkText" style="width: 100%;"></textarea></div>
            <button type="button" class="addMarketBulkSubmit button" data-regionid="{{:id}}">Add Markets</button>
        </div>
        {{if addRemove}}
        <button type="button" class="removeRegion button" data-regionid="{{:id}}">Remove</button>
        {{/if}}
        <ul class="region-markets"></ul>
    </li>
</script>

<script id="newMarket" type="text/x-jsrender">
    <li class="market" id="{{:marketId}}" data-regionId="{{:regionId}}">
        <input class="marketName form-text" type="text" placeholder="Market Name" value="{{:marketName}}">
        <button type="button" class="removeMarket button" data-regionid="{{:regionid}}">Remove</button>
    </li>
</script>

<div id="region-market-selector">
    <ul id="regions"></ul>
    <button type="button" id="addRegion" class="button">Add Another Region</button>
</div>