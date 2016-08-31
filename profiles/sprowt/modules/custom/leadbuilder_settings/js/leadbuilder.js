!function($) {
    Drupal.behaviors.leadbuilder = {
        attach: function(context, settings) {
            if (Drupal.settings.leadbuilder.ctmAccountId) {
                // Insert the Call Tracking Metrics Tracking script if account id is set
                var script = $('<script>');
                var firstScript = $('script').first();
                script.attr('src', '//' + Drupal.settings.leadbuilder.ctmAccountId + '.tctm.co/t.js');
                script.insertBefore(firstScript);
            }
        }
    }
}(jQuery);