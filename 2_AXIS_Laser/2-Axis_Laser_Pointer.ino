/*  
 *   2-AXIS LAZER POINTER
 * 
 *   Objective: To setup a joystick controlled setup with an Arduino for the Servo
 *        controlled lazer pointer.
 */

//  Include the Servo Library
#include <Servo.h>

//  Create the servo motor pins & 
int Panservo = 5;
int Tiltservo = 6;
Servo Pservo; Servo Tservo;

//  The joystick x, y and z axis.
int Upper_Thresh = 600;     // For x & y
int Lower_Thresh = 424;     // For x & y
int Pan_init = 150; int Tilt_init = 150;
int xaxis = 0; int yaxis = 1;
float x, y;
int zaxis = 3;

//  The laser output pin
int lazerpin = 4;
bool lazer_state = false;

//  Lazer pointer travel parameters
int LazerDelay = 195;
int minLazerDelay = 5;
double LDF = 1;           // Lazer Delay Factor

void setup() {
  Serial.begin(9600);

  //  Attach servos to Arduino
  Pservo.attach(Panservo);
  Tservo.attach(Tiltservo);

  //  Lazer pin is an output
  pinMode(lazerpin, OUTPUT);
  digitalWrite(lazerpin, HIGH);

  Serial.println("  x           y");
}

void loop() {
  //  Joystick pin definitions
  x = analogRead(xaxis);
  y = analogRead(yaxis);
  
  // Toggle Lazer State:
//  if(digitalRead(zaxis) == LOW) {
//    lazer_state = !lazer_state;
//    digitalWrite(lazerpin, lazer_state);
//  }

  // Pan axis of the system:
  if (x > Upper_Thresh){
    LDF = velocity_factor(true, x);
    Pan_init = counter(false,Pan_init,LDF);
  }
  else if (x < Lower_Thresh){
    LDF = velocity_factor(false, x);
    Pan_init = counter(true,Pan_init,LDF);
  }

  // Tilt axis of the system:
  if (y > Upper_Thresh){
    LDF = velocity_factor(true, y);
    Tilt_init = counter(false,Tilt_init,LDF);
  }
  else if (y < Lower_Thresh){
    LDF = velocity_factor(false, y);
    Tilt_init = counter(true,Tilt_init,LDF);
  }
  
  Pservo.write(Pan_init);
  Tservo.write(Tilt_init);
}

/*
 * Function: Essentially an adder and subtractor for the pan and tilt
 *      angles.
 *      operation = true; means move forward
 *      operation = false; means move reverse
 */
int counter(bool operation,int var, double f){
  if (operation){
    if (var < 180){
      var = var +1;
    }
  }
  else{
    if (var > 0){
      var = var -1;
    }
  }
  delay(LazerDelay*f + minLazerDelay);
  return var;
}

/*
 * Function: Returns the fraction to multiply the velocity by to reduce the speed
 *      of the lazer pointer's travel.
 *      operation = true; above upper thresh
 *      operation = false; below lower thresh
 */
double velocity_factor(bool operation,float vel){
  double vel_f;
  if (operation){
    vel_f = (vel - Upper_Thresh)/(1023 - Upper_Thresh);
  }
  else{
    vel_f = (Lower_Thresh - vel)/(Lower_Thresh);
  }
  vel_f = 1 - vel_f;
  return vel_f;
}

