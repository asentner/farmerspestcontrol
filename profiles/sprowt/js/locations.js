(function($){
    $(document).ready(function(){
        
        if ($('#locations_hidden').val() != "[]") {
            var default_locations = JSON.parse($('#locations_hidden').val());
            $.each(default_locations, function(i,v){
                if (i == 0) {
                    $.locations.addLocation(v, true);
                }
                else {
                    $.locations.addLocation(v);
                }
            });
        }
        else {
            $.locations.addLocation(undefined, true);
        }
        
        if ($('#hidden_errors').val() != "") {
            $.each(JSON.parse($('#hidden_errors').val()), function(i,v){
                $(v).addClass('error');
            });
        }
        
        $('#addLocation').click(function(){
            $.locations.addLocation();
        });
        
        $('#locations').on('keyup', 'input[type="text"]', $.locations.updateLocations);
        
        $('#locations').on('click', '.removeLocation', function(){
            $(this).closest('.location').remove();
             $.locations.updateLocations();
        });
    });
    
    $.locations = {
        fields: [
            'name',
            'address',
            'city',
            'state',
            'zip',
            'phone',
            'email',
            'gplus'
        ],
        nextItem: function(jqObj){
            var greatestnumber = 0;
            jqObj.each(function(){
                var id = $(this).attr('id');
                var num = parseInt(id.split('-').pop());
                if (num > greatestnumber) {
                    greatestnumber = num;
                }
            });
            
            return greatestnumber + 1;
        },
        addLocation: function(Obj, noRemove){
            if (Obj == undefined) {
                Obj = {
                    id: "location-" + $.locations.nextItem($('.location')),
                };
            }
            
            if (noRemove) {
                Obj.remove = false;
            }
            else {
                Obj.remove = true;
            }
            
            var location = $('#newLocation').render(Obj);
            $('#locations').append(location);
            $.locations.updateLocations();
        },
        updateLocations: function(){
            var locations = [];
            $('.location').each(function(){
                var id = $(this).attr('id');
                var obj = {
                    id: id
                }
                $.each($.locations.fields, function(i,v){
                    var val = $('#'+id+' .'+v).val();
                    if (val != '' && val != undefined) {
                        obj[v] = val;
                    }
                });
                locations.push(obj);
            });
            $('#locations_hidden').val(JSON.stringify(locations));
        }
    }
})(jQuery)