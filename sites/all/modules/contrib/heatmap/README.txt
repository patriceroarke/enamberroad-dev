INTRODUCTION
---------------
The HeatMap module records the users of the website and displays
the aggregated activity in form of heat maps of mouse movement,
heat maps of clicks and also gradient maps of scroll heights.

This gives you the power to keep this kind of business intelligence
on your own Drupal storage instead of having to use external tools
or services.

Bundled with the module are plugin modules for saving to CouchDB
or Elasticsearch since relational databases in general are not
scalable under load. 

REQUIREMENTS
--------------
HeatMap requires Library module to be installed as well as the
heatmap.js javascript to be installed into the libraries directory.
http://www.patrick-wied.at/static/heatmapjs/

The HeatMap Elasticsearch module requires the Elasticsearch Connector
module to be installed.

The HeatMap CouchDB module requires PHP-curl to be installed.

RECOMMENDATIONS
-------------
* GeoIP - If you install and enable GeoIP you will have the
option to filter the heat maps on country level.

* MemCache - This is highly recommended to install. With
Memcache enabled the statistical data will be written to
memory for a certain amount of time before being bulk-written
to persistent storage.

INSTALLATION
--------------
1. Copy the heatmap.js files into your libraries directory
so it looks like {libraries}/heatmap.js-develop/build/heatmap.js

2. Install as you would normally install a contributed module

3. Visit admin/config/system/heatmap and setup the settings as
you want (read more under configuration).

4. If you have the permission "View HeatMap" and you visit a 
theme and page that collects data you will see a tab on the top 
right side, click this to see the data for the page you are visiting.

CONFIGURATION
---------------
There are two permissions to HeatMap - one to configure HeatMap
settings and the other one to view HeatMap data.

TROUBLESHOOTING & FAQ
---------------
Q. Why do I see scrolling that occurs under the bottom of my page?
A. If you have a responsive design the height of the page may differ
depending on the width of the page, thus being higher on certain
devices.

Q. Why do I have to choose width?
A. It has the option to show everything, but this requires that
you fill in the selector where your content starts. Also this will give
very false information if you have a responsive design since
people might not see the page as it is rendered to you. Because
of this the best thing to do is to choose a width and scale your 
window too the size of that width to get optimal results

MAINTAINERS
----------------
Current maintainers:
 * Marcus Johansson (https://www.drupal.org/u/marcus_johansson)
 
This prject was sponsored by:
 * Marcus Johansson Drupal Consultancy
   Specialized in Drupal module development. I offer development
   of modules, themes and hosting in Berlin, Sweden and Spain as well as
   on distance. me@marcusmailbox.com