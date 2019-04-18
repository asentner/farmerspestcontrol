<?php
require_once drupal_get_path('module', 'pestpac_api') . '/PestPacApi.php';
require_once drupal_get_path('module', 'pestpac_api') . '/PestPacOauth.php';
/**
 * Created by PhpStorm.
 * User: michael
 * Date: 9/26/18
 * Time: 9:05 AM
 */

/**
 * Class PestPac
 *
 * Handles all business logic for PestPac Sync and API
 */
class PestPac extends PestPacApi {

  /**
   * @return array
   *
   * Fetches all branch names from PestPac
   */
  function fetchBranches(){
    $branches = [
      "BranchID" => "",
      "Name" => "",
      "Active" => true
    ];
    $allBranches = $this->callResource('/lookups/Branches',$branches,'get');
    $branchNames = [];
    foreach($allBranches as $branch){
      array_push($branchNames,$branch["Name"]);
    }
    return $branchNames;

  }

  function getWebhooks(){
    return $this->webhookResource('get');
  }
  function deleteWebhook($id){
    $webhook = array(
      "SubscriptionID" => $id,
      'EntityType' => 'Lead',
      'Action' => 'Update',
      'PostToUrl' => $GLOBALS['base_url'].'/pestpac/webhook/lead/update'
    );
    $webhookUri = "/".$id;
    $request = $this->webhookResource('delete',array(),$webhookUri);
    return $request;
  }

  function getCall($callID){
    $endpoint = "/calls/".$callID;
    $request = $this->callResource($endpoint,[],'get');
    return $request;
  }


  function createCall($data) {

    $fields = $this->setFields($data);

    $ppCall = [
      "LocationID" => $fields->locationID,
      "Branch" => $fields->branch,
      "Company" => $fields->company,
      "ContactName" => $data->name,
      "Address" => $data->street,
      "Address2" => "",
      "City" => $data->city,
      "State" => $data->state,
      "Zip" => $data->postal_code,
      "Country" => $data->country,
      "Phone" => $data->caller_number_bare,
      "PhoneExtension" => "",
      "AlternatePhone" => "",
      "AlternatePhoneExtension" => "",
      "Fax" => "",
      "FaxExtension" => "",
      "EMail" => $data->email,
      "CalledForUser" => "",
      "Description" => $fields->description,
      "Status" => "New",
      "Type" => "Customer",
      "DateOpened" => $data->called_at,
      "Source" => $fields->source,
      "TargetPest" => "",
      "MailTo" => "",
      "FoundIn" => "Current",
      "UserDefinedFields" => [
        [
          "Caption" => "CallID",
          "Value" => $data->id,
        ],
        [
          "Caption" => "CallAgent",
          "Value" => $fields->agent
        ],
        [
          "Caption" => "SMS",
          "Value" => $fields->sms,
        ],
      ],
    ];

    $ppc = new PestPacOauth('password');
    $ppc->authenticate();
    $pp = new PestPacApi();


    try {
      $request = $pp->callResource('/Calls', $ppCall);
      return $request;
    } catch (Exception $e) {
      watchdog('CTM_PestPac_Sync_Error', 'Trouble adding call to pestpac. More info: %e', [
        '%e' => $e,
      ]);
    }
  }

  function createLead($data) {

    $fields = $this->setFields($data);

    //change CreateLocation to true when ready
    $ppLead = [
      "LeadID" => 0,
      "LocationID" => $fields->locationID,
      "CreateLocation" => FALSE,
      "Branch" => $fields->branch,
      "LeadType" => "Lead",
      "WonStatus" => "New",
      "DateReceived" => date(DATE_ATOM),
      "DateClosed" => "",
      "CloseReason" => "",
      "Name" => $data->name,
      "Company" => "",
      "Address" => $data->street,
      "Address2" => "",
      "City" => $data->city,
      "State" => $data->state,
      "Zip" => $data->postal_code,
      "Country" => $data->country,
      "Phone" => $data->caller_number_bare,
      "PhoneExtension" => "",
      "Fax" => "",
      "FaxExtension" => "",
      "AlternatePhone" => "",
      "AlternatePhoneExtension" => "",
      "MobilePhone" => "",
      "MobilePhoneExtension" => "",
      "EMail" => "$data->email",
      "LocationType" => "",
      "Source" => $fields->source,
      "LeadCost" => "0",
      "ServiceCode" => "",
      "Salesperson" => "",
      "TargetPest" => $fields->tPest,
      "ProposalValue" => "0",
      "SalesStatus" => "",
      "PendingEvent" => "",
      "PendingEventDate" => "",
      "TimeRange" => "",
      "Duration" => "0",
      "Comment" => "",
      "UserDefinedFields" => [
        [
          "Caption" => "CallID",
          "Value" => $data->id,
        ],
      ],
      "Latitude" => $fields->lat,
      "Longitude" => $fields->long
    ];
    $ppc = new PestPacOauth('password');
    $ppc->authenticate();
    $pp = new PestPacApi();

    try {
      $request = $pp->leadResource("/Leads", $ppLead);

      return $request;
    } catch (Exception $e) {
      watchdog('CTM_PestPac_Sync_Error', 'Trouble creating lead in pestpac. More info: %e', [
        '%e' => $e,
      ]);
    }
  }

