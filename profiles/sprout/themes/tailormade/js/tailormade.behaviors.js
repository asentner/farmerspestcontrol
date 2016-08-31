(function ($) {

  Drupal.behaviors.tailormadeStarterMobileMenu = {
    attach: function (context, settings) {

    	var $menuBlock = '#block-menu-menu-mobile-menu';
        
        $($menuBlock).prependTo('body');

    	$($menuBlock + ' .menu').hide();
      $($menuBlock + ' > .block__title').on('click', function(e) {
        e.preventDefault();
        $($menuBlock + ' .menu').slideToggle();
      });

    }
  };
  
  Drupal.behaviors.tailormadeMapMouseOver = {
    attach: function (context, settings) {
      settings.mapmouseover = false;
      var map = undefined;
      
      $('.media_embed > iframe').each(function(){
        if ($(this).attr('src').indexOf('google.com/maps') > -1
            || $(this).attr('src').indexOf('maps.google.com') > -1
            ) {
          map = $(this);
          
          var wrap = map.closest('.media_embed');
          wrap.css('position','relative');
          wrap.prepend('<div class="map-disable" style="position:absolute; top: 0; left: 0; right: 0; bottom: 0;z-index:20;"></div>');
          
          wrap.click(function(){
            wrap.find('.map-disable').hide();
          });
          
          wrap.mouseleave(function(){
            wrap.find('.map-disable').show();
          });
        }
        
      });
    }
  };

})(jQuery);
