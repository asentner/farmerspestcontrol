(function($){
  Drupal.behaviors.videoModal = {
    attach: function (context, settings) {
      setTimeout(function(){
        $('.video-modal').magnificPopup({
          disableOn: 300,
          type: 'iframe',
          mainClass: 'mfp-fade',
          removalDelay: 160,
          preloader: false,
          fixedContentPos: false
        });
      },300);
    }
  };
})(jQuery)