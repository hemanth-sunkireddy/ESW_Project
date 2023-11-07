
// Temperature sensor 
// Red color = VCC
// Black color = GND
#define ONE_WIRE_BUS 18 // Yellow Color
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

float temperature_sensor(){
        // Code for temperature sensor.
        sensors.requestTemperatures();
        float temperature = sensors.getTempCByIndex(0); // Read temperature

        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.println(" °C");
        return temperature;
}