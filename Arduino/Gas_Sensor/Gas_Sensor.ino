
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display
 
void setup()
{
  lcd.init(); 
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.print("AIR QUALITY");
  lcd.setCursor(9,1);
  lcd.print("PPM");
}
 
void loop()
{
  int sensorValue = analogRead(A0);
  lcd.setCursor(4,1);
  lcd.print(sensorValue);
  delay(2000);
}
