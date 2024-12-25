#include <Servo.h>

// Define the pins for the ultrasonic sensor
const int trigPin = 9;
const int echoPin = 8;

// Define the servo motor
Servo myServo;

// Variables for duration and distance
long duration;
int distance;

void setup() {
  // Set up the pins for the ultrasonic sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Attach the servo motor to pin 7
  myServo.attach(7);
  
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Send out a pulse to start the measurement
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the duration of the echo pulse
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance in centimeters
  distance = duration * 0.034 / 2;
  
  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  
  // Map the distance to a servo angle (0 to 180 degrees)
  int angle = map(distance, 0, 100, 0, 180);
  
  // Constrain the angle to stay within the servo's range
  angle = constrain(angle, 0, 180);
  
  // Move the servo to the calculated angle
  myServo.write(angle);

  // Add a small delay to avoid rapid changes
  delay(100);
}
