(function ($) {

  $(document).ready(function () {
    var $solutionMenuToggleBlock = $('.solution-menu-toggle');

    if ($solutionMenuToggleBlock.length > 0) {
      var $menu = $('.block--nav-main');
      var $toggle = $solutionMenuToggleBlock.find('.menu-toggle');

      $toggle.click(function (e) {
        e.preventDefault();
        $toggle.toggleClass('open');
        $menu.toggleClass('open').slideToggle();
      });
    }


    var $lockBox = $('.lock-form--wrap');

    window.addEventListener('resize', function () {
      wS = $(this).scrollTop();
      hT = $lockBox.offset().top;
      if (wS > hT) {
        $lockBox.addClass('fix-box');
      }
    });

    $(window).scroll(function () {
      wS = $(this).scrollTop();
      hT = $lockBox.offset().top;
      hH = $lockBox.outerHeight();
      if (wS > hT) {
        $lockBox.addClass('fix-box');
        $lockBox.css('height', hH + 'px');
      } else {
        $lockBox.removeClass('fix-box');
        $lockBox.css('height', 'inherit');
      }
      if (wS > (hT + hH)) {
        $lockBox.addClass('shrink-box');
      } else {
        $lockBox.removeClass('shrink-box');
      }
    });

  });

})(jQuery);
