// #### Author: Manuel E. Topete Ortega
// #### e-mail: manueltopt96@gmail.com

#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include "Dust.h"
#include "Timest.h"
#include "FileManager.h"

void setup() {
  if (!SD.begin(D8)) {
    Serial.println("initialization failed!");
    return;
  }

  Wire.begin();
  sds.begin();
  DS3231_init(0);
  Serial.begin(9600);
}

void loop() {
  String str = "";
  
  str += recordTimeStr();
  str += ",";
  str += recordDustStr();
  writeFile(str);
  
  delay(1000);
}
