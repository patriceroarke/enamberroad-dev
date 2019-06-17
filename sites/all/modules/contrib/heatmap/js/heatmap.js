/**
 * @file
 * Javascript for recording the user.
 */

(function ($) {
  "use strict";

  Drupal.behaviors.heatMap = {
    attach: function (context, settings) {
      if(Drupal.settings.heatMap.getFragment != 100) {
        if(Math.floor((Math.random() * 100) + 1) >= Drupal.settings.heatMap.getFragment) return;
      }
      var mouseMoves = {};
      var mouseClicks = {};
      var counter = 0;
      var i = 0;
      var cancelled = false;
      var clicks = 0;
      var moves = 0;
      var lastMovement = 0;
      var startTime = new Date().getTime();
      var countTime = new Date().getTime();
      var lowestPosition = $(window).height() + $(window).scrollTop();
      
      $(window).bind("mousemove", function(event) {
        var changes = new Date().getTime() - startTime;
        var tenChanges = Math.round(changes / 250);
        if (tenChanges != lastMovement) {
          lastMovement = tenChanges;
          var now = new Date().getTime();
          var timeMove = Math.round((now - countTime));
          if(timeMove > 1500) timeMove = 1500;
          countTime = now;
          var mouseEvent = {'x': event.clientX, 'y': (event.clientY+$(window).scrollTop()), 'value': timeMove}
          mouseMoves[moves] = mouseEvent;
          moves++;
        }
      });
            
      $(window).bind("click", function(event) {
        //event.preventDefault();
        var clickEvent = {'value': 1, 'x': event.clientX, 'y': (event.clientY+$(window).scrollTop())}
        mouseClicks[clicks] = clickEvent;
        heatMapSendData(cancelled, mouseMoves, mouseClicks, lowestPosition);
        clicks++;
      });
      
      $(window).bind('scroll', function() {
        var newPosition = $(window).height() + $(window).scrollTop();
        if(newPosition > lowestPosition) {
          lowestPosition = newPosition;
        }
      });
      
      var myInterval = window.setInterval(function(){
        if (counter > (Drupal.settings.heatMap.maxInterval)) {
          clearInterval(myInterval);
          cancelled = true;
        }
        counter = counter + Drupal.settings.heatMap.saveInterval;
        heatMapSendData(cancelled, mouseMoves, mouseClicks, lowestPosition);
      }, Drupal.settings.heatMap.saveInterval);
      
    }
  };

  function heatMapSendData(cancelled, mouseMoves, mouseClicks, lowestPosition) {    
    if(!cancelled) {
      $.ajax({
        type: 'POST',
        url: Drupal.settings.heatMap.saveUrl,
        data: {
          "width":$(window).width(),
          "browser_language":window.navigator.language.toLowerCase(),
          "mouse_moves":JSON.stringify(mouseMoves),
          "clicks":JSON.stringify(mouseClicks),
          "href":window.location.href,
          "lowest_position":lowestPosition,
          "id":Drupal.settings.heatMap.id
        },
        success: function(result) {
          Drupal.settings.heatMap.id = result.id;
        },
      })
    }
  }  
})(jQuery);  