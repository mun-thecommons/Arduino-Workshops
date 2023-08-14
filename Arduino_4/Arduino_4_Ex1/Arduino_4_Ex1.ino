#include <Servo.h> // Allows the use of a library that includes the extra Servo functions 
int motor1Pin = 9; // Assign 9 to "motor1Pin"
int motor1Angle = 0; // Assign 0 to "motor1Angle"
Servo servo1Motor; // Declaring the servo object



void setup() { // This code will run once on startup
Serial.begin(9600); // Establishes use of serial monitor for later
servo1Motor.attach(motor1Pin); // Tells the arduino where the servo pin is
}


void loop() { // This code will repeat forever
servo1Motor.write(motor1Angle); // Outputs the angle to go to
}
