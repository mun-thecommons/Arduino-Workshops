int buzzer = 8; //this allows us to write "buzzer" instead of "8" so that if we plug it in somewhere else we need only change this 8
int led = 6; //this allows us to write "led" instead of "6" so that if we plug it in somewhere else we need only change this 6
int doorSensor = 2; //allows for the substitution of door sensor pin with just doorSensor
int button = 5; // assigns the value 5 to button
int i = 0; //this will allow us to use i as a placeholder later
int DelayInSeconds = 5; // this allows us to change the delay we want here instead of each time it occurs later
int DelayChange = 0; // used to keep track of how much the delay was incrased
int DelayIncrease = 5; // Sets the amount of time(seconds) increased each press of the button
int DelayLimit = 30; // Creates a limit of how long the delay can be in seconds even if the button was pressed again 

void setup() {
  pinMode(buzzer, OUTPUT); // set the pin assaigned to buzzer as an output
  pinMode(led, OUTPUT); // set the pin assigned to led as an output pin 
  pinMode(doorSensor, INPUT); // sets the pin number to of doorSensor to Input 
  pinMode(button, INPUT); // sets the pin number to of button to Input 
}

void loop() {
  if (digitalRead(button) == HIGH && DelayInSeconds < DelayLimit){ // checks for when the button is pressed
    DelayInSeconds = DelayInSeconds + DelayIncrease; // adds the additional time to the Delay
    DelayChange = DelayChange + DelayIncrease; // adds the same ammount of time 
    tone(buzzer, 175); // makes the buzzer create a sound at 175Hz
    delay(100); // waits 100 miliseconds
    noTone(buzzer); // tuns off buzzer
    delay(500); // waits 500 miliseconds
  }
  if (digitalRead(doorSensor) == LOW){ // sets the perameters for if the code inside the curly brackets will run
    for (i = 0; i < DelayInSeconds; i++){ // tell the code in the brackets to run a set number of times 
      delay(1000); // one second delay
      }
    DelayInSeconds -= DelayChange; // resets Delay in seconds to what it was before
    DelayChange = 0; // resets delay increase
    while (digitalRead(doorSensor) == LOW){
     tone(buzzer, 60); // makes the buzzer create a sound at 60Hz
     digitalWrite(led, HIGH); // sets the led pin to high turning on the led
     delay(200); // waits 200 miliseconds
     noTone(buzzer); // tuns off buzzer
     digitalWrite(led, LOW); // turns off LED
     delay(200); // waits 0.2 seconds
   }
  }
}
