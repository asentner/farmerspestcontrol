(function ($) {

  Drupal.behaviors.leadbuilderMobileMenu = {
    attach: function () {
      if ($('.mobile-menu-block').length > 0) {
        var menuBlock = $('.mobile-menu-block').first();
        
        menuBlock.prependTo('body');
        
        menuBlock.before('<a href="#" id="menu-toggle">Menu</a>');
        if (menuBlock.hasClass('slide-right')) {
          menuBlock.css({
            'position': 'absolute',
            'left':'-100%',
            'width': '100%',
            'z-index' : 100
          });
        }
        else {
          menuBlock.hide();
        }
        $('body').on('click','#menu-toggle',function(e){
          e.preventDefault();
          if (menuBlock.hasClass('slide-right')) {
            if (menuBlock.css('left') == '0px') {
              menuBlock.animate({left:'-100%'},400);
            }
            else {
              menuBlock.animate({left:'0'},400);
            }
          }
          else {
            menuBlock.slideToggle();
          }
        });
        
      }

    }
  };

})(jQuery);
