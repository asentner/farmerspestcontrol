(function($){
  Drupal.behaviors.viewsAjaxResetFix = {
    attach: function (context, settings) {
      $('.views-ajax-reset-fix-button').once('views-ajax-reset-fix', function(){
          $(this).bind('click', function(e){
            e.preventDefault();
            var $form = $(this.form);
            $form.clearForm();
            $form.find('.views-ajax-reset-fix-button-submit').trigger('click');
            return false;
          });
      });

    }
  };
})(jQuery);
