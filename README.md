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
1. pH is inversely proportional to the dissolved oxygen.
2. Temp is inversely proportional to the dissolved oxygen.
3. normal values for DO is 10-20 mg/L
4. Dissolved oxygen measure decreases in increase of fish count.
5. Suppose we increase fishes. that means they respire more O_2.
6. So we need to increase oxygen supply by turning ON the water fountain

![graph relation b/w DO and temp](dissolvedOxygen_temperature.jpg)

```
Dissolved Oxygen = (70 / (77 - pH)) * (-0.16) * temp + 12.26 
```

reference : 
[https://www.fondriest.com/environmental-measurements/parameters/water-quality/dissolved-oxygen/]

[[[https://pdf.sciencedirectassets.com/271816/1-s2.0-S0964569120X00081/1-s2.0-S0964569120300892/main.pdf?X-Amz-Security-Token=IQoJb3JpZ2luX2VjEGoaCXVzLWVhc3QtMSJHMEUCIEd4LTdy0rsN1JeLsLtWGPOA5hqaEfBlX%2F9P1U2ErD3dAiEAuHwdVP95QezlsdGwiqCr4%2F6hK7pUj4txlVcMetwz0rsqvAUIo%2F%2F%2F%2F%2F%2F%2F%2F%2F%2F%2FARAFGgwwNTkwMDM1NDY4NjUiDP6ZWzB1YafvLuSPoSqQBTw7Qil3DTKkyksd%2F4TmOkkUVT%2FUWB6Y86qeIBOWj6eNN3t44wFTWQfiXcdfnBvdd6cf%2FVDAQIDVizN%2F6HVcSnLh97%2FsMSt0NQri4tNgMdlpiPKbssNKVZfGThowWROQMOz2efCRZfeBOLcxUe6VAxoEec7q%2BZx1DgP0ph%2FPNG3IQc4uEKqAEFYy3TJyy1AzMN09jGFcBnTVd68cfSj10XwCtOB%2B66Y11kU%2BwGoQSGmhYCm2rVNoOUR51uvzdfWOKNAOE7EJ6ZhNJGD9ikFvtGcJBIUJY%2BK3kBh1bPyReZ3mtBJGGrYvJlAd5axCkIR%2BLbW3N8K2EP83WNWwub0S%2Bk0QZ4aofcE4HOZDwn49mDh582Ia%2FpyGml8dZcOT156d3n02TiKJcAtGiYqbkmxVRz5HJK3gNfGaHKC%2BKdGQ8F7eYndFULRSvbXmYnd2UBQld3pHsmpo%2FulT4T4ZkRin2lDZwSakGxofahZdCK52fz4rcrmuLO9LGAmv95QrpyDwmf4qwZZebC76KoaoysyzWOdjBav3uD0TqT%2BFkOi%2FeYVGrwvERZGv5ZoTRGa%2Bw%2BAXmydyg3BecEJHvnQqiQqRSxz8Yk6iVFuSxS%2FDM1dNmiVRmxgLXID%2FCaNnw0plmGyheAOb9K4uhyp%2Fxpj2bsE5G5nWlJJPWkQqxTq7mZda5WxKRpv%2B3J2aD38GIPJ4ryRSYmFHuuu%2B9iDbzkGylSaBr0tQu21DcQrwrSavtnaTlPu6a%2FE%2F9LCK0FU49AcGkbaYKdDJ9Pnry1ZJyuTZVHwoY9lfS3o8v0rLBtnHDp%2FtzIsijfRxm7k5MV9LwHoMFbZ0p%2FOb9yAO6l97rq8EANhG1PbWrMuZOx7tVuM55gAUxQ09MPeEqKoGOrEBUGxgBQLe1qxp62MFoAq2NueNTqZ3xHfTNsdfaRpckAanFjOJrhkvgBdcfbzTWKW6fao8gjM%2FPmzeoYXhfzsMOLtMsR1oPosx3OSZrswOQ%2FVH5lTJNLVzAEmI%2Bi5VPcFijUuUsssxsMIMZXw169adw7Xtmx3DOGRW%2FQMaZyryBt6A1C3cpIwlXJKh52RCxe6r02ph%2FrSP5aPutZNNYW%2F9teqPXx7Ga9%2FhhDIgULFAIJ7b&X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Date=20231107T101957Z&X-Amz-SignedHeaders=host&X-Amz-Expires=300&X-Amz-Credential=ASIAQ3PHCVTY3MUHZKVI%2F20231107%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Signature=7d338a04418d9a96800f5a7dd1b2bea34d3f6bb32ee30f785a2fd44f50bc10ef&hash=5f27ce5f52d82c0a0b1761731262b1b642fdcc33a78ed07a4f5b879743b1aba6&host=68042c943591013ac2b2430a89b270f6af2c76d8dfd086a07176afe7c76c2c61&pii=S0964569120300892&tid=spdf-1d7f7278-f8a6-4d4a-a52f-53af3b5ecef2&sid=5a7e4caa51f4d84e6c8b3284187454310201gxrqb&type=client&tsoh=d3d3LnNjaWVuY2VkaXJlY3QuY29t&ua=13085e555c5b0656575551&rr=8224d7440db09a8a&cc=in]]]


## pH

1. pH is directly propoertional to the Fish count.
2. Suppose fish count is more, it means that fish releases more ammonia in water.
3. Thus basicity of the liquid increases veryu slightly.
4. Amongst the species of fish, breeding occurs only within a specific pH range.
5. aquatic survival range is 5.5 to 8.5

## turbidity 

## temperature

