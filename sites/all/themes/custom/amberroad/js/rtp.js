(function(c,h,a,f,i){c[a]=c[a]||function(){(c[a].q=c[a].q||[]).push(arguments)};
 c[a].a=i;var g=h.createElement("script");g.async=true;g.type="text/javascript";
 g.src=f+'?rh='+c.location.hostname+'&aid='+i;var b=h.getElementsByTagName("script")[0];b.parentNode.insertBefore(g,b);
 })(window,document,"rtp","//sjrtp-cdn.marketo.com/rtp-api/v1/rtp.js","managementdynamics");

rtp('send','view');
rtp('get', 'campaign',true);
