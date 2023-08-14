#include<Servo.h> // The library that includes the extra Servo functions 
Servo servo1Motor; // Declaring the servo object
int potent1 = A0; // Assign first potentiometer to A0
int motor1Pin = 9; // Assign  pin 9 to motor1Pin
int motor1Angle; // Set up variable to store analogRead from potentiometer
int range1; // Setting the range of the servo
int delaytime = 5; // Creating a small delay for input

void setup() { // This code will run once on startup
pinMode(potent1,INPUT); // Set potentiometer as a input
servo1Motor.attach(motor1Pin); // Tells arduino where servo is
Serial.begin(9600); // Setting up serial monitor to view angle
}

void loop() { // This code will repeat forever
motor1Pos = analogRead(potent1); // Taking the position value from the potentiometer
range1 = map(motor1Angle, 0, 1023 ,0, 180); // Range for mapping to use motor1Pos value
Serial.println(range1); // Print the angle that the potentiometer is set to
servo1Motor.write(range1); // Output the angle to go to
delay(delaytime); // Waits the time equal to delaytime in miliseconds
}
