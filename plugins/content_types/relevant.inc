<?php
// $Id$
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
    'title' => t('Campaign'),
  );
}

/**
 * Callback function to supply a list of content types.
 */
function ding_campaign_relevant_content_type_content_types() {
  $types = array(
    'relevant_campaigns' => array(
      'title' => t('Relevant campaigns'),
      'category' => t('Miscellaneous'),
      'required context' => array(
        new ctools_context_optional(t('Page node'), 'node'), 
        new ctools_context_optional(t('Related library'), 'node'),
        new ctools_context_optional(t('Search term'), 'string'),
      ),
    ),
  );
  return $types;
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
  $block = new stdClass();
  $block->content = theme('ding_campaign_relevant_campaigns', $campaign_context);
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
 *
 * We're not actually doing anything here, but we need to have this hook 
 * for this content type to work.
 */
function ding_campaign_relevant_content_type_edit_form(&$form, &$form_state) {
  return $form;
}


