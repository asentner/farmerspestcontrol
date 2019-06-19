(function($){
    var addCustomField = function(fieldId, field,mapToField) {
        if(fieldId) {
            var id = fieldId.toLowerCase().replace(/[^a-z-]/, '-');
        }
        else {
            id = Math.random()
        }
        var $fieldset = $($('#customFieldTemplate').html());
        $fieldset.attr('id', id);
        $fieldset.find('.field-id').val(fieldId);
        $fieldset.find('.field-field').val(field);
        $fieldset.find('.map-to-field').val(mapToField);
        $('#customFieldsDisplay').append($fieldset);
    }

    var updateCustomFields = function(){
        var customfields = [];
        $('.custom-field-fieldset').each(function(){
            customfields.push({
                fieldId: $(this).find('.field-id').val(),
                field: $(this).find('.field-field').val(),
                mapToField: $(this).find('.map-to-field').val(),
            });
        });
        $('#customFields').val(JSON.stringify(customfields));

    };

    $(document).on('click', '#addCustomField', function(e){
        e.preventDefault();
        addCustomField(null, null,null);
    });

    $(document).on('click', '.field-remove', function(e) {
        var $fieldset = $(this).closest('.custom-field-fieldset');
        $fieldset.remove();
        updateCustomFields();
    });

    $(document).on('keyup', '.field-id', function(){
        updateCustomFields();
    });

    $(document).on('change', '.field-field', function(){
        updateCustomFields();
    });

    $(document).on('keyup', '.map-to-field', function(){
        updateCustomFields();
    });

    $(document).ready(function(){
        var customFields = $('#customFields').val();
        if(customFields) {
            customFields = JSON.parse(customFields);
        }

        if(customFields) {
            $.each(customFields, function(i,v) {
                addCustomField(v.fieldId, v.field,v.mapToField);
            });
        }
    });

})(jQuery)