#include <Adafruit_LiquidCrystal.h> // This gives us access to additional commands

Adafruit_LiquidCrystal lcd_1(0);  // Starts up the additional commands and tells it where we plugged in the LCD

void setup() {  //  This section will run once
  lcd_1.begin(16, 2);  // Starts the LCD
}

void loop() {  // Runs in a loop 
    lcd_1.setCursor(2, 0);  // Moves cursor to the third column and top row
    lcd_1.print("Hello World!"); // Show what is in the ” ” on the LCD
    delay(1000);  // Wait for 1000 millisecond(s)
    lcd_1.clear();  // resets the cursor to the top left corner and clears the display
    delay(1000);  // Wait for 1000 millisecond(s)
}
