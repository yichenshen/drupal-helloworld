<?php 

namespace CVWO\HelloWorld {
	require_once drupal_get_path("module", MODULE_NAME)."/helloworld_d7_api.inc";

	/**
	 * Displays the form for mass import of user records.
	 */
	function helloworld_addn_form($form, &$form_state) {
		$form = array();

		$form['csv'] = array(
			'#type' 	=> 	'textarea',
			'#title' 	=>	t('Import CSV'),
			'#rows'		=>	15,
			'#required'	=>	TRUE
		);

		$form['comments'] = array(
			'#type' 	=> 	'textarea',
			'#title' 	=> 	t('Comments'),
			'#required'	=>	FALSE
		);

		$form['import'] = array(
			'#type' 	=> 	'submit',
			'#value'	=>	t('Import')
		);

		return $form;
	}

	/**
	 * Validates the input.
	 *
	 * 1) Ensure that the input is in valid CSV format
	 * 2) Ensure that each email field is a valid email
	 *
	 * As this method needs to parse the CSV to verify it, the results are simply 
	 * stored in $form_state. Thus, there is no need to reparse the CSV in the submit hook.
	 */
	function helloworld_addn_form_validate($form, &$form_state){
		$csv = $form_state['values']['csv'];

		$csv_lines = explode(PHP_EOL, $csv);

		$csv_array = array();

		foreach ($csv_lines as $entry) {

			$parsed_array = array_map('trim', str_getcsv($entry));


			if(count($parsed_array) != 2){
				form_set_error('csv', 'CSV is invalid! Check the format!');
				
				$csv_array = NULL;

				break;
			} else if (!valid_email_address($parsed_array[1])){
				form_set_error('csv', $parsed_array[1] . ' is not a valid email address!');

				$csv_array = NULL;

				break;
			} else{
				array_push($csv_array, $parsed_array);
			}
		}

		//Since we've already parsed the CSV, might as well just save it.
		if(!is_null($csv_array)){
			$form_state['values']['parsed_csv'] = $csv_array;
		}
	}

	/**
	 * Implements form submit.
	 *
	 * Takes care of adding the comments and then entering it into the database.
	 */
	function helloworld_addn_form_submit($form, &$form_state) {
		$parsed_array = $form_state['values']['parsed_csv'];

		if(add_users($parsed_array, $form_state['values']['comments'])){
			drupal_set_message(t('Successfully imported ' . count($parsed_array) . ' users.'));

			$form_state['redirect'] = MODULE_NAME;			
		} else{
			drupal_set_message(t('An error occurred while importing the records! Check that the formats are valid.'));
			$form_state['rebuild'] = TRUE;
		}
	}
}
