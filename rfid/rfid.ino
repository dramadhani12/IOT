// RX           7
// TX           6
// RELAY        3
// LED          2
// RST          9
// SDA(SS)      10
// MOSI         11
// MISO         12
// SCK          13

byte sda = 10;
byte rst = 9;

#include <SoftwareSerial.h>
#include <DFPlayer_Mudah.h>
#include <KRrfid.h>
const int kontak = 3;
const int LED = 2;
//const int LEDM = 4;
SoftwareSerial MySerial(6, 7);
SoftwareSerial uno(4, 5);

void setup() {
  Serial.begin(9600);
  MySerial.begin(9600);
  uno.begin(9600);
  
  delay(500);
  mp3_set_serial(MySerial);
  inisial();
  atur_suara(25);
  rfidBegin();
  pinMode(kontak, OUTPUT);
  digitalWrite(kontak, LOW);
  pinMode(LED, OUTPUT);
//  pinMode(LEDM, OUTPUT);
}

void loop() {
  TAG.toInt();
  digitalWrite(LED, HIGH);
//  digitalWrite(LEDM,LOW);
  getTAG();
  if (TAG == "482412139") {
    digitalWrite(kontak, HIGH);
    digitalWrite(LED, LOW); //delay(3000);
//    digitalWrite(LEDM, HIGH);
    mainkan(9); //selamat datang di kedai (wafiq)
    delay (5000);
    digitalWrite(kontak, LOW);
    digitalWrite(LED, HIGH);
//    digitalWrite(LEDM, LOW);
//    Serial.print("TAG : ");
    Serial.println(TAG);
    uno.println(TAG);
    
//   int data = (TAG.toInt()) ;
//    if
//  (uno.available()>0){
//  
//   uno.write(data);
//  }
    TAG = "";
  }
  else if (TAG == "13020436761610") {
    digitalWrite(kontak, HIGH);
    digitalWrite(LED, LOW); //delay(3000);
//    digitalWrite(LEDM, HIGH);
    mainkan(9); //selamat datang di kedai (wafiq)
    delay (5000);
    digitalWrite(kontak, LOW);
    digitalWrite(LED, HIGH);
//    digitalWrite(LEDM, LOW);
//    Serial.print("TAG : ");
    Serial.println(TAG);
     uno.println(TAG);
    TAG = "";
  }
  else if (TAG == "") {
    TAG = "";
  }
  else {
    mainkan(2); //access denied (perempuan)
    delay (2000);
    Serial.print("TAG : ");
    Serial.println(TAG);
    TAG = "";
  }
  
}
