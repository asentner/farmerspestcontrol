(function($){
    $(document).ready(function() {
        var $block_link_title = $('#edit-field-block-link-und-0-title');
        var $table_link_title = $('#edit-field-table-link-und-0-title');
        var link_titles = [
            $block_link_title,
            $table_link_title
        ];

        $.each(link_titles, function(i, $link_title){
            var id = $link_title.attr('id');
            var $label = $('label[for="'+id+'"]');
            var $description = $link_title.closest('div').find('.description');
            var $url = $link_title.closest('.link-field-subrow').find('.link-field-url input');
            if($description.length == 0) {
                $description = '<div class="description"></div>';
                $link_title.closest('div').append($description);
            }

            var description_html = $description.html();
            description_html = description_html + " Title required if URL is filled out.";

            $description.html(description_html.trim());


            if($url.val() == '') {
                $label.find('.form-required').hide();
            }
            else {
                $label.find('.form-required').show();
            }
            $url.bind('keyup', function(){
                if($url.val() == '') {
                    $label.find('.form-required').hide();
                }
                else {
                    $label.find('.form-required').show();
                }
            });
        });
    });


})(jQuery)