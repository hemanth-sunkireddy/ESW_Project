#include <Arduino.h>
#include <WiFi.h>
#include <ThingSpeak.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>
#include <Wire.h>
#include <time.h>
#include <ESP32Servo.h>
#define TEMPERATURE 23

const char* ssid = "Hemanth";
const char* password = "12345678";

const char* thingSpeakWrite_ApiKey_pH = "T3V5SKT2D0768MCB";
const long thingSpeakChannelID_pH = 2266014;
const char* thingSpeakRead_ApiKey_pH = "IQ5YWGI14JAXQT6N";
const long thingSpeakFieldNumber_pH = 2;

int pH_field = 0;

WiFiClient client;
HTTPClient http;

const int potPin = A0;
float ph;
float Value = 0;

void setupWiFi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void setupThingSpeak() {
  ThingSpeak.begin(client);
  Serial.println("ThingSpeak setup completed");
  delay(1000);
}

void updateThingSpeak(int field, float value) {
  ThingSpeak.setField(field, value);
  int response = ThingSpeak.writeFields(thingSpeakChannelID_pH, thingSpeakWrite_ApiKey_pH);
  if (response == 200) {
    Serial.println("Data updated on ThingSpeak");
  } else {
    Serial.println("Error sending data to ThingSpeak");
  }
  delay(1000);
}

void setup() {
  Serial.begin(115200);
  pinMode(potPin, INPUT);
  setupWiFi();
  setupThingSpeak();
}

void loop() {
  Value = analogRead(potPin);
  Serial.print(Value);
  Serial.print(" | ");
  float voltage = Value * (3.3 / 4095.0);
  ph = (3.3 * voltage) + 2;
  Serial.print("pH : ");
  Serial.println(ph);

  float disoxy = (70/(63+ph)) * (-0.16 * TEMPERATURE) + 12.26;

  Serial.print("DisOxy : ");
  Serial.println(disoxy);

  if (ph > 6 && ph < 8) {
    updateThingSpeak(5, 0);
  } else {
    updateThingSpeak(5, 1);
  }

  updateThingSpeak(2, ph);

  delay(1000);
}
