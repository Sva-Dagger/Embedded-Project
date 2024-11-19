const int relay = 7;
int val= 0, val1 = 0;
void setup() {
  // put your setup code here, to run once:\
pinMode(A0, INPUT);
pinMode(relay, OUTPUT);
Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
val = analogRead(A0);
Serial.println("val=");
Serial.println(val);
delay(100);
if(val >= 1)
{
  
{
  Serial.println("Tank full");
  delay(100);
  
}
}

else if(val== 0)
{
  Serial.println("Tank not full");
  delay(100);
}

}
