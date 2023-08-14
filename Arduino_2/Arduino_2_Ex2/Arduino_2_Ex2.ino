#include <Servo.h> // Include the servo header
Servo servo1; //Creates a servo object
const int servopin = 9; // Sets the value of "servopin" to 9
const int photoresistorpin = 0; // Sets the value of "photoresistorpin" to 0
int val = 0; // Sets the value of "val" to 0
 
void setup() { // Code in setup will run only on startup
servo1.attach(servopin); // This tells the servo object what pin is being used
}

void loop() { // The loop is where the main part will go and will run in a loop forever
val = analogRead(photoresistorpin); // Update the value from the photoresistor
val = map(val,0,1023,0,180); // Convert "val" to degrees
servo1.write(val); //Output the angle to point to
delay(100); // Waits 100 miliseconds
}
