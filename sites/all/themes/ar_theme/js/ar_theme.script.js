/**
 * @file
 * Custom scripts for theme.
 */
jQuery(document).ready(function($) {
  // Add your code here.
  // $('#language-option').show();

  $(function(){
     $('#select').mouseenter(function(){
          $('#language-option').show();
          // $('.header-language').addClass('header-contact-shadow');
          // $('.header-language ul').addClass('header-contact-shadow');
      });
      $('.header-language').mouseleave(function(){
          // $('.header-language').removeClass('header-contact-shadow');
          // $('.header-language ul').removeClass('header-contact-shadow');
          $('#language-option').hide();
      });
   });

  // Sticky Navigation
  $('.nav-logo').hide();

  $(window).scroll(function() {
   if (document.documentElement.clientWidth > 960) {

      if ($(document).scrollTop() > 135) {
         //$('header').css('marginTop', 55 ); // Prevent screen Jumping nav.height()
         $('#main-menu').addClass('animated slideInDown navbar-fixed-top stick-to-top').css('-vendor-animation-duration', '3.8s');
         $('#main-menu').css( 'background', '#ffffff' );
/*
         $('header').css({
            'padding-top': '54px',
            'padding-left': 0
         });
*/

         $('.nav-logo').show();
         $('.nav-logo').css('display', 'inline');
         $('.tb-megamenu').css({
            'display': 'inline',
            'margin-top': '7px'
          }).addClass('pull-right');
         $('.responsive-menus').css('border-bottom', '1px solid #ededed');
      }
      if ($(document).scrollTop() < 100) {
         //$('header').css('marginTop', 55); // Prevent screen Jumping .addClass('slideOutUp')
         $('#main-menu').removeClass('animated slideInDown navbar-fixed-top stick-to-top').css('-vendor-animation-duration', '3.8s');
         //$('#main-menu').addClass('animated slideOutDown navbar-fixed-top stick-to-top').css('-vendor-animation-duration', '3.8s');
         $('#main-menu').css( 'background', 'transparent' );
/*
         $('header').css({
            'padding-top': '50px',
            'padding-left': '0'
         });
*/
         $('.nav-logo').hide();
         $('.tb-megamenu').css({
          'display': 'block',
          'margin-top': '0'
          }).removeClass('pull-right');
         $('#main-menu').css('border-bottom', 'none');
      }
   }
   });

});
