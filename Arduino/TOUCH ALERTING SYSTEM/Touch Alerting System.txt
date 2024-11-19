/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-touch-sensor-piezo-buzzer
 */

const int TOUCH_SENSOR_PIN = 7; // Arduino pin connected to touch sensor's pin
const int BUZZER_PIN       = 3; // Arduino pin connected to Buzzer's pin

void setup() {
  Serial.begin(9600);               // initialize serial
  pinMode(TOUCH_SENSOR_PIN, INPUT); // set arduino pin to input mode
  pinMode(BUZZER_PIN, OUTPUT);      // set arduino pin to output mode
}

void loop() {
  int touchState = digitalRead(TOUCH_SENSOR_PIN); // read new state

  if (touchState == HIGH) {
    Serial.println("The sensor is being touched");;
    digitalWrite(BUZZER_PIN, HIGH); // turn on Piezo Buzzer
  }
  else
  if (touchState == LOW) {
    Serial.println("The sensor is untouched");
    digitalWrite(BUZZER_PIN, LOW);  // turn off Piezo Buzzer
  }
}
