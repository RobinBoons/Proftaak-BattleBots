#include <SPI.h>
#include <Servo.h>
#include "Timer.h"
#include "Rp6.h"

#define robotSpeed 40
#define ShankPin 7
#define HitboxPin 2
#define MotorPwm 5


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

Timer t;

void setup() {
  Serial.begin(9600);
  myservo.attach(MotorPwm);
  Rp6.begin();
  // hierdoor staat de shank eigenlijk constant onder stroom
  pinMode(ShankPin, OUTPUT);
  digitalWrite(ShankPin, HIGH);
  pinMode(HitboxPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(HitboxPin), RegisterHit, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("in loop");
  receiveMessage();
  
  //CheckForHit();
  //RobotController();
  t.update();
}

void RobotController() {
  if (robMovement == none) {
    Rp6.stop();
  }

  Rp6.moveAtSpeed(robotSpeed, robotSpeed);

 
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
  
}

void CommandParser(String command) {

 
 // Serial.println(command);
  
 if (command.equals("%FWD$")) {
   Rp6.moveAtSpeed(robotSpeed, robotSpeed);
   Rp6.changeDirection(RP6_FORWARD);
   // Serial.println("in if");
  
    //robMovement = forward;
    //robDirection = straight;
  }
 else if (command == "%BKW$") {
  Rp6.changeDirection(RP6_BACKWARD);
    //robMovement = backward;
    //robDirection = straight;
  }
  else{
   // Serial.println("hoi");
  }
  if (command == "%LFT$") {
    Rp6.changeDirection(RP6_LEFT);
  }
  else if (command == "%RGT$") {
    Rp6.changeDirection(RP6_RIGHT);
   // robDirection = right;
  }
  else{
   // Serial.println("hoi");
  }
  
  if (command == "%SHK$") {
    FireServo();
    t.after(1000, RetractServo);
    
  }
  else{
    
  }
  
  if (command  == "%STP$") {
    // robMovement = none;
    Rp6.stop();
  }
  else{
    
  }
 
}

void FireServo() {
  myservo.write(30);
}

void RetractServo() {
  myservo.write(320);
}

void RegisterHit(){
  Serial.println("%HIT$");
}

void receiveMessage() {
  receivedData = "";
  //Serial.println("in receive");
  if (Serial.available() > 0)
  {
    // read the incoming byte:
    byte incomingByte = Serial.read();
   // Serial.println(incomingByte);

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
     // Serial.println(receivedData);
      CommandParser(receivedData);
    }
  }
}
