// #### Author: Manuel E. Topete Ortega
// #### e-mail: manueltopt96@gmail.com

#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include "Dust.h"
#include "Timest.h"
#include "Mq.h"
#include "FileManager.h"

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing");
  
  if (!SD.begin(D8)) {
    Serial.println("SD initialization failed!");
    return;
  }

  Wire.begin();
  sds.begin();
  DS3231_init(0);

  writeFile("Timestamp, PM25, PM10, CO");
}

void loop() {
  String str = "";
  
  str += recordTimeStr();
  str += ",";
  str += recordDustStr();
  str += ",";
  str += recordMq();
  writeFile(str);
  
  delay(1000);
}
