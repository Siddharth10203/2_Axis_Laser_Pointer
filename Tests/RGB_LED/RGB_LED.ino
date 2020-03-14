//RGB LED pins
int led[] = {10, 11, 9}; //the three digital pins of the digital LED 
                                   //10 = redPin, 11 = greenPin, 9 = bluePin
int R=60;
int G=0;
int B=0;

void setup(){
  for(int i = 0; i < 3; i++){
   pinMode(led[i], OUTPUT);   //Set the three LED pins as outputs
  }
}

void loop(){
   digitalWrite(led[0],R);
   digitalWrite(led[1],G);
   digitalWrite(led[2],B);
}
/*
void randomColor(){
  int rand = random(0, sizeof(COLORS) / 2);  //get a random number within the range of colors
  setColor(ledDigitalOne, COLORS[rand]);  //Set the color of led one to a random color
  delay(1000);
}
void setColor(int* led, boolean* color){
 for(int i = 0; i < 3; i++){
   digitalWrite(led[i], color[i]);
 }
}

void setColor(int* led, const boolean* color){
  boolean tempColor[] = {color[0], color[1], color[2]};
  setColor(led, tempColor);
}*/
