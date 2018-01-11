#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
String serialInput;
boolean debug = true;
int count = 1;
String startLine = "startLine";

void setup() {
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);
  Serial.begin(115200); // opens serial port, sets data rate to 9600 bps
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop() {

  while (Serial.available()) {
    serialInput = Serial.readString();

  }
  while (Serial.available()) {
    delay(3);  
    char c = Serial.read();
    serialInput += c; 
  }

  if(debug){ 
    count += 1;
    Serial.print(count);
    Serial.print(" ");
    Serial.println(serialInput);

  }

  if(serialInput == startLine){
    Serial.print("working");
    digitalWrite(13, HIGH);
    servo1.write(170);
    servo2.write(170);
    servo3.write(170);
  }

}

