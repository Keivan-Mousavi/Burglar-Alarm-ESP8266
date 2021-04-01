# Burglar Alarm ESP8266

<p>
In this type of design, an attempt has been made to don't use IP static to transfer information. 
</p>
<p>
The purpose of eliminating static IP is to lower the cost to the user and also to have a machine learning on the server side to continue the project. 
<br />
The manufacturer of this device can also earn money through the sale of the Internet and other services.
</p>

<p>
The next phase of the project is on movement and face recognition.
</p>

<p>
  * It should be noted that the above module is only for demos and for large projects need a more powerful module.
 </p> 
 
 <p>
 The method is that the module (Big sound module) measures the ambient sound, if it was too much, using the module (Infrared emission sensor module) turns on the TV (LG) and sends an error message to the server.
 </p>
 
<p>
  <b>
    Required Device
  </b>
</p>
<ul>
<li>ESP8266</li>
<li>Infrared emission sensor module</li>
<li>Big sound module</li>
</ul>

![ESP8266-Pic](https://user-images.githubusercontent.com/22281772/113051228-ff69cb00-91ba-11eb-9ef8-8153670c5b4d.png)

<br />
<table style="height: 232px;" width="256">
<tbody>
<tr>
<td style="width: 119px; text-align: center;">ESP8266</td>
<td style="width: 121px; text-align: center;">Big Sound</td>
</tr>
<tr>
<td style="width: 119px; text-align: center;">D0</td>
<td style="width: 121px; text-align: center;">D0</td>
</tr>
<tr>
<td style="width: 119px; text-align: center;">3V3</td>
<td style="width: 121px; text-align: center;">+</td>
</tr>
<tr>
<td style="width: 119px; text-align: center;">GND</td>
<td style="width: 121px; text-align: center;">G</td>
</tr>
<tr>
<td style="width: 119px; text-align: center;">A0</td>
<td style="width: 121px; text-align: center;">A0</td>
</tr>
</tbody>
</table>

 <table style="height: 292px;" width="234">
<tbody>
<tr>
<td style="width: 109px; text-align: center;">ESP8266</td>
<td style="width: 109px; text-align: center;">Infrared emission sensor module</td>
</tr>
<tr>
<td style="width: 109px; text-align: center;">VIN</td>
<td style="width: 109px; text-align: center;">+</td>
</tr>
<tr>
<td style="width: 109px; text-align: center;">GND</td>
<td style="width: 109px; text-align: center;">-</td>
</tr>
<tr>
<td style="width: 109px; text-align: center;">D2</td>
<td style="width: 109px; text-align: center;">S</td>
</tr>
</tbody>
</table>

![ESp8266](https://user-images.githubusercontent.com/22281772/113051306-13adc800-91bb-11eb-9fc7-f225b8897caf.png)

<p>
  <b>PlatformIO.ini</b>
</p>
<pre>
<code>
  [env:esp12e]
  platform = espressif8266
  board = esp12e
  framework = arduino
  monitor_speed = 115200
  lib_deps = 
	  crankyoldgit/IRremoteESP8266@^2.7.14
	  bblanchon/ArduinoJson@^6.17.2
</code>
</pre>
