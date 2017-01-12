<script id="newLocation" type="text/x-jsrender">
    <li class="location" id="{{:id}}">
        <div class="field-wrap">
            <label for="{{:id}}-name">*Location Name:</label>
            <input type="text" class="name form-text" id="{{:id}}-name" value="{{:name}}">
        </div>
        <div class="field-wrap">
            <label for="{{:id}}-address">*Street Address:</label>
            <input type="text" class="address form-text" id="{{:id}}-address" value="{{:address}}">
        </div>
        <div class="field-wrap">
            <label for="{{:id}}-city">*Locality:</label>
            <input type="text" class="city form-text" id="{{:id}}-city" value="{{:city}}">
        </div>
        <div class="field-wrap">
            <label for="{{:id}}-state">*State or Provence:</label>
            <input type="text" class="state form-text" id="{{:id}}-state" value="{{:state}}" maxlength="2">
        </div>
        <div class="field-wrap">
            <label for="{{:id}}-zip">*Postal code:</label>
            <input type="text" class="zip form-text" id="{{:id}}-zip" value="{{:zip}}">
        </div>
        <div class="field-wrap">
            <label for="{{:id}}-phone">*Phone:</label>
            <input type="text" class="phone form-text" id="{{:id}}-phone" value="{{:phone}}">
        </div>
        <div class="field-wrap">
            <label for="{{:id}}-email">Email Address:</label>
            <input type="text" class="email form-text" id="{{:id}}-email" value="{{:email}}">
        </div>
        <div class="field-wrap">
            <label for="{{:id}}-gplus">Google Plus URL:</label>
            <input type="text" class="gplus form-text" id="{{:id}}-gplus" value="{{:gplus}}">
        </div>
        {{if remove}}
        <button class="button removeLocation" data-location-id="{{:id}}">Remove</button>
        {{/if}}
    </li>
</script>


<div id="location-selector">
    <button type="button" id="addLocation" class="button">Add Another Location</button>
    <ul id="locations"></ul>
</div>