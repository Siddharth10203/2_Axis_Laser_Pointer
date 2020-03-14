int analogPin = 0;
float val = 0;
double voltage;
int lumens;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(analogPin);
  voltage = val*5/1023;
  Serial.println(voltage);
  delay(500);
}
