

float turbidity_sensor(){
     // Turbidity sensor value 
      int sensorValue = analogRead(A0);// read the input on analog pin 0:
      float voltage = sensorValue * (5.0 / 1024.0); // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
      voltage = 13.0 - voltage;
      Serial.print("Turbidity value: ");
      Serial.print(voltage); 
      Serial.println(" NTU.");
      return voltage;
}