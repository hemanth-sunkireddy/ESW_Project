
float ph_sensor(){

        float pH = analogRead(32);
        pH = pH * (3.3 / 4095.0);
        pH = (pH * 3.3) + 2;
        Serial.print("Ph Values for : ");
        Serial.print(pH);
        Serial.println(" ");
        return pH;
}