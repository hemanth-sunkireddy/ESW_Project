// const int potPin=A0;
// float ph;
// float Value=0;
 
// void setup() {
//   // put your setup code here, to run once:
//   Serial.begin(115200);
//   pinMode(potPin,INPUT);
//   delay(1000);
// }
//  void loop(){
 
//     Value= analogRead(potPin);
//     Serial.print(Value);
//     Serial.print(" | ");
//     float voltage=Value*(3.3/4095.0);
//     ph=(3.3*voltage);
//     Serial.println(ph);
//     delay(500);
//  }


#include <Arduino.h>
#include <WiFi.h>
#include <ThingSpeak.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>
#include <Wire.h>
#include <time.h>
#include <ESP32Servo.h>

const char* ssid = "Hemanth";
const char* password = "12345678";

const char* thingSpeakWrite_ApiKey_pH = "T3V5SKT2D0768MCB"; 
const long thingSpeakChannelID_pH = 2266014 ;
const char* thingSpeakRead_ApiKey_pH = "IQ5YWGI14JAXQT6N";
const long thingSpeakFieldNumber_pH = 2; 

int pH_field = 0;

WiFiClient client;
HTTPClient http;

const int potPin=A0;
float ph;
float Value=0;
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(potPin,INPUT);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Thingspeak connection activation.
 ThingSpeak.begin(client);

 Serial.println("Now Void Setup Has been completed");
  delay(1000);
}
 void loop(){
 
    Value= analogRead(potPin);
    Serial.print(Value);
    Serial.print(" | ");
    float voltage=Value*(3.3/4095.0);
    ph=(3.3*voltage);
    Serial.println(ph);
    if(ph > 6 && ph < 8)
    {
      ThingSpeak.setField(5, 0);
        int response_pH = ThingSpeak.writeFields(thingSpeakChannelID_pH, thingSpeakWrite_ApiKey_pH);
        if (response_pH == 200) {
          Serial.println("pH updated");
        } else {
          Serial.println("Error sending data to ThingSpeak");
        }
        delay(1000);
    }
    else
    {
      ThingSpeak.setField(5, 1);
        int response_pH = ThingSpeak.writeFields(thingSpeakChannelID_pH, thingSpeakWrite_ApiKey_pH);
        if (response_pH == 200) {
          Serial.println("pH updated");
        } else {
          Serial.println("Error sending data to ThingSpeak");
        }
        delay(1000);
    }
    ThingSpeak.setField(2, ph);
        int response_pH = ThingSpeak.writeFields(thingSpeakChannelID_pH, thingSpeakWrite_ApiKey_pH);
        if (response_pH == 200) {
          Serial.println("pH updated");
        } else {
          Serial.println("Error sending data to ThingSpeak");
        }
    delay(1000);
 }
