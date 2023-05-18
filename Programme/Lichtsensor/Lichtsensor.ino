#define PIN_Links A2
#define PIN_Mitte A1
#define PIN_Rechts A0

void initGIPO() {
  pinMode(PIN_Links, INPUT);
  pinMode(PIN_Mitte, INPUT);
  pinMode(PIN_Rechts, INPUT);
}

void setup() {
  Serial.begin(9600);
  initGIPO();
  Serial.println("----Lichtsensor----");
}

void loop() {
  Serial.print("Links: " + String(analogRead(PIN_Links)) + " | ");
  Serial.print("Mitte: " + String(analogRead(PIN_Mitte)) + " | ");
  Serial.println("Rechts: " + String(analogRead(PIN_Rechts)));
  delay(2000);
}
