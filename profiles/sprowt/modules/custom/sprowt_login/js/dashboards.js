(function($){
    $(document).ready(function(){
        var $wrap = $('#dashboards');
        if($wrap.length > 0) {
            var $$ = function(sel) {
                return $wrap.find(sel);
            }

            var $links = $$('#tab-links');
            var $tabs = $$('#tabs');

            $links.find('a').click(function(e){
                e.preventDefault();
                $links.find('a').removeClass('active');
                $tabs.find('.tab').hide();
                var id = $(this).attr('href');

                $(this).addClass('active');

                var hash = '#tab-' + id.replace( /^#/, '' );
                window.location.hash = hash;

                var $activeTab = $tabs.find(id);
                $tabs.find('.tab').removeClass('active');
                $activeTab.show();
                $activeTab.addClass('active');
            });

            var hashId = window.location.hash.replace('tab-', '');
            var tabFound = false;
            $links.find('a').each(function(){
                var $link = $(this);
                if(hashId == $link.attr('href')) {
                    tabFound = true;
                    $link.click();
                }
            });

            if(!tabFound) {
                var $activeLink = $links.find('li').first().find('a');
                $links.find('a').removeClass('active');
                $activeLink.addClass('active');

                var $activeTab = $tabs.find($activeLink.attr('href'));
                $tabs.find('.tab').removeClass('active');
                $activeTab.show();
                $activeTab.addClass('active');
            }
        }
    });
})(jQuery)