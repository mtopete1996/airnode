// #### Author: Manuel E. Topete Ortega
// #### e-mail: manueltopt96@gmail.com

#ifndef FILE_MANAGER_H

#define FILE_MANAGER_H

// PIN CONNECTIONS
// CS   -> D8
// MOSI -> D7
// MISO -> D6
// SCK  -> D5

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
