String incomingMessage;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  receiveMessage();
}

void receiveMessage() {
  String incomingMessage = "";
  if (Serial.available() > 0)
  {
    // read the incoming byte:
    byte incomingByte = Serial.read();

    // incoming
    char receivedCharacter = (char) incomingByte;
    if (receivedCharacter == '%') {
      incomingMessage += receivedCharacter;
      delay(10);

      do {
        receivedCharacter = (char) Serial.read();
        incomingMessage += receivedCharacter;
        delay(10);
      }
      while (receivedCharacter != '$');
      Serial.println(incomingMessage);
    }
  }
}
