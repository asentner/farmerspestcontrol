(function($){
    $(document).ready(function(){
        var copy_url = '/admin/appearance/theme-copy/copy-ajax';
        var ajax_url = copy_url;

        var run_copy = function() {

            $('.progressing').show();
            $('.done').hide();

            $.ajax(ajax_url).done(function (data, textStatus, jqXHR) {

                if (data.indexOf('xdebug-error') > -1) {
                    $('.progressing').html(data);
                }
            }).fail(function (jqXHR, textStatus, errorThrown) {
                var obj = {
                    textStatus: textStatus,
                    errorThrown: errorThrown
                };

                var error = {};

                error['Theme Copy Error'] = obj;

                console.log(error);
            });

            var intervalID = window.setInterval(function () {
                var progress_url = '/admin/appearance/theme-copy/copy-progress';

                $.ajax(progress_url).done(function (data, textStatus, jqXHR) {

                    if (data.indexOf('xdebug-error') > -1) {
                        clearInterval(intervalID);
                        $('.progressing').html(data);
                    }

                    if (data.indexOf('done123') > -1) {
                        clearInterval(intervalID);
                        $('.progressing').hide();
                        $('.theme-exists').hide();
                        $('.done').show();
                    }

                    if (data.indexOf('themeexists') > -1) {
                        clearInterval(intervalID);
                        $('.progressing').hide();
                        $('.theme-exists').show();
                    }
                })
            }, 500);
        };

        $('#i-understand').click(function(){
            if(this.checked) {
                ajax_url = copy_url + '?overwrite=1';
            }
            else {
                ajax_url = copy_url;
            }
        });

        $('#try-again').click(function(e){
            e.preventDefault();
            run_copy();
        });

        run_copy();
    });
})(jQuery);