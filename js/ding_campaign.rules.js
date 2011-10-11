
Drupal.behaviors.dingCampaignRules = function () {
  $('#campaign-rules')
    .find('.campaign-rule-wrap')
      .each(function (i) {
          var type = $(this).find('select').val();

          $(this).find('.form-text')
            // Remove the current autocomplete bindings.
            .unbind()
            // And remove the autocomplete class
            .removeClass('form-autocomplete')
          .end()
          // For those type selectors not processed yet, set up the
          // change event to trigger this behavior, and add the
          // processed indicator class.
          .find('select:not(.dingcampaignrules-processed)')
            .addClass('dingcampaignrules-processed')
            .change(Drupal.behaviors.dingCampaignRules)
          .end();
  
          if (type == 'page' || type == 'library' || type == 'taxonomy') {
            $(this).find('input.autocomplete')
              .removeClass('autocomplete-processed')
              .val(Drupal.settings.dingCampaignRules.autocompleteUrl + type)
            .end()
            .find('.form-text')
              .addClass('form-autocomplete');
            Drupal.behaviors.autocomplete(this);
          }

          if (type == 'generic') {
            $(this).find("div:has(input.form-text)").hide();
          }
          else {
            $(this).find("div:has(input.form-text)").show();
          }
          
          // Display the description matching the type
          $(this).find('dl > *').hide();
          $(this).find('dl dd.' + type).show();
      });
};

