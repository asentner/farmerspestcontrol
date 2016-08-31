(function ($) {

  $('body').bind('touchstart', function() {});

  Drupal.behaviors.interstatepestMobileMenu = {
    attach: function (context, settings) {

    	var $menuBlock = '.block--nav-mobile';

    	$($menuBlock + ' .block__content').hide();
      $($menuBlock + ' > .block__title').on('click', function(e) {
        e.preventDefault();
        $($menuBlock + ' .block__content').slideToggle();
      });

      $($menuBlock).prependTo('body');

    }
  };

  Drupal.behaviors.interstatepestLearningCenter = {
    attach: function(context, settings) {

      var blockId = '#block-views-pests-list';
      var navId = '#block-views-pests-list-nav';

      $(blockId).before('<ul id="block-views-pests-list-nav"></ul>');

      var headings = {};
      var count = 0;

      $(blockId + ' h2').each(function(e) {
        count++;
        headings[count] = $(this).text();
        var sanitized = $(this).text().replace(/\s+/g, '-').toLowerCase();
        $(this).attr('id', 'pests-list-'+ sanitized);
        $(navId).append('<li><a href="#pests-list-'+ sanitized +'">'+ $(this).text() +'</a></li>');
      });

      $(blockId + ' .views-row-last').each(function(e) {
        $(this).append('<a href="'+ navId +'" class="top">Back to top <i class="fa fa-arrow-up"></i></a>');
      });

    }
  };

  Drupal.behaviors.interstatepestMapMouseOver = {
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
