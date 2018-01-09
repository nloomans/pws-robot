String serialInput;

void setup() {
  Serial.print("start");
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}

void loop() {

  while (Serial.available()) {
    serialInput = Serial.readString();
    Serial.println(serialInput);

  }
}

