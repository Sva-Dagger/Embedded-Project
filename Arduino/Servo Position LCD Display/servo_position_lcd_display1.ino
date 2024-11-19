#include <LiquidCrystal_I2C.h>
#include <Servo.h>
	
LiquidCrystal_I2C lcd(0x27, 20, 4);
Servo myservo;

void write_angle_lcd(int pos)
{
	lcd.setCursor(0, 1);
	lcd.print(pos);
	lcd.print(" ");
}

void setup(){
	myservo.attach(9);
	lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
	lcd.print("SERVO ANGLE");
	lcd.setCursor(0, 1);
}
void loop(){
	int pos; 
	for(pos = 0; pos <= 180; pos += 1){
	myservo.write(pos);
	write_angle_lcd(pos);
	delay(50);
	} 
	for(pos = 180; pos >= 0; pos -= 1){                       
	myservo.write(pos);
	write_angle_lcd(pos);
	delay(50);
	} 
}

 