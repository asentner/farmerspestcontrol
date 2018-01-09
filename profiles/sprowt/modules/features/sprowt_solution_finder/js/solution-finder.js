(function($){
    $(document).ready(function(){
        $('.solution-finder-form').each(function(){
            var $form = $(this);
            var $$ = function(sel) {
                return $form.find(sel);
            }

            var $button = $$('.show-hide-button');
            var $hidden = $$('#hidden');

            $button.click(function(e){
                e.preventDefault();
                $button.toggleClass('shown');
                $hidden.slideToggle();

                if($button.hasClass('shown')) {
                    $button.text('Less Options');
                }
                else {
                    $button.text('More Options');
                }
            });

            var $checks = $$('input[type="checkbox"]');
            var hiddenChecked = false;
            $checks.each(function(){
                var $this = $(this);
                var $label = $(this).closest('label');
                var $wrap = $(this).closest('.concerns-wrapper');
                if(this.checked) {
                    $label.addClass('checked');
                    if($wrap.attr('id') == 'hidden') {
                        hiddenChecked = true;
                    }
                }
                else {
                    $label.removeClass('checked');
                }
                $this.change(function(){
                    if(this.checked) {
                        $label.addClass('checked');
                    }
                    else {
                        $label.removeClass('checked');
                    }
                });
            });

            if(hiddenChecked) {
              $button.trigger('click');
            }
        });
    });
})(jQuery)