#include<Servo.h> // The library that includes the extra Servo functions 
Servo servo1Motor; // Declaring the servo object for servo1
Servo servo2Motor;// Declaring the servo object for servo1
int potent1 = A0; // Assign first potentiometer to A0
Int potent2 = A1; // Assign second potentiometer to A1
int motor1Pin = 9; // Assign  pin 9 to motor1Pin
int motor1Angle; // Set up variable to store analogRead from potentiometer
int motor2Pin = 10; // Assign pin 10 to motor2Pin
Int motor2Angle; // Set up variable to store analogRead from  potentiometer 2
int range1; // Setting the range of the servo
Int range2; // Setting the range of the second servo
int delaytime = 5; // Creating a small delay for input

void setup() { // This code will run once on startup
pinMode(potent1,INPUT); // Set potentiometer as a input
servo1Motor.attach(motor1Pin); // Tells arduino where servo is

pinMode(potent2,INPUT); // Set potentiometer 2 as a input
servo2Motor.attach(motor2Pin); // Tells arduino where servo is
Serial.begin(9600); // Setting up serial monitor to view angle
}



void loop() { // This code will repeat forever
motor1Angle = analogRead(potent1); // taking  the position value from the potentiometer
range1 = map(motor1Angle, 0, 1023 ,0, 180); // Range for mapping to use motor1Angle value
Serial.print(range1);  // Print the angle that the potentiometer is set to
Serial.println(“, “); // Prints the comma and space to separate the angles being read
servo1Motor.write(range1); // Outputs the angle to go to

motor2Angle = analogRead(potent2); // Taking  the position value from the second potentiometer
range2 = map(motor2Angle,0,1023,0,180); // range for mapping to use motor2Pos value
Serial.println(range2); // Print the angle that the potentiometer is set to
Serial.println(“, “); // Prints the comma and space to separate the angles being read
servo2Motor.write(range2); // Outputs the angle to go to
delay(delaytime); // Waits the time equal to delaytime in miliseconds
}