  /**
   * @param $data
   * @param string $status
   *
   * @return array|mixed
   *
   * Handles pestpac call updating via a put request. Will also attach a call to a location if
   * a location ID is present in CTM.
   *
   * $status can be set to "Closed" to close a call. Defaults to "New".
   *
   */
  function updateCall($data, $status = "New") {

    $fields = $this->setFields($data);


    $ppCall = [
      "LocationID" => $fields->locationID,
      "CallID" => $fields->callID,
      "Branch" => $fields->branch,
      "Company" => $fields->company,
      "ContactName" => $data->name,
      "Address" => $data->street,
      "Address2" => "",
      "City" => $data->city,
      "State" => $data->state,
      "Zip" => $data->postal_code,
      "Country" => $data->country,
      "Phone" => $data->caller_number_bare,
      "PhoneExtension" => "",
      "AlternatePhone" => $fields->alternatePhone,
      "AlternatePhoneExtension" => "",
      "Fax" => "",
      "FaxExtension" => "",
      "EMail" => $data->email,
      "CalledForUser" => $fields->calledFor,
      "Description" => $fields->description,
      "Status" => $status,
      "Type" => "Customer",
      "DateOpened" => $data->called_at,
      "Source" => $fields->source,
      "TargetPest" => $fields->tPest,
      "MailTo" => "",
      "FoundIn" => "Current",
      "UserDefinedFields" => [
        [
          "Caption" => "CallID",
          "Value" => $data->id,
        ],
        [
          "Caption" => "VOICEMAIL",
          "Value" => $fields->voicemail
        ],
        [
          "Caption" => "CallAgent",
          "Value" => $fields->agent
        ],
        [
          "Caption" => "SMS",
          "Value" => $fields->sms
        ],
      ],
    ];

    $ppc = new PestPacOauth('password');
    $ppc->authenticate();
    $ppApi = new PestPacApi();

    $uri = '/Calls/' . $ppCall["CallID"] . "/";
    try {
      $request = $ppApi->callResource($uri, $ppCall, 'put');
      return $request;
    } catch (Exception $e) {
      watchdog('CTM_PestPac_Sync_Error', 'Trouble adding call to pestpac. More info: %e', [
        '%e' => $e,
      ]);

    }
  }

  function addNoteToCall($data,$note,$ctmNoteCode,$sms=false,$lead = false) {


    $fields = $this->setFields($data);
    //set note code for a pestpac note to be set to either the CTM note ID, or a custom, user selected id from the CTM call panel.
    if(!empty($fields->noteCode)){
        $noteCode = $fields->noteCode;
    }else{
        $noteCode = $ctmNoteCode;
    }

    $ppNote = [
      "NoteID" => "",
      "NoteDate" => date(DATE_ATOM),
      "NoteCode" => $noteCode, //either ctmCallID or user selected id from CTM picker in call panel
      "Note" => $note,
      "CreatedByUser" => $fields->calledFor,
      "AlertExpirationDate" => "",
      "showOnPortal" => true,
      "WWID" => $ctmNoteCode, //set to ctm note id, always.
      "Associations" => [
        [
          "LocationID" => $fields->locationID,
          "ContactID" => "",
          "BillToID" => "",
          "TaskID" => "",
          "OrderID" => "",
          "SalesLeadID" => "",
          "InvoiceID" => "",
          "CallID" => $fields->callID,
        ],
      ],
    ];

    if($lead){
      $leadID = $data->leadID;
      $uri = "/Leads/".$leadID."/notes";
      $request = $this->leadResource($uri,$ppNote,'post');
      return $request;
    }else{
      $uri = "/Calls/".$fields->callID."/notes";
      $request = $this->callResource($uri,$ppNote,'post');
      return $request;
    }

  }

