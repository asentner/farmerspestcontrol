(function($, Drupal)
/**
 * @file
 * JavaScript behaviors for the calculation of selected webform component numbers.
 */
{
// Our function name is prototyped as part of the Drupal.ajax namespace, adding to the commands:
  Drupal.ajax.prototype.commands.webformCalcHiddenComponentAjaxCallback = function(ajax, response, status) {
// The value we passed in our Ajax callback function will be available inside
// the response object. Since we defined it as selectedValue in our callback,
// it will be available in response.selectedValue. Usually we would not use
// an alert() function as we could use ajax_command_alert() to do it without
// having to define a custom ajax command, but for the purpose of demonstration,
// we will use an alert() function here:
// alert("hello from Webform calculation Hidden component ajax commands");
// For debugging use: console.log("this is the variable myvar> %o",myvar);
    var operation = response.webformOperationDataArray['operation'];
    var result_id = '#' + response.webformOperationDataArray['result_id'];
    var operation_result = 0;
    if (response.webformOperationDataArray['cumulative_result'] == 'yes') {
      result_field = Number($(result_id).val());
    }
    else {
      $(result_id).val('');
    }
    // Reset the variable result field if the input result field is empty.
    if ($(result_id).val() == '') {
      if (operation == 'addition' || operation == 'subtraction') {
        result_field = 0;
      }
      if (operation == 'multiplication' || operation == 'division' || operation == 'percentage' || operation == 'modulo') {
        result_field = 1;
      }
    }
    var operand_ids = response.webformOperationDataArray['operand_ids'];
    var operand_id = '';
    for (var i = 0; i < operand_ids.length; i++) {
      operand_id = '#' + operand_ids[i];
      if ($(operand_id).val() != '') {
        switch(operation) {
          case 'addition':
          operation_result = result_field + Number($(operand_id).val());
          break;

          case 'subtraction':
          operation_result = result_field - Number($(operand_id).val());
          break;

          case 'multiplication':
          operation_result = result_field * Number($(operand_id).val());
          break;

          case 'division':
          operation_result = result_field / ((Number($(operand_id).val()) == 0)? 1 : Number($(operand_id).val()));
          break;

          case 'percentage':
          operation_result = 0.01 * result_field * Number($(operand_id).val());
          break;

          case 'modulo':
          operation_result = Math.floor(result_field) % ((Number($(operand_id).val()) == 0)? 1 : Number($(operand_id).val()));
          if (response.webformOperationDataArray['cumulative_result'] == 'no' && result_field == 1) {
            operation_result = Number($(operand_id).val());
          }
          break;
        }
        console.log("operation_result > %o",operation_result);
        result_field = operation_result;
        console.log("result_field > %o",result_field);
      }
      $(result_id).val(operation_result);
    }
  };
}(jQuery, Drupal));
