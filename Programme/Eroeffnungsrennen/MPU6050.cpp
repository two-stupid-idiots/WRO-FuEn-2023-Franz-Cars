#include "MPU6050.h"

void MPU6050::initI2C(void) {
  Wire.end(); //Beendet offene I2C Busses
  Wire.begin(); //Meldung als Host
}

void MPU6050::startMPU(bool print) {
  Wire.beginTransmission(MPU_address);
  Wire.write(0x6B);
  Wire.write(0);
  int error = Wire.endTransmission(true);
  if (print)
    printI2CError(error);
}

void MPU6050::printI2CError(int error) {
  switch (error) {
    case 0:
      Serial.println("MPU6050: 0 => success");
      break;
    case 1:
      Serial.println("MPU6050: 1 => data too long to fit in transmit buffer");
      break;
    case 2:
      Serial.println("MPU6050: 2 => received NACK on transmit of address");
      break;
    case 3:
      Serial.println("MPU6050: 3 => received NACK on transmit of data");
      break;
    case 4:
      Serial.println("MPU6050: 4 => other error");
      break;
    case 5:
      Serial.println("MPU6050: 5 => timeout");
      break;
    default:
      Serial.println("MPU6050: ? => unkown responce");
      break;
  }
}