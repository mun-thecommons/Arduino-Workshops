#include <DHT.h> // Adds additional commands related to the DHT(Temperature and humidity) sensors
#include <LiquidCrystal_I2C.h> // This gives us access to additional commands
#define DHTPIN 5 // This sets “DHTPIN” to “5” so instead of writing 5 we wright DHTPIN and if we decide to change pins we only have to adjust it here
#define DHTTYPE DHT11 // Tells our code what kind of DHT sensor we are using 

DHT dht(DHTPIN, DHTTYPE); // sets DHT as a variable representing what comes after it
LiquidCrystal_I2C lcd_1(0x27, 20, 4);  // Starts up the additional commands and tells it where we plugged in the LCD

void setup() {  //  This section will run once
  lcd_1.init();  // Starts the LCD
  lcd_1.backlight(); // Turns on backlght for LCD
  dht.begin(); // Starts the DHT sensor
}

void loop()
{
   float Humidity = dht.readHumidity(); // Reads the humidity value from the sensor
   float Temperature = dht.readTemperature(); // Reads the temperature value from the sensor

   lcd_1.clear();  // resets the cursor to the top left corner and clears the display
   lcd_1.print("Humidity (%): "); // Prints what is inside the “ ” on the lcd
   lcd_1.print(Humidity); // Prints the humidity detected onto the LCD

   lcd_1.setCursor(0, 1);  // Moves cursor to the first column and second row
   lcd_1.print("Temp (C): "); // Prints what is inside the “ ” on the lcd
   lcd_1.print(Temperature); // Prints the temperature detected onto the LCD
   delay(1000); // waits for 1 second

   lcd_1.clear();  // resets the cursor to the top left corner and clears the display
   if (15.0 > (Temperature) || (Temperature) > 24.0){// sets range for temperature before giving an alert
     lcd_1.clear();
     lcd_1.print("Temp is outside");
     lcd_1.setCursor(0, 1);
     lcd_1.print("set range");
     delay(1000);
     lcd_1.clear();
   } 
   if (40.0 > (Humidity) || (Humidity) > 80.0){ // sets range for Humidity before giving an alert
     lcd_1.clear();
     lcd_1.print("Humidity beyond");
     lcd_1.setCursor(0, 1);
     lcd_1.print("set limit");
     delay(1000);
     lcd_1.clear();  
   }
}
