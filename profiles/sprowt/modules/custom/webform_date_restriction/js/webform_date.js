(function($){
    var empty = function(val){
        return typeof val == 'undefined'
            || typeof val == 'object' && JSON.stringify(val) == '{}'
            || typeof val == 'object' && Array.isArray(val) && JSON.stringify(val) == '[]'
            || val == null
            || val == ''
            || val == false
    };

    var wdtrd = {
        init: function(id, rests){
            var $el = $('.'+id);
            this.rests = rests;
            this.id = id;
            this.$el = $el;
            this.$month = $el.find('.month');
            this.$day = $el.find('.day');
            this.$year = $el.find('.year');
            this.rests = rests;
            this.dateObj = this.getDateObj();
            this.update();
        },
        updateCal: function(){
            var $el = this.$el;
            var $cal = $el.find('.webform-calendar');
            var rests = this.rests;

            var beforeShowDay = function(date) {
                var show = true;
                if(!empty(rests.years)) {
                    $.each(rests.years, function (i, year) {
                        if (parseInt(date.getFullYear()) == parseInt(year)) {
                            show = false;
                        }
                    });
                }

                if(!empty(rests.months)) {
                    $.each(rests.months, function (i, month) {
                        if (parseInt(date.getMonth() + 1) == parseInt(month)) {
                            show = false;
                        }
                    });
                }

                if(!empty(rests.daysoyear)) {
                    $.each(rests.daysoyear, function (i, doy) {
                        var doyArr = doy.split('-');
                        if (parseInt(date.getMonth() + 1) == parseInt(doyArr[0])
                            && parseInt(date.getDate()) == parseInt(doyArr[1])
                        ) {
                            show = false;
                        }
                    });
                }

                if(!empty(rests.daysoweek)) {
                    $.each(rests.daysoweek, function (i, dow) {
                        if (parseInt(date.getDay()) == parseInt(dow)) {
                            show = false;
                        }
                    });
                }

                var compareDates = function(dateStr) {
                    var dateArr = dateStr.split('-');
                    var dateUTC = new Date(Date.UTC(date.getFullYear(), date.getMonth(), date.getDate()));
                    var dateObjUTC = new Date(Date.UTC(dateArr[0], dateArr[1] - 1, dateArr[2]));
                    return dateUTC.valueOf() == dateObjUTC.valueOf();
                }

                if(!empty(rests.days)) {
                    $.each(rests.days, function (i, day) {
                        if (compareDates(day)) {
                            show = false;
                        }
                    });
                }

                if(!empty(rests.phpval)) {
                    $.each(rests.phpval, function (i, day) {
                        var dayObj = new Date(day);
                        if (compareDates(day)) {
                            show = false;
                        }
                    });
                }

                return [show];

            };

            var $webformDatepicker = $el;
            //taken from webform/js/webform.js::Drupal.webform.datepicker

            var startDate = $cal[0].className.replace(/.*webform-calendar-start-(\d{4}-\d{2}-\d{2}).*/, '$1').split('-');
            var endDate = $cal[0].className.replace(/.*webform-calendar-end-(\d{4}-\d{2}-\d{2}).*/, '$1').split('-');
            var firstDay = $cal[0].className.replace(/.*webform-calendar-day-(\d).*/, '$1');
            // Convert date strings into actual Date objects.
            startDate = new Date(startDate[0], startDate[1] - 1, startDate[2]);
            endDate = new Date(endDate[0], endDate[1] - 1, endDate[2]);

            // Ensure that start comes before end for datepicker.
            if (startDate > endDate) {
                var laterDate = startDate;
                startDate = endDate;
                endDate = laterDate;
            }

            var startYear = startDate.getFullYear();
            var endYear = endDate.getFullYear();

            var options = {
                dateFormat: 'yy-mm-dd',
                yearRange: startYear + ':' + endYear,
                firstDay: parseInt(firstDay),
                minDate: startDate,
                maxDate: endDate,
                onSelect: function (dateText, inst) {
                    var date = dateText.split('-');
                    $webformDatepicker.find('select.year, input.year').val(+date[0]).trigger('change');
                    $webformDatepicker.find('select.month').val(+date[1]).trigger('change');
                    $webformDatepicker.find('select.day').val(+date[2]).trigger('change');
                },
                beforeShow: function (input, inst) {
                    // Get the select list values.
                    var year = $webformDatepicker.find('select.year, input.year').val();
                    var month = $webformDatepicker.find('select.month').val();
                    var day = $webformDatepicker.find('select.day').val();

                    // If empty, default to the current year/month/day in the popup.
                    var today = new Date();
                    year = year ? year : today.getFullYear();
                    month = month ? month : today.getMonth() + 1;
                    day = day ? day : today.getDate();

                    // Make sure that the default year fits in the available options.
                    year = (year < startYear || year > endYear) ? startYear : year;

                    // jQuery UI Datepicker will read the input field and base its date off
                    // of that, even though in our case the input field is a button.
                    $(input).val(year + '-' + month + '-' + day);
                }
            };
            options.beforeShowDay = beforeShowDay;
            $cal.datepicker("destroy");
            $cal.datepicker(options);
        },
        getDateObj: function(){
            return {
                day: this.$day.val(),
                month: this.$month.val(),
                year: this.$year.val()
            };
        },
        update: function() {
            var date = this.dateObj;
            var $day = this.$day;
            var $month = this.$month;
            var $year = this.$year;
            var rests = this.rests;
            var disDays = [];

            if(!empty(rests.years)) {
                if($year.is('select')) {
                    $year.find('option').each(function(){
                        var $opt = $(this);
                        $opt[0].disabled = false;
                        $.each(rests.years, function(i, year){
                            if(parseInt($opt.attr('value')) == parseInt(year)) {
                                $opt[0].disabled = true;
                            }
                        });
                    });
                }
            }

            if(!empty(rests.months)) {
                $month.find('option').each(function(){
                    var $opt = $(this);
                    $opt[0].disabled = false;
                    $.each(rests.months, function(i, month){
                        if(parseInt($opt.attr('value')) == parseInt(month)) {
                            $opt[0].disabled = true;
                        }
                    });
                });
            }

            if(!empty(rests.daysoyear)) {
                if(!empty($month.val())) {
                    $day.find('option').each(function(){
                        var $opt = $(this);
                        $.each(rests.daysoyear, function(i, doy){
                            var doyArr = doy.split('-');
                            if($month.val() == doyArr[0]) {
                                if (parseInt($opt.attr('value')) == parseInt(doyArr[1])) {
                                    disDays.push($opt);
                                }
                            }
                        });
                    });
                }
            }

            if(!empty(rests.days)) {
                $.each(rests.days, function(i, date){
                    var dateArr = date.split('-');
                    var y = dateArr[0];
                    var m = dateArr[1];
                    var d = dateArr[2];
                    if(!empty($year.val())
                        && !empty($month.val())
                        && parseInt($year.val()) == parseInt(y)
                        && parseInt($month.val()) == parseInt(m)
                    ) {
                        $day.find('option').each(function() {
                            var $opt = $(this);
                            if(parseInt($opt.val()) == parseInt(d)) {
                                disDays.push($opt);
                            }
                        });
                    }
                });
            }

            if(!empty(rests.phpval)) {
                $.each(rests.phpval, function(i, date){
                    var dateArr = date.split('-');
                    var y = dateArr[0];
                    var m = dateArr[1];
                    var d = dateArr[2];
                    if(!empty($year.val())
                        && !empty($month.val())
                        && parseInt($year.val()) == parseInt(y)
                        && parseInt($month.val()) == parseInt(m)
                    ) {
                        $day.find('option').each(function() {
                            var $opt = $(this);
                            if(parseInt($opt.val()) == parseInt(d)) {
                                disDays.push($opt);
                            }
                        });
                    }
                });
            }

            if(!empty(rests.daysoweek)) {
                $.each(rests.daysoweek, function(i, dayoweek){
                    if(!empty($year.val())
                        && !empty($month.val())
                    ) {
                        $day.find('option').each(function() {
                            var $opt = $(this);
                            if(!empty($opt.val())) {
                                var dateObj = new Date($year.val(), (parseInt($month.val()) - 1), parseInt($opt.val()));
                                var w = dateObj.getDay();
                                if(parseInt(w) == dayoweek) {
                                    disDays.push($opt);
                                }
                            }
                        });
                    }
                });
            }

            $day.find('option').each(function() {
                var $opt = $(this);
                $opt[0].disabled = false;
                if(!empty($opt.val()) && !empty($month.val())) {
                    var year = $year.val();
                    if (empty(year)) {
                        year = 1971;
                    }
                    var dateObj = new Date(year, (parseInt($month.val()) - 1), parseInt($opt.val()));
                    if ((parseInt(dateObj.getMonth()) + 1) != parseInt($month.val())) {
                        disDays.push($opt);
                    }
                }
            });

            $.each(disDays, function(i, $opt){
                $opt[0].disabled = true;
            });

            var inputs = [$month, $day, $year];
            $.each(inputs, function(i, $input) {
                if($.isArray($input.val())) {
                    $input.val('');
                }
            });

        }
    };



    Drupal.behaviors.webformDateRestrictionDate = {
        attach: function (context, settings) {
            var datefields = settings.webform_date_restriction_date;
            $.each(datefields, function(i, v){
                var id = v.id;
                var rests = v.rests;
                var jObj = Object.create(wdtrd);
                jObj.init(id, rests);
                if(jObj.$el.find('.webform-calendar').length) {
                    jObj.updateCal();
                }

                jObj.$month.change(function(){
                    jObj.init(id, rests);
                });

                jObj.$day.change(function(){
                    jObj.init(id, rests);
                });

                if(jObj.$year.is('select')) {
                    jObj.$year.change(function(){
                        jObj.init(id, rests);
                    });
                }
                else {
                    jObj.$year.keyup(function(){
                        jObj.init(id, rests);
                    });
                }
            });
        }
    };
})(jQuery);