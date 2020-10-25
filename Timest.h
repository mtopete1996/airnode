// #### Author: Manuel E. Topete Ortega
// #### e-mail: manueltopt96@gmail.com

#ifndef TIMEST_H

#define TIMEST_H

#include <ds3231.h>

class Timest { 
  
  int hr, mint, sec, mday, mon, yr;
  
  public:
    void setRtcTime() {
      struct ts t;

      t.hour=19; 
      t.min=02;
      t.sec=0;
      t.mday=22;
      t.mon=10;
      t.year=2020;
    
      DS3231_set(t); 
    }

    void printTimestamp() {
      struct ts tstx;
      DS3231_get(&tstx);

      Serial.print("Date : ");
      Serial.print(tstx.mday);
      Serial.print("/");
      Serial.print(tstx.mon);
      Serial.print("/");
      Serial.print(tstx.year);
      Serial.print(" ");
      Serial.print(tstx.hour);
      Serial.print(":");
      Serial.print(tstx.min);
      Serial.print(":");
      Serial.println(tstx.sec);
    }

    String printableLine() {
      struct ts tstx;
      DS3231_get(&tstx);

      String str = "";

      str += tstx.mday;
      str += "/";
      str += tstx.mon;
      str += "/";
      str += tstx.year;
      str += " ";
      str += tstx.hour;
      str += ":";
      str += tstx.min;
      str += ":";
      str += tstx.sec;

      return str;
    }
};

#endif
