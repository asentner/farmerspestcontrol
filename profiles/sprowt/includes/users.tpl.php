<script id="newUser" type="text/x-jsrender">
    <li class="user" id="{{:id}}">
        <div class="image_wrap">
            <label>Add User Image</label>
            <img src="{{:image}}">
            <input type="file" class="image-file form-file">
            <button type="button" class="removeImage button">Remove Image</button>
        </div>
        <div class="fields-wrap">
            <div class="field-wrap">
                <label for="{{:id}}-username">Username:</label>
                <input type="text" class="username form-text" id="{{:id}}-username" value="{{:username}}">
            </div>
            <div class="field-wrap">
                <label for="{{:id}}-password">Password:</label>
                <input type="password" class="password form-text" id="{{:id}}-password" value="{{:password}}">
            </div>
            <div class="field-wrap">
                <label for="{{:id}}-roles">Roles:</label>
                <div class="role-checks">
                    <label><input type="checkbox" value="authenticated user" {{:authenticated_check}}>Authenticated User</label>
                    <label><input type="checkbox" value="administrator" {{:admin_check}}>Administrator</label>
                    <label><input type="checkbox" value="content admin" {{:content_check}}>Content Admin</label>
                </div>
            </div>
            <div class="field-wrap">
                <label for="{{:id}}-email">Email:</label>
                <input type="text" class="email form-text" id="{{:id}}-email" value="{{:email}}">
            </div>
            <div class="field-wrap">
                <label for="{{:id}}-first_name">First Name:</label>
                <input type="text" class="first_name form-text" id="{{:id}}-first_name" value="{{:first_name}}">
            </div>
            <div class="field-wrap">
                <label for="{{:id}}-last_name">Last Name:</label>
                <input type="text" class="last_name form-text" id="{{:id}}-last_name" value="{{:last_name}}">
            </div>
            <div class="field-wrap">
                <label for="{{:id}}-position">Position:</label>
                <input type="text" class="position form-text" id="{{:id}}-position" value="{{:position}}">
            </div>
            <div class="field-wrap">
                <label for="{{:id}}-google_plus_id">Google+ ID:</label>
                <input type="text" class="google_plus_id form-text" id="{{:id}}-google_plus_id" value="{{:google_plus_id}}">
            </div>
            <div class="field-wrap">
                <label for="{{:id}}-Description">Description:</label>
                <textarea class="Description form-textarea" id="{{:id}}-Description">{{:Description}}</textarea>
            </div>
            <button type="button" data-user="{{:id}}" class="button removeUser">Remove</button>
        </div>
    </li>
</script>

<div id="region-market-selector">
    <div class="user-button-wrap">
        <select id="user-drop-down" class="form-select">
            <option value="0">New User</option>
            <?php foreach($users as $value => $textArray): ?>
                <option value="<?php print $value; ?>"><?php print implode(' ', $textArray); ?></option>
            <?php endforeach; ?>
        </select>
        <button type="button" id="addUser" class="button">Add User</button>
    </div>
    <ul id="users"></ul>
</div>