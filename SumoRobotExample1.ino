// Set the delay time in milliseconds for the sensor readings
int DelayTime = 500;
​
// Define the pin connected to the ultrasonic sensor's trigger
int TrigPin = A0;
​
// Define the pin connected to the ultrasonic sensor's echo
int EchoPin = A1;
​
// Variables to store the sensor reading and calculated distance
int reading, distance;
​
// Setup function, runs once when the Arduino is powered on or reset
void setup() {
  // Initialize serial communication with a baud rate of 9600
  Serial.begin(9600);
​
  // Set the trigger pin as an output
  pinMode(TrigPin, OUTPUT);
​
  // Set the echo pin as an input
  pinMode(EchoPin, INPUT);
}
​
​
// Loop function, runs repeatedly after the setup function
void loop() {
  // Send a short LOW pulse to the trigger pin to start the ultrasonic sensor
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
​
  // Send a HIGH pulse to the trigger pin for 10 microseconds to trigger the sensor
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
​
  // Turn off the trigger pulse
  digitalWrite(TrigPin, LOW);
​
  // Read the duration of the pulse received on the echo pin
  reading = pulseIn(EchoPin, HIGH);
​
  // Calculate the distance using the speed of sound (approximately 0.034 cm per microsecond)
  distance = (reading * 0.034 / 2);
​
  // Introduce a delay before the next sensor reading
  delay(DelayTime);
​
  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm");
​
  // Check if the distance is greater than or equal to 50cm
  if (distance >= 50) 
  {
    Serial.println(" - Higher");
  } 
​
  
  else 
  {
    // If the distance is less than 50cm, move to the next line in the Serial Monitor
    Serial.println(" - Lower");
  }
​
  // Introduce a delay before the next iteration of the loop
  delay(DelayTime);
}
​