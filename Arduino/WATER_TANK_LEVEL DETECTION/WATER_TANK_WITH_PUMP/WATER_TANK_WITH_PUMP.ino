const int buzzer = 3, led = 4, led1 = 5;
int val;
int val1;

void setup() {
  // put your setup code here, to run once:
val = 0;
val1 = 0;
pinMode(A0, INPUT);
pinMode(A1, INPUT);
pinMode(buzzer, OUTPUT);
pinMode(led, OUTPUT);
pinMode(led1, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
val = analogRead("val:"A0);
val1 = analogRead("val1:"A1);
Serial.println(val);

Serial.println(val1);
if(val > 18)
{
  digitalWrite(buzzer, HIGH);
  digitalWrite(led, HIGH);
  digitalWrite(led1, LOW);
  delay(100);
  
  digitalWrite(buzzer, LOW);
  digitalWrite(led, LOW);
  digitalWrite(led1, LOW);
  delay(100);
}
else
{
  digitalWrite(buzzer, LOW);
  digitalWrite(led, LOW);
  digitalWrite(led1, HIGH);
}
}
