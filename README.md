&nbsp; &nbsp; &nbsp;  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<img src="https://github.com/Godson-Thomas/IOT_ESP32_Google_Firebase/blob/master/Images/A/1_image.png" width="500" >  <br>
# ESP32 To  GOOGLE FIREBASE
## ***Arduino IDE Setup*** :

 1. Install Arduino IDE. [link here](https://www.arduino.cc/en/main/software)<br>
 2. Now we have to Install ESP32 Board.<br>
* Copy<br>
```
https://dl.espressif.com/dl/package_esp32_index.json
```


* ***File*** >> ***Preferences*** >> Paste the Url into the *Additional Board Manager URLs*<br><br>
<img src="https://github.com/Godson-Thomas/Data-transfer-between-Arduino-UNO-and-ESP8266/blob/master/UNO_to_ESP8266/Images/B.png" width="400"> <br><br>
<img src="https://github.com/Godson-Thomas/IOT_ESP32_Google_Firebase/blob/master/Images/A/_3.JPG" width="400"> <br><br>

3. ***Tools*** >> ***Board*** >>***Boards Manager*** <br><br>
<img src="https://github.com/Godson-Thomas/Data-transfer-between-Arduino-UNO-and-ESP8266/blob/master/UNO_to_ESP8266/Images/B6.png" width="400"> <br><br>

4. Type **esp32** in the search bar and Install it.<br><br>
<img src="https://github.com/Godson-Thomas/IOT_ESP32_Google_Firebase/blob/master/Images/A/_5.png" width="400"> <br><br>

5. Connect ESP32 and upload the Code by selecting ***Tools*** >> ***Board*** >> ***NodeMCU***.<br><br>
<img src="https://github.com/Godson-Thomas/IOT_ESP32_Google_Firebase/blob/master/Images/A/_6.png" width="400"> <br><br>

6. Installing Firebase library<br>
 * [click here](https://github.com/Godson-Thomas/IOT_ESP32_Google_Firebase/raw/master/Images/Firebase_ESP32_Client.rar) to download the library
 * Go to ***Sketch*** >> ***Include Library*** >> ***Add .ZIP Library*** >> Select the downloaded firebase library<br><br>
 <img src="https://github.com/Godson-Thomas/IOT_Google_Firebase-NodeMCU/blob/master/Images/A/1.jpg" width="400"> <br><br>
 
 

## ***Google Firebase Setup*** :

8. Open Google Firebase Website [link](https://firebase.google.com/)<br><br>
<img src="https://github.com/Godson-Thomas/IOT_Google_Firebase-NodeMCU/blob/master/Images/F/4.png" width="600"> <br><br>

9. Sign in using your G-Mail
10. click on ***Create a project***<br><br>
<img src="https://github.com/Godson-Thomas/IOT_Google_Firebase-NodeMCU/blob/master/Images/F/6.png" width="700"> <br><br>

11. Enter a Project Name and read & accept the terms<br><br>
<img src="https://github.com/Godson-Thomas/IOT_Google_Firebase-NodeMCU/blob/master/Images/F/7.png" width="600"> <br><br>

12. Click on ***Continue***<br><br>
<img src="https://github.com/Godson-Thomas/IOT_Google_Firebase-NodeMCU/blob/master/Images/F/8.png" width="700"> <br><br>

13. Select ***Default Account for Firebase***<br><br>
<img src="https://github.com/Godson-Thomas/IOT_Google_Firebase-NodeMCU/blob/master/Images/F/9.jpg" width="800"> <br><br>

14. Your Project will be created & loaded .Click on  ***Continue***<br><br>
<img src="https://github.com/Godson-Thomas/IOT_Google_Firebase-NodeMCU/blob/master/Images/F/11.png" width="600"> <br><br>

## ***Coding*** : 
### [code](https://github.com/Godson-Thomas/IOT_ESP32_Google_Firebase/blob/master/ESP32_Firebase/ESP32_Firebase.ino)

15.  Include necessary libraries
```
#include <WiFi.h>
#include <FirebaseESP32.h>
```
16. ### Provide your realtime database URL
```
#define FIREBASE_HOST "paste_URL"
```
<br>

*  Open Firebase >> ***Database*** <br><br>
<img src="https://github.com/Godson-Thomas/IOT_Google_Firebase-NodeMCU/blob/master/Images/F/12.png" width="200"> <br><br>

* ***choose Realtime database*** >> ***Create database***<br><br>
<img src="https://github.com/Godson-Thomas/IOT_Google_Firebase-NodeMCU/blob/master/Images/F/13.png" width="800"> <br><br>

* ***Start in test mode*** >> ***click Enable***<br><br>
<img src="https://github.com/Godson-Thomas/IOT_Google_Firebase-NodeMCU/blob/master/Images/F/14.png" width="600"><br><br>

* Copy your database URL <br><br>
<img src="https://github.com/Godson-Thomas/IOT_Google_Firebase-NodeMCU/blob/master/Images/F/14b.png" width="700">  <br><br>

* Paste it in the Arduino code

17. ### Provide your database authentication key
```
#define FIREBASE_AUTH ""
```
* For this, click on ***Project Overview*** >> ***Project Settings***<br><br>
 <img src="https://github.com/Godson-Thomas/IOT_Google_Firebase-NodeMCU/blob/master/Images/F/15.png" width="700"> <br><br>
 
 * click on ***Service Accounts*** <br><br>
 <img src="https://github.com/Godson-Thomas/IOT_Google_Firebase-NodeMCU/blob/master/Images/F/16.png" width="800"> <br><br>
 
* click on ***Database Secrets***<br><br>
 <img src="https://github.com/Godson-Thomas/IOT_Google_Firebase-NodeMCU/blob/master/Images/F/17.png" width="800"> <br><br>
* Copy the secret key and paste it in the Arduino code

18. Connect the ESP8266 to a WIFI-Hotspot by giving its SSID and Password
```
#define WIFI_SSID "Name"
#define WIFI_PASSWORD "P455Word"
```
19. Starting the Serial Monitor Communication
```
Serial.begin(9600);
```
20. Checking whether connection is available and displaying IP address if the connection is successfull
```
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
  ```
21. Initializing Firebase Connection
```
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

   //Set database read timeout to 1 minute (max 15 minutes)
  Firebase.setReadTimeout(firebaseData, 1000 * 60);
  //tiny, small, medium, large and unlimited.
  //Size and its write timeout e.g. tiny (1s), small (10s), medium (30s) and large (60s).
  Firebase.setwriteSizeLimit(firebaseData, "tiny");
  
 
  Serial.println("------------------------------------");
  Serial.println("Connected...");
```
22. Senting data to Google Firebase
```
 for(begi=0;begi<=ter;begi++){
  Serial.println(begi); 
  delay(100);
  json.set("/data", begi);
  delay(100);
  Firebase.updateNode(firebaseData,"/Sensor",json);
  delay(1000);
  }
  begi=0;
  
 
delay(100);             
```

23. In your Realtime Databse of Firebase you can see the changes<br><br>
 
