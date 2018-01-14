String input;
void setup() {
  pinMode(12, OUTPUT);
  digitalWrite(12, LOW);
  Serial.begin(115200);
}

void loop() {
  if (Serial.available()) {

    input = Serial.readString();
    input.trim();
    if (input == "startLine") {
      digitalWrite(12, HIGH);
    }
    else {
      digitalWrite(12, LOW);
    }
  }
}
