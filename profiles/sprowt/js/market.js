(function($){
    $(document).ready(function(){
        if ($('#region_markets').val() == '{}') {
            $.market_setup.addRegion(true);
        }
        else {
            var regions = JSON.parse($('#region_markets').val());
            $.market_setup.regionInit(regions);
        }
        
        if ($('#services_hidden').val() == '[]') {
            $.market_setup.addService(true);
        }
        else {
            var services = JSON.parse($('#services_hidden').val());
            $.market_setup.serviceInit(services);
        }
        
        
        
        $('#regions').on('keyup blur', '.regionName', function(){
            $.market_setup.updateValues();
        });
        $('#regions').on('keyup blur', '.marketName', function(){
            $.market_setup.updateValues();
        });
        
        $('#addRegion').click(function(){
            $.market_setup.addRegion();
        });
        
        $('#regions').on('keydown', '.regionName', function(e){
            if (e.which == 13) {
                e.preventDefault();
                var regionId = $(this).data('regionid');
                var marketId = $.market_setup.addMarket(regionId);
                $('#'+marketId).find('input').focus();
            }
        });
        
        $('#regions').on('keydown', '.marketName', function(e){
            if (e.which == 13) {
                e.preventDefault();
                var regionId = $(this).closest('li').data('regionid');
                var marketId = $.market_setup.addMarket(regionId);
                $('#'+marketId).find('input').focus();
            }
        });
        
        $('#regions').on('click', '.addMarket', function(){
            var regionId = $(this).data('regionid');
            $.market_setup.addMarket(regionId);
        });
        
        $('#regions').on('click', '.removeRegion', function(){
            var regionId = $(this).data('regionid');
            $.market_setup.removeRegion(regionId);
        });
        
        $('#regions').on('click', '.removeMarket', function(){
            $(this).closest('.market').remove();
            $.market_setup.updateValues();
        });
        $('#addService').click(function(){
            $.market_setup.addService();
        });
        $('#services').on('click', '.removeService', function(){
            $(this).closest('.service').remove();
            $.market_setup.updateServices();
        });
        $('#services').on('keyup blur', '.serviceName', function(e){
            $.market_setup.updateServices();
        });
        
        $('#services').on('keydown', '.serviceName', function(e){
            if (e.which == 13) {
                e.preventDefault();
                $.market_setup.addService();
                $(this).closest('li').siblings('li').find('input').focus();
            }
        });
        
        
        if ($('#hidden_errors').val() != '') {
            var errors = JSON.parse($('#hidden_errors').val());
            $.each(errors, function(i,v){
                $(v).addClass('error');
            });
        }
        

        $('#bulkAddServices').click(function(e){
            e.preventDefault();
            $('#bulkServiceAddArea').val('');
            $('#bulk-services-form').slideToggle();
        });

        $('#bulkAddServicesSubmit').click(function(e){
            e.preventDefault();
            var services = $('#bulkServiceAddArea').val().trim().split("\n");
            $.each(services, function(i,service){
                if(service != '') {
                    service = service.trim();
                    $.market_setup.addService(undefined, undefined, service);
                }
            });
            $('#bulkServiceAddArea').val('');
            $('#bulk-services-form').slideToggle();
        });

        $('#regions').on('click', '.addMarketBulk', function(){
            var regionId = $(this).data('regionid');
            $('#'+regionId).find('.marketBulkText').val('');
            $('#'+regionId).find('.marketBulkWrap').slideToggle();
        });

        $('#regions').on('click', '.addMarketBulkSubmit', function(){
            var regionId = $(this).data('regionid');
            var markets = $('#'+regionId).find('.marketBulkText').val().trim().split("\n");
            $.each(markets, function(i,market){
                market = market.trim();
                $.market_setup.addMarket(regionId, market);
            });
            $('#'+regionId).find('.marketBulkText').val('');
            $('#'+regionId).find('.marketBulkWrap').slideToggle();
        });

    });
    
    $.market_setup = {
        nextItem: function(jqObj){
            var greatestnumber = 0;
            jqObj.each(function(){
                var id = $(this).attr('id');
                var num = parseInt(id.split('-').pop());
                if (num > greatestnumber) {
                    greatestnumber = num;
                }
            });
            
            return greatestnumber + 1;
        },
        updateValues: function(){
            rmVal = {};
            $('.region').each(function(){
                var regionId = $(this).attr('id');
                var regionName = $(this).find('.regionName').val();
                var markets = [];
                $('#'+regionId+" .market").each(function(){
                    var marketName = $(this).find('.marketName').val();
                    var marketId = $(this).attr('id')
                    var obj = {};
                    obj[marketId] = marketName;
                    markets.push(obj);
                });
                rmVal[regionId] = {regionName:regionName, markets:markets};
            });
            $('#region_markets').val(JSON.stringify(rmVal));
        },
        addRegion: function(omitRemove, regionId, regionName){
            if (omitRemove != undefined
                && omitRemove == true) {
                var addRemove = false;
            }
            else {
                addRemove = true;
            }
            
            if (regionId == undefined) {
                regionId = "region-" + $.market_setup.nextItem($('.region'));
            }
            
            var obj = {
                id:regionId,
                addRemove: addRemove,
            }
            
            if (regionName != undefined) {
                obj.regionName = regionName;
            }
            else {
                obj.regionName = '';
            }
            
            
            var region = $('#newRegion').render(obj);
            $('#regions').append(region)
            $.market_setup.updateValues();
        },
        removeRegion: function(regionId) {
            $('#'+regionId).remove();
            $.market_setup.updateValues();
        },
        addMarket: function(regionId, marketName, marketId) {
            var obj = {
                regionId:regionId
            }
            if (marketName != undefined) {
                obj.marketName = marketName;
            }
            if (marketId != undefined) {
                obj.marketId = marketId;
            }
            else {
                obj.marketId = regionId + "-market-" + $.market_setup.nextItem($('#'+regionId+" .market"));
            }
            
            var market = $('#newMarket').render(obj);
            $('#'+regionId+' .region-markets').append(market);
            $.market_setup.updateValues();
            return obj.marketId;
        },
        updateServices: function(){
            var services = [];
            $('.service').each(function(){
                var serviceId = $(this).attr('id');
                var obj = {};
                obj[serviceId] = $(this).find('.serviceName').val();
                services.push(obj);
            });
            $('#services_hidden').val(JSON.stringify(services));
        },
        addService: function(omitRemove, serviceId, serviceName){
            if (omitRemove != undefined
                && omitRemove == true) {
                var addRemove = false;
            }
            else {
                addRemove = true;
            }
            if (serviceId == undefined) {
                serviceId = "service-"+$.market_setup.nextItem($('.service'));
            }
            
            var obj = {
                id: serviceId,
                addRemove: addRemove
            }
            
            if (serviceName != undefined) {
                obj.serviceName = serviceName;
            }
            else {
                obj.serviceName = "";
            }
            
            var service = $('#newService').render(obj);
            $('#services').append(service);
            $.market_setup.updateServices();
        },
        regionInit: function(regions){
            var first = true;
            $.each(regions,function(regionId,v){
                if (first) {
                    first = false;
                    $.market_setup.addRegion(true, regionId, v.regionName);
                }
                else {
                    $.market_setup.addRegion(false, regionId, v.regionName);
                }
                
                $.each(v.markets, function(i,v){
                    for(marketId in v){
                        $.market_setup.addMarket(regionId,v[marketId],marketId);
                    }
                });
            });
        },
        serviceInit: function(services){
            var first = true;
            $.each(services, function(i,v){
                for(serviceId in v){
                    if (first) {
                        first = false;
                        $.market_setup.addService(true, serviceId, v[serviceId]);
                    }
                    else {
                        $.market_setup.addService(false, serviceId, v[serviceId]);
                    }
                }
            })
        }
    }
})(jQuery)