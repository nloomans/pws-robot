#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
boolean debug = false;
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
  pinMode(12, OUTPUT);
  stopLine();
  Serial.println("start");

  for (int i = 0; i < 4; i++) {
    digitalWrite(12, HIGH);
    delay(100);
    digitalWrite(12, LOW);
    delay(100);
  }

  digitalWrite(12, LOW);
}


void loop() {
  if (Serial.available()) {
    String input;
    input = Serial.readString();
    input.trim();

    while (input == "startLine") {
      digitalWrite(12, LOW);
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
      digitalWrite(12, LOW);
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
      digitalWrite(12, LOW);
      dance();
      if (Serial.available()) {
        input = Serial.readString();
        input.trim();
      }

      if (debug) {
        Serial.print("dance ");
      }
    }
    if (input != "startLine" || input != "stopLine" || input != "dance") {
      digitalWrite(12, HIGH);
      stopLine();
    }


  }
  if (input != "startLine" || input != "stopLine" || input != "dance") {
    digitalWrite(12, HIGH);
    stopLine();
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
  servo3.write(0);
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





