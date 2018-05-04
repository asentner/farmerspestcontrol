<script id="review_link_row" type="text/x-jsrender">
    <tr class="link-row" id="{{:id}}">
        <td>
            <div class="form-item form-type-checkbox form-item-nodes-82">
             <input id="{{:id}}-enabled" value="1" class="form-checkbox enabled-check" type="checkbox" {{if enabled}} checked="checked"{{/if}}>
            </div>
        </td>
        <td>
            {{if default}}
                <h2>{{:title}}</h2>
                <input type="hidden" id="{{:id}}-title" value="{{:title}}">
                <input type="hidden" id="{{:id}}-class" value="{{:class}}">
                <input type="hidden" id="{{:id}}-default" value="1">
            {{else}}
                <input type="hidden" id="{{:id}}-default" value="0">
                <div class="form-item form-type-text form-item-type" style="display: block;">
                    <input id="{{:id}}-title" value="{{:title}}" class="form-text required machine-name-source" type="text">
                    <span class="field-suffix"><small id="{{:id}}-class-machine" style="display: inline;"> <span class="machine-name-label">Machine name:</span> <span class="machine-name-value">{{:class}}</span> <span class="admin-link"><a href="#">Edit</a></span></small></span>
                </div>
                <div class="form-item form-type-machine-name form-item-type" style="display: none;">
                    <label for="edit-type">Machine-readable name <span class="form-required" title="This field is required.">*</span></label>
                    <input dir="ltr" id="{{:id}}-class" class="form-text required machine-name-target" type="text" value="{{:class}}">
                </div>
            {{/if}}
        </td>
        <td>
            <div class="form-item form-type-text form-item-type" style="display: block;">
                <input id="{{:id}}-link" size="60" class="form-text" type="text" value="{{:link}}">
            </div>
        </td>
        <td>
            {{if !default}}
                <div class="remove-condition">
                    <input type="button" value="Remove" class="removeRow" data-id="{{:id}}">
                </div>
            {{/if}}
        </td>
    </tr>
</script>
<h1>External Review Settings</h1>

<table id="reviewTable" class="sticky-enabled table-select-processed tableheader-processed sticky-table">
    <thead>
        <tr>
            <th>
                Enabled
            </th>
            <th>
                Review Site Name
            </th>
            <th>
                Review Site Url
            </th>
            <th>

            </th>
        </tr>
    </thead>
    <tbody id="table-body">

    </tbody>
</table>

<?php print drupal_render($form); ?>