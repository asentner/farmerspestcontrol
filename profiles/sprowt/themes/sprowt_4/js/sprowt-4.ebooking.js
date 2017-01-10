(function ($) {

  Drupal.behaviors.sprowtEbooking = {
    attach: function (context, settings) {
      var $target = $('.node-ebooking');
      var $fieldsets = $('fieldset.panel');

      // add previous, next, etc buttons and validation error message
      if ($target.length && !($target.hasClass('processed'))) {

        // add 'previous' buttons
        $fieldsets.not(':first').each(function(){
          $(this).addClass('right');
          $(this).append('<a class="button button-prev" href="#">Previous Step</a>');
        });

        // add inactive 'previous' button to first panel
        $fieldsets.filter(':first').append('<a class="button inactive" href="#">Previous Step</a>');

        // add 'next' buttons
        $fieldsets.not(':last').each(function(){
          $(this).append('<a class="button button-next" href="#">Next Step</a>');
        });

        // Add link to view as a single page
        // $fieldsets.filter(':first').append('<a class="basic-form" href="#">Don’t like this form, fill out a single page now!</a>');

        // add the 'checkout' button
        $fieldsets.filter(':last').append('<a class="button button-checkout" href="#">Checkout</a>')

        // make the first panel active
        $fieldsets.filter(':first').addClass('active');

        // add anchor/id to each panel to scroll to when next/previous is clicked
        $fieldsets.attr('id', 'panel');

        // add validation error messages, step numbers, basic form links
        var stepNumber = 1;
        $fieldsets.each(function(){
          $(this).prepend('<div class="validation-error"><span>Some fields have been filled out wrong!</span></div>');
          $('.validation-error').hide(); // hide the validation error messages
          $(this).prepend('<h3 class="step-number">Step ' + stepNumber + ' of ' + ($fieldsets.length+1) + '</h3>');
          stepNumber++;
        });

        // add link to return to 'panel' form layout
        if($fieldsets.length) {
          $('.node--webform').append('<a class="panel-form" href="#">Take me back to the panels!</a>');
        };


        $target.addClass('processed');
      } // end panel 'build out'


      if ($target.length) {

        // next button validation and functionality
        $('.button-next').click(function(e){
          e.preventDefault();
          // make sure all of the answers have been filled out
          var validation = true;
          var $webformComponents = $(this).siblings('.fieldset-wrapper').find('.webform-component');

          // check each webform component for validation
          $webformComponents.each(function(){
            // required radio buttons - if there are required radio buttons, make sure at least one is checked
            if($(this).filter('.webform-component-radios').find('input:required').length
                && ($(this).find('input:checked').length < 1)) {
              validation = false;
            }
            // required select boxes - if a select box is required and the first option is selected, validation = false
            else if($(this).find('select:required').find('option:first').filter(':selected').length > 0) {
              validation = false;
            }
            // required 'options with markup' - similar to radio buttons
            else if($(this).filter('.webform-component-optionsmarkup').find('.form-required').length > 0
                &&  ($(this).find('input:checked').length < 1)) {
              validation = false;
            }
          });

          // after checking validation make the next work
          if($(this).parent('fieldset').hasClass('active') && validation == true) {
            $(this).parent('fieldset').removeClass('active').addClass('left');
            $(this).parent('fieldset').next('.panel').removeClass('right').addClass('active');
            $(this).siblings('.validation-error').hide();
            panelScroll(750);
          }
          else if(validation == false){
            $(this).siblings('.validation-error').show();
            panelScroll(0);
          }
        });

        // make the validation error dissapear when a user makes a selection (not just 'next step')
        $('input:radio').change(function(){
          $(this).parents('.fieldset-wrapper').siblings('.validation-error').hide();
        });
        $('select').change(function(){
          $(this).parents('.fieldset-wrapper').siblings('.validation-error').hide();
        });

        // prevent default action of inactive previous button on first panel
        $('.button.inactive').click(function(e){
          e.preventDefault();
        });

        // make the previous buttons work
        $('.button-prev').click(function(e){
          e.preventDefault();
          if($(this).parent('fieldset').hasClass('active')) {
            $(this).parent('fieldset').removeClass('active').addClass('right');
            $(this).parent('fieldset').prev('.panel').removeClass('left').addClass('active');
            $(this).siblings('.validation-error').hide();
            panelScroll(750);
          };
        });

        // clicking on a date select box opens the date picker calendar instead
        var $datePicker = $('.webform-datepicker').find('select');
        // prevent the default behavior of the date select box
        $datePicker.on('mousedown', function(e){
          e.preventDefault();
          this.blur();
          window.focus();
        });
        // open date picker menu when date select boxes are clicked
        $datePicker.click(function(e){
          $(this).parent().siblings('input.webform-calendar').click();
        });

        // make the checkout button work
        $('.button-checkout').click(function(e){
          e.preventDefault();

          // validate the panel
          // NOTE: can i refactor this to use one function for validation

          var validation = true;
          var $webformComponents = $(this).siblings('.fieldset-wrapper').find('.webform-component');

          // check each webform component for validation
          $webformComponents.each(function(){
            // required radio buttons - if there are required radio buttons, make sure at least one is checked
            if($(this).filter('.webform-component-radios').find('input:required').length
                && ($(this).find('input:checked').length < 1)) {
              validation = false;
            }
            // required select boxes - if a select box is required and the first option is selected, validation = false
            else if($(this).find('select:required').find('option:first').filter(':selected').length > 0) {
              validation = false;
            }
            // required 'options with markup' - similar to radio buttons
            else if($(this).filter('.webform-component-optionsmarkup').find('.form-required').length > 0
                &&  ($(this).find('input:checked').length < 1)) {
              validation = false;
            }
          });

          if(validation == true) {
            $('.webform-next').click();
          }
          else if(validation == false){
            $(this).siblings('.validation-error').show();
            panelScroll(0);
          }

        });

        // clicking on the "basic-form" link adds class to page-node
        $('.basic-form').click(function(e){
          e.preventDefault();
          $('.page-node').addClass('basic-form');
        });

        // clicking the panel form button removes class from page-node
        $('.panel-form').click(function(e){
          e.preventDefault();
          $('.page-node').removeClass('basic-form');
          panelScroll(500);
        });

        // set min height of form based on tallest panel
        var minHeight = 0;
        $fieldsets.each(function(){
          if ($(this).height() > minHeight) {
            minHeight = $(this).height();
          };
        });
        $fieldsets.parent().css('min-height', minHeight + 200);

        // selectiing a package adds a class to it's "label"
        var $packages = $('.form-radios').find('.webform-component-optionsmarkup').filter('[class*=package]');

        $packages.each(function(){
          $(this).find('input').change(function(){
            $(this).parent().siblings().find('.package').removeClass('selected');
            $(this).siblings('label').find('.package').addClass('selected');
          });
        })

      }; // endif

      function panelScroll(delay) {
        if($('.panel.active').offset().top - $(window).scrollTop() < 50) {
          $('html, body').delay(delay).animate({
              scrollTop: $("#panel").offset().top - 50
            }, 1000);
        };
      };

      // add tooltip icon to monthly price on the checkout page
      $('.amount-due').find('p:last-of-type').append('<span class="tooltip-icon"></span>');
      $('.tooltip-icon').hover(
        function(){
          $(this).closest('.webform-component').siblings('[class*=tooltip]').show();
        },
        function(){
          $(this).closest('.webform-component').siblings('[class*=tooltip]').hide();
        }
      );
      // $('.tooltip-icon').on('touchstart', function(){
      //   $(this).closest('.webform-component').siblings('[class*=tooltip]').addClass('mobile-touch');
      // });
      // $('.tooltip-icon').on('touchend', function(){
      //   $(this).closest('.webform-component').siblings('[class*=tooltip]').removeClass('mobile-touch');
      // });



    }
  };




})(jQuery);
