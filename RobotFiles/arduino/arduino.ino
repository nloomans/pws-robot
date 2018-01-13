#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
boolean debug = true;
long count = 1;
String input;
int ofset1 = 1;
void setup() {
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);
  Serial.begin(115200); // opens serial port, sets data rate to 9600 bps
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  stopLine();
}


void loop() {
  if (Serial.available()) {
    String input;
    input = Serial.readString();
    input.trim();

    while (input == "startLine") {
      startLine();
      if (Serial.available()) {
        input = Serial.readString();
        input.trim();
      }

      if (debug) {
        Serial.print("startLine ");
      }
    }

    while (input == "stopLine") {
      stopLine();
      if (Serial.available()) {
        input = Serial.readString();
        input.trim();
      }

      if (debug) {
        Serial.print("stopLine ");
      }
    }

    while (input == "dance") {
      dance();
      if (Serial.available()) {
        input = Serial.readString();
        input.trim();
      }

      if (debug) {
        Serial.print("dance ");
      }
    }

  }
  if (debug) {
    count += 1;
    Serial.print(count);
    Serial.print(" ");
    Serial.println(input);
  }
}



void startLine() {
  digitalWrite(13, HIGH);
  servo1.write(170 + ofset1);
  servo2.write(170);
}

void stopLine() {
  digitalWrite(13, LOW);
  servo1.write(90 + ofset1); // + 1 is ofset ofset
  servo2.write(90);
  servo3.write(90);
}

void dance() {
  digitalWrite(13, HIGH);
  servo1.write(170 + ofset1);
  servo2.write(170);
  servo3.write(170);
  delay(700);
  servo1.write(170 + ofset1);
  servo2.write(170);
  servo3.write(170);

}





