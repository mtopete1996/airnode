// #### Author: Manuel E. Topete Ortega
// #### e-mail: manueltopt96@gmail.com

#ifndef FILE_MANAGER_H

#define FILE_MANAGER_H

// PIN CONNECTIONS
// SCK  -> D5
// MISO -> D6
// MOSI -> D7
// CS   -> D8

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

#endif
