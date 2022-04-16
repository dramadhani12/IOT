#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>
#include <time.h>
#include <SoftwareSerial.h>

  #define ssid "Coffee Drip"
  #define pass "kopisusu"


SoftwareSerial mcu(D6, D5);
int data;
void setup() {

  // put your setup code here, to run once:
  mcu.begin(9600);
  Serial.begin(9600);
 

//    WiFi.begin(ssid,pass);
//  
//    while (WiFi.status()!=WL_CONNECTED){
//      delay(500);
//      Serial.println("Waiting for connection");

}



void loop() {
 mcu.write("mcu");
  if(mcu.available() > 0) {
    data = mcu.read();
    Serial.println(data);
    delay(5000);
  }

}
