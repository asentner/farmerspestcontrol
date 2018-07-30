(function($){
    $(document).ready(function(){
        $('#edit-submit').click(function(e){
            var $fileInput = $('#edit-file');
            if(empty($fileInput.val())) {
                e.preventDefault();
                $fileInput.click();
            }
        });
    });
})(jQuery)