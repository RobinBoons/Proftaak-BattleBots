// #include <Wire.h>
//#include "Rp6.h"
#define KEY_INPUT 6
#define FWD_JOY_Y A0
#define SPD_JOY_X A1
#define SPD_JOY_Y A2
#define SPD_JOY_B A3

/*
   square joystick deadzones: x ~530, y ~540
   round joystrick deadzones: x -505, y -516

   button deadzone = ~500 nominal, 0 when pressed, or <5 at least.

   FWD_JOY is exclusively for making the robot go forwards and backwards (Y-Axis)
   SPD_JOY is for going right or left (X-axis) and for increasing or decreasing the speed (Y-axis)

*/

/*
   Theoretically this works fine with the RP6. To control it via the computer, all you need is:
 * * add serial
 * * instead of the Rp6. commands in RobotController(), print these commands (or your own protocol)
     into the serial, then

*/

enum robotMovement {
  forward,
  backward,
  none
};

enum robotDirection {
  left,
  right,
  straight
};

robotMovement robMovement = none;
robotDirection robDirection = straight;
int robotSpeed = 0;
int shankStatus = 0;
void setup() {
  Serial.begin(9600);
  //Rp6.begin();
  //digitalWrite(SHANK_BTN, HIGH);

  //Serial.write("setup");

  /* emergency stop maybe?
    pinMode(KEY_INPUT, INPUT);
    digitalWrite(KEY_INPUT, HIGH);
  */
}

void loop() {
  //Serial.write("loop");
  CheckForwardBackward();
  CheckLeftRight();
  CheckButton();
//  CheckSpeed();
  RobotController();
  delay(50);
}

/*
   These functions read the appropriate analog port and then changes the enums and speed.
   Speed is constrained because speed is a byte in the RP6 code.

   Still need to account for turning, though I'm not sure whether to do that here or in th RP6 code.
   Kind of want to keep that one a dummy slave.

*/

void CheckForwardBackward() {
  int joyValue = analogRead(FWD_JOY_Y);

  if (joyValue > 600) {
    robMovement = forward;
  }
  else if (joyValue < 400) {
    robMovement = backward;
  }
  else {
    robMovement = none;
  }

}
// RobotDirection* robDirection
// functie-pointers?
void CheckLeftRight() {
  int joyValue = analogRead(SPD_JOY_X);

  if (joyValue > 600) {
    robDirection = right;
  }
  else if ( joyValue < 400) {
    robDirection = left;
  }
  else {
    robDirection = straight;
  }

}
/*
void CheckSpeed() {
  int joyValue = analogRead(SPD_JOY_Y);

  if (joyValue > 600) {
    robotSpeed += 10;

    if (robotSpeed > 254) {
      robotSpeed = 254;
    }
  }
  else if (joyValue < 490) {
    robotSpeed -= 10;

    if (robotSpeed < 0) {
      robotSpeed = 0;
    }
  }
  ;
}

/*
   This function collects all the data and passes it on to the RP6.
   Problem as it is now is that you can't change direction and move at the same time.
*/

void RobotController() {

  //Rp6.moveAtSpeed(robotSpeed, robotSpeed);
  //Serial.write("hoi");
  
  if (robMovement == forward) {
    Serial.write("%FWD$\n");

  }
  else if (robMovement == backward) {
    Serial.write("%BKW$\n");
  }

  if (robDirection == straight) {
    // Rp6.changeDirection(RP6_FORWARD);
  }
  else if (robDirection == left) {
    Serial.write("%RGT$\n");
  }
  else if (robDirection == right) {
    Serial.write("%LFT$\n");
  }

  if (robMovement == none && robDirection == straight) {
    Serial.write("%STP$\n");
  }

  if(shankStatus == 1){
    Serial.write("%SHK$\n");
    shankStatus = 0;
  }

}

void CheckButton(){
  int buttonValue = analogRead(SPD_JOY_B);
  if(shankStatus == 0 && buttonValue < 5){
    shankStatus = 1;
  }
}



