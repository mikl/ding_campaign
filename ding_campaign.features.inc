<?php

/**
 * Implementation of hook_content_default_fields().
 */
function ding_campaign_content_default_fields() {
  module_load_include('inc', 'ding_campaign', 'ding_campaign.defaults');
  $args = func_get_args();
  return call_user_func_array('_ding_campaign_content_default_fields', $args);
}

/**
 * Implementation of hook_ctools_plugin_api().
 */
function ding_campaign_ctools_plugin_api() {
  module_load_include('inc', 'ding_campaign', 'ding_campaign.defaults');
  $args = func_get_args();
  return call_user_func_array('_ding_campaign_ctools_plugin_api', $args);
}

/**
 * Implementation of hook_strongarm().
 */
function ding_campaign_strongarm() {
  module_load_include('inc', 'ding_campaign', 'ding_campaign.defaults');
  $args = func_get_args();
  return call_user_func_array('_ding_campaign_strongarm', $args);
}
