(function($){
    
    /**
     * Attaches the batch behavior to progress bars.
     */
    Drupal.behaviors.sproutSetup = {
      attach: function (context, settings) {
        $('#progress', context).once('batch', function () {
            var holder = $(this);
      
            // Success: redirect to the summary.
            var updateCallback = function (progress, status, pb) {
                if (progress == 100) {
                  pb.stopMonitoring();
                  console.log('done');
                  $('#sprout-setup-form').submit();
                }
            };
      
            var errorCallback = function (pb) {
              holder.prepend($('<p class="error"></p>').html("ERROR!"));
              $('#wait').hide();
            };
      
            var progress = new Drupal.progressBar('updateprogress', updateCallback, 'POST', errorCallback);
            progress.setProgress(-1, "initialize");
            holder.append(progress.element);
            progress.startMonitoring('/profiles/sprout/ajax_setup.php', 10);
            
            //var setup_url = '/profiles/sprout/background_sprout_build.php?XDEBUG_SESSION_START=1';
            
            var setup_url = '/profiles/sprout/background_sprout_build.php';

            var ajax_ops = {
                url: setup_url,
                dataType: 'json',
                success: function( data, textStatus, jqXHR ) {

                    if (data.indexOf('xdebug-error') > -1) {
                        $('#progress').after(data);
                    }

                    console.log(data);
                },
                error: function( jqXHR, textStatus, errorThrown ) {
                    var obj = {
                        textStatus: textStatus,
                        errorThrown: errorThrown
                    };

                    var error = {};

                    error['Sprout Setup Error'] = obj;

                    console.log(error);
                }
            }


            $.ajax(ajax_ops);
          
        });
      }
    };
    $(document).ready(function(){
    });
})(jQuery);