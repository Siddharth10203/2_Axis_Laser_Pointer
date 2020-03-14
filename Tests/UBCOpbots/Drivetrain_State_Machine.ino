
/* Title: UBC OPEN ROBOTICS - Drivetrain Finite State Machine
 * Author: Siddharth G., Siddharth C.
 * Date: February 28, 2019
 * 
 * Objective: To define a FSM for the operation of the V2 drivetrain of
 *          the robot. Through inputs of 0 to 8, the arduino shall move
 *          the motor as descibed in that particular state.
 */

// Define all possible states in this script
#define STOP 0
#define NORTH 1
#define EAST 2
#define SOUTH 3
#define WEST 4
#define NORTHEAST 5
#define NORTHWEST 6
#define SOUTHEAST 7
#define SOUTHWEST 8

// Define all internal variables req'd
String User_in = "";            // Empty string to be filled by user input from Serial monitor
int State;                      // Define the state of the drivetrain and store value here.


void setup() {
  // Initialize Motor Driver/Drivers

  // Initialze Serial Port
  Serial.begin(9600);
}

void loop() {
  // Obtain State parameter from Serial/Comm Line
  if (Serial.available()>0){
    User_in = Serial.readString();
    State = User_in.toInt();
  }
  // Report current state Serial Monitor/Master
  else (Serial.println(State));

  // Define State Machine Conditions
  switch (State){
    case  NORTH:
      break;

    case  EAST:
      break;

    case  SOUTH:
      break;

    case  WEST:
      break;
      
    case  NORTHEAST:
      break;

    case  NORTHWEST:
      break;
        
    case  SOUTHEAST:
      break;
      
    case  SOUTHWEST:
      break;
      
    default:
    // ROBOT MUST STOP HERE
    break;
  }

  delay(50);
}
