# ESW PROJECT

## Project title:  Innovative Aquatic Cultivation

## Problem statement:

The irregular provision of food to fish often results in instances of overfeeding or underfeeding, subsequently leading to diseases. The release of ammonia into the water necessitates manual intervention for feeding. In the context of cultivating fish within a closed container, it becomes imperative to monitor dissolved oxygen levels at regular intervals. The consistent growth of bacteria, coupled with fluctuations in pH levels, contributes to diminished fish productivity. Furthermore, factors such as temperature and light play significant roles in fish production. Instances of changing water composition also pose threats to the survival of the fish population.


## Solution:

Our proposed solution revolves around the implementation of an automated fish feeding system, aimed at addressing the issues of overfeeding, nitrogen release, and the elimination of manual intervention. We intend to measure the dissolved oxygen content, and if it falls below a predetermined threshold, we will employ natural aeration methods to enhance the oxygen concentration in the water. Additionally, we will monitor various parameters such as pH, Total Dissolved Solids (TDS), and temperature readings to assess the stress levels experienced by the fish population due to environmental factors.  As an optional feature, we are considering the incorporation of a robotic arm to extend the lifespan of the water sensors.

By undertaking these initiatives, we aim to revolutionize aquaculture practices, ensuring optimal fish health, growth, and productivity.


## ThingSpeak creditionals
```
Username: hemanthkumarreddysunkireddy51@gmail.com
password: Iiits@123$
```

## Presentatation
```
https://www.canva.com/design/DAFwGi38-_A/lzGJ421ybFxFqyTZbmun0g/edit?utm_content=DAFwGi38-_A&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton
```
## Live website deployed at
```
https://hemanth-sunkireddy.github.io/ESW_Project/
```


## Dissolved Oxygen
- pH is inversely proportional to the dissolved oxygen.
- Temp is inversely proportional to the dissolved oxygen.


```
Dissolved Oxygen = (70 / (77 - pH)) * (-0.16) * temp + 12.26 
```

reference : 
[https://www.fondriest.com/environmental-measurements/parameters/water-quality/dissolved-oxygen/]


## pH Sensor Calculation:

```(float)avgValue * 5.0 / 1024```: This part of the calculation is used to convert the analog reading into millivolts (mV). Here's how it works:

avgValue contains the average analog reading from the pH sensor. It's multiplied by 5.0 because the Arduino's analog pins provide a voltage range of 0 to 5 volts.
The result is divided by 1024 because the analog-to-digital converter (ADC) in the Arduino has a 10-bit resolution, which means it can represent values from 0 to ```1023 (2^10 - 1)```. Dividing by 1024 scales the reading to a voltage between 0 and 5 volts.
So, after this part of the calculation, phValue represents the voltage in millivolts.

```phValue = 3.5 * phValue```: This part of the calculation is used to convert the millivolt reading into a pH value. The factor 3.5 is likely based on the characteristics of the specific pH sensor being used. The factor is determined through calibration of the sensor.

Different pH sensors may have different sensitivity values, and calibration is necessary to relate the sensor's millivolt output to the actual pH value.
The multiplication by 3.5 is part of the calibration process. It scales the millivolt reading to the pH scale based on the sensor's characteristics.

