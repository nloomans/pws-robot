#include <Servo.h>
Servo ser;
String input = "0";
void setup() {
  Serial.begin(115200);
  ser.attach(9);
  ser.write(0);
}

void loop() {

  if (Serial.available()) {

    input = Serial.readString();
    input.trim();
    input.toInt();
    
  }
  ser.write(input.toInt());
  Serial.print(ser.read());
  Serial.print(" ");
  Serial.println(input);
  delay(200);
}

