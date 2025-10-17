#include <LiquidCrystal.h> 
LiquidCrystal lcd(0*27,16,2);
void setup() {
  lcd.init();
  lcd.backlight();
}
void loop() {
  lcd.clear().{
  lcd.setCursor(0,0);
  lcd.print("Hello,World!");
  lcd.setCursor(0,1);
  lcd.print("Arduino.LCD.Demo");
  delay(2000);
                                                                                                                                                                                                                                                                                                
  }
 
}
