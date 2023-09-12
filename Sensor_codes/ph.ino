#define SensorPin A0          // the pH meter Analog output is connected with the Arduino’s Analog
unsigned long int avgValue;  //Store the average value of the sensor feedback
float b;
int buf[10],temp;
 
void setup()
{
  pinMode(13,OUTPUT);  
  Serial.begin(9600);  
  Serial.println("Ready");    //Test the serial monitor
}
void loop()
{
  for(int i=0;i<10;i++)       //Get 10 sample value from the sensor for smooth the value
  { 
    buf[i]=analogRead(SensorPin);
    delay(10);
  }
  for(int i=0;i<9;i++)        //sort the analog from small to large
  {
    for(int j=i+1;j<10;j++)
    {
      if(buf[i]>buf[j])
      {
        temp=buf[i];
        buf[i]=buf[j];
        buf[j]=temp;
      }
    }
  }
  avgValue=0;
  for(int i=2;i<8;i++)                      //take the average value of 6 center sample
    avgValue+=buf[i];
  float phValue=(float)avgValue*5.0/1024/6; //convert the analog into millivolt
  phValue=3.5*phValue;                      //convert the millivolt into pH value
  Serial.print("    pH:");  
  Serial.print(phValue,2);
  Serial.println(" ");
  digitalWrite(13, HIGH);       
  delay(800);
  digitalWrite(13, LOW); 
 
}


// (float)avgValue * 5.0 / 1024: This part of the calculation is used to convert the analog reading into millivolts (mV). Here's how it works:

// avgValue contains the average analog reading from the pH sensor. It's multiplied by 5.0 because the Arduino's analog pins provide a voltage range of 0 to 5 volts.
// The result is divided by 1024 because the analog-to-digital converter (ADC) in the Arduino has a 10-bit resolution, which means it can represent values from 0 to 1023 (2^10 - 1). Dividing by 1024 scales the reading to a voltage between 0 and 5 volts.
// So, after this part of the calculation, phValue represents the voltage in millivolts.

// phValue = 3.5 * phValue: This part of the calculation is used to convert the millivolt reading into a pH value. The factor 3.5 is likely based on the characteristics of the specific pH sensor being used. The factor is determined through calibration of the sensor.

// Different pH sensors may have different sensitivity values, and calibration is necessary to relate the sensor's millivolt output to the actual pH value.
// The multiplication by 3.5 is part of the calibration process. It scales the millivolt reading to the pH scale based on the sensor's characteristics.
