#include <Servo.h> // This allows access to additional resources to make using the servo easier
Servo servo1; // Creates a servo object so that we can use the resources added with "Servo.h" 
int servopin = 9; // This will Rename 9 to "servopin"

void setup() { // Code in setup will run only on startup
servo1.attach(servopin); // This tells the servo object what pin is being used
}

void loop() { // The loop is where the main part will go and will run in a loop forever
servo1.write(180); // Rotates the servo to the 180 degree position
delay(2000); // Waits for 2 seconds before continuing with the next line
servo1.write(0); // Rotates the servo to the 0 degree position
delay(2000); // Waits for 2000 miliseconds before continuing with the next line
}
