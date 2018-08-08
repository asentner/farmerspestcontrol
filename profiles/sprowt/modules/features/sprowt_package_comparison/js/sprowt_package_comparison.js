(function ($) {

  Drupal.behaviors.sprowtPackageCompareButtonHover = {
    // if the package colors have been overriden by the user, this behavior sets
    // the button hover colors for the package panels
    attach: function (context, settings) {
      var $packageButtons = $('.node--package--alt-teaser .button.overridden');
      var $comparisonPage = $('.node-type-package-comparison');
      var $comparisionBean = $('.bean-package-comparison');
      if (($comparisonPage.length || $comparisionBean.length) && $packageButtons.length) {
        $packageButtons.hover(
          function(){
            bgColor = $(this).attr('style');
            bgColor = bgColor.substr(bgColor.indexOf("#")+1);
            hoverColor = '#' + darkenColor(bgColor, 10);
            $(this).attr('style', 'background-color: ' + hoverColor);
          },
          function(){
            $(this).attr('style', 'background-color: #' + bgColor);
          }
        );
      };

      // http://stackoverflow.com/questions/5560248/programmatically-lighten-or-darken-a-hex-color-or-rgb-and-blend-colors
      function darkenColor(color, amt) {
        var num = parseInt(color,16);
        var r = (num >> 16) - amt;
        var b = ((num >> 8) & 0x00FF) - amt;
        var g = (num & 0x0000FF) - amt;
        var newColor = g | (b << 8) | (r << 16);
        return newColor.toString(16);
      };
    }
  };

  Drupal.behaviors.sprowtMobilePackages = {
    attach: function (context, settings) {
      var features = $('.node--package--alt-teaser .field--name-field-package-features .field__items');
      $(features).each(function() {
        var $features = $(this);
        var $node = $features.closest('.node');
        var excess = [];

        excess = $(this).children("div").slice(4);
        if(excess.length > 0) {
          var $toggleWrap = $('<div class="toggle-wrap"></div>');

          $toggleWrap.css('display', 'none');
          $toggleWrap.append(excess);
          $toggleWrap.appendTo($features);

          var viewMore = 'View More <i class="fa fa-plus-circle"></i>';
          var viewLess = 'View Less <i class="fa fa-minus-circle"></i>';
          var $toggle = $('<div class="toggle"></div>');

          $toggle.html(viewMore);
          $features.after($toggle);
          $node.on('click', '.toggle', function(){
            $toggleWrap.slideToggle();
            if($toggleWrap.hasClass('open')) {
              $toggleWrap.removeClass('open');
              $toggle.html(viewMore);
            }
            else {
              $toggleWrap.addClass('open');
              $toggle.html(viewLess);
            }
          });
        }

      });
    }
  };

})(jQuery);
