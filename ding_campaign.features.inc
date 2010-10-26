<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function ding_campaign_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function ding_campaign_node_info() {
  $items = array(
    'campaign' => array(
      'name' => t('Campaign'),
      'module' => 'features',
      'description' => t('A campaign, a small image or text snippet displayed on the page like an ad.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'has_body' => '1',
      'body_label' => t('Campaign text'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
