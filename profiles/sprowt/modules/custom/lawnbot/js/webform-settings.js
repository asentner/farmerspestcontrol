(function($){
    $(document).ready(function(){
        var required_keys = [
            'first_or_full_name_key',
            'phone_key',
            'email_key',
            'address_key',
            'zip_key'
        ];

        var $enabled = $('input[name="enable_lawnbot_integration"]');
        var isEnabled = $enabled.prop('checked');

        var setRequired = function(required) {
            $.each(required_keys, function(idx, key) {
                var $input = $('[name="'+key+'"]');
                var $label = $('label[for="'+$input.attr('id')+'"]');
                if(required) {
                    $input.attr('required', 'required');
                    $label.html($label.text() + '<span class="form-required" title="This field is required.">*</span>');
                }
                else {
                    $input.removeAttr('required');
                    $label.find('.form-required').remove();
                }
            });
        }
        setRequired(isEnabled);
        $enabled.change(function() {
            var isEnabled = $enabled.prop('checked');
            setRequired(isEnabled);
        });
    });
})(jQuery)
