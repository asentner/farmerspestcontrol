(function($){
    var url = new URI();
    $(document).ready(function(){
        var q = url.search(true);

        var $form = $('.special-offer-form');
        if($form.length > 0) {
            var optionList = $('#edit-submitted-which-special-offer-are-you-interested-in');
            var option = $('#edit-submitted-which-special-offer-are-you-interested-in option');
            
            option.each(function() {
                if(q.offer === $(this).attr('value')) {
                    optionList.val(q.offer);
                }
            });
        }
    });
})(jQuery)