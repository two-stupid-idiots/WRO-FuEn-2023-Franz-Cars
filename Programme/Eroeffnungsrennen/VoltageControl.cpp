#include "VoltageControl.h"

void VoltageControl::initVoltageControl(void) {
  pinMode(powerConrol_PIN, INPUT);
}

float VoltageControl::getVoltage(void) {
  float voltage = (analogRead(powerConrol_PIN) *5) * ((10 + 1.5) / 1.5) / 1024;
  return voltage;
}