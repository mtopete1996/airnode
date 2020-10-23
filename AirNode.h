// #### Author: Manuel E. Topete Ortega
// #### e-mail: manueltopt96@gmail.com

#ifndef AIRNODE_H

#define AIRNODE_H

#include "Weather.h";
#include "Dust.h";
#include "FileManager.h";
#include "Timest.h"

class AirNode
{
  public:
    Weather weather;
    Dust dust;
    FileManager fm;
    Timest timest;
    
    void writeWeatherOnSd() {
        fm.writeFile(weather.recordString());
    }
    
    void printBmeData() {
      weather.printValues();
    }

    void printDustData(){
      dust.printValues();
    }

    void printTimes() {
      timest.printTimestamp();
    }
};

#endif
