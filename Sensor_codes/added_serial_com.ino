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


// Network creditionals 
const char* ssid = "Hemanth";
const char* password = "12345678"; 

// Servo motor conditions 
// Red color = VCC
// Brown color = GND
// Orange color = PWM = 26
#define SERVO_PIN 26
Servo servoMotor;

// Temperature sensor 
// Red color = VCC
// Black color = GND
#define ONE_WIRE_BUS 18 // Yellow Color
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// Time management for servo motor. 
int timeToDelayInOneSecond = 10;
int timeToDelayInBetweenOnOff = 1 ;
int timeToAutomateActivationOfOnOff = 10;
int initialOrResetTime = 0; 

// Angel to rotate
int initialAngleToRotate = 75 ; 
int finalAngleToRotate = 110; 


// Thingspeak creditionals for servo motor
const char* thingSpeakWrite_ApiKey_ServoMotor = "T3V5SKT2D0768MCB"; 
const long thingSpeakChannelID_ServoMotor = 2266014 ;
const char* thingSpeakRead_ApiKey_ServoMotor = "IQ5YWGI14JAXQT6N";
const long thingSpeakFieldNumber_ServoMotor = 1; 
const long thingSpeakFieldNumber_Temperature = 2; 
const long thingSpeakFieldNumber_Turbidity = 3; 

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

  // Servo motor connection activation. 
  servoMotor.attach(SERVO_PIN);

  // Temperature sensor 
  sensors.begin();
}

 void loop() {

      // Turbidity sensor value 
      int sensorValue = analogRead(A0);// read the input on analog pin 0:
      float voltage = sensorValue * (5.0 / 1024.0); // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
      Serial.print("Turbidity value");
      Serial.println(voltage); 


        // Code for temperature sensor.
        sensors.requestTemperatures();
        float temperature = sensors.getTempCByIndex(0); // Read temperature

        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.println(" °C");

        // Code for Calculating Dissolved Oxygen 
        float DissolvedOxygen = (70 / 63 + PH_VALUE ) * (-0.16 * (temperature - 5)) + 12.26;
        Serial.print("Dissolved Oxygen : ");
        Serial.print(DissolvedOxygen);
        Serial2.println(DissolvedOxygen);    // This data is sent to the arduino with baud 4800
        Serial.println(" mg/L");

        // Incrementing time according to minutes scale. 
        initialOrResetTime = initialOrResetTime + 1 ;
        // Serial.print("Initial time");
        // Serial.println(initialOrResetTime);


        // Updating servo motor code 90 degrees, on condition.
        int condition = (initialOrResetTime == timeToAutomateActivationOfOnOff);
        // Serial.println(condition);
        if ( initialOrResetTime == timeToAutomateActivationOfOnOff ){
          for ( int position = initialAngleToRotate; position <= finalAngleToRotate; position++ ){
            servoMotor.write(position);
            delay(15);
          }

          // Serial monitor printing statements. 
          Serial.print("Successfully activated Servo motor by automatic activation, Food feeding started and after ");
          Serial.print(timeToDelayInBetweenOnOff);
          Serial.println(" seconds the servo motor closes.");
          Serial.println();


          // Sending data of the temperature sensor to thingspeak.
          ThingSpeak.setField(thingSpeakFieldNumber_Temperature, temperature);
          ThingSpeak.setField(thingSpeakFieldNumber_Turbidity, voltage);
          int response_ServoMotor = ThingSpeak.writeFields(thingSpeakChannelID_ServoMotor, thingSpeakWrite_ApiKey_ServoMotor);
          if (response_ServoMotor == 200) {
            Serial.println("Temperature data sent to thingspeak successfully.");
          } else {
            Serial.println("Error sending data to ThingSpeak of temperature ");
          }
          // Wait for delay time in between of one cycle. 
          delay(timeToDelayInBetweenOnOff * 1000 );

          // Getting back servo motor to close position from open position. 
          for ( int position = finalAngleToRotate; position >=  initialAngleToRotate; position-- ){
            servoMotor.write(position);
            delay(15);
          }

          // Serial monitor printing statements. 
          Serial.print("Successfully closed Servo motor by automatic activation, Food feeding stopped and again activates after ");
          Serial.print(timeToAutomateActivationOfOnOff);
          Serial.println(" seconds again servo motor activates. ");
          Serial.println();

          // Resetting time to 0 again after one succesfull cycle.
          initialOrResetTime = 0; 
        }

        // Serial monitor printing statements. 
        Serial.print("Current time in Seconds: ");
        Serial.println(initialOrResetTime);
        Serial.print(", After every ");
        Serial.print(timeToAutomateActivationOfOnOff);
        Serial.print(" seconds the automatic servo motor starts rotating and ");
        Serial.print(timeToDelayInBetweenOnOff);
        Serial.println(" seconds later it will automatically close.");
        Serial.println();


        // Reading the data from the Website button from thingspeak. 
        int dataFromThingSpeakOfServoMotor = ThingSpeak.readIntField(thingSpeakChannelID_ServoMotor, thingSpeakFieldNumber_ServoMotor, thingSpeakRead_ApiKey_ServoMotor);
        Serial.print("Data from the thingspeak, either 0 or 1, 1 means activation of servo motor, 0 means no need to activate the servo motor:-");
        Serial.println(dataFromThingSpeakOfServoMotor);
        Serial.println();
        if ( dataFromThingSpeakOfServoMotor == 1){
          for ( int position = initialAngleToRotate; position <= finalAngleToRotate; position++ ){
            servoMotor.write(position);
            delay(15);
          }

          // Serial monitor printing statements. 
          Serial.print("Successfully activated Servo motor by website control, Food feeding started and after ");
          Serial.print(timeToDelayInBetweenOnOff);
          Serial.println(" seconds the servo motor closes.");
          Serial.println();

        // Temperature sensor sending to thingspeak.
        ThingSpeak.setField(thingSpeakFieldNumber_Temperature, temperature);
        // Turbidity setting field value 
        ThingSpeak.setField(thingSpeakFieldNumber_Turbidity, voltage);
        int response_temperature = ThingSpeak.writeFields(thingSpeakChannelID_ServoMotor, thingSpeakWrite_ApiKey_ServoMotor);
        if (response_temperature == 200) {
          Serial.println("Temperature data sent to thingspeak successfully.");
        } else {
          Serial.println("Error sending data to ThingSpeak of temperature ");
        }

          // Wait for delay time in between of one cycle. 
          delay(timeToDelayInBetweenOnOff * 1000);

          // Getting back servo motor to close position from open position. 
          for ( int position = finalAngleToRotate; position >= initialAngleToRotate; position-- ){
            servoMotor.write(position);
            delay(15);
          }

          // Serial monitor printing statements. 
          Serial.print("Successfully closed Servo motor by website control, Food feeding stopped and again activates after ");
          Serial.print(timeToAutomateActivationOfOnOff);
          Serial.println(" seconds again servo motor activates. ");
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
        int response_ServoMotor2 = ThingSpeak.writeFields(thingSpeakChannelID_ServoMotor, thingSpeakWrite_ApiKey_ServoMotor);
        if (response_ServoMotor2 == 200) {
          Serial.println("Once again closed the activation of servo motor for safety purpose.");
        } else {
          Serial.println("Error sending data to ThingSpeak");
        }

          // Resetting time to 0 again after one successful cycle.
          initialOrResetTime = 0; 
        }

        //  ThingSpeak.setField(thingSpeakFieldNumber_Temperature, temperature);
        // int response_ServoMotor = ThingSpeak.writeFields(thingSpeakChannelID_ServoMotor, thingSpeakWrite_ApiKey_ServoMotor);
        // if (response_ServoMotor == 200) {
        //   Serial.println("Temperature data sent to thingspeak successfully.");
        // } else {
        //   Serial.println("Error sending data to ThingSpeak of temperature ");
        // }
        
        // Delay for 1 minute after every loop 
        delay(timeToDelayInOneSecond);

}
