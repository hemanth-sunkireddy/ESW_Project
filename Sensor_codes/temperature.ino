#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is connected to GPIO 4 (you can change this pin)
const int oneWireBus = 4;

OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures(); // Send the command to get temperatures
  
  // You can have multiple DS18B20 sensors on the same bus.
  // To address a specific sensor, use the sensor's unique address.
  // For now, we'll just read the first sensor found.
  float temperatureC = sensors.getTempCByIndex(0);
  
  if (temperatureC != DEVICE_DISCONNECTED_C) {
    Serial.print("Temperature: ");
    Serial.print(temperatureC);
    Serial.println(" °C");
    
    // Uncomment the following line if you want to convert temperature to Fahrenheit
    // float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
    // Serial.print("Temperature: ");
    // Serial.print(temperatureF);
    // Serial.println(" °F");
  } else {
    Serial.println("Error: Could not read temperature data");
  }
  
  delay(1000); // Delay for one second before taking the next reading
}
