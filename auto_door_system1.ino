// C++ code
//
#include <Servo.h>

int integrated_door = 0;

int i = 0;

int j = 0;

int servo_motor = 0;

int k = 0;

int m = 0;

int n = 0;

int o = 0;

int p = 0;

int q = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

Servo servo_7;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
  servo_7.attach(7, 500, 2500);
}

void loop()
{
  integrated_door = 0.01723 * readUltrasonicDistance(4, 4);
  servo_motor = 0;
  digitalWrite(13, HIGH);
  digitalWrite(11, LOW);
  if (integrated_door <= 50) {
    for (servo_motor = 0; servo_motor <= 90; servo_motor += 1) {
      digitalWrite(13, LOW);
      digitalWrite(11, HIGH);
      servo_7.write(90);
    }
  } else {
    for (servo_motor = 90; servo_motor >= 0; servo_motor -= 1) {
      digitalWrite(13, HIGH);
      digitalWrite(11, LOW);
      servo_7.write(0);
    }
  }
  delay(10); // Delay a little bit to improve simulation performance
}