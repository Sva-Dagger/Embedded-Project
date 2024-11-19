#include <Servo.h>

Servo myMotor;

void setup()
{

myMotor.attach(9);

}

void loop()
{

myMotor.write(100); // can be any value 0 - 180
// nothing happens here!
// switch back to the Turnigy and it works like a charm as I twist the knob.

}
