(function($){

$(document).ready(function(){

    $('.form-item-theme-chooser .form-radio').change(function(){
        $('#edit-theme-chooser .choose_theme_radio_field').removeClass('checked');
        if (this.checked) {
            $(this).siblings('label').find('.choose_theme_radio_field').addClass('checked');
        }
    });
    
    $('.form-item-theme-chooser .form-radio').each(function(){
        if (this.checked) {
            $('#edit-theme-chooser .choose_theme_radio_field').removeClass('checked');
            $(this).siblings('label').find('.choose_theme_radio_field').addClass('checked');
        }
    });
    
});


})(jQuery)