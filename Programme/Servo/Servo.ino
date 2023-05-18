#include <Servo.h>
#define Servo_Pin 10

Servo servo;

void setup() {
  Serial.begin(9600);
  Serial.println("----Servo----");
  servo.attach(Servo_Pin);
  servo.write(90);
  Serial.println("Position: 90");
  delay(5000);
}

void loop() {
  for (int i = 0; i <= 180; i += 10) {
    servo.write(i);
    Serial.print("Position: ");
    Serial.print(i);
    Serial.println();
    delay(1000);
  }
  for (int i = 180; i >= 0; i -= 10) {
    servo.write(i);
    Serial.print("Position: ");
    Serial.print(i);
    Serial.println();
    delay(1000);
  }
}
