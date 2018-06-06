(function($){

    var qs = (function(a) {
        if (a == "") return {};
        var b = {};
        for (var i = 0; i < a.length; ++i)
        {
            var p=a[i].split('=', 2);
            if (p.length == 1)
                b[p[0]] = "";
            else
                b[p[0]] = decodeURIComponent(p[1].replace(/\+/g, " "));
        }
        return b;
    })(window.location.search.substr(1).split('&'));

    /**
     * Attaches the batch behavior to progress bars.
     */
    Drupal.behaviors.sprowtSetup = {
      attach: function (context, settings) {
        $('#progress', context).once('batch', function () {
            var holder = $(this);
      
            // Success: redirect to the summary.
            var updateCallback = function (progress, status, pb) {
                if (progress == 100) {
                  pb.stopMonitoring();
                  console.log('done');
                  $('#sprowt-setup-form').submit();
                }
            };
      
            var errorCallback = function (pb) {
              holder.prepend($('<p class="error"></p>').html("ERROR!"));
              $('#wait').hide();
            };
      
            var progress = new Drupal.progressBar('updateprogress', updateCallback, 'POST', errorCallback);
            progress.setProgress(-1, "initialize");
            holder.append(progress.element);
            progress.startMonitoring('/profiles/sprowt/ajax_setup.php', 10);

            if(qs['debug'] == 1) {
                var setup_url = '/profiles/sprowt/background_sprowt_build.php?XDEBUG_SESSION_START=1';
            }
            else {
                var setup_url = '/profiles/sprowt/background_sprowt_build.php';
            }

            var ajax_ops = {
                url: setup_url,
                dataType: 'json',
                timeout: 0,
                success: function( data, textStatus, jqXHR ) {

                    if (data.indexOf('xdebug-error') > -1) {
                        $('#progress').after(data);
                    }

                    console.log(data);
                },
                error: function( jqXHR, textStatus, errorThrown ) {
                    var obj = {
                        jQXHR: jqXHR,
                        textStatus: textStatus,
                        errorThrown: errorThrown
                    };

                    var error = {};

                    error['Sprowt Setup Error'] = obj;

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