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