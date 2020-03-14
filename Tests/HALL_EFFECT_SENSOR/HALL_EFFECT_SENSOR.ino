int analog0 = 0;
void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(analog0));
  delay(100);
}
