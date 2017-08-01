!function($) {
    Drupal.behaviors.sprowt = {
        attach: function(context, settings) {
            if (Drupal.settings.sprowt.ctmAccountId) {
                // Insert the Call Tracking Metrics Tracking script if account id is set
                var script = $('<script>');
                var firstScript = $('script').first();
                script.attr('src', '//' + Drupal.settings.sprowt.ctmAccountId + '.tctm.co/t.js');
                script.insertBefore(firstScript);
            }

            //gtm parameter fields
            var utm = {
                utm_source: $('#edit-submitted-utm-source'),
                utm_medium: $('#edit-submitted-utm-medium'),
                utm_campaign: $('#edit-submitted-utm-campaign'),
                utm_content: $('#edit-submitted-utm-content')
            }

            $.each(utm, function(key, $field){
                if($field.length > 0) {
                    var params = new URLSearchParams(window.location.search);
                    if(null !== params.get(key)) {
                        $field.val(params.get(key));
                    }
                }
            });
        }
    }
}(jQuery);