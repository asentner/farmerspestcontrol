(function ($) {

  Drupal.behaviors.sprowtEbooking = {
    attach: function (context, settings) {
      var $target = $('.node-ebooking').not('.page-node-edit');
      var $fieldsets = $('fieldset.panel');

      // add previous, next, etc buttons and validation error message
      if ($target.length && !($target.hasClass('processed'))) {

        // clear form elements on load (so when you return from the summary page, it resets the form)
        $(document).ready(function () {
          var $summaryPage = $('[value="Page break"]');

          if (!($summaryPage.length)) {
            $('input[type="radio"]').prop('checked', false);
            // re-select the selected package so that auto selecting the package will work
            $('.package.selected').parent().siblings('.form-radio').prop('checked', true);
            $('select').prop('selectedIndex',0);
          };

          if($summaryPage.length) {
              if(typeof Drupal.ajax != 'undefined') {
                  /**
                   * Override webformStripeCheckout
                   */
                  Drupal.ajax.prototype.commands.webformStripeCheckout = function (ajax, data, status) {
                      var $form = $(ajax.form[0]);
                      var $email = $form.find('.form-email').first();
                      StripeCheckout.open($.extend(data.params, {
                          email: $email.val(),
                          token: function (token) {
                              $('.webform-stripe-token', ajax.form.context).val(token.id + ':' + token.email);
                              ajax.form[0].submit();
                          }
                      }));
                  };
              }
          }
        });

        // add 'previous' buttons and 'intialize' class to panels
        $fieldsets.not(':first').each(function(){
          $(this).addClass('initialize');
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

        // add the 'Review' button
        $fieldsets.filter(':last').append('<a class="button button-checkout" href="#">Review Order</a>')

        // make the first panel active
        $fieldsets.filter(':first').addClass('active');

        // add anchor/id to each panel to scroll to when next/previous is clicked
        $fieldsets.attr('id', 'panel');

        // add validation error messages and step numbers
        var stepNumber = 1;
        $fieldsets.each(function(){
          $(this).prepend('<div class="validation-error"><span>Submission Error: Please correct the information below.</span></div>');
          $('.validation-error').hide(); // hide the validation error messages
          $(this).prepend('<h3 class="step-number">Step ' + stepNumber + ' of ' + ($fieldsets.length+1) + '</h3>');
          stepNumber++;
        });

        // add link to return to 'panel' form layout
        if($fieldsets.length) {
          $('.node--webform').append('<a class="panel-form" href="#">Take me back to the panels!</a>');
        };

        // make the 'pop-ups' closeable
        $('[class*=if-business]').prepend('<span class="close-popup">Close</span>');

        $('.close-popup').click(function(){
          $('input.business-disable').prop('checked', false);
          $('[class*=if-business]').addClass('webform-conditional-hidden').hide();
        });

        $target.addClass('processed');
      } // end panel 'build out'


      if ($target.length) {

        // next button validation and functionality
        $('.button-next').click(function(e){
          e.preventDefault();
          // make sure all of the answers have been filled out
          var $webformComponents = $(this).siblings('.fieldset-wrapper').find('.webform-component');
          var validation = validate($webformComponents);

          // after checking validation make the next work
          if($(this).parent('fieldset').hasClass('active') && validation == true) {
            $(this).parent('fieldset').removeClass('active').addClass('left');
            $(this).parent('fieldset').next('.panel').removeClass('right').addClass('active');
            $(this).parent('fieldset').next('.panel').removeClass('initialize');
            $(this).siblings('.validation-error').hide();
            panelScroll(750);
          }
          else if(validation == false){
            $(this).siblings('.validation-error').show();
            panelScroll(0);
          }
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

        // make the validation error dissapear when a user makes a selection (not just 'next step')
        $('input:radio').change(function(){
          $(this).parents('.fieldset-wrapper').siblings('.validation-error').hide();
        });
        $('select').change(function(){
          $(this).parents('.fieldset-wrapper').siblings('.validation-error').hide();
        });
        $('input:text').change(function(){
          $(this).parents('.fieldset-wrapper').siblings('.validation-error').hide();
        });
        $('input').filter('[type=email]').change(function(){
          $(this).parents('.fieldset-wrapper').siblings('.validation-error').hide();
        });

        // prevent default action of inactive previous button on first panel
        $('.button.inactive').click(function(e){
          e.preventDefault();
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
        $('select[id*=time]').change(function(){
          $('.button-checkout').addClass('button-disable');
          $('.button-checkout').delay(1000).queue(function(){
            $(this).removeClass('button-disable').dequeue();
          });
        });

        $('.button-checkout').click(function(e){
          if(!$(this).hasClass('button-disable')) {
            e.preventDefault();

            // var validation = true;
            var $webformComponents = $(this).siblings('.fieldset-wrapper').find('.webform-component');
            var validation = validate($webformComponents);

            if(validation == true) {
              $('.webform-next').click();
            }
            else if(validation == false){
              $(this).siblings('.validation-error').show();
              panelScroll(0);
            }

          } // endif
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

        // if a package is pre-selected, make its label "active"
        $packages.find(':checked').siblings('label').find('.package').addClass('selected');

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
      if(!($('.tooltip-icon').length)) {
        $('.amount-due').find('p:last-of-type').append('<span class="tooltip-icon"></span>');

        // add ability to close the tooltip on mobile-touch
        $('.tooltip-icon').closest('.webform-component').siblings('[class*=tooltip]').prepend('<span class="close-tooltip">Close</span>');
      };

      // make tool tip icons work
      $('.tooltip-icon').hover(
        function(){
          $(this).closest('.webform-component').siblings('[class*=tooltip]').show();
        },
        function(){
          $(this).closest('.webform-component').siblings('[class*=tooltip]').hide();
        }
      );
      $('.close-tooltip').click(function(){
        $(this).parent().hide();
      });


      // add step numver to Checkout page
      // first extract the ebooking_summary fieldset number from the class
      // http://stackoverflow.com/questions/7033334/how-to-extract-number-from-a-string-in-javascript
      if ( $('fieldset.ebooking_summary').length && !($('fieldset.ebooking_summary').hasClass('step-numbers')) ) {
        var finalStep = $('fieldset.ebooking_summary').attr('class').replace(/[^0-9\.]/g, '');
        var finalStep = parseInt(finalStep, 10);
        $('fieldset.ebooking_summary').prepend('<h3 class="step-number">Step ' + finalStep + ' of ' + finalStep + '</h3>');
        $('fieldset.ebooking_summary').addClass('step-numbers');
        // add validation error message
        $('fieldset.ebooking_summary').prepend('<div class="validation-error"><span>Submission Error: Please correct the information below.</span></div>');
        $('.validation-error').hide(); // hide the validation error messages
      };

      // move the form-actions inside the the checkout panel
      if( $('fieldset.ebooking_summary').length && !($('.form-actions').hasClass('moved')) ) {
        $('.form-actions').append('<a class="button payment">Proceed to Checkout</a>');
        $('.form-actions').find('.webform-submit').hide();
        $('.form-actions').detach().appendTo('fieldset.ebooking_summary > .fieldset-wrapper');
        $('.form-actions').addClass('moved');
      };

      // perform validation on the form submit button
      $('.button.payment').click(function(e){
        // var validation = true;
        $webformComponents = $('.webform-component');
        var validation = validate($webformComponents);

        if(validation == true) {
          $('.form-submit').mousedown();
          $('.validation-error').hide();
        }
        else if(validation == false){
          $('.validation-error').show();
          $('html, body').animate({
              scrollTop: $('fieldset.ebooking_summary').offset().top - 50
            }, 1000);
        }

      });

      // validation function
      function validate($webformComponents) {
        validation = true;

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
          // required exmail input fields
          else if($(this).find('input:required').filter('[type=email]').length > 0
              && !(isEmail($(this).find('input:required').filter('[type=email]').val())) ) {
            validation = false;
          }
          // required inputs other than email fields
          else if($(this).find('input:required').length > 0 && $(this).find('input:required').val().length < 1) {
            validation = false;
          }
        });
        return validation;

      };


      // email validation function - http://stackoverflow.com/questions/2507030/email-validation-using-jquery
      function isEmail(email) {
        var regex = /^([a-zA-Z0-9_.+-])+\@(([a-zA-Z0-9-])+\.)+([a-zA-Z0-9]{2,4})+$/;
        return regex.test(email);
      };



    }
  };

})(jQuery);
