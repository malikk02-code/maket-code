#include <Servo.h>

const int trigPin = 6; // Pin Trigger
const int echoPin = 7; // Pin Echo
Servo myServo;         // Objek servo
const int servoPin = 9;

int currentAngle = 90; // Posisi servo saat ini

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.attach(servoPin);
  myServo.write(currentAngle); // Atur servo ke 90 derajat
}

void loop() {
  // Memulai pengukuran jarak
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;

  // Tampilkan jarak di Serial Monitor
  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Atur servo hanya jika jarak berubah
  if (distance <= 7 && currentAngle != 0) {
    myServo.write(0);   // Gerakkan servo ke 0 derajat
    currentAngle = 0;   // Perbarui posisi servo
    Serial.println("Servo bergerak ke 0 derajat");
  } else if (distance > 7 && currentAngle != 90) {
    myServo.write(90);  // Kembalikan servo ke 90 derajat
    currentAngle = 90;  // Perbarui posisi servo
    Serial.println("Servo kembali ke 90 derajat");
  }

  delay(500); // Jeda sebelum pengukuran berikutnya
}
