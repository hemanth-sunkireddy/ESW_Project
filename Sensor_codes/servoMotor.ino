#include <Arduino.h>
#include <WiFi.h>
#include <ThingSpeak.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>
#include <Wire.h>
#include <time.h>
#include <ESP32Servo.h>

// Network creditionals 
const char* ssid = "Hemanth";
const char* password = "12345678"; 

// Servo motor conditions 
#define SERVO_PIN 26
Servo servoMotor;

// Time management for servo motor. 
int timeToDelayInOneSecond = 1000;
int timeToDelayInOneMinute = 60 * timeToDelayInOneSecond;
int timeToDelayInBetweenOnOffInMinutes = 2 ;
int timeToDelayInBetweenOnOffInSeconds = timeToDelayInBetweenOnOffInMinutes * timeToDelayInOneMinute; 
int timeToAutomateActivationOfOnOffInMinutes = 3;
int timeToAutomateActivationOfOnOffInSeconds = timeToAutomateActivationOfOnOffInMinutes * timeToDelayInOneMinute;
int initialOrResetTime = 0; 

// Thingspeak creditionals for servo motor
const char* thingSpeakWrite_ApiKey_ServoMotor = "T3V5SKT2D0768MCB"; 
const long thingSpeakChannelID_ServoMotor = 2266014 ;
const char* thingSpeakRead_ApiKey_ServoMotor = "IQ5YWGI14JAXQT6N";
const long thingSpeakFieldNumber_ServoMotor = 1; 

// Calling clients of Wifi and HTTP server.
WiFiClient client;
HTTPClient http;


void setup() {
  Serial.begin(115200);

  // Wifi setup 
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Thingspeak connection activation.
 ThingSpeak.begin(client);

  // Servo motor connection activation. 
  servoMotor.attach(SERVO_PIN);
}

 void loop() {

        // Incrementing time according to minutes scale. 
        initialOrResetTime++;

        // Updating servo motor code 180 degrees, on condition.
        if ( initialOrResetTime == timeToAutomateActivationOfOnOffInSeconds ){
          for ( int position = 0; position <=180; position++ ){
            servoMotor.write(position);
            delay(15);
          }

          // Serial monitor printing statements. 
          Serial.print("Successfully activated Servo motor by automatic activation, Food feeding started and after ");
          Serial.print(timeToDelayInBetweenOnOffInMinutes);
          Serial.println(" minutes the servo motor closes.");
          Serial.println();

          // Wait for delay time in between of one cycle. 
          delay(timeToDelayInBetweenOnOffInSeconds);

          // Getting back servo motor to close position from open position. 
          for ( int position = 180; position >= 0; position-- ){
            servoMotor.write(position);
            delay(15);
          }

          // Serial monitor printing statements. 
          Serial.print("Successfully closed Servo motor by automatic activation, Food feeding stopped and again activates after ");
          Serial.print(timeToAutomateActivationOfOnOffInMinutes);
          Serial.println(" minutes again servo motor activates. ");
          Serial.println();

          // Resetting time to 0 again after one succesfull cycle.
          initialOrResetTime = 0; 
        }

        // Serial monitor printing statements. 
        Serial.print("Current time in Seconds: ");
        Serial.println(initialOrResetTime);
        Serial.print(", After every ");
        Serial.print(timeToAutomateActivationOfOnOffInMinutes);
        Serial.print(" minutes the automatic servo motor starts rotating and ");
        Serial.print(timeToDelayInBetweenOnOffInMinutes);
        Serial.println(" minutes later it will automatically close.");
        Serial.println();


        // Reading the data from the Website button from thingspeak. 
        int dataFromThingSpeakOfServoMotor = ThingSpeak.readIntField(thingSpeakChannelID_ServoMotor, thingSpeakFieldNumber_ServoMotor, thingSpeakRead_ApiKey_ServoMotor);
        Serial.print("Data from the thingspeak, either 0 or 1, 1 means activation of servo motor, 0 means no need to activate the servo motor:-");
        Serial.println(dataFromThingSpeakOfServoMotor);
        Serial.println();
        if ( dataFromThingSpeakOfServoMotor == 1){
          for ( int position = 0; position <=180; position++ ){
            servoMotor.write(position);
            delay(15);
          }

          // Serial monitor printing statements. 
          Serial.print("Successfully activated Servo motor by website control, Food feeding started and after ");
          Serial.print(timeToDelayInBetweenOnOffInMinutes);
          Serial.println(" minutes the servo motor closes.");
          Serial.println();

          // Wait for delay time in between of one cycle. 
          delay(timeToDelayInBetweenOnOffInMinutes * timeToDelayInOneMinute);

          // Getting back servo motor to close position from open position. 
          for ( int position = 180; position >= 0; position-- ){
            servoMotor.write(position);
            delay(15);
          }

          // Serial monitor printing statements. 
          Serial.print("Successfully closed Servo motor by website control, Food feeding stopped and again activates after ");
          Serial.print(timeToAutomateActivationOfOnOffInMinutes);
          Serial.println(" minutes again servo motor activates. ");
          Serial.println();

        // Turning off the Website click to 0 in thingspeak.
        ThingSpeak.setField(1, 0);
        int response_ServoMotor = ThingSpeak.writeFields(thingSpeakChannelID_ServoMotor, thingSpeakWrite_ApiKey_ServoMotor);
        if (response_ServoMotor == 200) {
          Serial.println("Successfully closed the activation of food feeding by the website.");
        } else {
          Serial.println("Error sending data to ThingSpeak");
        }
        delay(15000); // Wait for 15 seconds and again send a safety request to thingspeak to close the circuit completly.
        ThingSpeak.setField(1, 0);
        int response_ServoMotor = ThingSpeak.writeFields(thingSpeakChannelID_ServoMotor, thingSpeakWrite_ApiKey_ServoMotor);
        if (response_ServoMotor == 200) {
          Serial.println("Once again closed the activation of servo motor for safety purpose.");
        } else {
          Serial.println("Error sending data to ThingSpeak");
        }

          // Resetting time to 0 again after one successful cycle.
          initialOrResetTime = 0; 
        }


        // Delay for 1 minute after every loop 
        delay(timeToDelayInOneSecond);
}

 
