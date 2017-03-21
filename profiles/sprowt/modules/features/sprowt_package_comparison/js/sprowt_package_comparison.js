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

})(jQuery);
