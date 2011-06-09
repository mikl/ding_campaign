<?php
/**
 * @file relevant.inc
 * Provides several library portal page related panels content types.
 */

/**
 * Callback function to supply a list of content types.
 *
 * This is only required to make CTools know that we're providing 
 * multiple types here (since we have no single => TRUE in the array).
 */
function ding_campaign_relevant_ctools_content_types() {
  return array(
    'title' => t('Relevant campaigns'),
    'description' => t('Uses the Ding! campaign system to display campaigns relevant to the current page.'),
    'single' => TRUE,
    'defaults' => array('campaign_count' => 3, 'campaign_offset' => 0),
    'category' => t('Miscellaneous'),
    'required context' => array(
      new ctools_context_optional(t('Page node'), 'node'),
      new ctools_context_optional(t('Related library'), 'node'),
      new ctools_context_optional(t('Search term'), 'string'),
    ),
  );
}

/**
 * Return the pane contents.
 */
function ding_campaign_relevant_content_type_render($subtype, $conf, $panel_args, $context) {
  $campaign_context = array(
    'page' => isset($context[0]->data) ? drupal_clone($context[0]->data) : NULL,
    'library' => isset($context[1]->data) ? drupal_clone($context[1]->data) : NULL,
    'search_term' => isset($context[2]->data) ? check_plain($context[2]->data) : NULL,
  );
  $count = ($conf['campaign_count']) ? $conf['campaign_count'] : DING_CAMPAIGN_DEFAULT_COUNT;
  $offset = ($conf['campaign_offset']) ? $conf['campaign_offset'] : 0;
  $block = new stdClass();
  $block->content = theme('ding_campaign_relevant_campaigns', $campaign_context, $count, $offset);
  return $block;
}

/**
 * Return the pane titles.
 */
function ding_campaign_relevant_content_type_admin_title($subtype, $conf, $context) {
  return t('Relevant campaigns');
}

/**
 * Returns an edit form for the content type.
 */
function ding_campaign_relevant_content_type_edit_form(&$form, &$form_state) {
  $form['campaign_count'] = array(
    '#type' => 'textfield',
    '#title' => t('Campaign count'),
    '#description' => t('The maximum number of campaigns to display'),
    '#default_value' => (isset($form_state['conf']['campaign_count'])) ? $form_state['conf']['campaign_count'] : DING_CAMPAIGN_DEFAULT_COUNT,
    '#size' => 3,
  );
  $form['campaign_offset'] = array(
    '#type' => 'textfield',
    '#title' => t('Campaign offset'),
    '#description' => t('Which campaign should we count from when returning campaigns. This is used to avoid displaying the same campaigns when using multiple campaign panes on the same panel. Use 0 to return the most relevant campaigns.'),
    '#default_value' => (isset($form_state['conf']['campaign_offset'])) ? $form_state['conf']['campaign_offset'] : 0,
    '#size' => 3,
  );
  
  return $form;
}

/**
 * Validation for content type settings form.
 */
function ding_campaign_relevant_content_type_edit_form_validate(&$form, &$form_state) {
  // Sanitise the submitted values.
  $values = array('campaign_count' => 1, 'campaign_offset' => 0);
  foreach ($values as $value => $min_value) {
    $val = trim($form_state['values'][$value]);
    $count = intval($val);
  
    // Give an error if a value less than 1 was entered.
    if (!empty($val) && $count < $min_value) {
      form_set_error($value, t('%value must be a number larger than zero.', array('%value' => ucfirst(str_replace('_', ' ', $value)))));
    }
    // Otherwise, store the sanitised value in the form state.
    else {
      $form_state['values'][$value] = $count;
    }
  }
}

/**
 * Submit handler for content type settings form.
 */
function ding_campaign_relevant_content_type_edit_form_submit(&$form, &$form_state) {
  $form_state['conf']['campaign_count'] = $form_state['values']['campaign_count'];
  $form_state['conf']['campaign_offset'] = $form_state['values']['campaign_offset'];
}

