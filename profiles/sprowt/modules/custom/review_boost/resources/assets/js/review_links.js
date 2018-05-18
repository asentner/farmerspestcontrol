(function($){
    var rb = {
        init: function(){
            var links = rb.getLinks();
            $.each(links, function(i,v){
                rb.addRow(v);
            });

            $('#addRow').click(function(e){
                e.preventDefault();
                rb.addRow();
            });

            $('#table-body').on('keyup', '.machine-name-source', function(){
                var val = $(this).val();
                $(this).closest('div').find('.machine-name-value').text(rb.machinify(val));
                $(this).closest('tr').find('.machine-name-target').val(rb.machinify(val));
            });

            $('#table-body').on('keyup', '.machine-name-target', function(){
                var val = $(this).val();
                $(this).val(rb.machinify(val));
            });

            $('#table-body').on('keyup click', function(){
                rb.updateLinks();
            });

            $('#table-body').on('click', '.admin-link', function(e){
                e.preventDefault();
                $(this).closest('td').find('.form-type-machine-name').show();
                $(this).closest('.field-suffix').remove();
            });

            $('#table-body').on('click', '.removeRow', function(e){
                e.preventDefault();
                $(this).closest('tr').remove();
                rb.updateLinks();
            });

            rb.handleErrors();

        },
        machinify: function(val) {
            return val.replace(/[^A-Za-z0-9\-]/g,'_').toLowerCase();
        },
        addRow: function(obj) {
            if(obj == undefined) {
                obj = {
                    id: $('.link-row').length,
                    title: '',
                    class: '',
                    link: '',
                    default: false,
                    enabled: false
                };
            }

            var html = $('#review_link_row').render(obj);
            $('#table-body').append(html);
        },
        updateLinks: function(){
            val = [];
            $('.link-row').each(function(){
                var id = $(this).attr('id');
                if($('#'+id+'-class').val() != '') {
                    var obj = {
                        id: $('#' + id + '-class').val(),
                        title: $('#' + id + '-title').val(),
                        class: $('#' + id + '-class').val(),
                        link: $('#' + id + '-link').val(),
                        enabled: $('#' + id + '-enabled').prop('checked'),
                        default: $('#' + id + '-default').val() == "1"
                    };
                    if(!rb.handleErrors()) {
                        val.push(obj);
                    }
                }
            });
            $('#review-links').val(JSON.stringify(val));
        },
        getLinks: function(){
            return JSON.parse($('#review-links').val());
        },
        handleErrors: function(){
            if($('.match-error').length > 0) {
                if($('.match-error').hasClass('messages-exist')) {
                    $('.match-error').remove();
                }
                else {
                    $('.messages.error').remove();
                }
            }
            var ids = [];
            if(Drupal.settings.hidden_errors != undefined) {
                ids.push.apply(ids, JSON.parse(Drupal.settings.hidden_errors));
            }
            var current_classes = [];
            var match_error = false;
            $('.link-row').each(function(){
                $(this).removeClass('error');
                var id = $(this).attr('id');
                var obj = {
                    id: $('#' + id + '-class').val(),
                    title: $('#' + id + '-title').val(),
                    class: $('#' + id + '-class').val(),
                    link: $('#' + id + '-link').val(),
                    enabled: $('#' + id + '-enabled').prop('checked'),
                    default: $('#' + id + '-default').val() == "1"
                };
                if($.inArray(obj.class, current_classes) >= 0) {
                    ids.push(obj.id);
                    match_error = true;
                }
                else {
                    current_classes.push(obj.class);
                }
            });

            $.each(ids, function(i,v){
                $('#'+v).addClass('error');
            });

            var $match_error = $('<div class="match-error">All machine names must be unique</div>');
            if(match_error) {
                if($('.messages.error').length > 0) {
                    $match_error.addClass('messages-exist');
                    $('.messages.error').append($match_error);
                }
                else {
                    if($('#console').length == 0) {
                        $('#content').prepend('<div id="console"></div>');
                    }
                    var $messages = $('<div class="messages error"></div>');
                    $messages.append($match_error);
                    $('#console').append($messages);
                }
            }

            return match_error;
        }
    }

    $(document).ready(function(){
        rb.init();
    });
})(jQuery)