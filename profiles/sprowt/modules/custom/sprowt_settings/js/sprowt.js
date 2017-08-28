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
                //$field.closest('div').show();
                if($field.length > 0) {
                    var params = new URLSearchParams(window.location.search);
                    if(null !== params.get(key)) {
                        $field.val(params.get(key));
                    }

                    var hash = window.location.hash;
                    var re = new RegExp('[#&]'+ key + '=([^&]+)');
                    if(re.test(hash)) {
                        var matches = re.exec(hash);
                        if(typeof matches[1] != 'undefined') {
                            $field.val(matches[1]);
                        }
                    }
                }
            });
        }
    }
}(jQuery);