(function($){
    $(document).ready(function(){
        var getContrast = function (hexcolor, orig){
            if(hexcolor.indexOf('#') == -1) {
                return orig;
            }
            else {
                hexcolor = hexcolor.replace('#', '');
            }
            if(hexcolor.length == 3) {
                var hexparts = hexcolor.split();
                var newhex = '';
                $.each(hexparts, function(i,v){
                    newhex += v+v;
                });
                hexcolor = newhex;
            }
            else if (hexcolor.length != 6) {
                return orig;
            }
            return (parseInt(hexcolor, 16) > 0xffffff/2) ? 'black':'white';
        }

        $('.spectrum').each(function(){
            var $parentWrap = $(this).closest('.color-picker');
            var $textInput = $parentWrap.find('.color');
            var colorId = $textInput.attr('id');
            var initcolor = $('#'+colorId).val();
            $(this).spectrum({
                color: initcolor,
                change: function(color) {
                    $('#'+colorId).removeClass('error');
                    var hex = color.toHexString();
                    $('#'+colorId).val(hex);
                    var css = {
                        background: hex,
                        color: getContrast(hex, $('#'+colorId).css('color'))
                    }
                    $('#'+colorId).css(css);
                },
            });
        });

        $('.color').keyup(function(){
            $(this).removeClass('error');
            var hex = $(this).val();
            if (/^\#[0-9a-zA-Z]{3}$/.test($(this).val())
                || /^\#[0-9a-zA-Z]{6}$/.test($(this).val())
            )
            {
                var spectrum = $('#'+$(this).data('spectrum'));
                spectrum.spectrum('set', $(this).val());
                var css = {
                    background: $(this).val(),
                    color: getContrast($(this).val(), $(this).css('color'))
                }
                $(this).css(css);
            }
            else {
                $(this).addClass('error');
            }
        });
    });
})(jQuery)