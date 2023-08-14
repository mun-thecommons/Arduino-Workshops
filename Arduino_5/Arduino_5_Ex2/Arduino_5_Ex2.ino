int sensorValMinimum = 166; // Sets our value threshold
int value = 0; // Setting our value variable to 0  
int buzzer = 9; // Assign digital pin 9 to buzzer
int frequency1 = 1000; // Setting buzzer frequency tone to 1000 Hertz
int frequency2 = 250; // Setting buzzer frequency tone to 250 Hertz
int delayTime = 500; // Delay time in miliseconds
int sensorValue; // Creating a open variable to store read sensor values
int criticalDistance = 3; // Setting a critical distance in which alarm goes off
int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
int echoPin = 6; // Echo Pin of Ultrasonic Sensor
int delayMS1 = 2; // Delay time in miliseconds
int delayMS2 = 10; // Delay time in miliseconds

void setup() { // This code will run once on startup
   Serial.begin(9600); // Starting Serial Terminal
   pinMode(buzzer, OUTPUT); // Set buzzer as a output
   pinMode(pingPin, OUTPUT); // Setting pin 7/pingpin as a output
   pinMode(echoPin, INPUT); // Setting pin 6/echopin as an input
}

void loop() { // This code will repeat forever
   long duration, inches, cm;
   digitalWrite(pingPin, LOW); // Setting pingPin to low
   delay(delayMS1);  // Delay time equal to delayMS1
   digitalWrite(pingPin, HIGH); // Setting pingPin to high 
   delay(delayMS2); // Delay time equal to delayMS2
   digitalWrite(pingPin, LOW); // Setting pingPin to low
   duration = pulseIn(echoPin, HIGH); // Reads pulse value for distance 
   inches = microsecondsToInches(duration); // Converts inputs to inches
   cm = microsecondsToCentimeters(duration); // Converts input to centimeters
     if (cm <= criticalDistance){ // If statement for when the detected distance of ultrasonic sensor is less than or equal to critical distance value
  tone(buzzer, frequency1); // Turns on buzzer at frequency1
 delay(delayTime); // Delay equal to delayTime
 noTone(buzzer); // Turn off buzzer
 tone(buzzer,frequency2); // Turns on buzzer at a different frequency
 noTone(buzzer); // Turn off buzzer
 delay(delayTime); // Wait equal to delayTime
}
   else { // If not in the range does what is in brackets
   noTone(buzzer); // Turns off buzzer
   }

   delay(delayTime); // Waits for time equal to delayTime
   Serial.print("Water Height: "); // Prints whats in the " "
   Serial.print(inches); // Prints inches stored value
   Serial.print("in"); // Prints what’s in the " "
   Serial.print(", "); // Prints what’s in the " "
   Serial.print(cm); // Prints cm stored value
   Serial.print("cm"); // Prints what’s in the " "
   Serial.println(); // Prints a new line
}
long microsecondsToInches(long microseconds) { // Sets up the function to convert from the data received by the sensor to inches
   return microseconds / 74 / 2;
}
long microsecondsToCentimeters(long microseconds) { // Sets up the function to convert from the data received by the sensor to centimeters
   return microseconds / 29 / 2;
}
