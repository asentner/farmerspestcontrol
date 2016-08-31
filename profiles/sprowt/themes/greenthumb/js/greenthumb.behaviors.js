(function ($) {

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
  Drupal.theme.prototype.greenthumbExampleButton = function (path, title) {
    // Create an anchor element with jQuery.
    return $('<a href="' + path + '" title="' + title + '">' + title + '</a>');
  };

  Drupal.behaviors.greenthumbMobileMenu = {
    attach: function(context, settings) {

      // hide menu links
      $('.block--nav-mobile .block__content').hide();
      $('.block--nav-mobile .block__title')
        // make menu title look like a link
        .css('cursor', 'pointer')
        // when clicked, toggle the menu
        .click(function(e) {
          e.preventDefault();
          $(this).next().slideToggle();
      });

    }
  };

  // this code was taken from the scroll to destination anchors module
  Drupal.behaviors.greenthumbScroll = {
    attach: function() {

      function validateSelector(a) {
        return /^#[a-z]{1}[a-z0-9_-]*$/i.test(a);
      }
      function scrollToDestination(a,b) {
        if (a > b) {
          destination = b;
        } else {
          destination = a;
        }
        $('html,body').animate({ scrollTop: destination }, 800, 'swing');
      }
      $('a[href^="#"]').click(function(event) {
        event.preventDefault();
        var hrefValue = $(this).attr('href');
        var strippedHref = hrefValue.replace('#','');
        var heightDifference = $(document).height() - $(window).height();
        if (validateSelector(hrefValue)) {
          if ($(hrefValue).length > 0) {
            var linkOffset = $(this.hash).offset().top;
            scrollToDestination(linkOffset, heightDifference);
          }
          else if ($('a[name=' + strippedHref + ']').length > 0) {
            var linkOffset = $('a[name=' + strippedHref + ']').offset().top;
            scrollToDestination(linkOffset, heightDifference);
          }
        }
      });

    }
  };

  Drupal.behaviors.greenthumbMapMouseOver = {
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
  Drupal.behaviors.greenthumbExampleBehavior = {
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
        var $anchor = Drupal.theme('greenthumbExampleButton', settings.myExampleLinkPath, settings.myExampleLinkTitle);

        // The anchor is then appended to the current element.
        $anchor.appendTo(this);
      });
    }
  };

})(jQuery);
