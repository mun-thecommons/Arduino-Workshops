const int LED = 9; // Sets the value of "LED" to 9
const int photoresistorpin = 0; // Sets the value of "photoresistorpin" to 0
int val = 0; // Sets the value of "val" to 0

void setup() { // This code will run once
pinMode(LED, OUTPUT); // Telling the board pin 9(LED) will be an output 
}
void loop() { // Main code that will repeat forever
  val = analogRead(photoresistorpin); //Update the value received from photoresistor
  analogWrite(LED, val/4); // Output the scaled photoresistor value to the LED
  delay(10); // Give a short delay of 10 miliseconds between cycles
}
