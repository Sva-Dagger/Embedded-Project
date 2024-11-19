#include<Wire.h>
const int MPU=0x68; 
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
int led1=2; // Pin numbers to arduino
int led2=3;
int led3=4;

void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B); 
  Wire.write(0);    
  Wire.endTransmission(true);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  Serial.begin(9600);
}
void loop(){
  
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,12,true);  
  AcX=Wire.read()<<8|Wire.read();    
  AcY=Wire.read()<<8|Wire.read();  
  AcZ=Wire.read()<<8|Wire.read();  
  GyX=Wire.read()<<8|Wire.read();  
  GyY=Wire.read()<<8|Wire.read();  
  GyZ=Wire.read()<<8|Wire.read(); 
if (AcX>10000)
 {
  Serial.print("AcX = ");
  Serial.print(AcX);
  Serial.print(" | GyX = ");
  Serial.print(GyX);
  digitalWrite(led1, HIGH);
 }
  else
  digitalWrite(led1, LOW);
 if (AcY>10000)
 {
  Serial.print("AcY = ");Serial.print(AcY);
  Serial.print(" | GyY = ");Serial.print(GyY);
  digitalWrite(led2, HIGH);
 }
  else
  digitalWrite(led2, LOW);
 if (AcZ>10000)
 {
  Serial.print("AcZ = ");Serial.print(AcZ);
  Serial.print(" | GyZ = ");
  Serial.print(GyZ);
  digitalWrite(led3, HIGH);
 }
  else
  digitalWrite(led3, LOW);
  delay(333);
}
