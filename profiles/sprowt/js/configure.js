(function($){
    $('.messages').hide();
    $(document).ready(function(){
        if($('.messages').hasClass('status')){
            var interior = $('.messages.status').html();

            var html = 'Sprowt Installed! Click <a href="#" class="status_messages_toggle">here</a> to see module status messages';
            html += '<div class="status_messages" style="display:none;">';
            html += '<div style="text-align:right;"><a href="#" class="status_messages_toggle">Close</a></div><br>'
            html += interior;
            html += '</div>';
            
            $('.messages.status').html(html);
            
            $('.messages.status .status_messages_toggle').on('click', function(e){
                e.preventDefault();
                $('.messages .status_messages').slideToggle();
            });
        }
        $('.messages').show();
    });
})(jQuery)