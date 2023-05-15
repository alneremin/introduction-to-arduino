
int buttonPin = 3;
int intButtonPin = 0;
int ledPin = 9;
volatile bool ledStatus = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  intButtonPin = digitalPinToInterrupt(buttonPin);
  Serial.begin(9600);
  attachInterrupt(intButtonPin, onPressed, RISING);
}

void onPressed() {
  ledStatus = !ledStatus;
}

void loop() {
  digitalWrite(ledPin, ledStatus);
  delay(100);
  Serial.println(ledStatus);
}
