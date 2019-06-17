/**
 * @file
 * Javascript for showing the heatmap and the filter form.
 */

(function ($) {
  "use strict";

  Drupal.behaviors.heatMapShow = {
    attach: function (context, settings) {
      $('body').append('<div id="heatmapbody" style="width:' + $(window).width() + 'px; height:' + $(document).height() + 'px; display:none; position: absolute; top: 0; left: 0;"></div>');
      var noShow = true;
      var width = '';
      var type = 1;
      
      var heatmap = h337.create({
        container: document.querySelector('#heatmapbody')
      });
      
      $('#heatmap-heatmapform .form-select').bind('change', function() {
        paintHeatMap(heatmap);
      });

      $('#edit-heatmapenabled').bind('click', function() {
          if($('#edit-heatmapenabled').is(':checked')) {
            $('#heatmapbody').fadeIn();
            $('#heatmapbody').css('position', 'absolute');
            if(width != '') {
              paintHeatMap(heatmap)
            } else if(Drupal.settings.heatMapShow.getClass != '') {
              width = 'all';
              paintHeatMap(heatmap)
            }
          } else {
            $('#heatmapbody').fadeOut(400, function() {
              $('.scrollmapobject').remove();
            });        
          }
      });

      $('#heatmap-pullin').bind('click', function() {
          if(noShow) {
            $('#heatmap').css('right', '0px');
            noShow = false;
          } else {
            $('#heatmap').css('right', '-380px');
            noShow = true;
          }
      });
    }
  }
  
  function paintHeatMap(heatmap) {
    var extra = '';
    $('.scrollmapobject').remove();
    if(Drupal.settings.heatMapShow.getClass != '' && $('#edit-heatmapwidth').val() == 'all') {
      var pos = $(Drupal.settings.heatMapShow.getClass).position();
      if(pos == null) {
        alert(Drupal.t('You have setup the heatmap settings incorrect for this theme - the following selector was not found: ' + Drupal.settings.heatMapShow.getClass));
      } else {
        extra = '&pos=' + pos.left + '&windowwidth=' + $(window).width() + '&windowtype=' + Drupal.settings.heatMapShow.getAlignment + '&divwidth=' + $(Drupal.settings.heatMapShow.getClass).width();
      }
    } else if ($('#edit-heatmapwidth').val() == 'all') {
      alert(Drupal.t('Note that you haven\'t set a selector for this theme in heatmap, so the result of this is probably wrong.'));
    }
      
    var fullUrl = Drupal.settings.heatMapShow.getUrl + 
    '?type=' + $('#edit-heatmaptype').val() + 
    '&url=' + window.location.href +
    '&width=' + $('#edit-heatmapwidth').val() + 
    '&navigator=' + $('#edit-heatmapbrowser').val() + 
    '&language=' + $('#edit-heatmaplanguage').val() + 
    '&country=' + $('#edit-heatmapcountry').val() + 
    '&fromdate=' + $('#edit-heatmapfromyear').val() + '-' + $('#edit-heatmapfrommonth').val() + '-' + $('#edit-heatmapfromday').val() + 
    '&todate=' + $('#edit-heatmaptoyear').val() + '-' + $('#edit-heatmaptomonth').val() + '-' + $('#edit-heatmaptoday').val() +  
    extra;

    $.getJSON(fullUrl, function(returndata) {
      if($('#edit-heatmaptype').val() != 3) {
        heatmap.setData(returndata); 
      } else {
        heatmap.setData({'data': []});
        paintScrollMap(returndata); 
      }
    });
    $('#heatmapbody').css('position', 'absolute');    
  }
  
  function paintScrollMap(data) {
    var lastY = 0;
    var sumValue = 0;
    var percent = 100;
    var red = 200;
    var green = 44;
    var blue = 50;
    for (var i = 0; i < data.data.length; i++) {
      var value = data.data[i].value + sumValue;
      var y = data.data[i].y;
      var rounded = Math.round((value*100)/data.total);
      if(rounded >= 1) {
        $('#heatmapbody').append('<div class="scrollmapobject" style="top: ' + lastY + 'px; height: ' + (y-lastY) + 'px; background: #' + red.toString(16) + 
        green.toString(16) + blue.toString(16) + '"><span>' + percent + '%</span></div>');
        percent = Math.round(percent - (rounded));
        red = Math.round(red-rounded*1.71);
        console.log(red);
        green = Math.round(green+rounded*0.7);
        blue = Math.round(blue+rounded*1.43);
        lastY = y;
      } else {
        sumValue = value;
      }      
    }
    if(($(document).height()-lastY) > 20) {
      $('#heatmapbody').append('<div class="scrollmapobject" style="top: ' + lastY + 'px; height: ' + ($(document).height()-lastY) + 'px; background: #555"><span>0%</span></div>');
    }

  }
  
})(jQuery);