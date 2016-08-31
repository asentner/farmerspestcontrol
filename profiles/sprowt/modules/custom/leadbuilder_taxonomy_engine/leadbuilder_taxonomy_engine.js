(function($) {
  $(document).ready(function() {
    if ($('.page-admin-structure-taxonomy-markets-add').length ||
    	$('.page-taxonomy-term-edit #taxonomy-form-term[action$="markets"]').length ||
    	$('.page-admin-structure-taxonomy-services-add').length ||
    	$('.page-taxonomy-term-edit #taxonomy-form-term[action$="services"]').length) {
    	//Set message
    	var message = 'Name cannot contain the string " in "';
    	//Attach to submit buttons
    	$('#taxonomy-form-term #edit-submit').click(function(e) {
    		if ($('#taxonomy-form-term #edit-name').val().indexOf(' in ') !== -1) {
    			e.preventDefault();
    			alert(message);
    		}
    	});
    }
  });
})(jQuery);