<style>
    #rollout h2 {
        margin-top: 20px;
    }
    .form-wrap {
        margin-top: 30px;
    }
</style>

<div id="content">
    <h1>Sprowt Rollout</h1>

    <p>These nodes will be pulled in on a Sprowt roll out. Add/remove nodes below and save to edit this list.</p>

    <div id="selectFormWrap"></div>
    <div id="rollout"></div>

    <script id="selectForm" type="text/x-jsrender">
        <div class="select-form">
            <label for="selectNodes">Add Nodes</label>
            <select id="selectNodes" class="form-select" multiple>
                {^{for options}}
                    <option value="{{:value}}">{{:text}}</option>
                {{/for}}
            </select>
            <button type="button" id="addNodes">Add</button>
        </div>
    </script>

    <script id="typeTable" type="text/x-jsrender">
        <h2>{^{> type_name }} Nodes</h2>
        <table class="node-table">
            <thead>
                <tr>
                    <th>Title</th>
                    <th>Status</th>
                    <th>Operations</th>
                </tr>
            </thead>
            <tbody>
                {^{for nodes}}
                    <tr>
                        <td><a href="/node/{{:nid}}">{{> title }}</a></td>
                        <td>{{if status == '1'}}published{{else}}not published{{/if}}</td>
                        <td><a href="/node/{{:nid}}">View</a> | <a href="/node/{{:nid}}/edit">Edit</a> | <a href="#" class="remove-node" data-uuid="{{:uuid}}">Remove</a></td>
                    </tr>
                {{/for}}
            </tbody>
        </table>
    </script>

    <div class="form-wrap">
        <?php print render($form); ?>
    </div>

</div>