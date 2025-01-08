#include <Servo.h>

const int trigPin = 6;      // Pin untuk Trigger HC-SR04
const int echoPin = 7;      // Pin untuk Echo HC-SR04
const int ldrPin = A0;      // Pin untuk Sensor LDR (Analog)
const int ledPin = 13;      // Pin untuk LED
const int servoPin = 9;     // Pin untuk Mini Servo

Servo myServo;              // Objek servo

void setup() {
  // Inisialisasi pin
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  // Inisialisasi servo
  myServo.attach(servoPin);
  
  // Mulai komunikasi serial untuk debugging
  Serial.begin(9600);
}

void loop() {
  // Mengukur jarak menggunakan sensor ultrasonik
  long duration, distance;
  
  // Kirim pulse ke trigPin
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Mengukur waktu untuk echo pin kembali
  duration = pulseIn(echoPin, HIGH);
  
  // Hitung jarak berdasarkan waktu echo
  distance = duration * 0.0344 / 2;  // Rumus jarak dalam cm
  
  // Tampilkan jarak untuk debugging
  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Menggerakkan servo berdasarkan jarak
  if (distance < 20) {
    myServo.write(0);  // Gerakkan servo ke 0 derajat jika jarak < 20 cm
    delay(3500);       // Tambahkan delay 1 detik sebelum servo kembali
  } else {
    myServo.write(90);   // Gerakkan servo ke 90 derajat jika jarak >= 20 cm
  }

  // Membaca nilai LDR untuk mendeteksi cahaya
  int ldrValue = analogRead(ldrPin);
  
  // Tampilkan nilai sensor LDR untuk debugging
  Serial.print("Nilai LDR: ");
  Serial.println(ldrValue);
  
  // Jika nilai LDR menunjukkan cukup cahaya, nyalakan LED
  if (ldrValue < 100) {  // Angka 100 bisa disesuaikan dengan kondisi cahaya
    digitalWrite(ledPin, HIGH);  // Nyalakan LED
  } else {
    digitalWrite(ledPin, LOW);   // Matikan LED
  }
  
  // Delay sebentar untuk stabilitas
  delay(100);
}
