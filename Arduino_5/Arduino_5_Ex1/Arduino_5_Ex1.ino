int sensorPower = 5;  // Assigns digital pin 5 to sensorPower
int sensorSignal = A5; // Assigns analog pin A5 to sensorSignal
int Red_LED = 12; // Assigns pin 12 to Red_LED
int sensorValMinimum = 166; // Set minimum sensor value for sensor powering
int delayTime = 500;  // Delay time is set to 500
int sensorValue;  // Setting a open variable to store read values from the water sensor

void setup() { // This code will run once on startup
   Serial.begin(9600);// Starting Serial Terminal
   pinMode(sensorPower, OUTPUT); // Telling the board pin 5 is an output
   digitalWrite(sensorPower, LOW); // Turns the sensor off
   pinMode(Red_LED, OUTPUT); // Telling board pin 5 is a output
}

void loop() { // This code will repeat forever
   digitalWrite(sensorPower, HIGH); // Turns water sensor on
   sensorValue = analogRead(sensorSignal); // Reads value from the analog pin

   if (sensorValMinimum <= sensorValue){ // Tells the arduino what to do if read value is larger than minimum value set
    digitalWrite(Red_LED, HIGH);} // Turns on the led
   else(digitalWrite(Red_LED, LOW)); // Turns off the led

   delay(delayTime);  // Waits time equal to dalayTime in miliseconds 
   Serial.print("Water sensor value: "); // Prints what is in the " "
   Serial.print(sensorValue); // Prints the sensorValue detected
   Serial.println(); // Prints to new line

}
