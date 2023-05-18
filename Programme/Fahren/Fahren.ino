#include "Fahren.h"

#define standBy 3

#define PWMR 5
#define RMR 7

#define PWML 6
#define RML 8

void initGIPO() {
  pinMode(standBy, OUTPUT);

  pinMode(PWMR, OUTPUT);
  pinMode(RMR, OUTPUT);

  pinMode(PWML, OUTPUT);
  pinMode(RML, OUTPUT);
}

void runMotor(enum motorSide side, enum rotation direction, int speed) {
  digitalWrite(standBy, HIGH);

  boolean dir;
  switch (direction) {
    case forward:
      dir = HIGH;
      break;
    case backward:
      dir = LOW;
      break;
    default:
      stop();
      break;
  }

  switch (side) {
    case right:
      digitalWrite(RMR, dir);
      analogWrite(PWMR, speed);
      break;
    case left:
      digitalWrite(RML, dir);
      analogWrite(PWML, speed);
      break;
    case both:
      digitalWrite(RMR, dir);
      analogWrite(PWMR, speed);
      digitalWrite(RML, dir);
      analogWrite(PWML, speed);
      break;
    default:
      stop();
      break;
  }
}

void go_forward(int speed) {
  runMotor(both, forward, speed);
}

void go_backward(int speed) {
  runMotor(both, backward, speed);
}

void stop() {
  digitalWrite(standBy, LOW);
}

void setup() {
  initGIPO();
}

void loop() {
  go_forward(100);
  delay(2000);
  go_backward(100);
  delay(2000);
}