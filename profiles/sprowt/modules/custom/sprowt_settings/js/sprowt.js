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
                utm_content: $('#edit-submitted-utm-content'),
                utm_term: $('#edit-submitted-utm-term')
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

    Drupal.behaviors.sprowt_devel = {
        attach: function(context, settings) {
            // rework krumo events to work with dom generated krumo (e.g. from ajax)
            // see devel/devel_krumo.js
            var selector = '.krumo-element';

            if($(document).on) {//only for later jQueries

                $(document).on('click', selector, function (e) {
                    var events = $(this).data('events');
                    if (!events) {
                        events = $._data(this).events;
                    }
                    if (!events || !events.click) {
                        krumo.toggle(this);
                    }
                });

                $(document).on('mouseover', selector, function (e) {
                    var events = $(this).data('events');
                    if (!events) {
                        events = $._data(this).events;
                    }
                    if (!events || !events.mouseover) {
                        krumo.over(this);
                    }
                });

                $(document).on('mouseout', selector, function (e) {
                    var events = $(this).data('events');
                    if (!events) {
                        events = $._data(this).events;
                    }
                    if (!events || !events.mouseout) {
                        krumo.out(this);
                    }
                });
            }
        }
    }

}(jQuery);