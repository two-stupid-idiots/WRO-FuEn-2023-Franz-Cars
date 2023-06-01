#include "Ultraschallsensor.h"

Servo servo;

void Ultraschallsensor::initUltraschallsensor(void) {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  servo.attach(10);
  servo.write(90); //Ausrichtung des Servomotors
  Serial.println("Servo Position: 90°");
}

int Ultraschallsensor::getUltrasonic(int degree, bool print) {
  setServoPosition(degree, print);
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
  servo.write(degree);
  if (print)
    Serial.println("Servo Position: " + String(degree) + "°");
}
