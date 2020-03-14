//The below is code for an IR sensor.

void setup() {
  Serial.begin(9600);
  pinMode(7,INPUT);
  pinMode(A0,INPUT);
  Serial.print("Sensor REAding:  ");
}

void loop() {
  Serial.println(analogRead(A0));
  delay(200);
}
