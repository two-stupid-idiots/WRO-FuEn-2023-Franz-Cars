#include "Ultraschallsensor.h"

Servo servoUltraschall;

void Ultraschallsensor::initUltraschallsensor(void) {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  /*servoUltraschall.attach(ServoUltraschall_PIN);
  int degree = 90;
  servoUltraschall.write(degree); //Ausrichtung des Servomotors
  Serial.println("Servo Ultraschall Position: " +String(degree) + "°");*/
}

int Ultraschallsensor::getUltrasonic(int degree, bool print) {
  //setServoPosition(degree, print);
  int i = 0;
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  i = ((int)pulseIn(ECHO_PIN, HIGH) / 58);
  if (print)
    Serial.println("Entfernung: " + String(i) + "cm");
  return i;
}

void Ultraschallsensor::setServoPosition(int degree, bool print) {
  servoUltraschall.write(degree);
  if (print)
    Serial.println("Servo Position: " + String(degree) + "°");
}
