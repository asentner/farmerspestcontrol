(function($){

    var foundIds = [];
    var accounts = [];

    var uniqueId = function(mediaObj) {
        var id = '';
        var idx = 0;
        if(mediaObj.machineName) {
            id = mediaObj.machineName;
        }
        else {
            id = 'account';
        }

        idClone = id.toString();
        while(foundIds.indexOf(id) >= 0) {
            ++idx;
            id = idClone + idx;
        }

        foundIds.push(id);
        return id;
    };

    var getTemplate = function(mediaObj, type) {
        mediaObj.type = type;
        if(type != 'other') {
            var typeObj = $('#socialTemplate').data('social-media-settings').filter(function(obj) {
                return obj.machineName == type;
            });
            if(typeObj && JSON.stringify(typeObj) != '[]') {
                typeObj = JSON.parse(JSON.stringify(typeObj.shift()));
                mediaObj = Object.assign(typeObj, mediaObj);
            }
        }


        var $tmp = $($('#socialTemplate').html());
        $tmp.data('social-type', type);
        var hasMachineName = mediaObj.machineName || false;
        var id = uniqueId(mediaObj);
        if(hasMachineName) {
            mediaObj.machineName = id;
        }

        var fieldsetId = $tmp.attr('id');
        $tmp.attr('id', fieldsetId + '--' + id);

        $tmp.filter(function(){
            return $(this).attr('id') || $(this).attr('for');
        }).each(function() {
            var id = $(this).attr('id');
            var forText = $(this).attr('for');
            if(forText) {
                $(this).attr('for', forText + '--' + id);
            }
            if(id) {
                $(this).attr('id', id + '--' + id);
            }
        });

        return updateTemplate($tmp, mediaObj);
    };

    var updateTemplate = function($tmp, mediaObj) {
        var $$ = function(selector) {
            return $tmp.find(selector);
        };
        $$('.account-name').find('.form-text').val(mediaObj.name);
        $$('.account-machine-name').find('.form-text').val(mediaObj.machineName);
        $$('.account-icon').find('.form-text').val(mediaObj.iconClass);
        $$('.account-link').find('.form-text').val(mediaObj.link);
        $$('.account-description').find('.form-text').val(mediaObj.description);

        if(mediaObj.name) {
            $$('.fieldset-legend').text(mediaObj.name);
        }
        if(mediaObj.linkTitle) {
            $$('.account-link').find('label').html(mediaObj.linkTitle + '<span class="form-required" title="This field is required.">*</span>');
        }
        if(mediaObj.linkPlaceholder) {
            $$('.account-link').find('.form-text').attr('placeholder', mediaObj.linkPlaceholder);
        }
        if(mediaObj.linkDescription)  {
            $$('.account-link').find('description').html(mediaObj.linkDescription);
        }
        if(mediaObj.linkDescriptionTitle) {
            $$('.account-description').find('label').html(mediaObj.linkDescriptionTitle);
        }
        if(mediaObj.linkDescriptionDescription) {
            $$('.account-description').find('description').html(mediaObj.linkDescriptionDescription);
        }
        if(mediaObj.hide) {
            $.each(mediaObj.hide, function(hi, hide) {
                $$(hide).hide();
            });
        }

        return $tmp;
    }

    var collectData = function() {
        var data = [];
        $('#sprowt-settings-social-media-accounts fieldset.account-set').each(function(){
            var $set = $(this);
            var $$ = function(selector) {
              return $set.find(selector);
            };
            var mediaObj = {};
            mediaObj.type = $set.data('social-type');
            mediaObj.name = $$('.account-name').find('.form-text').val();
            mediaObj.machineName = $$('.account-machine-name').find('.form-text').val();
            mediaObj.iconClass = $$('.account-icon').find('.form-text').val();
            mediaObj.link = $$('.account-link').find('.form-text').val();
            mediaObj.description = $$('.account-description').find('.form-text').val();
            if(mediaObj.machineName) {
                data.push(mediaObj);
            }
        });
        return data;
    };

    var setData = function() {
        var data = collectData();
        $('#sprowt_settings_social_media').val(JSON.stringify(data));
    };

    var addAccount = function(mediaObj, type) {
        var $tmp = getTemplate(mediaObj, type);
        $('#sprowt-settings-social-media-accounts').append($tmp);
        setData();
        return $tmp;
    };

    var machineNameUnique = function(machineName) {
        var data = collectData();
        data.filter(function(mediaObj) {
            mediaObj.machineName == machineName;
        });
        return data.length > 1;
    };

    var machineNameAccurate = function(machineName) {
        if(!machineName) {
            return true
        }
        else {
            return /^[a-z0-9_]+$/.test(machineName);
        }
    };

    $(document).on('keyup', '#sprowt-settings-social-media-accounts .form-text', function() {
        var $set = $(this).closest('.account-set');
        var name = $set.find('.account-name .form-text').val();
        $set.find('.fieldset-legend').html(name);
        setData();
        var machineName = $set.find('.account-machine-name .form-text').val();
        if(!machineNameUnique(machineName) || !machineNameAccurate(machineName)) {
            $set.find('.account-machine-name .form-text').addClass('error');
        }
        else {
            $set.find('.account-machine-name .form-text').removeClass('error');
        }
    });

    $(document).on('click', '#sprowt-settings-social-media-accounts .remove-button', function(e) {
        e.preventDefault();
        var $set = $(this).closest('.account-set');
        $set.remove();
        setData();
    });

    $(document).on('click', '#sprowt-settings-social-media-add-button', function(e){
        e.preventDefault();
        var type = $('select.sprowt_settings_social_media_add').val();
        if(type) {
            addAccount({}, type);
        }
    });

    $(document).ready(function() {
        var accounts = JSON.parse($('#sprowt_settings_social_media').val());
        $.each(accounts, function(ai, account) {
            var $set = addAccount(account, account.type);
            var machineName = $set.find('.account-machine-name .form-text').val();
            if(!machineNameUnique(machineName) || !machineNameAccurate(machineName)) {
                $set.find('.account-machine-name .form-text').addClass('error');
            }

            var link = $set.find('.account-link .form-text').val();
            if(!link) {
                $set.find('.account-link .form-text').addClass('error');
            }
        });
    });

})(jQuery);