  /**
   * @param $data
   *  Standard object containing incoming data from CTM
   * @param $msg
   *  String containing the message to add
   * @param $noteCode
   *  String containing the code for the note
   *
   * @return array|mixed
   *  The updated call in PestPac
   */
  function syncSms($data,$msg="",$noteCode = ""){

    if(empty($msg)){
      $msg = "https://app.calltrackingmetrics.com/messages#callNav=text_message&callId=".$data->id;
    }
    if(empty($noteCode)){
      $noteCode = 'sms';
    }

    //add to pestpac as note
    $ppNote = $this->addNoteToCall($data,$msg,$noteCode,true);


    return $ppNote;
  }

  /**
   * @param $data
   *  A standard object containing CTM data.
   * @param $currData
   *  A standard object containing the current lead fields (based on the lead id)
   * @return array|bool|mixed
   *  Returns an array containing the updated lead from pestpac.
   */
  function updateLead($data,$currData) {

    $fields = $this->setFields($data,$currData);


      if($currData->WonStatus === "Open" || $currData->WonStatus === "New" || $currData->WonStatus === "Hold"){

          $ppLead = [
              "LeadID" => $fields->leadID,
              "LocationID" => $currData->LocationID,
              "CreateLocation" => FALSE,
              "Branch" => $fields->branch,
              "LeadType" => $currData->LeadType,
              "WonStatus" => $currData->WonStatus,
              "DateReceived" => $currData->DateReceived,
              "DateClosed" => $currData->DateClosed,
              "CloseReason" => $currData->CloseReason,
              "Name" => $data->name,
              "Company" => $fields->company,
              "Address" => $data->street,
              "Address2" => $currData->Address2,
              "City" => $data->city,
              "State" => $data->state,
              "Zip" => $data->postal_code,
              "Country" => $data->country,
              "Phone" => $fields->leadPhone,
              "PhoneExtension" => $currData->PhoneExtension,
              "Fax" => $currData->Fax,
              "FaxExtension" => $currData->FaxExtension,
              "AlternatePhone" => $fields->alternatePhone,
              "AlternatePhoneExtension" => $currData->AlternatePhoneExtension,
              "MobilePhone" => $fields->mobilePhone,
              "MobilePhoneExtension" => $currData->MobilePhoneExtension,
              "EMail" => $fields->email,
              "LocationType" => $currData->LocationType,
              "Source" => $fields->source,
              "LeadCost" => $currData->LeadCost,
              "ServiceCode" => $currData->ServiceCode,
              "Salesperson" => $currData->Salesperson,
              "TargetPest" => $fields->tPest,
              "SalesStatus" => $currData->SalesStatus,
              "PendingEvent" => $currData->PendingEvent,
              "PendingEventDate" => $currData->PendingEventDate,
              "ProposalValue" => $currData->ProposalValue,
              "TimeRange" => $currData->TimeRange,
              "Duration" => $currData->Duration,
              "Comment" => $currData->Comment,
              "UserDefinedFields" => [
                  [
                      "Caption" => "CallID",
                      "Value" => $data->id,
                  ],
              ],
              "Latitude" => $fields->lat,
              "Longitude" => $fields->long
          ];

          $ppc = new PestPacOauth('password');
          $ppc->authenticate();
          $ppApi = new PestPacApi();

          $uri = '/Leads/' . $ppLead["LeadID"] . "/";
          try {
              //Only update lead if the current lead data has a won status of open, new, or hold. Other than that, ignore.

              $request = $ppApi->LeadResource($uri, $ppLead, 'put');
              return $request;

          } catch (Exception $e) {
              watchdog('CTM_PestPac_Sync_Error', 'Trouble adding call to pestpac. More info: %e', [
                  '%e' => $e,
              ]);

          }
      }

  }

  /**
   * @param array $options
   *
   * @return bool|mixed
   *
   * Wrapper for API
   */
  function fetchInvoices($options = []) {
    return $this->invoiceResource($options);
  }

  /**
   * @param $callID
   *
   * @return array|mixed
   *
   * Fetches all notes attached to a specific call id.
   */
  function fetchCallNotes($callID){
    $uri = '/Calls/'.$callID.'/notes';
    return $this->callResource($uri,[],'get');
  }

  function fetchLeadNotes($leadID){
    $uri = '/Leads/'.$leadID.'/notes';
    return $this->leadResource($uri,[],'get');
  }

