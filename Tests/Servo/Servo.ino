/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo1;  // create servo object to control a servo
Servo myservo2;
Servo myservo3;
// twelve servo objects can be created on most boards

int pos1 = 0;    // variable to store the servo position
int pos2 = 0;
int pos3 = 0;

int x=0;
int y=0;
int s=0;

void setup() {
  Serial.begin(9600);
  myservo1.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(10);
  myservo3.attach(11);
}

void loop() {
  x = analogRead(2);
  y = analogRead(1);
  s = analogRead(0);
  xmotor();
  ymotor();
  switch1();
}

void xmotor(){
  if (x>650 && pos1<180){
    pos1 += 1;
    myservo1.write(pos1);
  }

  else if(x<400 && pos1>0){
    pos1 -= 1;
    myservo1.write(pos1);
  }
}

void ymotor(){
  if (y>650 && pos2<180){
    pos2 += 1;
    myservo2.write(pos2);
  }

  else if(y<400 && pos2>0){
    pos2 -= 1;
    myservo2.write(pos2);
  }
}

void switch1(){
  if (s==0 && pos3 <90){
    pos3 = 180;
    delay(400);
  }

  else if(s==0 && pos3 >90){
    pos3 = 0;
    delay(400);
  }

  myservo3.write(pos3);
}

