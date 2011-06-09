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
 * Implementation of hook_imagecache_default_presets().
 */
function ding_campaign_imagecache_default_presets() {
  $items = array(
    'ding_campaign' => array(
      'presetname' => 'ding_campaign',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '210',
            'height' => '500',
            'upscale' => 0,
          ),
        ),
      ),
    ),
  );
  return $items;
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
