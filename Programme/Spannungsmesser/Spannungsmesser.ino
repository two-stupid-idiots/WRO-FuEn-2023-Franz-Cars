#define PIN A3

void initGIPO() {
  pinMode(PIN, INPUT);
}

void setup() {
  Serial.begin(9600);
  initGIPO();
  Serial.println("----Spannungsmessung----");
}

void loop() {
  float voltage = (analogRead(PIN) *5) * ((10 + 1.5) / 1.5) / 1024;
  Serial.println("Spannung: " + String(voltage) + "V");
  delay(2000);
}