/*  Company/Affiliation: UBC Open Robotics
 *  Title: Firgelli_Linear_Servo Training Code
 *  Author: Siddharth Ganapathy
 *  Date: November 30th, 2017
 * 
 *  Objective: Following takes User Input from the Serial Monitor in the form
 *              of extension length for the Linear Firgelli Servo. It realizes
 *              the extension by linearly converting the distance to the angle
 *              required by the servo to move the shaft to that position.
 */

#include<Servo.h>

// Linearly calibrate for distance in terms of angle:

byte Max_Dist = 136;            // Fully extended position of the actuator
byte Max_angle = 140;           // Corresponding angle to above
byte Min_Dist = 4;              // Fully retracted position of the actuator
byte Min_angle = 36;            // Corresponding angle to above
double angle_per_dist = 1.0;    // Converts the desired angule to a linear distance
//double Ext_prcnt = 0;           // The extension of the linear servo as a percentage


int Angle;                      // Angle of servo motor
int Position;                   // A value from 4-136 mm
int wait_time = 1000;           // Defines the wait time from start of actuation
String User_in = "";            // Empty string to be filled by user input from Serial monitor

Servo linear_servo_1;           // Initiate a single servo for this particular example.

void setup() {
  // Define Pin placement for Servos
  linear_servo_1.attach(9);

  // Initiate Serial comms
  Serial.begin(9600);
  Serial.println(" Please insert the absolute extension position between 4 to 136 mm :");
}

void loop() {
  if (Serial.available()>0){
    
    // Obtain user input from serial monitor, this is the extension of the actuator from
    //    4 to 136mm
    User_in = Serial.readString();
    Position = User_in.toInt();
    Angle = angle_per_dist*(Position-Min_Dist) + Min_angle;
    //Ext_prcnt = (Position - Min_Dist)*100/(Max_Dist-Min_Dist);

    // Prints the received position & angle req'd to realize action w/ servo onto screen
    Serial.print(Position);
    Serial.print("      ");
    //Serial.print(Ext_prcnt);
    //Serial.print("%     ");
    Serial.println(Angle);
  }

  // The angle is what truly drives the servo to it's end position, the angle defines the
  //    final extension position as well.
  linear_servo_1.write(Angle);

  // Clear User input string
  User_in = "";

  // Wait time until taking next command
  delay(wait_time);
}
