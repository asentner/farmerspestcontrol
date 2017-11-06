(function ($) {

  /**
   For not loading video files on mobile
   */
  $(document).ready(function(){
    if($('.video-js').length > 0) {
      if (window.matchMedia("(min-width: 1024px)").matches) {
        var $sources = $('.video-js').find('source');
        $sources.each(function(){
          var $this = $(this);
          var src = $this.data('src');
          $this.attr('src', src);
        });

        var video = $('.video-js')[0];
        video.load();
      }
    }

  });

})(jQuery);
