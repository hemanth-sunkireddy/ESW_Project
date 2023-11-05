// Adafruit Motor Shield library - Version: Latest 
#include <AFMotor.h>

AF_DCMotor motor(3);
/*

*/

void setup() {
  Serial.begin(9600);
}

void loop() {
    motor.setSpeed(200);
    motor.run(FORWARD);
    Serial.println("---Rotating-Forward---");
    delay(1000);
    motor.run(RELEASE);
    delay(500);
    motor.run(BACKWARD);
    Serial.println("---Rotating-Backward---");
    delay(1000);
    motor.run(RELEASE);
}
