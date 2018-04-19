!function($) {
    Drupal.behaviors.referrer = {
        attach: function(context, settings) {
            $('form').each(function(){
                var $referrerField = $(this).find('input[name="submitted[referrer]"]');
                if($referrerField.length > 0) {
                    $referrerField.val(document.referrer);
                }
            });
        }
    }
}(jQuery);