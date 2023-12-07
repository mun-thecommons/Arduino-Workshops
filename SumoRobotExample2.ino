// Include the Adafruit Motor Shield library
#include <Adafruit_MotorShield.h>
​
// Include the Adafruit Motor library for DC motor control
#include <AFMotor.h>
​
// Create instances of DC motors named LeftMotor and RightMotor
AF_DCMotor LeftMotor(1);
AF_DCMotor RightMotor(2);
​
// Define variables for the ultrasonic sensor
int DelayTime = 500;  // Set the delay time in milliseconds for sensor readings
int TrigPin = A0;     // Define the pin connected to the ultrasonic sensor's trigger
int EchoPin = A1;     // Define the pin connected to the ultrasonic sensor's echo
​
int reading, distance;  // Variables to store the sensor reading and calculated distance
​
// Setup function, runs once when the Arduino is powered on or reset
void setup() {
  // Initialize serial communication with a baud rate of 9600
  Serial.begin(9600);
​
  // Set the trigger pin as an output
  pinMode(TrigPin, OUTPUT);
​
  // Set the echo pin as an input
  pinMode(EchoPin, INPUT);
​
  // Set the speed of the left motor to maximum (255)
  LeftMotor.setSpeed(255);
​
  // Set the state of the left motor to RELEASE (no motion)
  LeftMotor.run(RELEASE);
​
  // Set the speed of the right motor to maximum (255)
  RightMotor.setSpeed(255);
​
  // Set the state of the right motor to RELEASE (no motion)
  RightMotor.run(RELEASE);
​
  // Initialize serial communication again (repeated line, consider removing)
  Serial.begin(9600);
}
​
// Loop function, runs repeatedly after the setup function
void loop() {
  // Send a short LOW pulse to the trigger pin to start the ultrasonic sensor
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  
  // Send a HIGH pulse to the trigger pin for 10 microseconds to trigger the sensor
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  
  // Turn off the trigger pulse
  digitalWrite(TrigPin, LOW);
​
  // Read the duration of the pulse received on the echo pin
  reading = pulseIn(EchoPin, HIGH);
​
  // Calculate the distance using the speed of sound (approximately 0.034 cm per microsecond)
  distance = (reading * 0.034 / 2);
​
  // Introduce a delay before the next sensor reading
  delay(DelayTime);
​
  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm");
  Serial.print("     |    ");
​
  // Introduce a delay before the next iteration of the loop
  delay(500);
​
  // Check if the distance is less than or equal to 50 cm
  if (distance <= 50) {
    // If so, print "ATTACK" to the Serial Monitor
    Serial.print("ATTACK");
    Serial.println();
​
    // Set the speed of both motors to maximum (255) and move them forward
    LeftMotor.setSpeed(255);
    RightMotor.setSpeed(255);
    LeftMotor.run(FORWARD);
    RightMotor.run(FORWARD);
​
    // Introduce a short delay (300 milliseconds) for the attack action
    delay(300);
  } else {
    // If the distance is greater than 50 cm, print "HUNTING" to the Serial Monitor
    Serial.print("HUNTING");
    Serial.println();
​
    // Set the speed of both motors to a lower value (150)
    LeftMotor.setSpeed(150);
    RightMotor.setSpeed(150);
​
    // Move the left motor forward and the right motor backward
    LeftMotor.run(FORWARD);
    RightMotor.run(BACKWARD);
​
    // Introduce a short delay (200 milliseconds) for the hunting action
    delay(200);
​
    // Stop both motors by setting their states to RELEASE
    LeftMotor.run(RELEASE);
    RightMotor.run(RELEASE);
  }
​
  // Introduce a delay before the next iteration of the loop
  delay(1000);
}