const int ledPin = 13;

const int ldrPin = A0;
int value = 0;
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);
}

void loop() {
  int ldrStatus = analogRead(ldrPin);
  value = analogRead(ldrPin);
  if (value <= 1000) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPin, HIGH);
    Serial.println(value);
  }else {
    digitalWrite(ledPin, LOW);
    Serial.println(value);
  }
}