  function fetchLocationNotes($locationID){
    $uri = "/Locations/".$locationID."/notes";
    return $this->locationResource($uri,[],'get');
  }

  /**
   * @param $notes
   * @param $newNote
   *
   * @return bool
   *
   * Checks to see if a note exists in a pestpac call
   */
  function checkIfNoteExists($notes,$newNote){
    $noteCodes = array();
    foreach($notes as $note){
      if(!empty($note['WWID'])){
        array_push($noteCodes,$note['WWID']);
      }

    }
    //if note exists in pestpac we return true
    if(in_array($newNote,$noteCodes)){
      return true;
    }else{
      return false;
    }
  }

  function getBillTos($billToID){

    $uri = "/BillTos/".$billToID;

    $unpaidInvoice = [
      "InvoiceID" => "",
      "LocationID"=> "",
      "BillToID"=> "",
      "SetupID"=> "",
      "InvoiceNumber"=> "",
      "Branch"=> "",
      "ServiceCode"=> "",
      "Description"=> "",
      "SubTotal" => "",
      "Tax"=> "",
      "Total"=> "",
      "Balance"=> "",
      "InvoiceDate"=> "",
      "WorkDate"=> "",
      "Duration"=> "",
      "InvoiceType"=> "" ,
      "Origin"=> "",
      "Tech1"=> "",
      "TechID1"=> "",
      "Route"=> "",
      "PdfUrls"=> [
        [
        ],
      ],
    ];
    $request = $this->billToResource($uri,$unpaidInvoice,'get');

    return $request;
  }

  function getLocation($locationID){
    $uri = "/Locations/".$locationID;
    $location = [
      "LocationID"=> "",
      "LocationCode"=> "",
      "Branch"=> "",
      "BillToID"=> "",
      "Company"=> "",
      "LastName"=> "",
      "FirstName"=> "",
      "Title"=> "",
      "Salutation"=> "",
      "SalutationName"=> "",
      "Address"=> "",
      "Address2"=> "",
      "City"=> "",
      "State"=> "",
      "Zip"=> "",
      "Country"=> "",
      "Phone"=> "",
      "PhoneExtension"=> "",
      "AlternatePhone"=> "",
      "AlternatePhoneExtension"=> "",
      "Fax"=> "",
      "FaxExtension"=> "",
      "MobilePhone"=> "",
      "MobilePhoneExtension"=> "",
      "EMail"=> "",
      "Website"=> "",
      "Active"=> "",
      "IncludeInMailings"=> "",
      "Prospect"=> "",
      "EnteredDate"=> "",
      "ContactDate"=> "",
      "ContactCode"=> "",
      "County"=> "",
      "Division"=> "",
      "Source"=> "",
      "TaxCode"=> "",
      "TaxRate"=> "",
      "Type"=> "",
      "MapCode"=> "",
      "Comment"=> "",
      "Instructions"=> "",
      "Latitude"=> "",
      "Longitude"=> "",
      "GLCode"=> "",
      "DoNotGeocode"=> "",
      "Builder"=> "",
      "Subdivision"=> "",
      "TaxExemptNumber"=> "",
      "PurchaseOrderNumber"=> "",
      "PurchaseOrderExpirationDate"=> "",
      "InternalIdentifier"=> "",
      "UserDefinedFields"=> [
        [
          "Caption"=> "Test",
          "Value"=> "Test"
        ],
      ],
      "AutomatedEmails"=>[
        [
        ],
      ],
    ];

    $request = $this->locationResource($uri,$location,'get');

    return $request;
  }

  /**
   * @param $data
   *  Array containing parsed request link from Call Tracking Metrics
   * @return array|bool|mixed
   *  Returns Updated PestPac Location if successful, and false if not. If false, error data will be
   *  added to watchdog for debugging.
   *
   * Updates Address, State, Zip, and Email in a PestPac Location.
   */
  function updateLocation($data){

    $locationID = $data->custom_fields->locationid;
    $uri = "/locations/".$locationID;
    $location = [];

    foreach($data as $k => $v){
      switch($k){
        case "street":
          if(!empty($v)){
            $location[] = array(
              "op" => "replace",
              "path" => "/address",
              "value" => $v
            );
          }
          break;
        case "city":
          if(!empty($v)){
            $location[] = array(
              "op" => "replace",
              "path" => "/City",
              "value" => $v
            );
          }
          break;
        case "state":
          if(!empty($v)){
            $location[]=array(
              "op" => "replace",
              "path" => "/State",
              "value" => $v
            );
          }
          break;
        case "postal_code":
          if(!empty($v)){
            $location[]=array(
              "op" => "replace",
              "path" => "/Zip",
              "value" => $v
            );
          }
          break;
        case "email":
          if(!empty($v)){
            $location[]=array(
              "op" => "replace",
              "path" => "/EMail",
              "value" => $v
            );
          }
          break;
      }
    }

    json_encode($location);

    try{
      $request = $this->locationResource($uri,$location,'patch');
    }
    catch(Exception $e){
      $request = $e;
            watchdog("CTM_PestPac_Sync_Error","Error Updating Location with ID %locationID with exception %e", array(
              "%locationID" => $locationID,
              "%e" => $e
            ));

    }


    return $request;
  }

