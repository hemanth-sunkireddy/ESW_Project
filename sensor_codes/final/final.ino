#include <Arduino.h>
#include <WiFi.h>
#include <ThingSpeak.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>
#include <Wire.h>
#include <time.h>
#include <ESP32Servo.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define PH_VALUE 7
#define RXp2 16     // reciever pin
#define TXp2 17     // transmission pin

#include "temperature.h"
#include "dissolved_oxygen.h"
#include "ph.h"



// Network creditionals 
const char* ssid = "Hemanth";
const char* password = "12345678"; 



// Thingspeak creditionals for servo motor
const char* thingSpeakWrite_ApiKey_ESW_SENSORS = "G3OOXJ4BJJJTRJLV"; 
const long thingSpeakChannelID_ESW_SENSORS = 2335414 ;
// const char* thingSpeakRead_ApiKey_ServoMotor = "IQ5YWGI14JAXQT6N";
const long thingSpeakFieldNumber_temperature = 1; 
const long thingSpeakFieldNumber_temperatureAlert = 2; 
const long thingSpeakFieldNumber_turbidity = 3; 
const long thingSpeakFieldNumber_turbidityAlert = 4; 
const long thingSpeakFieldNumber_pH = 3; 
const long thingSpeakFieldNumber_pHalert = 3; 
const long thingSpeakFieldNumber_dissolvedOxygen = 3; 
const long thingSpeakFieldNumber_waterpump = 3; 

// Calling clients of Wifi and HTTP server.
WiFiClient client;
HTTPClient http;


void setup() {
  Serial.begin(9600);
  Serial2.begin(4800, SERIAL_8N1, RXp2, TXp2);  // For communicating with arduino

  // Wifi setup 
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Thingspeak connection activation.
  ThingSpeak.begin(client);


  // Temperature sensor 
  sensors.begin();

  pinMode(32, INPUT);
}

 void loop() {

      float turbidity = turbidity_sensor();

      float temperature = temperature_sensor();

      float dissolvedOxygen = dissolved_oxygen();

      float pHValue = ph_sensor();

      int temperature_alert = 0; 
      int turbidity_alert = 0;
      int pH_alert = 0; 
      int motorStatus = 0;
      
      if ( temperature >= 30 ){
          temperature_alert = 1;
      }
      if ( turbidity >= 10 ) { 
          turbidity_alert = 1;
      }
      if ( pHValue >= 9 || pHValue <= 5 ) { 
          pH_alert = 1;
      }

      if ( dissolvedOxygen < 11 ){
        motorStatus = 1;
      }
      
      ThingSpeak.setField(thingSpeakFieldNumber_temperature, temperature);
      ThingSpeak.setField(thingSpeakFieldNumber_temperatureAlert, temperature_alert);
      ThingSpeak.setField(thingSpeakFieldNumber_pH, pHValue);
      ThingSpeak.setField(thingSpeakFieldNumber_pHalert, pH_alert);
      ThingSpeak.setField(thingSpeakFieldNumber_turbidity, turbidity);
      ThingSpeak.setField(thingSpeakFieldNumber_turbidityAlert, turbidity_alert);
      ThingSpeak.setField(thingSpeakFieldNumber_dissolvedOxygen, dissolvedOxygen);
      ThingSpeak.setField(thingSpeakFieldNumber_waterpump, motorStatus);


      int response_ServoMotor = ThingSpeak.writeFields(thingSpeakChannelID_ESW_SENSORS, thingSpeakWrite_ApiKey_ESW_SENSORS);
      if (response_ServoMotor == 200) {
        Serial.println("Successfully sent all the details to the thingSpeak.");
      } else {
        Serial.println("Error sending data to ThingSpeak");
      }
      delay(15000); // Wait for 15 seconds and again send a safety request to thingspeak to close the circuit completly.
}
