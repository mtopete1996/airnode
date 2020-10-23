// #### Author: Manuel E. Topete Ortega
// #### e-mail: manueltopt96@gmail.com

#ifndef TIMEST_H

#define TIMEST_H

#include <ds3231.h>

class Timest { 
  
  struct ts t;
  
  public:
    void setRtcTime() {
      this->t.hour=19; 
      this->t.min=02;
      this->t.sec=0;
      this->t.mday=22;
      this->t.mon=10;
      this->t.year=2020;
    
      DS3231_set(t); 
    }

    void updateRtcTime() {
      struct ts tstx;
      DS3231_get(&tstx);

      this->t = tstx;
    }

    String printTimestamp() {
      updateRtcTime();
      
      Serial.print("Date : ");
      Serial.print(this->t.mday);
      Serial.print("/");    
      Serial.print(this->t.mon);
      Serial.print("/");
      Serial.print(this->t.year);
      Serial.print("\t Hour : ");
      Serial.print(this->t.hour);
      Serial.print(":");
      Serial.print(this->t.min);
      Serial.print(".");
      Serial.println(this->t.sec); 
    }
    
    int getHour() {
      return this->t.hour;
    }
    
    int getMinute() {
      return this->t.min;
    }
    
    int getSecond() {
      return this->t.sec;
    }
    
    int getMday() {
      return this->t.mday;
    }
    
    int getMonth() {
      return this->t.mon;
    }
    
    int getYear() {
      return this->t.year;
    }
};

#endif
