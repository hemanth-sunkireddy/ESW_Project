#include <SoftwareSerial.h>

#define RXp2 2  // Define the pin number for the software serial RX
#define TXp2 3  // Define the pin number for the software serial TX

SoftwareSerial espSerial(RXp2, TXp2);  // Define a software serial port

void setup() {
  Serial.begin(4800);  // Initialize the Serial Monitor
  espSerial.begin(4800);  // Initialize the software serial port for ESP32 communication
}

void loop() {
  if (espSerial.available()) {
    String dataFromESP32 = espSerial.readString();  // Read data from ESP32
    Serial.println(dataFromESP32);  // Print received data to Serial Monitor
  }
}
