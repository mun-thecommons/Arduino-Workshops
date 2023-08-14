#include <IRremote.h> // Adds the library that includes the extra IR functions 
#include <Stepper.h> // Adds functions for the stepper motor
#define IRreceiver 6 // Defining the text "IRreceiver" as 6 (Pin 6)
#define Forward  64 // Define what code means Forward (Fast Forward button)
#define Back 68 // Define what code means Back (Rewind button)
#define Slow  12 // Define what code means Slow (1 button)
#define Medium  24 // Define what code means Medium (2 Button)
#define Fast  94 // Define what code means Fast (3 Button)
const int stepsPerRevolution = 2048; // Define number of steps per rotation
const int IN1 = 8; // Renames the number 8 to "IN1" 
const int IN2 = 9; // Renames the number 9 to "IN2"
const int IN3 = 10; // Renames the number 10 to "IN3"
const int IN4 = 11; // Renames the number 11 to "IN4"
Stepper myStepper(stepsPerRevolution, IN1, IN3, IN2, IN4); // Create a stepper object, setting # of steps & pin locations

bool dir = 1; // Set the direction, true/1 for CW, false/0 for CCW

void setup() { // Code in setup will run only on startup
Serial.begin(9600); // Start serial communications at a baud rate of 9600
IrReceiver.begin(IRreceiver); // Start the receiver
myStepper.setSpeed(5); // Set an initial speed
}

void loop() {
if(IrReceiver.decode()) // If the sensor detects a signal it will run what is in the Brackets
{
int result = IrReceiver.decodedIRData.command; // Sets the value of the decode to "result"

if (result == Forward){ // Check if IR data means forward
dir = true;  // Set direction
Serial.println("CW"); // Prints direction to serial 
}
else if (result == Back){ //check if IR data means back
dir = false; // Set direction
Serial.println("CCW"); // Prints direction to serial 
}
else if (result == Slow){ //check if IR data means slow
myStepper.setSpeed(5); // Sets the speed of in RPM
Serial.println("Slow"); // Prints "Slow" to Serial
}
else if (result == Medium){ //check if IR data means medium
myStepper.setSpeed(10);
Serial.println("Medium"); // Prints "Medium" to Serial
else if (result == Fast){ //check if IR data means fast
myStepper.setSpeed(15); // Sets the speed of in RPM
Serial.println("Fast"); // Prints "Fast" to Serial
}
else
Serial.println("Unknown command");
}
IrReceiver.resume(); //Prepare to receive the next value  
if (dir == true){ // Check the direction set
myStepper.step(50); // make 50 steps CW
}
else
myStepper.step(-50); //Make 50 steps CCW
}
