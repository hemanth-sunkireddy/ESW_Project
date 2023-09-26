// Include required libraries
#include <Arduino.h>

// Define the analog pin for the turbidity sensor
const int turbidityPin = A0;

void setup() {
  // Start serial communication
  Serial.begin(9600);
}

void loop() {
  // Read the analog value from the turbidity sensor
  int turbidityValue = analogRead(turbidityPin);

  // Print the turbidity value to the Serial monitor
  Serial.print("Turbidity Value: ");
  Serial.println(turbidityValue);

  // You can add further processing or send the data to a server or display it on an OLED screen, etc.
  
  delay(1000); // Delay for 1 second before the next reading
}
