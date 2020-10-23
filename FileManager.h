// #### Author: Manuel E. Topete Ortega
// #### e-mail: manueltopt96@gmail.com

#ifndef FILE_MANAGER_H

#define FILE_MANAGER_H

#include <SPI.h>
#include <SD.h>

class FileManager { 
  public:
    void writeFile(String line) {
      File myFile;
      myFile = SD.open("sensor_lectures.csv", FILE_WRITE);

      if (myFile) {
        Serial.println("Escribiendo en tarjeta: ");
        Serial.println(line);
        myFile.println(line);
      } else {
          Serial.println("ERROR AL ESCRIBIR EN MEMORIA");
      }
      
      myFile.close();
    }
};

#endif
