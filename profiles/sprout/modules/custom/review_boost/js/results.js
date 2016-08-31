(function($){
    //from http://stackoverflow.com/questions/5999118/add-or-update-query-string-parameter
    function UpdateQueryString(key, value, url) {
        if (!url) url = window.location.href;
        var re = new RegExp("([?&])" + key + "=.*?(&|#|$)(.*)", "gi"),
            hash;

        if (re.test(url)) {
            if (typeof value !== 'undefined' && value !== null)
                return url.replace(re, '$1' + key + "=" + value + '$2$3');
            else {
                hash = url.split('#');
                url = hash[0].replace(re, '$1$3').replace(/(&|\?)$/, '');
                if (typeof hash[1] !== 'undefined' && hash[1] !== null)
                    url += '#' + hash[1];
                return url;
            }
        }
        else {
            if (typeof value !== 'undefined' && value !== null) {
                var separator = url.indexOf('?') !== -1 ? '&' : '?';
                hash = url.split('#');
                url = hash[0] + separator + key + '=' + value;
                if (typeof hash[1] !== 'undefined' && hash[1] !== null)
                    url += '#' + hash[1];
                return url;
            }
            else
                return url;
        }
    }

    //from: http://stackoverflow.com/questions/901115/how-can-i-get-query-string-values-in-javascript
    var params = (function(a) {
        if (a == "") return {};
        var b = {};
        for (var i = 0; i < a.length; ++i)
        {
            var p=a[i].split('=');
            if (p.length != 2) continue;
            b[p[0]] = decodeURIComponent(p[1].replace(/\+/g, " "));
        }
        return b;
    })(window.location.search.substr(1).split('&'))

    var rb_filters = {
        init: function(){
            var filters = params['filters'];
            if(filters != undefined){
                $('#current-filters-hidden').val(filters);
            }
            else {
                $('#current-filters-hidden').val('[]');
            }
            var $csvLink;
            $('.action-links a').each(function(){
                if(this.href.indexOf('/admin/survey/results/csv') >= 0) {
                    $csvLink = $(this);
                }
            });

            if($csvLink != undefined){
                $csvLink.attr('href', UpdateQueryString('filters', filters, $csvLink.attr('href')));
            }


            this.show();
        },
        clear: function(){
            $('.filter-wrap').each(function(){
                var $wrap = $(this);

                $wrap.find('input').val('');
                $wrap.find('.date-type').val('all');
            });
        },
        show: function(){
            var current = JSON.parse($('#current-filters-hidden').val());
            var $tags = $('#current-filters');
            $tags.html('');
            $.each(current, function(i, filter){
               var $tag = $('<div class="filter-tag" data-filter-id="'+filter.id+'"></div>');
                $tag.addClass('filter-tag-'+filter.key);
                $tag.addClass('tag-'+filter.type);
                var val = '';
                switch(filter.type) {
                    case 'date':
                        if(filter.value == 'all') {
                            val = 'All Time';
                        }
                        else {
                            if(filter.dateType == 'custom') {
                                val = filter.value.from + ' to ' + filter.value.to;
                            }
                            else {
                                val = 'Last ' + filter.value.dateType + ' Days';
                            }
                        }
                        break;
                    case 'text':
                        var val = filter.value;
                        break;
                }


                $tag.append('<a href="#" class="remove-tag">x</a><strong>'+filter.title+'</strong>: <span>'+val+'</span>');
                $tags.append($tag);
            });
        },
        add: function(key) {
            var current = JSON.parse($('#current-filters-hidden').val());
            var currentIds = [];
            $.each(current, function(i, f){
                currentIds.push(f.id);
            });
            var $wrap = $('#filter-'+key);
            var $val = $wrap.find('.filter-val');
            var filter =  {};
            var type = $val.data('filter-type');
            var i = 0;
            var id = type+'-'+i;
            while($.inArray(id, currentIds) >= 0) {
                i++;
                id = type+'-'+i;
            }
            filter.id = id;
            filter.title = $wrap.find('.title').text();
            filter.type = type;
            filter.key = key;
            
            switch(type) {
                case 'date':
                    var dateType = $val.find('.date-type').val();
                    if(dateType == 'all') {
                        var val = 'all';
                    }
                    else if(dateType == 'custom') {
                        var val = {
                            from: $val.find('.from').val(),
                            to: $val.find('.to').val(),
                            dateType: 'custom'
                        }
                        if(val.from == '' || val.to == '') {
                            val = '';
                        }
                    }
                    else {
                        var val = {};
                        var now = new Date();
                        val.to = jQuery.datepicker.formatDate('mm/dd/yy', now);

                        var day = 8.64e+7;
                        var fromDate = new Date(now.valueOf() - (day * parseInt(dateType)));
                        val.from = jQuery.datepicker.formatDate('mm/dd/yy', fromDate);
                        val.dateType = dateType;
                    }
                    break;
                case 'text':
                    var val = $val.find('input').val();
                    break;
            }
            if(val != undefined && val != '') {
                filter.value = val;
                current.push(filter);
                $('#current-filters-hidden').val(JSON.stringify(current));
                this.apply();
            }
        },
        remove: function(id) {
            var current = JSON.parse($('#current-filters-hidden').val());
            var newFilters = [];
            $.each(current, function(i,v){
                if(v.id != id) {
                    newFilters.push(v);
                }
            });
            $('#current-filters-hidden').val(JSON.stringify(newFilters));
            this.apply();
        },
        apply: function(){
            var filters = $('#current-filters-hidden').val();
            var url = UpdateQueryString('filters', filters);
            window.location = url;
        }
    }

    $(document).ready(function(){
        if(params['per_page'] != undefined) {
            $('#result-count').val(params['per_page']);
        }
        rb_filters.init();

        $('#add-filter').click(function(){
            $(this).prop('disabled', true);
            rb_filters.add($('#filter-select').val());
        });

        $('#current-filters').on('click', '.remove-tag', function(e){
            e.preventDefault();
            var $tag = $(this).closest('.filter-tag');
            rb_filters.remove($tag.data('filter-id'));
        });

        $('#apply-filters').click(function(){
            rb_filters.apply();
        });

        $('.filter-wrap input').keyup(function(e){
            if(e.which == 13) {
                $('#add-filter').click();
            }
        });

        $('#result-count').change(function(){
            window.location = UpdateQueryString('per_page', $(this).val());
        });

        $('#filter-' +  $('#filter-select').val()).show();
        $('#filter-select').change(function(){
            if($(this).val() == 'none') {
                $('.filters').hide();
            }
            else {
                $('.filters').show();
            }
            $('.filter-wrap').hide();
            $('#filter-' + $(this).val()).show();
        });

        $('.date-type').change(function(){
            var $wrap = $(this).closest('.filter-wrap');
            $wrap.find('.custom-range').hide();
            if($(this).val() == 'custom') {
                $wrap.find('.custom-range').show();
            }
        });

        jQuery('.datepick').datepicker();
    });
})(jq11)