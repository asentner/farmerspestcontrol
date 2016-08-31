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