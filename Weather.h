// #### Author: Manuel E. Topete Ortega
// #### e-mail: manueltopt96@gmail.com

#ifndef WEATHER_H

#define WEATHER_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include "Util.h";

#define SEALEVELPRESSURE_HPA (1013.25)

class Weather {
  float temperature, humidity, pressure, altitude;
  Adafruit_BME280 bme;
  Util util;

  public:
    Weather() {
      bme.begin(0x76);
      readValues();
    }

    void readValues() {
      this->temperature = bme.readTemperature();
      this->humidity = bme.readHumidity();
      this->pressure = bme.readPressure() / 100.0F;
      this->altitude = bme.readAltitude(SEALEVELPRESSURE_HPA);
    }

    void printValues() {
      readValues();

      util.printSeparator();
      util.printData("temp: ", temperature);
      util.printData("hum: ", humidity);
      util.printData("press: ", pressure);
      util.printData("alt: ", altitude);
      Serial.println();
    }

    String recordString() {
      readValues();
      return String(this->temperature) + ", "+ String(this->humidity) + ", "+ String(this->pressure) + ", "+ String(this->altitude);
    }

    // Getters
    float getTemperature() {
      return this->temperature;
    }

    float getHumidity() {
      return this->humidity;
    }

    float getPressure() {
      return this->pressure;
    }

    float getAltitude() {
      return this->altitude;
    }
};

#endif
