/*
Developed for an Arduino-based remote-controlled car. The provided code 
utilizes a 4-button setup for backward and forward motion of the two motors.
the motors used are VEX-robotics based (servo based.)

improvements were made but not in this set of code to use a bluetooth
adapter to receive movement commands from the controller to the arduino.
*/

#include <Servo.h>
Servo MotorL;
Servo MotorR;
//declaration of motors as a type of servo, accessing of the servo library
int LeftForward = 0;
int LeftBackward = 0;
//declaring the directions and values
int RightForward = 0;
int RightBackward = 0;

const int MF = 120;  // angle that moves motor forward
const int MB = 70; // angle that moves motor backward
const int MS = 179; // angle that stops the motor

void setup()
{
  MotorL.attach(10);
  MotorR.attach(11);
  
//setting up buttons and motor ports
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
}

void loop()
{
  int x;
  LeftForward = digitalRead(2);
  LeftBackward = digitalRead(3);

  RightForward = digitalRead(4);
  RightBackward = digitalRead(5);

//motor commands, if button x = whatever, turn on. if not, turn off
  if (LeftForward == HIGH)
  {
    MotorL.write(MF); // move forward
  }
  else
  {
    MotorL.write(MS);
  }

  if (LeftBackward == HIGH)
  {
    MotorL.write(MB); // move backward
  }

  if (RightForward == HIGH)
  {
    MotorR.write(MF); // move forward
  }

else 
{
  MotorR.write(MS);
}

  if (RightBackward == HIGH)
  {
    MotorR.write(MB); // move backward
  }
  
}
