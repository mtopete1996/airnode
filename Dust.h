// #### Author: Manuel E. Topete Ortega
// #### e-mail: manueltopt96@gmail.com

#ifndef DUST_H

#define DUST_H

#include "Util.h";
#include "SdsDustSensor.h";

class Dust { 
  float pm25, pm10;
  Util util;
  SdsDustSensor sds;
  
  public:
    static int rxPin;
    static int txPin;
    
    Dust() : sds(this->rxPin, this->txPin) {
      this->sds = sds;
    }
    
    void readValues() {
      PmResult pm = this->sds.readPm();
      if (pm.isOk()) {
        this->pm25 = pm.pm25;
        this->pm10 = pm.pm10;
      }
    }

    void printValues() {
      readValues();
     
      util.printSeparator();
      util.printData("pm10: ", pm10);
      util.printData("pm25: ", pm25);
      Serial.println();
    }

    String recordString() {
      readValues();
      return String(this->pm25) + ", "+ String(this->pm10);
    }

    float getPm10() {
      return this->pm10;
    }
    
    float getPm25() {
      return this->pm25;
    }
};

int Dust::rxPin = D3;
int Dust::txPin = D4;

#endif
