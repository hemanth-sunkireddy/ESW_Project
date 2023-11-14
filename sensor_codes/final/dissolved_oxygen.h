float dissolved_oxygen(){

  // Code for Calculating Dissolved Oxygen 
        float DissolvedOxygen = (70 / (77 - PH_VALUE) ) * (-0.16 * (temperature)) + 12.26;
        // (70 / (77 - pH)) * (-0.16) * temp + 9.26
        Serial.print("Dissolved Oxygen : ");
        Serial.println(DissolvedOxygen);
        char buffer[10];  // Buffer to hold the converted value
        dtostrf(DissolvedOxygen, 4, 2, buffer);  // Convert the float to a string
        Serial2.println(buffer);  // Send the string to Arduino with baud 4800
        return DissolvedOxygen;
}
