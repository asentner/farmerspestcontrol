(function ($) {
    Drupal.behaviors.sprowtLoginMenu = {
        attach: function (context, settings) {
            var $nav = $('#sprowt-dashboard-nav').find('.sprowt-dashboard-nav');
            var $ul = $nav.find('ul');
            var $toggle = $nav.find('.sprowt-dashboard-nav-mobile-toggle');

            $toggle.once().bind('click', function(e){
                e.preventDefault();
                $ul.slideToggle();
            });
        }
    }
})(jQuery)