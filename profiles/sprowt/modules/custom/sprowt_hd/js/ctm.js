!function($) {
    Drupal.behaviors.sprowtHDCTM = {
        attach: function(context, settings) {
            if (Drupal.settings.sprowt.ctmAccountId) {
                // Insert the Call Tracking Metrics Tracking script if account id is set
                var script = $('<script>');
                var firstScript = $('script').first();
                script.attr('src', '//' + Drupal.settings.sprowt.ctmAccountId + '.tctm.co/t.js');
                script.insertBefore(firstScript);
            }
        }
    }
}(jQuery);