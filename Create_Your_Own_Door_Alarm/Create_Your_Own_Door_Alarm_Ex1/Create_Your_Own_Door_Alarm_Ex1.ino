int buzzer = 8; //this allows us to write "buzzer" instead of "8" so that if we plug it in somewhere else we need only change this 8
int led = 6; //this allows us to write "led" instead of "6" so that if we plug it in somewhere else we need only change this 6

void setup() {
  pinMode(buzzer, OUTPUT); // set the pin assaigned to buzzer as an output
  pinMode(led, OUTPUT); // set the pin assigned to led as an output pin 
}

void loop() {
  tone(buzzer, 60); // makes the buzzer create a sound at 60Hz
  digitalWrite(led, HIGH); // sets the led pin to high turning on the led
  delay(200); // waits 200 miliseconds
  noTone(buzzer); // tuns off buzzer
  digitalWrite(led, LOW); // turns off LED-
  delay(200); // waits 0.2 seconds
}
