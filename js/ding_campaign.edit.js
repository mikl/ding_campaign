
Drupal.behaviors.dingCampaignEdit = function () {
  $('#node-form')
    .find('.campaign-type-select input')
      .click(function () {
          if ($(this).val() == 'text-only') {
            $('#node-form')
              .find('.body-field-wrapper').show('fast').end()
              .find('#edit-field-campaign-image-0-ahah-wrapper').hide('fast').end()
            .end();
          }
          else if ($(this).val() == 'image-only') {
            $('#node-form')
              .find('.body-field-wrapper').hide('fast').end()
              .find('#edit-field-campaign-image-0-ahah-wrapper').show('fast').end()
            .end();
          }
          else {
            $('#node-form')
              .find('.body-field-wrapper').show('fast').end()
              .find('#edit-field-campaign-image-0-ahah-wrapper').show('fast').end()
            .end();
          }

          // This is a Luckow-style hack to work around the problem that
          // the link field is required. The field is hidden and set to
          // a bogus value when WYSIWYG-mode is active.
          if ($(this).val() == 'wysiwyg-title') {
            $('#node-form')
              .find('#edit-field-campaign-link-0-url').val('undefined').parent().hide('fast');
          }
          else {
            $('#node-form')
              .find('#edit-field-campaign-link-0-url').val('').parent().show('fast');
          }
        })
      .end()
    // Now that we have a click handler, trigger it on the already
    // selected radio to have the inital hiding taking place.
    .find('.campaign-type-select input[checked]').click()
    .end();
};

