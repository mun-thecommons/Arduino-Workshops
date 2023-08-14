int LED = 13; // Renames the number 13 to "LED"

void setup() { // Code in setup will run only on startup
pinMode(LED, OUTPUT); // Changes LED pin to an output pin
}

void loop() { // The loop is where the main part will go and will run in a loop forever
digitalWrite(LED, HIGH); // Turns on the LED
delay(500); // Waits for 500 miliseconds before continuing with the next line
digitalWrite(LED, LOW); // Turns off the LED
delay(500); // Waits for 500 miliseconds before continuing with the next line
}