  /**
   * @param $data
   *  Array containing parsed request link from Call Tracking Metrics
   * @param $billToID
   *  BillTo ID from a PestPac Location
   * @return array|mixed
   *  Returns updated PestPac BillTo
   *
   * Updates Address, City, State, Zip, and Email fields for a PestPac BillTo.
   */
  function updateBillTo($data,$billToID){
    $uri = "/BillTos/".$billToID;
    $billTo[] = array(
      "op" => "replace",
      "path" => "/address",
      "value" => $data->street
    );
    $billTo[] = array(
      "op" => "replace",
      "path" => "/City",
      "value" => $data->city
    );
    $billTo[]=array(
      "op" => "replace",
      "path" => "/State",
      "value" => $data->state
    );
    $billTo[]=array(
      "op" => "replace",
      "path" => "/Zip",
      "value" => $data->postal_code
    );
    $billTo[]=array(
      "op" => "replace",
      "path" => "/EMail",
      "value" => $data->email
    );

    json_encode($billTo);

    $request = $this->billToResource($uri,$billTo,'patch');

    return $request;
  }

  function getBillToId($locationID){
    $location = $this->getLocation($locationID);
    return $location["BillToID"];
  }

  function getRandBranch(){
    $branches = $this->fetchBranches();
    $branch = $branches[mt_rand(0, count($branches) - 1)];
    return $branch;
  }

  /**
   *
   * Returns an array containing all PestPac Employees from the Lookup Table
   *
   * @return array|mixed
   */
  function getEmployees(){
    $uri = "/lookups/Employees";
    return $this->callResource($uri,[],'get');
  }

  /**
   *
   * Returns an array containing all PestPac Sources from the Lookup Table
   *
   * @return array|mixed
   */
  function getSources(){
    $uri = "/lookups/sources";
    return $this->callResource($uri,[],'get');
  }

  /**
   *
   * Returns an array containing all PestPac Target Pests from the Lookup Table
   *
   * @return array|mixed
   */
  function getTargetPests(){
    $uri = "/lookups/TargetPests";
    return $this->callResource($uri,[],'get');
  }

  /**
   *
   * Takes a PestPac Lookup Table and returns a formatted array containing
   * the proper key/value pairs.
   * Note: Only tested with Employees, Sources, and Target Pest Lookup Tables. May
   * need to be updated to match other Lookup Table criteria.
   *
   * @param $table
   *
   * @return array
   */
  function formatTable($table){
    $formattedTable = [];
    foreach($table as $t){

      if($t["Active"]){

        //Check if employees table
        if(array_key_exists("FirstName",$t) || array_key_exists("LastName",$t)){
          $value = $t["FirstName"]." ".$t["LastName"];
          if($t["FirstName"] === "" || $t["LastName"] === ""){
            $value = $t["Username"];
          }
          $formattedTable[$t["Username"]] = $value;
        }else{
          //For everything else
          $value = $t["Description"];
          if($value === ""){
            $value = $t["Code"];
          }
          $formattedTable[$t["Code"]] = $value;
        }
      }
    }
    return array_filter($formattedTable,'strlen');//strip null values
  }

