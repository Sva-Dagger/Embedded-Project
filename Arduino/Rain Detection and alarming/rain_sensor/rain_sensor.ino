int alarm = 5; //PWM (~) Pin
int rainAnalogPin = A0;
int rainDigitalPin = 3;
int redLED = 4;
void setup(){
  pinMode(rainAnalogPin, INPUT);
  pinMode(rainDigitalPin, INPUT);
  pinMode(alarm, OUTPUT);
  pinMode(redLED, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  // read the input on analog pin 0:
  int sensorAnalogValue = analogRead(rainAnalogPin);
  Serial.print("Rain sensor analog value: ");
  Serial.println(sensorAnalogValue);
  delay(3000);
  
  // read the input on digital pin 2:
  int sensorDigitalValue = digitalRead(rainDigitalPin);
  Serial.print("Rain sensor digital value: ");
  Serial.println(sensorDigitalValue);
  
//digital output
 if(sensorAnalogValue <= 500) //High means rain detected; In some case vise versa
 {
  digitalWrite(redLED, HIGH);
  digitalWrite(alarm, HIGH); //the buzzer sound frequency at 5000 Hz
  Serial.println("Rain Detected");
  delay(1000);
 }
 else {
  digitalWrite(redLED, LOW);
  digitalWrite(alarm, LOW);
  Serial.println("Rain not Detected");
  delay(1000);
 }
}
