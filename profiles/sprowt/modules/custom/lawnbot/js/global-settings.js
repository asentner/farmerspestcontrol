(function($){
    $(document).ready(function(){
        var required_keys = [
            'lawnbot_customerId',
            'lawnbot_botId'
        ];

        var $enabled = $('input[name="lawnbot_enable_integration"]');
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
