#include <LiquidCrystal_I2C.h> // This gives us access to additional commands

LiquidCrystal_I2C lcd_1(0x27, 20, 4);   // Starts up the additional commands and tells it where we plugged in the LCD

void setup() {  //  This section will run once
  lcd_1.init(); // Starts the LCD
  lcd_1.backlight(); // Turns on backlght for LCD
}

void loop() {  // Runs in a loop 
    lcd_1.setCursor(2, 0);  // Moves cursor to the third column and top row
    lcd_1.print("Hello World!"); // Show what is in the ” ” on the LCD
    delay(1000);  // Wait for 1000 millisecond(s)
    lcd_1.clear();  // resets the cursor to the top left corner and clears the display
    delay(1000);  // Wait for 1000 millisecond(s)
}