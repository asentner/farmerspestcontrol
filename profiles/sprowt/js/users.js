(function($){
    $(document).ready(function(){
        
        $.users.default_image = '/profiles/sprowt/images/default.jpg';
        
        if ($('#users_hidden').val() != "[]") {
            var default_users = JSON.parse($('#users_hidden').val());
            $.each(default_users, function(i,v){
                $.users.addUser(v);
            });
        }
        
        if ($('#hidden_errors').val() != "") {
            $.each(JSON.parse($('#hidden_errors').val()), function(i,v){
                $(v).addClass('error');
            });
        }
        
        $('#addUser').click(function(){
            var userFile = $('#user-drop-down').val();
            if(userFile == 0) {
                $.users.addUser();
            }
            else {
                $.getJSON(userFile, function(userObj){
                    userObj.id = userObj.username;
                    userObj.password = '';
                    $.users.addUser(userObj);
                });
            }
        });
        
        $('#users').on('click', '.removeUser', function(){
            var userId =  $('#'+$(this).data('user')).attr('id');
            $.users.removeImage(userId);
            $('#'+$(this).data('user')).remove();
            $.users.updateUsers();
        });
        
        $('#users').on('change keyup', 'input', function(){
            $.users.updateUsers();
        });
        
        $('#users').on('keyup', 'textarea', function(){
            $.users.updateUsers();
        });
        
        $('#users').on('change', '.image-file', function(){
            var userId = $(this).closest('.user').attr('id');
            $.users.addFile(userId);
        });
        
        $('#users').on('click', '.removeImage', function(){
            var userId = $(this).closest('.user').attr('id');
            $.users.removeImage(userId);
        });
    });
    
    $.users = {
        user_text_fields: [
            'username',
            'password',
            'email',
            'first_name',
            'last_name',
            'position',
            'google_plus_id',
            'Description'
        ],
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
        addUser: function(UserObj){
            if (UserObj == undefined) {
                UserObj = {
                    id: "user-" + $.users.nextItem($('.user')),
                    image: $.users.default_image,
                };
            }
            
            if (UserObj.image == undefined) {
                UserObj.image = $.users.default_image;
            }
            
            if (UserObj.roles != undefined) {
                $.each(UserObj.roles, function(i,v){
                    switch(v) {
                        case 'authenticated user':
                            UserObj.authenticated_check = 'checked="checked"';
                            break;
                        case 'administrator':
                            UserObj.admin_check = 'checked="checked"';
                            break;
                        case 'content admin':
                            UserObj.content_check = 'checked="checked"';
                            break;
                    }
                });
            }
            
            var user = $('#newUser').render(UserObj);
            $('#users').append(user);
            $.users.updateUsers();
        },
        updateUsers: function(){
            var users = [];
            $('.user').each(function(){
                var id = $(this).attr('id');
                var obj = {};
                
                $.each($.users.user_text_fields, function(i,v){
                    var textVal = $('#' +id+"-"+v).val();
                    if (textVal != '' && textVal != undefined) {
                        obj[v] = $('#' +id+"-"+v).val();
                    }
                });
                
                var roles = [];
                
                $('#'+id+" .role-checks input").each(function(){
                    if (this.checked) {
                        roles.push($(this).val());
                    }
                });
                
                if (JSON.stringify(roles) != '[]') {
                    obj.roles = roles;
                }
                
                var image = $('#'+id+" .image_wrap img").attr('src');
                if (image != $.users.default_image) {
                    obj.image = image;
                }
                
                obj.id = id;
                users.push(obj);
            });
            
            $('#users_hidden').val(JSON.stringify(users));
        },
        addFile: function(userId){
            var file = $('#'+userId+" .image-file")[0].files[0];
            if(file != undefined){
              formData = new FormData();
              if(!!file.type.match(/image.*/)){
                formData.append("action", "addImage");
                formData.append("image", file);
                formData.append("user_id", userId);
                $.ajax({
                  url: "/profiles/sprowt/ajax_image_handler.php",
                  type: "POST",
                  data: formData,
                  processData: false,
                  contentType: false,
                  success: function(data){
                      if (data.indexOf(file.name) > -1) {
                        $('#'+userId+" .image_wrap img").attr('src', data);
                        $.users.updateUsers();
                      }
                      else {
                        console.log('something went wrong: '+ data);
                        $('#'+userId+" .image-file").val('ERROR');
                      }
                  }
                });
              }else{
                console.log('Not a valid image!');
                $('#'+userId+" .image-file").val('ERROR');
              }
            }else{
              console.log('Input something!');
              $('#'+userId+" .image-file").val('ERROR');
            }
        },
        removeImage: function(userId){
            var image = $('#'+userId+" .image_wrap img").attr('src');
            formData = new FormData();
            formData.append("action", "removeImage");
            formData.append("image", image);
            formData.append("user_id", userId);
            $.ajax({
              url: "/profiles/sprowt/ajax_image_handler.php",
              type: "POST",
              data: formData,
              processData: false,
              contentType: false,
              success: function(data){
                    if (data == 'success') {
                        $('#'+userId+" .image_wrap img").attr('src', $.users.default_image);
                    }
                    else {
                        console.log('something went wrong:');
                        console.log(data);
                    }
              }
            });
        }
    }
    
})(jQuery)