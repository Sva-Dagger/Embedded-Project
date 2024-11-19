//Motor one
int M1 = 2;
int M2 = 3;
int M3 = 4;
int M4 = 5;
#define IN1 7
#define IN2 8

//Motor two
#define IN3 9
#define IN4 10

void setup() {
  //Sensor pins
  pinMode(M1, INPUT);
  pinMode(M2, INPUT);
  pinMode(M3, INPUT);
  pinMode(M4, INPUT);
  //Motor one
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  //Motor two
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

}
void loop() {
  bool SOne = digitalRead(M1);
  bool STwo = digitalRead(M2);
  bool SThree = digitalRead(M3);
  bool SFour = digitalRead(M4);

  if (SOne == 0 && STwo == 1 && SThree == 1 && SFour == 0 ) {
    forward();
  } else if (SOne == 1 && STwo == 1 && SThree == 1 && SFour == 1) {
    Stop();
  } else if (SOne == 0 && STwo == 0 && SThree == 0 && SFour == 0) {
    Stop();
  }  else if (SOne == 1 && STwo == 1 && SThree == 0 && SFour == 0) {
    turnleft();
  } else if (SOne == 0 && STwo == 0 && SThree == 1 && SFour == 1) {
    turnright();
  }
}

void forward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void turnright() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void turnleft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void Stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}