<?php

/**
 * Implementation of hook_strongarm().
 */
function ding_campaign_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_campaign';
  $strongarm->value = 0;

  $export['comment_anonymous_campaign'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_campaign';
  $strongarm->value = '0';

  $export['comment_campaign'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_campaign';
  $strongarm->value = '4';

  $export['comment_default_mode_campaign'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_campaign';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '-3',
    'menu' => '-4',
  );

  $export['content_extra_weights_campaign'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_campaign';
  $strongarm->value = array(
    0 => 'status',
  );

  $export['node_options_campaign'] = $strongarm;
  return $export;
}
