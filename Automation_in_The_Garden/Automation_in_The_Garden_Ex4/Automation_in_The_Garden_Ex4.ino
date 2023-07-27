#include <DHT.h> // Adds additional commands related to the DHT11(Temperature and humidity) sensor
#include <Adafruit_LiquidCrystal.h> // This gives us access to additional commands

#define DHTPIN 5 // This sets “DHTPIN” to “5” so instead of writing 5 we wright DHTPIN and if we decide to change pins we only have to adjust it here
#define DHTTYPE DHT11 // Tells our code what kind of DHT sensor we are using 
#define AOUT_PIN A0 // Arduino pin that connects to ANALOG OUT pin of moisture sensor
#define Buttonpin 12 //Assigns pin 12 to the name button pin

DHT dht(DHTPIN, DHTTYPE); // sets DHT as a variable representing what comes after it
Adafruit_LiquidCrystal lcd_1(0);  // Starts up the additional commands and tells it where we plugged in the LCD

void setup() {  //  This section will run once
  lcd_1.begin(16, 2);  // Starts the LCD
  dht.begin(); // Starts the DHT sensor
}

void loop()
{
   float Humidity = dht.readHumidity();
   float Temperature = dht.readTemperature();
   int soilMoisture = analogRead(AOUT_PIN); // read the analog value from sensor
   int i = 0;// this will allow us to use later in the next loop
   if (digitalRead(Buttonpin) == 1){
     for (i = 0; i < 5; i++) { // i = 0 sets i to 0 then i < 5 will allow it to stop when not true and i++ will add 1 to i each time it runs

       lcd_1.clear();  // resets the cursor to the top left corner and clears the display
       lcd_1.print("Humidity (%): "); // Prints what is inside the “ ” on the lcd
       lcd_1.print(Humidity); // Prints the humidity detected onto the LCD

       lcd_1.setCursor(0, 1);  // Moves cursor to the first column and second row
       lcd_1.print("Temperature  (C): "); // Prints what is inside the “ ” on the lcd
       lcd_1.print(Temperature); // Prints the temperature detected onto the LCD
       delay(1000); // waits for 1 second
  
       lcd_1.clear();  // resets the cursor to the top left corner and clears the display
       lcd_1.print("Moisture: "); // Measured from 0 to 1024 the higher the dryer(520:Dry soil/260:wet soil)
       lcd_1.print(soilMoisture); //Prints the detected value 
     }
   }

   lcd_1.clear();  // resets the cursor to the top left corner and clears the display
   if (15.0 > (Temperature) > 24.0){// sets range for temperature before giving an alert
     lcd_1.clear();
     lcd_1.print("Temp is outside");
     lcd_1.setCursor(0, 1);
     lcd_1.print("set range");
     delay(1000);
     lcd_1.clear();
   } 
   if (40.0 > (Humidity) > 80.0){ // sets range for Humidity before giving an alert
     lcd_1.clear();
     lcd_1.print("Humidity beyond");
     lcd_1.setCursor(0, 1);
     lcd_1.print("set limit");
     delay(1000);
     lcd_1.clear();  
   }
   if (450 < (soilMoisture)){ //Sets range for soil moisture before giving an alert
     lcd_1.clear();
     lcd_1.print("Soil Moisture");
     lcd_1.setCursor(0, 1);
     lcd_1.print("too low");
     delay(1000);
     lcd_1.clear();
   }
}
