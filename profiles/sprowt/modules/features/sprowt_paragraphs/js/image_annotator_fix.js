(function($){

    Drupal.behaviors.imageAnnotatorFix = {
        attach: function (context) {
            var waitForIt = window.setInterval(function(){
                if ($(context).is('form') || typeof Drupal.imageAnnotators !== 'undefined') {
                    fixPointers(context);
                    clearInterval(waitForIt);
                }
            },100);

        }
    };

    var fixPointers = function (context) {
            var num = 0
            $(context).find('.image-annotator-pointers').each(function() {
                ++num;
                var pointer_data = JSON.parse('[' + $(this).val() + ']');
                $.each(pointer_data, function (index, data){
                    var type = (typeof data.type == 'undefined') ? 'pointer' : data.type;
                    var number = num;
                    var dataId = (typeof data.id != 'undefined') ? data.id : number;
                    var id = data.field + '__' + data.language + '__' + data.delta + '__' + dataId + '__pointer';
                    var $pointer = $('#'+id);
                    var x = parseFloat(data.x, 10);
                    var y = parseFloat(data.y, 10);

                    var css = {
                        top: (y * 100) + '%',
                        left: (x * 100) + '%'
                    }


                    if (type !== 'rectangle') {
                        $pointer.css(css);
                    }
                });
            });
        };
})(jQuery)