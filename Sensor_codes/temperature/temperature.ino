#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is connected to pin 2 on the Arduino
#define ONE_WIRE_BUS 4

// Create a OneWire instance to communicate with the DS18B20 sensor
OneWire oneWire(ONE_WIRE_BUS);

// Pass our OneWire reference to Dallas Temperature sensor
DallasTemperature sensors(&oneWire);

DeviceAddress insideThermometer;


void setup() {
  // Start the serial communication
  Serial.begin(115200);

  // Initialize the DS18B20 sensor
  sensors.begin();

  Serial.print(sensors.getDeviceCount(), DEC);
  Serial.println();

  Serial.print("Parasite power is:");
  if(sensors.isParasitePowerMode()) Serial.println("ON");
  else Serial.println("OFF");
}

void loop() {
  // Request temperature data from all sensors on the bus
  sensors.requestTemperatures();

  // Read the temperature from the DS18B20 sensor
  float temperatureCelsius = sensors.getTempCByIndex(0);

  if(temperatureCelsius != DEVICE_DISCONNECTED_C){
    Serial.print("Temperature for the device 1 ( index 0 ) is: ");
    Serial.println(temperatureCelsius);
  }
  else{
    Serial.println("Error reading sensor data");
  }


  

  // Add a delay to avoid rapid readings
  delay(1000);
}
