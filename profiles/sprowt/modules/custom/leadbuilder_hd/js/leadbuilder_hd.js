!function($) {
    Drupal.behaviors.leadbuilderHd = {
        attach: function(context) {
            var ctmSidInputSelector = $('input[name="submitted[ctm_sid]"]');
            // Check to see if the ctm_sid input element exists
            if (ctmSidInputSelector.length) {
                var runCount = 0;
                var intervalId = setInterval(function () {
                    runCount++;
                    // Wait until the __ctm global is defined
                    if (typeof __ctm != 'undefined') {
                        ctmSidInputSelector.val(__ctm.config.sid);

                        // Kill the recursion
                        window.clearInterval(intervalId);
                    }
                    else if (runCount >= 10) {
                        // If we made it here, __ctm will not be available. The tracking code is missing or an error
                        // occurred before it was included
                        window.clearInterval(intervalId);
                    }
                }, 300);
            }
        }
    }
}(jQuery);