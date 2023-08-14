int LED = 13; // Renames the number 13 to "LED"
int BUTTON = 4; // Remanes the number 4 to "BUTTON"

void setup() { // Code in setup will run only on startup
pinMode(LED, OUTPUT); // Changes LED pin to an output pin
pinMode(LED, INPUT); // Changes BUTTON pin to an input pin
}

void loop() { // The loop is where the main part will go and will run in a loop forever
  if(digitalRead(BUTTON) == HIGH){ // Checkes if the button is pressed and if it is it runs the code inside the Brackets
    digitalWrite(LED, HIGH); // Turns on the LED
  } 
  else{ // This will run whe the button is not pressed 
    digitalWrite(LED, LOW); // Turns off the LED
  }
} 
