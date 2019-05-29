(function($){

    var allNodes = [];
    var uuids = [];
    var options = {};


    var optionData = {
        options: options
    };

    var tables = [];

    var buildSelectOptions = function() {
        options = [];
        $.each(allNodes, function(i, node){
            if(uuids.indexOf(node.uuid) < 0) {
                options.push({
                    value: node.uuid,
                    text: node.type_name + ' -- ' + node.title + ' (' + node.nid + ')'
                });
            }
        });

        options.sort(function(a, b) {
            if(a.text === b.text) {
                return 0;
            }
            else {
                return a.text < b.text ? -1 : 1;
            }
        });

        $.observable(optionData).setProperty('options', options);
        $('#selectNodes').select2();
    };

    var buildTables = function() {
        var nodes = allNodes.filter(function(node){
            if(uuids.indexOf(node.uuid) >= 0) {
                return true;
            }
        });

        var tableTypesSet = [];
        var newTables = [];

        $.each(nodes, function(i, node) {
            if(tableTypesSet.indexOf(node.type) < 0) {
                tableTypesSet.push(node.type);
                newTables.push({
                    type: node.type,
                    type_name: node.type_name,
                    nodes: []
                });
            }

            var table = newTables.find(function(tab) {
               return tab.type === node.type;
            });

            var i = newTables.indexOf(table);

            var inNodes = table.nodes.some(function(n) {
                return n.uuid === node.uuid;
            });

            if(!inNodes) {
                newTables[i].nodes.push(node);
            }
        });

        return newTables;
    }

    $(document).ready(function() {
        allNodes = JSON.parse($('#all-nodes').val());
        uuids = JSON.parse($('#rollout-uuids').val());

        tables = buildTables();

        $.templates('#selectForm').link('#selectFormWrap', optionData);

        $.templates('#typeTable').link('#rollout', tables);

        buildSelectOptions();

        $(document).on('click', '#addNodes', function(){
            var data = $('#selectNodes').select2('data');
            $.each(data, function(i,v) {
                uuids.push(v.id);
            });

            $('#rollout-uuids').val(JSON.stringify(uuids));
            $('#selectNodes').val('');
            buildSelectOptions();
            $.observable(tables).refresh(buildTables());
        });

        $(document).on('click', '.remove-node', function(e){
            e.preventDefault();

            var i = uuids.indexOf($(this).data('uuid'));

            if(i >= 0) {
                uuids.splice(i, 1);

                $('#rollout-uuids').val(JSON.stringify(uuids));
                buildSelectOptions();
                $.observable(tables).refresh(buildTables());
            }
        });
    });

})(jQuery);