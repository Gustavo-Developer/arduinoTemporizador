#include <Wire.h>
#include <LiquidCrystal_I2C_JHD1214.h>

// Precompiler directive #define IN_PROTEUS in "LiquidCrystal_I2C_JHD1214.cpp" file with #undef IN_PROTEUS
// if you use real dispaly or PCF8574 or PCF8574A Driver, you can found all included libraries files 
// into Arduino libraries folder, example: "C:\Users\GioRock\Documents\Arduino\libraries\LiquidCrystal_I2C"

  LiquidCrystal_I2C lcd(0x7C>>1, 16, 2); // JHD-2X16-I2C Display Device Addrress must be shift right by 1 to match in Proteus
//LiquidCrystal_I2C lcd(0x38, 16, 2); // Set display with PCF8574 or PCF8574A Driver like previous scheme
//LiquidCrystal_I2C lcd(0x38, 20, 4); // Set real display - address, columns, rows


void setup() {
  lcd.begin();
  //lcd.backlight(); // only with real display or display with PCF8574 or PCF8574A Driver
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("LCD DISPLAY JHD");
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.printstr("1214 BY GIOROCK");
  delay(1000);
}

void loop() {
  
  lcd.setCursor(0, 1);
  
  // print the number of seconds since reset:
  lcd.print(millis()/1000);
  
  delay(100);

}
