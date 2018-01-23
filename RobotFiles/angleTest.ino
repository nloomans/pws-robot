
#include <Servo.h>
#include <math.h>
Servo servo1;
Servo servo2;
Servo servo3;

void setup() {
  Serial.begin(115200); 

}

void loop() {
  if (Serial.available()) {
    String input;
    input = Serial.readString();
    input.trim();
    servo1.write(cos(150- input.toInt()));
    servo2.write(cos(30- input.toInt()));
    servo3.write(cos(270- input.toInt()));

    delay(20);
  }
}
