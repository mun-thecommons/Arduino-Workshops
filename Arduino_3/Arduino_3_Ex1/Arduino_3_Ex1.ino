#include <IRremote.h> //The library that includes the extra IR functions 
const int IRreceiver = 6; //Defining the text "IRreceiver" as 6 (Pin 6)

void setup() { // Code in setup will run only on startup
 Serial.begin(9600); // Start serial communications at a baud rate of 9600
IrReceiver.begin(IRreceiver); // Start the receiver
}

void loop() { // The loop is where the main part will go and will run in a loop forever
 if(IrReceiver.decode()){ // If the sensor detects a signal the code inside the curly brackets will run
Serial.println(IrReceiver.decodedIRData.command); //Prints detected values to console
IrReceiver.resume(); // Resume sensing for new signals
  }
delay(100); // Waits 100 miliseconds before continuing to run
}
