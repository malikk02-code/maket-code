#include <Servo.h>

// Definisi pin untuk sensor ultrasonik
const int trigPin = 6;  // Pin Trigger
const int echoPin = 7;  // Pin Echo
Servo myServo;          // Objek servo
const int servoPin = 9; // Pin untuk servo

// Definisi pin untuk LDR dan LED
const int ledPin = 13;  // Pin untuk LED
const int ldrPin = A0;  // Pin untuk LDR
int ldrValue = 0;       // Variabel untuk membaca nilai LDR

// Variabel untuk posisi servo
int currentAngle = 90;  // Posisi awal servo pada 90 derajat

void setup() {
  // Serial monitor untuk debugging
  Serial.begin(9600);

  // Konfigurasi pin untuk ultrasonik
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Konfigurasi pin untuk LDR dan LED
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);

  // Inisialisasi servo
  myServo.attach(servoPin);
  myServo.write(currentAngle); // Set posisi servo ke 90 derajat
}

void loop() {
  // Bagian Sensor Ultrasonik dan Servo
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;

  // Logika servo berdasarkan jarak
  if (distance <= 7 && currentAngle != 0) {
    myServo.write(0);   // Servo bergerak ke 0 derajat
    currentAngle = 0;   // Update posisi servo
    Serial.println("Servo bergerak ke 0 derajat");
  } else if (distance > 7 && currentAngle != 90) {
    myServo.write(90);  // Servo kembali ke 90 derajat
    currentAngle = 90;  // Update posisi servo
    Serial.println("Servo kembali ke 90 derajat");
  }

  // Tampilkan jarak di Serial Monitor
  Serial.print("Jarak Ultrasonik: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Bagian Sensor LDR dan LED
  ldrValue = analogRead(ldrPin);

  if (ldrValue <= 1000) {
    digitalWrite(ledPin, HIGH); // Nyalakan LED
    Serial.print("LDR Value: ");
    Serial.print(ldrValue);
    Serial.println(" (LED ON)");
  } else {
    digitalWrite(ledPin, LOW); // Matikan LED
    Serial.print("LDR Value: ");
    Serial.print(ldrValue);
    Serial.println(" (LED OFF)");
  }

  // Jeda sebelum iterasi berikutnya
  delay(500);
}
