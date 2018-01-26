(function($){
    Drupal.behaviors.sprowtAnnotatedImage = {
        attach: function (context, settings) {
            $('.field--name-field-image-annotated img').each(function(){
                var $wrap = $(this).closest('div');
                var $pointers = $wrap.find('.pointer');
                var $annotations = $('.field--name-field-annotations .field__item');

                $(document).on('click', function(e){
                    var $target = $(e.target);
                    $annotations.removeClass('pointer-clicked');
                    if($target.is('.field--name-field-image-annotated .pointer')) {
                        e.preventDefault();
                        var $annotation = $('#' + $target.data('annotation-id'));
                        $annotation.addClass('pointer-clicked');
                    }
                });

                $pointers.each(function(){
                    var $pointer = $(this);
                    var $annotation = $('#' + $pointer.data('annotation-id'));
                    $pointer.mouseleave(function(){
                        $annotations.removeClass('pointer-hover');
                    });

                    $pointer.mouseenter(function(){
                        $annotations.removeClass('pointer-hover');
                        $annotation.addClass('pointer-hover');
                    });
                });
            });
        }
    }
})(jQuery)