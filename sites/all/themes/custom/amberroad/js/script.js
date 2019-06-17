/**
 * @file
 * A JavaScript file for the theme.
 *
 */

(function ($, Drupal, window, document, undefined) {

  Drupal.behaviors.add_class = {
    attach: function(context, settings) {
      if ($('.node-type-podcast .pane-node-field-podcast-author-image .field-item.odd')[0]) {
        $('.node-type-podcast .pane-node-field-podcast-author-image').addClass('width_image');
        $('.podcast_node_detail').addClass('width_detail');
      }
    }
  };

  Drupal.behaviors.tbMegaMenu = {
    attach: function(context) {
      $('.tb-megamenu-button').click(function() {
        $(this).parent().children('.nav-collapse').toggleClass('mobile-nav');
      });
    }
  };

  Drupal.behaviors.removeEmptyTags = {
    attach: function(context) {

      $('.node-type-page .field-name-body .field-item h1').each(function() {
        if ( !($(this).find('img').length) &&     // If there's not an image
              (!$.trim($(this).text()).length) )  // and there's no text
          {
            $(this).addClass('emptyTag');         // Add a CSS class
          }
      });

      $('.node-type-page .field-name-body .field-item p').each(function() {
        if ( !($(this).find('img').length) && (!$.trim($(this).text()).length) ) {
          $(this).addClass('emptyTag');
        }
      });

      if ($('.node-type-page .field-name-body .field-item p iframe').length > 0) {
        $('.node-type-page .field-name-body .field-item p iframe').parent().removeClass('emptyTag');
      }

      if ($('.node-type-page .field-name-body .field-item p object').length > 0) {
        $('.node-type-page .field-name-body .field-item p object').parent().removeClass('emptyTag');
      }

      $('.node-type-solution-area .field-name-body .field-item h1').each(function() {
        if ( !($(this).find('img').length) && (!$.trim($(this).text()).length) ) {
          $(this).addClass('emptyTag');
        }
      });

      $('.node-type-solution-area .field-name-body .field-item p').each(function() {
        if ( !($(this).find('img').length) && (!$.trim($(this).text()).length) ) {
          $(this).addClass('emptyTag');
        }
      });

      if ($('.node-type-solution-area .field-name-body .field-item p iframe').length > 0) {
        $('.node-type-solution-area .field-name-body .field-item p iframe').parent().removeClass('emptyTag');
      }

    }
  };

  Drupal.behaviors.checkboxClass = {
    attach: function(context) {
      $('.resource-library-search-filters .bef-toggle').click(function() {
        $('.resource-library-search-filters .bef-toggle:contains("Select None")').addClass('select-none-checkbox');
        $('.resource-library-search-filters .bef-toggle:contains("Select All")').removeClass('select-none-checkbox');
      });
      $('.resource-library-search-filters .bef-toggle:contains("Select None")').addClass('select-none-checkbox');
    }
  };

})(jQuery, Drupal, this, this.document);
