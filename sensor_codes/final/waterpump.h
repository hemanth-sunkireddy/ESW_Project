// Motor A
int motor1Pin1 = 27; 
int motor1Pin2 = 26; 
int enable1Pin = 14; 

// Setting PWM properties
const int pwmChannel = 0;

void rotate(int delay_time)
{
  Serial.println("Motor Rotating");
  digitalWrite(motor1Pin1, HIGH);
  delay(delay_time);
}

void Stop(int delay_time)
{
  Serial.println("Motor Rotating");
  digitalWrite(motor1Pin1, LOW);
  delay(delay_time);
}
