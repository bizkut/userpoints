<?php
// $Id: userpoints.views.inc,v 1.2 2008-08-05 02:41:57 kbahey Exp $

/**
 *  @file
 *  This defines views hooks for the Userpoints module. It will be loaded automatically as needed by the Views module.
 */

/**
 * Implementation of hook_views_data()
 */
function userpoints_views_data() {
  // ----------------------------------------------------------------
  // userpoints table

  // Define the base group of this table. Fields that don't
  // have a group defined will go into this field by default.
  $data['userpoints']['table']['group']  = t('Userpoints');

  $data['userpoints']['table']['base'] = array(
    'field' => 'uid',
    'title' => t('Userpoints'),
    'help' => t('Points accumulated by users on your site.'),
  );

  $data['userpoints']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
    'node' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
    // This goes to the node so that we have consistent authorship.
    'node_revisions' => array(
      'left_table' => 'node',
      'left_field' => 'uid',
      'field' => 'uid',
    ),
  );

  // points
  $data['userpoints']['points'] = array(
    'title' => t('Points'),
    'help' => t("A User's current points."), // The help that appears on the UI,
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
//       'name field' => 'name', // display this field in the summary
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  return $data;
}
