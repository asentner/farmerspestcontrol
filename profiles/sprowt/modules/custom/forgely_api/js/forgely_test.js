(function($){
    $(document).ready(function(){
        var $form = $('#-forgely-api-test-form');
        $form.submit(function(e){
            e.preventDefault();
        });

        $form.find('#edit-submit').click(function(e){
            e.preventDefault();
            $('#api-results').html('Loading...');
            $('#api-results').load('/ajax/forgely');
        });
    });
})(jQuery)