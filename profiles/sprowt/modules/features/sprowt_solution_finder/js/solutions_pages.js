(function ($) {
  
$(document).ready(function(){
  var $solutionMenuToggleBlock = $('.solution-menu-toggle');

  if($solutionMenuToggleBlock.length > 0) {
    var $menu = $('.block--nav-main');
    var $toggle = $solutionMenuToggleBlock.find('.menu-toggle');

    $toggle.click(function(e){
      e.preventDefault();
      $toggle.toggleClass('open');
      $menu.toggleClass('open').slideToggle();
    });
  }
});

})(jQuery);
