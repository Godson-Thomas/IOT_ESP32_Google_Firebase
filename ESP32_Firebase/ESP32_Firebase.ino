#include <WiFi.h>
#include <FirebaseESP32.h>
 
 
#define FIREBASE_HOST ""
#define FIREBASE_AUTH ""
#define WIFI_SSID "Name"
#define WIFI_PASSWORD "P455Word"
 
 
//Define FirebaseESP32 data object
FirebaseData firebaseData;
FirebaseJson json;
int begi=0; 
int ter=7; 
 
void setup()
{
 
  Serial.begin(115200);
 
 
 
 
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
 
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
 
  //Set database read timeout to 1 minute (max 15 minutes)
  Firebase.setReadTimeout(firebaseData, 1000 * 60);
  //tiny, small, medium, large and unlimited.
  //Size and its write timeout e.g. tiny (1s), small (10s), medium (30s) and large (60s).
  Firebase.setwriteSizeLimit(firebaseData, "tiny");
 
  /*
  This option allows get and delete functions (PUT and DELETE HTTP requests) works for device connected behind the
  Firewall that allows only GET and POST requests.
  
  Firebase.enableClassicRequest(firebaseData, true);
  */
 
  //String path = "/data";
  
 
  Serial.println("------------------------------------");
  Serial.println("Connected...");
  
}
 
void loop()
{

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
  
 
}
