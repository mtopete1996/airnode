// #### Author: Manuel E. Topete Ortega
// #### e-mail: manueltopt96@gmail.com

#ifndef TIMEST_H

#define TIMEST_H

#include <ds3231.h>

struct ts tsx;

String recordTimeStr(){
  DS3231_get(&tsx);

  String str = "";

  str += tsx.mday;
  str += "/";
  str += tsx.mon;
  str += "/";
  str += tsx.year;
  str += " ";
  str += tsx.hour;
  str += ":";
  str += tsx.min;
  str += ":";
  str += tsx.sec;

  return str;
}

#endif
