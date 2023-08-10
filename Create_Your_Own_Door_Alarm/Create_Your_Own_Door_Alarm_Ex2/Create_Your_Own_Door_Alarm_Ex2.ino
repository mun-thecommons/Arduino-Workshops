int buzzer = 8; //this allows us to write "buzzer" instead of "8" so that if we plug it in somewhere else we need only change this 8
int led = 6; //this allows us to write "led" instead of "6" so that if we plug it in somewhere else we need only change this 6
int doorSensor = 2; //allows for the substitution of door sensor pin with just doorSensor
int i = 0; //this will allow us to use i as a placeholder later
int DelayInSeconds = 5; // this allows us to change the delay we want here instead of each time it occurs later
void setup() {
  pinMode(buzzer, OUTPUT); // set the pin assaigned to buzzer as an output
  pinMode(led, OUTPUT); // set the pin assigned to led as an output pin 
  pinMode(doorSensor, INPUT); // sets the pin number to of doorSensor to Input 
  
}

void loop() {
  if (digitalRead(doorSensor) == LOW){ // sets the perameters for if the code inside the curly brackets will run
    for (i = 0; i < DelayInSeconds; i++){ // tell the code in the brackets to run a set number of times 
      delay(1000); // one second delay
      }
    while (digitalRead(doorSensor) == LOW){
     tone(buzzer, 60); // makes the buzzer create a sound at 175Hz
     digitalWrite(led, HIGH); // sets the led pin to high turning on the led
     delay(200); // waits 200 miliseconds
     noTone(buzzer); // tuns off buzzer
     digitalWrite(led, LOW); // turns off LED
     delay(200); // waits 0.2 seconds
   }
  }
}
