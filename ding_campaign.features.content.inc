<?php

/**
 * Implementation of hook_content_default_fields().
 */
function ding_campaign_content_default_fields() {
  $fields = array();

  // Exported field: field_campaign_image
  $fields['campaign-field_campaign_image'] = array(
    'field_name' => 'field_campaign_image',
    'type_name' => 'campaign',
    'display_settings' => array(
      'weight' => '-1',
      'parent' => '',
      'token' => array(
        'format' => 'ding_campaign_default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'ding_campaign_default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'ding_campaign_default',
        'exclude' => 0,
      ),
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'ding_campaign_default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'ding_campaign_default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'png jpg jpeg gif',
      'file_path' => 'campaigns',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'max_resolution' => '0',
      'min_resolution' => '0',
      'alt' => '',
      'custom_alt' => 0,
      'title' => '',
      'custom_title' => 0,
      'title_type' => 'textfield',
      'default_image' => NULL,
      'use_default_image' => 0,
      'insert' => 1,
      'insert_styles' => array(
        'imagecache_ding_campaign' => 'imagecache_ding_campaign',
        'auto' => 0,
        'link' => 0,
        'image' => 0,
        'imagecache_80_x' => 0,
        'imagecache_120_120' => 0,
        'imagecache_180_x' => 0,
        'imagecache_680_200_crop' => 0,
        'imagecache_ting_search_carousel' => 0,
      ),
      'insert_default' => 'imagecache_ding_campaign',
      'insert_class' => 'ding-campaign-image',
      'insert_width' => '',
      'label' => 'Kampagnebillede',
      'weight' => '-1',
      'description' => 'Upload det billede som skal bruges til billedkampagnen.',
      'type' => 'imagefield_widget',
      'module' => 'imagefield',
    ),
  );

  // Exported field: field_campaign_link
  $fields['campaign-field_campaign_link'] = array(
    'field_name' => 'field_campaign_link',
    'type_name' => 'campaign',
    'display_settings' => array(
      'weight' => 0,
      'parent' => '',
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'link',
    'required' => '1',
    'multiple' => '0',
    'module' => 'link',
    'active' => '1',
    'attributes' => array(
      'target' => 'default',
      'rel' => '',
      'class' => '',
    ),
    'display' => array(
      'url_cutoff' => '80',
    ),
    'url' => 0,
    'title' => 'none',
    'title_value' => '',
    'enable_tokens' => 0,
    'validate_url' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'url' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Kampagnedestination',
      'weight' => 0,
      'description' => 'Kampagnedestinationen skal være en URL (internetadresse) til det sted brugeren sendes hen, når han klikker på kampagnen.',
      'type' => 'link',
      'module' => 'link',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Kampagnebillede');
  t('Kampagnedestination');

  return $fields;
}
