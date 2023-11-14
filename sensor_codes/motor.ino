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

void setup() {
  // sets the pins as outputs:
  pinMode(motor1Pin1, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(enable1Pin, pwmChannel);
  Serial.begin(115200);

  // testing
  Serial.print("Testing DC Motor...");
}

void loop() {

  // Stop the DC motor
  Stop(1000);
  // Move DC motor at maximum speed
  rotate(1000);

}
