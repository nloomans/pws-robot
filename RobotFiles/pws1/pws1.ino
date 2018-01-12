#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
boolean debug = true;
long count = 1;
long startLine = 1;
long stopLine = 1;
long dance = 1;
void setup() {
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);
  Serial.begin(115200); // opens serial port, sets data rate to 9600 bps
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop() {
  if(Serial.available()){
    String input;
    input = Serial.readString();
    input.trim();
    if (debug) {
      count += 1;
      Serial.print(count);
      Serial.print(" ");
      Serial.println(serialInput);
    }

    if (input == "startLine") {
      if(debug){
        Serial.println("startLine Running");
      }
      startLine += 1;
      digitalWrite(13, HIGH);
      servo1.write(170);
      servo2.write(170);
      servo3.write(170);
    }
    if (input == "stopLine") {
      if(debug){
        Serial.println("stopLine Running");
      }
      stopLine += 1;
      digitalWrite(13, HIGH);
      servo1.write(0);
      servo2.write(0);
      servo3.write(0);
    }
    if (input == "dance") {
      if(debug){
        Serial.println("dance working");
      }
      dance += 1;
      digitalWrite(13, HIGH);
      servo1.write(170);
      servo2.write(170);
      servo3.write(170);
    }
  }
delay(10);
}

//100 loops = 1 second

