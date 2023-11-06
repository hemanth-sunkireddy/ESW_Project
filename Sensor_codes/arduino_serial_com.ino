#include <SoftwareSerial.h>
#include <AFMotor.h>    // DC motor Drivers

#define RXp2 2  // Define the pin number for the software serial RX
#define TXp2 3  // Define the pin number for the software serial TX

AF_DCMotor motor(3);  // We are providing motor to the third pin

SoftwareSerial espSerial(RXp2, TXp2);  // Define a software serial port

void setup() {
  Serial.begin(4800);  // Initialize the Serial Monitor
  espSerial.begin(4800);  // Initialize the software serial port for ESP32 communication
  motor.setSpeed(255);
}

void loop() {
  if (espSerial.available()) {
    String dataFromESP32 = espSerial.readString();  // Read data from ESP32
    Serial.println(dataFromESP32);  // Print received data to Serial Monitor
    if(dataFromESP32 < "10")
    {
      // Oxygen Low case so provide O2 for it
      motor.run(FORWARD);
      Serial.println("--- Low Oxygen ---");
      delay(10000);
      Serial.println("--- Oxygen Provided Success ---");
    }
    // Turn the Motor OFF
    motor.run(RELEASE);
  }
}