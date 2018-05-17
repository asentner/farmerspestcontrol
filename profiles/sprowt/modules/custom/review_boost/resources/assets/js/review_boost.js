// (function($){
//
//     $(document).ready(function() {
//
//         function Undelivered(){
//
//         }
//
//         Undelivered.prototype.checkCallback = function(){
//
//             //todo add timeout
//             setInterval(function(){
//                 $.ajax({
//                     type:"POST",
//                     url:"/sms/callback",
//                     success: function(data) {
//                         $('#undelivered').text("Some message(s) were not delivered. Please click here to view the phone numbers.");
//                     }
//                 });
//             },1000);
//         };
//
//         Undelivered.prototype.setRead = function(){
//             //ajax to url that will update database of all undelivered texts
//         };
//
//         Undelivered.prototype.getRead = function(){
//             //will i need this?
//         };
//
//
//         function init(){
//             var undelivered = new Undelivered();
//             undelivered.checkCallback();
//         }
//
//     });
//
//
//
// })(jQuery);


(function($){

  //todo load only on customer-survey template
  $(document).ready(function(){
    function Review(){
      this.reviewLinks = $('ul.review-boost-review-links');
    }

    /**
     * Logs every time a user clicks on a review link
     */
    Review.prototype.logClick = function() {
      var $this = this;
      this.reviewLinks.children().click(function(e){
        $this.handleClick(this.className,$this.fetchTokenFromUrl());
      });
    };

    /**
     * Performs an ajax post to the server with the user token and link class that was clicked
     *
     * @param link
     * @param token
     */
    Review.prototype.handleClick = function(link,token){
      $.ajax({
        type:"POST",
        url:"/review/links/get-clicked-link",
        data:{'_link':link,'_token':token},
        dataType:'json',
        success: function(data) {
          //woohoo
        }
      });
    };

    /**
     * Parses url for token and returns it
     * @returns {string}
     */
    Review.prototype.fetchTokenFromUrl = function(){
      //parse relative url path
      var path = window.location.pathname;
      return path.split("/").slice(1)[1]; //remove first / from array, fetch the second param, and return the value
    };

    /**
     * Returns an array of all the class names of the review url's on the page.
     * @returns {any[]}
     */
    Review.prototype.getLinksOnPage = function(){
      var $this = this;
      var reviewLinks = this.reviewLinks.children();
      var linkClass = Array();
      reviewLinks.each(function(index){
        linkClass.push(this.className);
      });
      return linkClass;
    };

    var review = new Review();
    review.logClick();

  });


})(jQuery);