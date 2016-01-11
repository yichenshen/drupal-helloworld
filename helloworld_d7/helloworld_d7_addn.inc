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
	 */
	function helloworld_addn_form_validate($form, &$form_state){
		
	}


	/**
	 * Implements form submit.
	 *
	 * Takes care of parsing the csv, adding the comments and then entering it into the database.
	 */
	function helloword_addn_form_submit($form, &$form_state) {

	}
}
