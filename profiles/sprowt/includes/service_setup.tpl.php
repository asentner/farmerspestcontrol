<script id="newService" type="text/x-jsrender">
    <li class="service" id="{{:id}}">
        <input data-serviceid="{{:id}}" class="serviceName form-text" type="text" placeholder="Service Name" value="{{:serviceName}}">
        {{if addRemove}}
        <button type="button" class="removeService button" data-serviceid="{{:id}}">Remove</button>
        {{/if}}
    </li>
</script>

<ul id="services">
    
</ul>
<button type="button" class="button" id="addService">Add Another Service</button>
<button type="button" class="button" id="bulkAddServices">Bulk Add Services</button>
<div id="bulk-services-form" style="display:none;">
    <h3>Add Services. One per line</h3>
    <div><textarea id="bulkServiceAddArea" rows="10" style="width: 100%;"></textarea></div>
    <button type="button" class="button" id="bulkAddServicesSubmit">Add Services</button>
</div>