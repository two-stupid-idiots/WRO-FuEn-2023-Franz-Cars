#include "IRSensor.h"

void IRSensor::initIR(void) {
  //IRPins
  pinMode(IR_Links, INPUT);
  pinMode(IR_Mitte, INPUT);
  pinMode(IR_Rechts, INPUT);
}

float IRSensor::getLeftInfrared(bool print) {
  float IR = analogRead(IR_Links);
  if (print)
    Serial.println("IR Links: " + String(IR));
  return IR;
}

float IRSensor::getMiddleInfrared(bool print) {
  float IR = analogRead(IR_Mitte);
  if (print)
    Serial.println("IR Mitte: " + String(IR));
  return IR;
}

float IRSensor::getRightInfrared(bool print) {
  float IR = analogRead(IR_Rechts);
  if (print)
    Serial.println("IR Rechts: " + String(IR));
  return IR;
}
