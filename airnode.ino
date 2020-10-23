// #### Author: Manuel E. Topete Ortega
// #### e-mail: manueltopt96@gmail.com

#include "AirNode.h"
#include "Timest.h"

Timest tst;
//AirNode air;

void setup() {
//  if (!SD.begin(D8)) {
//    Serial.println("initialization failed!");
//    return;
//  }
//  
//  Serial.println("initialization done.");
  Wire.begin();
  Serial.begin(9600);

//  air.fm.writeFile("temperature, humidity, pressure, altitude");
}

void loop() {
//  air.writeWeatherOnSd();
//  air.printDustData();
//  air.printTimes();
  tst.printTimestamp();
  delay(1000);
}
