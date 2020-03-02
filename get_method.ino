#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
#define led D4

const char* ssid     = "vivo 1606";
const char* password = "12345678";
const char* State;

//const char* host     = "http://jsonplaceholder.typicode.com/users/1"; // Your domain  
const char* host     ="http://vedanshu.000webhostapp.com/nodeMCU.json";
String payload ;

void setup() 
{
  pinMode(led, OUTPUT); 
  pinMode(D6,OUTPUT);
  Serial.begin(115200);
  delay(3000);
  Serial.println("ESP As a Station Point Mode");
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {  
  
  delay(500); // wait for server to respond

  // read response
   HTTPClient http;  //Declare an object of class HTTPClient
 
    http.begin(host);  //Specify request destination
    int httpCode = http.GET();                                                                  //Send the request
 
    if (httpCode > 0) {
      const size_t bufferSize = JSON_OBJECT_SIZE(1);
      DynamicJsonBuffer jsonBuffer(bufferSize);
      JsonObject& root = jsonBuffer.parseObject(http.getString());
      State=root["State"];
      Serial.println(State);
      if(strcmp(State,"on")==0)
      {
        digitalWrite(D4,LOW);
        digitalWrite(D6,HIGH);
        Serial.println("led is on");
      }
      else
      {
          digitalWrite(D4,HIGH);
          digitalWrite(D6,LOW);
          Serial.println("led is off");
      }
    }
    
}
