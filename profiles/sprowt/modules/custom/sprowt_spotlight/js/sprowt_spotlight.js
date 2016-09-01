(function($) {

    $.sprowt_spotlight = {
        data: false,
        getData: function() {
            var $this = this;
            $.getJSON('/spotlight-ajax', function(d){
               if(d.success) {
                   $this.data = d.data;
                   $this.populate();
               }
            });
        },
        populate: function(){
            var $sl = this;
            var data = $sl.data;
            var $bar = $('.spot-bar');
            var $elements = $bar.find('.spot-item .data');

            $elements.each(function(){
                var $this = $(this);
                switch(true) {
                    case $this.hasClass('data-sessions'):
                        $this.html(data.sessions.total);
                        break;
                    case $this.hasClass('data-pageviews'):
                        $this.html(data.pageViews.total);
                        break;
                    case $this.hasClass('data-leads'):
                        $this.html(data.leads.total.total);
                        break;
                    case $this.hasClass('data-conversion-rate'):
                        $this.html(data.conversionRates.total);
                        break;
                    case $this.hasClass('data-cost-per-lead'):
                        $this.html(data.costPerLead.total);
                }
            });
        }
    };


    $(function(){
        var $sl = $.sprowt_spotlight;

        window.setInterval(function(){
            $sl.getData();
        }, (60 * 1000));

    });



    Drupal.behaviors.sprowtSpotlight = {
        attach: function(context, settings) {
            //console.log('ok');
        }
    }
})(jQuery);