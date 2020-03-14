 #define green  8
 #define black 9
 #define red 10
 #define blue 11

 #define delaytime 9
 
void setup() {
  // initialize the serial port:
  Serial.begin(9600);
  pinMode(green,OUTPUT);
  pinMode(black,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(blue,OUTPUT);
}

void loop() {
  int steps=200;
  step_OFF();
  while(steps>0){
    forward();
    steps--;
  }
}

void step_OFF(){
  digitalWrite(green,LOW);
  digitalWrite(black,LOW);
  digitalWrite(red,LOW);
  digitalWrite(blue,LOW);
}

void Step_A(){
  digitalWrite(green,HIGH);
  digitalWrite(black,LOW);
  digitalWrite(red,HIGH);
  digitalWrite(blue,LOW);
}
void Step_B(){
  digitalWrite(green,LOW);
  digitalWrite(black,HIGH);
  digitalWrite(red,HIGH);
  digitalWrite(blue,LOW);
}
void Step_C(){
  digitalWrite(green,LOW);
  digitalWrite(black,HIGH);
  digitalWrite(red,LOW);
  digitalWrite(blue,HIGH);
}
void Step_D(){
  digitalWrite(green,HIGH);
  digitalWrite(black,LOW);
  digitalWrite(red,LOW);
  digitalWrite(blue,HIGH);
}

void forward(){
  Step_A();
  delay(delaytime);
  Step_B();
  delay(delaytime);
  Step_C();
  delay(delaytime);
  Step_D();
  delay(delaytime);
}

void backward(){
  Step_D();
  delay(delaytime);
  Step_C();
  delay(delaytime);
  Step_B();
  delay(delaytime);
  Step_A();
  delay(delaytime);
}

