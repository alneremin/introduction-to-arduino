

const int ledPin = 9;
int currentV = 0;
int voltageDirection = -1;

void setup() {
  pinMode(ledPin, OUTPUT);
}

// заглушка, потенциометра нет
void changeVoltage() {
  if (currentV == 255 || currentV == 0) {
    voltageDirection = -voltageDirection;
  }
  currentV += voltageDirection;
}

void loop() {
  changeVoltage();
  delay(10);
  analogWrite(ledPin, currentV);
}
