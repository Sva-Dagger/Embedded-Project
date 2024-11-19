const int relay = 7;
int val = 0, val1 = 0;
void setup() {
  // put your setup code here, to run once:
pinMode(A1, INPUT);
pinMode(A2, INPUT);
pinMode(relay, OUTPUT);
Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
val = analogRead(A1);
val1 = analogRead(A2);
Serial.println("val=");
Serial.println(val);
Serial.println("val1=");
Serial.println(val1);
delay(100);
if(val<10 && val1<10)
{
  digitalWrite(relay, LOW);
  delay(100);
  if(val>10&&val1<10)
{
  digitalWrite(relay, LOW);
  delay(100);
}
}

else if(val>10&&val1>10)
{
  digitalWrite(relay, HIGH);
  delay(100);
}
}
