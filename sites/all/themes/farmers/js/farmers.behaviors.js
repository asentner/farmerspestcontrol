(function ($) {

  Drupal.behaviors.sprowtMenu = {
    attach: function (context, settings) {

      //includes tablet toggle - removed for template
      // $('#block-logo-block-logo').once().append('<div class="mobile-menu-toggle"><i class="fa fa-bars"></i></div><div class="tablet-menu-toggle"><i class="fa fa-bars"></i><span>Menu</span></div>');

      $('#block-logo-block-logo').once().append('<div class="mobile-menu-toggle"><i class="fa fa-bars"></i></div>');

      $('#block-logo-block-logo').on('click', '.tablet-menu-toggle', function () {
        $('.block--nav-main').toggleClass('open');
      });


      $('.block--nav-main', context).once('menu', function () {
        var $block = $(this);
        // whole menu toggle
        $(this).children('.block__title').click(function (e) {
          e.preventDefault();
          $(this).next().slideToggle();
          $block.toggleClass('open');
        });

        $('.mobile-menu-toggle').click(function (e) {
          e.preventDefault();
          $('.block--nav-main .block__content').slideToggle();
          $(this).toggleClass('open');
        });

        // add children toggles
        $(this).find('.expanded .menu').before('<a href="#" class="menu-child-toggle">Toggle children</a>');

        // toggle the children
        $('.menu-child-toggle').click(function (e) {
          e.preventDefault();
          $(this).toggleClass('open');
          $(this).siblings('a').toggleClass('open');
          $(this).parent().toggleClass('open');
          $(this).next().slideToggle();
        });
      });





    }
  };

  Drupal.behaviors.scrollStickyMobileMenu = {
    attach: function (context, settings) {
      var menu = $('.block--nav-mobile-utility .menu');
      var didScroll;
      var lastScrollTop = 0;
      var navbarHeight = menu.outerHeight(true);

      $(window).scroll(function (e) {
        didScroll = true;
      });

      setInterval(function () {
        if (didScroll) {
          hasScrolled();
          didScroll = false;
        }
      }, 0);

      function hasScrolled() {
        var st = $(this).scrollTop();

        if (st > lastScrollTop && st > navbarHeight) {
          // Scroll Down
          menu.removeClass('visible').addClass('hidden');
        }
        else {
          // Scroll Up
          if (st + $(window).height() < $(document).height()) {
            menu.removeClass('hidden').addClass('visible');
          }
        }
        lastScrollTop = st;
      }
    }
  };

  Drupal.behaviors.sprowtAccordions = {
    attach: function (context, settings) {
      // find div's with class = accordion and turn them in to accordions
      var $accordions = $('div.accordion').each(function () {
        $(this).find('h3').first().addClass('accordion-header');
        $(this).children().not('.accordion-header').wrapAll('<div class="accordion-content"></div>');
      });

      // close the accordions
      $('.accordion-content').hide();

      // make the accordions work
      $('.accordion-header').click(function () {
        $(this).toggleClass('open');
        $(this).siblings('.accordion-content').slideToggle();
      });

    }
  };

  Drupal.behaviors.sprowtMapMouseOver = {
    attach: function (context, settings) {
      settings.mapmouseover = false;
      var map = undefined;

      $('iframe').each(function () {
        if ($(this).attr('src').indexOf('map') > -1) {
          //if the map isnt wrapped with a div.media_embed, wrap in one
          if ($(this).parent('.media_embed').length < 1) {
            $(this).wrap('<div class="media_embed"></div>');
          };

          //apply the scroll fix to the div.media_embed
          map = $(this);

          var wrap = map.closest('.media_embed');
          wrap.css('position', 'relative');
          wrap.prepend('<div class="map-disable" style="position:absolute; top: 0; left: 0; right: 0; bottom: 0;z-index:20;"></div>');

          wrap.click(function () {
            wrap.find('.map-disable').hide();
          });

          wrap.mouseleave(function () {
            wrap.find('.map-disable').show();
          });

        };
      });

    }
  };

  /**
   * The recommended way for producing HTML markup through JavaScript is to write
   * theming functions. These are similiar to the theming functions that you might
   * know from 'phptemplate' (the default PHP templating engine used by most
   * Drupal themes including Omega). JavaScript theme functions accept arguments
   * and can be overriden by sub-themes.
   *
   * In most cases, there is no good reason to NOT wrap your markup producing
   * JavaScript in a theme function.
   */
  Drupal.theme.prototype.sprowt1ExampleButton = function (path, title) {
    // Create an anchor element with jQuery.
    return $('<a href="' + path + '" title="' + title + '">' + title + '</a>');
  };

  /**
   * Behaviors are Drupal's way of applying JavaScript to a page. In short, the
   * advantage of Behaviors over a simple 'document.ready()' lies in how it
   * interacts with content loaded through Ajax. Opposed to the
   * 'document.ready()' event which is only fired once when the page is
   * initially loaded, behaviors get re-executed whenever something is added to
   * the page through Ajax.
   *
   * You can attach as many behaviors as you wish. In fact, instead of overloading
   * a single behavior with multiple, completely unrelated tasks you should create
   * a separate behavior for every separate task.
   *
   * In most cases, there is no good reason to NOT wrap your JavaScript code in a
   * behavior.
   *
   * @param context
   *   The context for which the behavior is being executed. This is either the
   *   full page or a piece of HTML that was just added through Ajax.
   * @param settings
   *   An array of settings (added through drupal_add_js()). Instead of accessing
   *   Drupal.settings directly you should use this because of potential
   *   modifications made by the Ajax callback that also produced 'context'.
   */
  Drupal.behaviors.sprowt1ExampleBehavior = {
    attach: function (context, settings) {
      // By using the 'context' variable we make sure that our code only runs on
      // the relevant HTML. Furthermore, by using jQuery.once() we make sure that
      // we don't run the same piece of code for an HTML snippet that we already
      // processed previously. By using .once('foo') all processed elements will
      // get tagged with a 'foo-processed' class, causing all future invocations
      // of this behavior to ignore them.
      $('.some-selector', context).once('foo', function () {
        // Now, we are invoking the previously declared theme function using two
        // settings as arguments.
        var $anchor = Drupal.theme('sprowt1ExampleButton', settings.myExampleLinkPath, settings.myExampleLinkTitle);

        // The anchor is then appended to the current element.
        $anchor.appendTo(this);
      });
    }
  };


  $(document).ready(function(){
      var stickyBlocks = [
          $('.node-type-localtarget .ltp-free-quote-form').closest('.block--webform'),
          $('.sticky-block')
      ];

      $('body').data('original-padding', $('body').css('padding-top'));

      $.each(stickyBlocks, function(sti, $blocks) {
          $blocks.each(function() {
              var $lockBoxInterior = $(this);
              $lockBox = $('<div class="block--lockbox"></div>');
              $lockBoxInterior.before($lockBox);
              $lockBox.append($lockBoxInterior);
              window.addEventListener('resize', function () {
                  if($lockBox.length > 0) {
                      var wS = $(this).scrollTop();
                      var hT = $lockBox.offset().top;
                      var hH = $lockBox.outerHeight();
                      var bodyPadding = $('body').data('original-padding');
                      if (wS > hT) {
                          $lockBox.addClass('fix-box');
                          $('body').css({
                              paddingTop: bodyPadding + hH
                          });
                      }
                      else {
                          $('body').css({
                              paddingTop: ''
                          });
                      }
                  }
              });

              $(window).scroll(function () {
                  if($lockBox.length > 0) {
                      var wS = $(this).scrollTop();
                      var hT = $lockBox.offset().top;
                      var hH = $lockBox.outerHeight();
                      var bodyPadding = $('body').data('original-padding');
                      if (wS > hT) {
                          $lockBox.addClass('fix-box');
                          $lockBox.css('height', hH + 'px');
                          $('body').css({
                              paddingTop: bodyPadding + hH
                          });
                      } else {
                          $lockBox.removeClass('fix-box');
                          $lockBox.css('height', 'inherit');
                          $('body').css({
                              paddingTop: ''
                          });
                      }
                      if (wS > (hT + hH)) {
                          $lockBox.addClass('shrink-box');
                      } else {
                          $lockBox.removeClass('shrink-box');
                      }
                  }
              });
          });
      });

  });

})(jQuery);
