jQuery(document).ready(function(n){n(function(){n("#select").mouseenter(function(){n("#language-option").show()}),n(".header-language").mouseleave(function(){n("#language-option").hide()})}),n(".nav-logo").hide(),n(window).scroll(function(){document.documentElement.clientWidth>960&&(n(document).scrollTop()>135&&(n("#main-menu").addClass("animated slideInDown navbar-fixed-top stick-to-top").css("-vendor-animation-duration","3.8s"),n("#main-menu").css("background","#ffffff"),n(".nav-logo").show(),n(".nav-logo").css("display","inline"),n(".tb-megamenu").css({display:"inline","margin-top":"7px"}).addClass("pull-right"),n(".responsive-menus").css("border-bottom","1px solid #ededed")),n(document).scrollTop()<100&&(n("#main-menu").removeClass("animated slideInDown navbar-fixed-top stick-to-top").css("-vendor-animation-duration","3.8s"),n("#main-menu").css("background","transparent"),n(".nav-logo").hide(),n(".tb-megamenu").css({display:"block","margin-top":"0"}).removeClass("pull-right"),n("#main-menu").css("border-bottom","none")))})});
//# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbImFyX3RoZW1lLnNjcmlwdC5qcyJdLCJuYW1lcyI6WyJqUXVlcnkiLCJkb2N1bWVudCIsInJlYWR5IiwiJCIsIm1vdXNlZW50ZXIiLCJzaG93IiwibW91c2VsZWF2ZSIsImhpZGUiLCJ3aW5kb3ciLCJzY3JvbGwiLCJkb2N1bWVudEVsZW1lbnQiLCJjbGllbnRXaWR0aCIsInNjcm9sbFRvcCIsImFkZENsYXNzIiwiY3NzIiwiZGlzcGxheSIsIm1hcmdpbi10b3AiLCJyZW1vdmVDbGFzcyJdLCJtYXBwaW5ncyI6IkFBSUFBLE9BQUFDLFVBQUFDLE1BQUEsU0FBQUMsR0FJQUEsRUFBQSxXQUNBQSxFQUFBLFdBQUFDLFdBQUEsV0FDQUQsRUFBQSxvQkFBQUUsU0FJQUYsRUFBQSxvQkFBQUcsV0FBQSxXQUdBSCxFQUFBLG9CQUFBSSxXQUtBSixFQUFBLGFBQUFJLE9BRUFKLEVBQUFLLFFBQUFDLE9BQUEsV0FDQVIsU0FBQVMsZ0JBQUFDLFlBQUEsTUFFQVIsRUFBQUYsVUFBQVcsWUFBQSxNQUVBVCxFQUFBLGNBQUFVLFNBQUEsc0RBQUFDLElBQUEsNkJBQUEsUUFDQVgsRUFBQSxjQUFBVyxJQUFBLGFBQUEsV0FRQVgsRUFBQSxhQUFBRSxPQUNBRixFQUFBLGFBQUFXLElBQUEsVUFBQSxVQUNBWCxFQUFBLGdCQUFBVyxLQUNBQyxRQUFBLFNBQ0FDLGFBQUEsUUFDQUgsU0FBQSxjQUNBVixFQUFBLHFCQUFBVyxJQUFBLGdCQUFBLHNCQUVBWCxFQUFBRixVQUFBVyxZQUFBLE1BRUFULEVBQUEsY0FBQWMsWUFBQSxzREFBQUgsSUFBQSw2QkFBQSxRQUVBWCxFQUFBLGNBQUFXLElBQUEsYUFBQSxlQU9BWCxFQUFBLGFBQUFJLE9BQ0FKLEVBQUEsZ0JBQUFXLEtBQ0FDLFFBQUEsUUFDQUMsYUFBQSxNQUNBQyxZQUFBLGNBQ0FkLEVBQUEsY0FBQVcsSUFBQSxnQkFBQSIsImZpbGUiOiJhcl90aGVtZS5zY3JpcHQuanMiLCJzb3VyY2VzQ29udGVudCI6WyIvKipcbiAqIEBmaWxlXG4gKiBDdXN0b20gc2NyaXB0cyBmb3IgdGhlbWUuXG4gKi9cbmpRdWVyeShkb2N1bWVudCkucmVhZHkoZnVuY3Rpb24oJCkge1xuICAvLyBBZGQgeW91ciBjb2RlIGhlcmUuXG4gIC8vICQoJyNsYW5ndWFnZS1vcHRpb24nKS5zaG93KCk7XG5cbiAgJChmdW5jdGlvbigpe1xuICAgICAkKCcjc2VsZWN0JykubW91c2VlbnRlcihmdW5jdGlvbigpe1xuICAgICAgICAgICQoJyNsYW5ndWFnZS1vcHRpb24nKS5zaG93KCk7XG4gICAgICAgICAgLy8gJCgnLmhlYWRlci1sYW5ndWFnZScpLmFkZENsYXNzKCdoZWFkZXItY29udGFjdC1zaGFkb3cnKTtcbiAgICAgICAgICAvLyAkKCcuaGVhZGVyLWxhbmd1YWdlIHVsJykuYWRkQ2xhc3MoJ2hlYWRlci1jb250YWN0LXNoYWRvdycpO1xuICAgICAgfSk7XG4gICAgICAkKCcuaGVhZGVyLWxhbmd1YWdlJykubW91c2VsZWF2ZShmdW5jdGlvbigpe1xuICAgICAgICAgIC8vICQoJy5oZWFkZXItbGFuZ3VhZ2UnKS5yZW1vdmVDbGFzcygnaGVhZGVyLWNvbnRhY3Qtc2hhZG93Jyk7XG4gICAgICAgICAgLy8gJCgnLmhlYWRlci1sYW5ndWFnZSB1bCcpLnJlbW92ZUNsYXNzKCdoZWFkZXItY29udGFjdC1zaGFkb3cnKTtcbiAgICAgICAgICAkKCcjbGFuZ3VhZ2Utb3B0aW9uJykuaGlkZSgpO1xuICAgICAgfSk7XG4gICB9KTtcblxuICAvLyBTdGlja3kgTmF2aWdhdGlvblxuICAkKCcubmF2LWxvZ28nKS5oaWRlKCk7XG5cbiAgJCh3aW5kb3cpLnNjcm9sbChmdW5jdGlvbigpIHtcbiAgIGlmIChkb2N1bWVudC5kb2N1bWVudEVsZW1lbnQuY2xpZW50V2lkdGggPiA5NjApIHtcblxuICAgICAgaWYgKCQoZG9jdW1lbnQpLnNjcm9sbFRvcCgpID4gMTM1KSB7XG4gICAgICAgICAvLyQoJ2hlYWRlcicpLmNzcygnbWFyZ2luVG9wJywgNTUgKTsgLy8gUHJldmVudCBzY3JlZW4gSnVtcGluZyBuYXYuaGVpZ2h0KClcbiAgICAgICAgICQoJyNtYWluLW1lbnUnKS5hZGRDbGFzcygnYW5pbWF0ZWQgc2xpZGVJbkRvd24gbmF2YmFyLWZpeGVkLXRvcCBzdGljay10by10b3AnKS5jc3MoJy12ZW5kb3ItYW5pbWF0aW9uLWR1cmF0aW9uJywgJzMuOHMnKTtcbiAgICAgICAgICQoJyNtYWluLW1lbnUnKS5jc3MoICdiYWNrZ3JvdW5kJywgJyNmZmZmZmYnICk7XG4vKlxuICAgICAgICAgJCgnaGVhZGVyJykuY3NzKHtcbiAgICAgICAgICAgICdwYWRkaW5nLXRvcCc6ICc1NHB4JyxcbiAgICAgICAgICAgICdwYWRkaW5nLWxlZnQnOiAwXG4gICAgICAgICB9KTtcbiovXG5cbiAgICAgICAgICQoJy5uYXYtbG9nbycpLnNob3coKTtcbiAgICAgICAgICQoJy5uYXYtbG9nbycpLmNzcygnZGlzcGxheScsICdpbmxpbmUnKTtcbiAgICAgICAgICQoJy50Yi1tZWdhbWVudScpLmNzcyh7XG4gICAgICAgICAgICAnZGlzcGxheSc6ICdpbmxpbmUnLFxuICAgICAgICAgICAgJ21hcmdpbi10b3AnOiAnN3B4J1xuICAgICAgICAgIH0pLmFkZENsYXNzKCdwdWxsLXJpZ2h0Jyk7XG4gICAgICAgICAkKCcucmVzcG9uc2l2ZS1tZW51cycpLmNzcygnYm9yZGVyLWJvdHRvbScsICcxcHggc29saWQgI2VkZWRlZCcpO1xuICAgICAgfVxuICAgICAgaWYgKCQoZG9jdW1lbnQpLnNjcm9sbFRvcCgpIDwgMTAwKSB7XG4gICAgICAgICAvLyQoJ2hlYWRlcicpLmNzcygnbWFyZ2luVG9wJywgNTUpOyAvLyBQcmV2ZW50IHNjcmVlbiBKdW1waW5nIC5hZGRDbGFzcygnc2xpZGVPdXRVcCcpXG4gICAgICAgICAkKCcjbWFpbi1tZW51JykucmVtb3ZlQ2xhc3MoJ2FuaW1hdGVkIHNsaWRlSW5Eb3duIG5hdmJhci1maXhlZC10b3Agc3RpY2stdG8tdG9wJykuY3NzKCctdmVuZG9yLWFuaW1hdGlvbi1kdXJhdGlvbicsICczLjhzJyk7XG4gICAgICAgICAvLyQoJyNtYWluLW1lbnUnKS5hZGRDbGFzcygnYW5pbWF0ZWQgc2xpZGVPdXREb3duIG5hdmJhci1maXhlZC10b3Agc3RpY2stdG8tdG9wJykuY3NzKCctdmVuZG9yLWFuaW1hdGlvbi1kdXJhdGlvbicsICczLjhzJyk7XG4gICAgICAgICAkKCcjbWFpbi1tZW51JykuY3NzKCAnYmFja2dyb3VuZCcsICd0cmFuc3BhcmVudCcgKTtcbi8qXG4gICAgICAgICAkKCdoZWFkZXInKS5jc3Moe1xuICAgICAgICAgICAgJ3BhZGRpbmctdG9wJzogJzUwcHgnLFxuICAgICAgICAgICAgJ3BhZGRpbmctbGVmdCc6ICcwJ1xuICAgICAgICAgfSk7XG4qL1xuICAgICAgICAgJCgnLm5hdi1sb2dvJykuaGlkZSgpO1xuICAgICAgICAgJCgnLnRiLW1lZ2FtZW51JykuY3NzKHtcbiAgICAgICAgICAnZGlzcGxheSc6ICdibG9jaycsXG4gICAgICAgICAgJ21hcmdpbi10b3AnOiAnMCdcbiAgICAgICAgICB9KS5yZW1vdmVDbGFzcygncHVsbC1yaWdodCcpO1xuICAgICAgICAgJCgnI21haW4tbWVudScpLmNzcygnYm9yZGVyLWJvdHRvbScsICdub25lJyk7XG4gICAgICB9XG4gICB9XG4gICB9KTtcblxufSk7XG4iXSwic291cmNlUm9vdCI6Ii9zb3VyY2UvIn0=