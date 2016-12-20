(function($){
    $(document).ready(function(){
        var okayToRemove = false;
        $(document).delegate('.removeYear', 'mousedown click', function(e){
            e.preventDefault();
            var $this = $(this);
            var $parent = $(this).closest('.form-wrapper');
            var $remove = $parent.find('.removeYearVal');
            var $submit = $parent.find('.removeButtonAjax');
            $(this).hide();
            $submit.closest('div').show();
            $remove.val('1');
            $submit.trigger('mousedown');
        });

        $(document).delegate('.removeDay', 'mousedown click', function(e){
            e.preventDefault();
            var $this = $(this);
            var $parent = $(this).closest('.form-wrapper');
            var $remove = $parent.find('.removeDayVal');
            var $submit = $parent.find('.removeButtonAjax');
            $(this).hide();
            $submit.closest('div').show();
            $remove.val('1');
            $submit.trigger('mousedown');
        });

        $(document).delegate('.removeDayoyear', 'mousedown click', function(e){
            e.preventDefault();
            var $this = $(this);
            var $parent = $(this).closest('.form-wrapper');
            var $remove = $parent.find('.removeDayoyearVal');
            var $submit = $parent.find('.removeButtonAjax');
            $(this).hide();
            $submit.closest('div').show();
            $remove.val('1');
            $submit.trigger('mousedown');
        });

        $(document).delegate('.removePhp', 'mousedown click', function(e){
            e.preventDefault();
            var $this = $(this);
            var $parent = $(this).closest('.form-wrapper');
            var $remove = $parent.find('.removePhpVal');
            var $submit = $parent.find('.removeButtonAjax');
            $(this).hide();
            $submit.closest('div').show();
            $remove.val('1');
            $submit.trigger('mousedown');
        });
    });
})(jQuery)