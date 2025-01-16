#include <Servo.h>

const int trigPin = 6;      
const int echoPin = 7;      
const int ldrPin = A0;      
const int ledPin = 13;      
const int servoPin = 9;     

Servo myServo;

void setup() {
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  
  myServo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  long duration, distance;
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  
  distance = duration * 0.0344 / 2;  
  
  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  if (distance < 20) {
    myServo.write(0);  
    delay(3500);    
  } else {
    myServo.write(90);   
  }

  int ldrValue = analogRead(ldrPin);
  
  Serial.print("Nilai LDR: ");
  Serial.println(ldrValue);
  
  if (ldrValue < 100) {
    digitalWrite(ledPin, HIGH);  
  } else {
    digitalWrite(ledPin, LOW);  
  }
  delay(100);
}
