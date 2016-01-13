# drupal-helloworld

CVWO Assignmment 2: A Drupal Module expansion

This repository contains the HelloWorld Module for CVWO at SoC NUS, as well as an expansion to it which allows for mass import of records.

## Author

Shen Yichen (A0091173J)

## Requirements
 
 - Drupal 7 and it's dependencies
 - CVWO Drupal Modules

## Organisation

The HelloWorld module is organised into the API and 3 other sections. They are:

 - form (helloworld_d7_form.inc): The admin form as well as the form for adding/editing/deleting a single record
 - list (helloworld_d7_list.inc): The interface for listing the user records
 - addn (helloworld_d7_addn.inc): The form that allows mass import of user records
  - addn is a new addition to the original helloworld module from CVWO

### Hooks

Each of these three sections make use of the Drupal form API. They implement the _form, _form_validate, and form_submit hooks as neccessary.

### Database

The forms themselves calls the API to perform it's operations. Methods in the API should use the database helpers in the CVWO core module instead of directly calling upon the Drupal database API.
