// #### Author: Manuel E. Topete Ortega
// #### e-mail: manueltopt96@gmail.com

#ifndef DUST_H

#define DUST_H

#include "SdsDustSensor.h";

// PIN CONNECTIONS
// TX -> D3
// RX -> D4

int rxPin = D3; 
int txPin = D4;
SdsDustSensor sds(rxPin, txPin);

String recordDustStr() {
  PmResult pm = sds.readPm();
  String res = "ERROR ON DUST READING";
  
  if (pm.isOk()) {
    res = String(pm.pm25) + ", "+ String(pm.pm10);
  }
  
  return res;
}


#endif