  function setFields($data,$ppData=null){

    $fields = new StdClass();
    $fields->voicemail = 0;
    $fields->tPest = "";
    $fields->callID = "";
    $fields->calledFor = "";
    $fields->locationID = "";
    $fields->agent = "";
    $fields->company = "";
    $fields->branch = _ctm_pestpac_sync_fetch_rand_branch_from_db();
    $fields->wonStatus = "Open";
    $fields->leadID = "";
    $fields->status = "";
    $fields->description = "";
    $fields->email = "";
    $fields->source = "";
    $fields->address = "";
    $fields->lat = "";
    $fields->long = "";
    $fields->noteCode = "";
    $fields->leadPhone = $data->caller_number_bare;
    $fields->calledAt = "";
    $fields->alternatePhone = "";
    $fields->mobilePhone = "";


//if email exists in pestpac, don't update it
    //if you add an email to ctm, and the email does not exist in pestpac, update.


    foreach($data as $k => $v){
      switch($k){
        case "status":
          $fields->status = $v;
          break;
          case "source":
              if(variable_get("ctm_sync_sources")){
                  $fields->source = $data->source;
              }else{
                  if(!empty($data->tracking_label)){
                      $fields->source = $data->tracking_label;
                  }
              }
          break;
        case "street":
          $fields->address = $v;
          break;
        case "tag_list":
          foreach($v as $tagKey => $tagVal){
            if($tagVal === "voicemail" && !empty($data->audio)){
              $fields->voicemail = 1;
            }
          }
          break;
        case "agent":
          $rawAgent = str_replace(' ', '', $data->agent->name);
          $fields->agent = substr($rawAgent,0,10);
          $fields->description = "Answered by: ". $data->agent->name;
          break;
        case "ppCallID":
          $fields->callID = $data->ppCallID;
          break;
        case "latitude":
          $fields->lat = $v;
          break;
        case "longitude":
          $fields->long = $v;
          break;
        case "custom_fields":
          foreach($v as $cfKey => $cfVal){
            switch($cfKey){
              case "branch":
                $fields->branch = $cfVal;
                break;
              case "target_pest":
                $fields->tPest = $cfVal;
                break;
              case "value":
                $fields->callID = $cfVal;
                break;
              case "called_for":
                $fields->calledFor = $cfVal;
                break;
              case "leadid":
                $fields->leadID = $cfVal;
                break;
              case "locationid":
                $fields->locationID = $cfVal;
                break;
              case "company_name":
                $fields->company = $cfVal;
                break;
              case "won_status":
                $fields->wonStatus = $cfVal;
                break;
              case "note_code":
                $fields->noteCode = $cfVal;
                break;
              case "mobile_phone":
                $fields->mobilePhone = localize_us_number($cfVal);
                break;
              case "alternate_phone":
                  $fields->alternatePhone = localize_us_number($cfVal);
                  break;
            }
          }
          break;
      }
    }

    if($fields->status === "received" || $fields->status === "delivered"){
      $fields->sms = 1;
    }else{
      $fields->sms = 0;
    }

    //If a field is set in PestPac, do not change. If not, fetch w/e is in CTM and sync to PestPac
    if($ppData){
      if(!empty($ppData->EMail)){
        $fields->email = $ppData->EMail;
      }else{
        $fields->email = $data->email;
      }

      if(!empty($ppData->Source)){
        $fields->source = $ppData->Source;
      }

      if(!empty($ppData->Latitude)){
        $fields->lat = $ppData->Latitude;
      }
      if(!empty($ppData->Longitude)){
        $fields->long = $ppData->Longitude;
      }
      if(!empty($ppData->Phone)){
          $fields->leadPhone = $ppData->Phone;
      }
      if(!empty($ppData->TargetPest)){
          $fields->tPest = $ppData->TargetPest;
      }
      if(!empty($ppData->MobilePhone)){
          $fields->mobilePhone = $ppData->MobilePhone;
      }
      if(!empty($ppData->AlternatePhone)){
          $fields->alternatePhone = $ppData->AlternatePhone;
      }

    }

    return $fields;

  }

  /*
   * Test Cases
   */
  function addNoteToCallTest($callID,$note){

    $ppNote = [
      "NoteID" => "",
      "NoteDate" => date(DATE_ATOM),
      "NoteCode" => "ctm_". rand(100000,999999),
      "Note" => $note,
      "CreatedByUser" => "ADMN",
      "AlertExpirationDate" => "",
      "Associations" => [
        [
          "LocationID" => "",
          "ContactID" => "",
          "BillToID" => "",
          "TaskID" => "",
          "OrderID" => "",
          "SalesLeadID" => "",
          "InvoiceID" => "",
          "CallID" => $callID,
        ],
      ],
    ];

    $uri = "/Calls/".$callID."/notes";
    $request = $this->callResource($uri,$ppNote,'post');
    return $request;
  }

  function testGetSources(){
    $uri = "/lookups/sources";
    return $this->callResource($uri,[],'get');
  }
  /*
   * End Test Cases
   */


}