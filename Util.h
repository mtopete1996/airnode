// #### Author: Manuel E. Topete Ortega
// #### e-mail: manueltopt96@gmail.com

#ifndef UTILS_H

#define UTILS_H

class Util {
  public:
    void printSeparator() {
      Serial.println("##############");
    }

    void printData(String title, float val) {
      Serial.print(title);
      Serial.println(val);
    }

};

#endif
