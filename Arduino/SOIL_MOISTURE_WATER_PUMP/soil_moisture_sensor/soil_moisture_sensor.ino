int sensorPin = A0; 
int sensorValue;  

void setup() {
 Serial.begin(9600);
 pinMode(7, OUTPUT);
}

void loop() {

 sensorValue = analogRead(sensorPin);
 
 if (sensorValue<300) { 
  
 Serial.println("Sensor reached water");
 digitalWrite(7, HIGH);
  delay(1000);
 }
  else if (sensorValue>=300 & sensorValue<=600 ) {    
    Serial.println("Soil is Humid");
    digitalWrite(7, HIGH);
  delay(1000);
  }
 else {
  
 Serial.println("Soil is dry");
 digitalWrite(7, LOW);
  delay(5000);
 } 
}
