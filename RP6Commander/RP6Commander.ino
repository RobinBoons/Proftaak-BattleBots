#include <SPI.h>
#include <Servo.h>
//#include "Timer.h"
#include "Rp6.h"

#define robotSpeed 40
#define ShankPin 3
#define HitboxPin 4


String receivedData = "";
String incomingMessage = "";
Servo myservo;

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

void setup() {
  Serial.begin(9600);
  myservo.attach(5);
  Rp6.begin();
  // hierdoor staat de shank eigenlijk constant onder stroom
  pinMode(ShankPin, OUTPUT);
  digitalWrite(ShankPin, HIGH);
  pinMode(HitboxPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  receiveMessage();
  //CheckForHit();
  RobotController();
}

void RobotController() {
  if (robMovement == none) {
    Rp6.stop();
  }

  Rp6.moveAtSpeed(robotSpeed, robotSpeed);

/* 
  if (robMovement == forward) {
    Rp6.changeDirection(RP6_FORWARD);
  }
  else if (robMovement == backward) {
    Rp6.changeDirection(RP6_BACKWARD);
  }

  if (robDirection == straight) {
    Rp6.changeDirection(RP6_FORWARD);
  }
  else if (robDirection == left) {
    Rp6.changeDirection(RP6_LEFT);
  }
  else if (robDirection == right) {
    Rp6.changeDirection(RP6_RIGHT);
  }
  */
}

void CommandParser(String command) {

  Rp6.moveAtSpeed(robotSpeed, robotSpeed);
  //Serial.println(robotSpeed);
  if (command == "%FWD$"){
    Rp6.changeDirection(RP6_FORWARD);
    //Serial.println("ComaandParser");
    //Serial.println(command);
  }
 /* if (command == "%FWD$") {
    robMovement = forward;
    robDirection = straight;
  }
  if (command == "%BKW$") {
    robMovement = backward;
    robDirection = straight;
  }
  if (command == "%LFT$") {
    robDirection = left;
  }
  if (command == "%RGT$") {
    robDirection = right;
  }
  
  if (command == "%SHK$") {
    // dit is niet netjes
    FireServo();
    delay(10);
    RetractServo();
  }
  
  if (command  == "%STP$") {
    robMovement = none;
    //RobotSpeed = 0;
  }
  */
}
/*
void FireServo() {
  myservo.write(30);
  // hier timer
}

void RetractServo() {
  myservo.write(320);
  // hier end timer
}

void CheckForHit() {
  if (digitalRead(HitboxPin) == HIGH) {
    //xbee send hit
  }
}
*/
void receiveMessage() {
  receivedData = "";
  if (Serial.available() > 0)
  {
    // read the incoming byte:
    byte incomingByte = Serial.read();
    //Serial.println(incomingByte);

    // incoming
    char receivedCharacter = (char) incomingByte;
    if (receivedCharacter == '%') {
      receivedData += receivedCharacter;
      delay(10);

      do {
        receivedCharacter = (char) Serial.read();
        receivedData += receivedCharacter;
        //Serial.println(receivedData);
        delay(10);
      }
      while (receivedCharacter != '$');
      //Serial.println(receivedData);
      CommandParser(receivedData);
    }
  }
}

