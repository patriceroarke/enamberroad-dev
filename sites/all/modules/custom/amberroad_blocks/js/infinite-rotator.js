(function($) {
  // Behavior to attach rotator to client image on homepage.
  Drupal.behaviors.rotator = {
    attach: function(context, settings) {
      //initial fade-in time (in milliseconds)
      var initialFadeIn = 0;

      //interval between items (in milliseconds)
      var itemInterval = 4000;

      //cross-fade time (in milliseconds)
      var fadeTime = 100;

      //count number of items
      var numberOfItems = $('.rotating-items').length;

      //set current item
      var currentItem = 0;

      //show first item
      $('.rotating-items').eq(currentItem).fadeIn(initialFadeIn);

      //loop through the items
      var infiniteLoop = setInterval(function() {
        $('.rotating-items').eq(currentItem).fadeOut(fadeTime);

        if(currentItem == numberOfItems -1) {
          currentItem = 0;
        }
        else {
          currentItem++;
        }
        $('.rotating-items').eq(currentItem).fadeIn(fadeTime);

      }, itemInterval);
    }
  };

})(jQuery);
