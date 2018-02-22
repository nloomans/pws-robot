#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
boolean debug = false;
long count = 1;
String input;
int ofset1 = 1;

void setup() {
  pinMode(3, OUTPUT);
  digitalWrite(3, LOW);

  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);
  
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  while (!Serial) {
    ; // wait for serial port to connect. Needed foAr native USB port only
  }
  
  stopLine();
  for (int i = 0; i < 4; i++) {
    digitalWrite(5, HIGH);
    delay(100);
    digitalWrite(5, LOW);
    delay(100);
  }
  for (int i = 0; i < 4; i++) {
    digitalWrite(6, HIGH);
    delay(100);
    digitalWrite(6, LOW);
    delay(100);
  }
}


void loop() {
  if (Serial.available() > 0) {
    int inByte = Serial.read();
    digitalWrite(5, HIGH);
    delay(200);
    digitalWrite(5, LOW);
    switch (inByte) {
      case 65:
        startLine();
        break;
      case 78:
        dance();
        break;
      case 90:
        stopLine();
        break;
    }
  }
}

void startLine() {
  digitalWrite(6, HIGH);
  servo1.write(170 + ofset1);
  servo3.write(0);
}

void stopLine() {
  digitalWrite(6, LOW);
  servo1.write(90 + ofset1); // + 1 is ofset ofset
  servo2.write(90);
  servo3.write(90);
}

void dance() {
  digitalWrite(6, HIGH);
  servo1.write(170 + ofset1);
  servo2.write(170);
  servo3.write(170);
  delay(700);
  servo1.write(170 + ofset1);
  servo2.write(170);
  servo3.write(170);
}





