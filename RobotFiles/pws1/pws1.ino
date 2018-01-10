#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
String serialInput;
boolean debug = true;
int count = 1;

void setup() {
  servo1.attach(9);
  servo2.attach(10);
  servo2.attach(11);
  Serial.begin(115200); // opens serial port, sets data rate to 9600 bps
  pinMode(13, OUTPUT);
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);

}

void loop() {

  while (Serial.available()) {
    serialInput = Serial.readString();

  }
  if(debug){ 
    count += 1;
    Serial.print(count);
    Serial.println(serialInput);

  }

  if(serialInput == "stopLine"){
    digitalWrite(13, LOW);
        servo1.write(170);
  servo2.write(170);
  servo3.write(170);
  }

}








