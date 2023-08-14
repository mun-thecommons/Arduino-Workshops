#include <Stepper.h> // Adds functions for the stepper motor
const int stepsPerRevolution = 2048; // Define number of steps per rotation
const int IN1 = 8; // Renames the number 8 to "IN1" 
const int IN2 = 9; // Renames the number 9 to "IN2"
const int IN3 = 10; // Renames the number 10 to "IN3"
const int IN4 = 11; // Renames the number 11 to "IN4"

Stepper myStepper(stepsPerRevolution, IN1, IN3, IN2, IN4); // Create a stepper object, setting # of steps & pin locations

void setup() { // Code in setup will run only on startup
  myStepper.setSpeed(10);  // Set the speed to 10 rpm:
  Serial.begin(9600); // Begin Serial communication at a baud rate of 9600:
}

void loop() {
  Serial.println("clockwise"); //Print to serial monitor 
  myStepper.step(stepsPerRevolution); // Step one revolution clockwise
  delay(500); // Wais 500 miliseconds before starting next line
  Serial.println("counterclockwise"); //Print to serial monitor
  myStepper.step(-stepsPerRevolution); // Step one revolution counterclockwise
  delay(500); // Waits 500 miliseconds before starting next line
}
