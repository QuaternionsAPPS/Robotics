#include <AFMotor.h>
AF_DCMotor motorlu(4);
AF_DCMotor motorld(1);
AF_DCMotor motorrd(2);
AF_DCMotor motorru(3);

void setup() {
  // put your setup code here, to run once:
// turn on motor
    motorlu.setSpeed(200);
    motorld.setSpeed(200);
    motorru.setSpeed(200);
    motorrd.setSpeed(200);
    motorlu.run(RELEASE);
    motorld.run(RELEASE);
    motorru.run(RELEASE);
    motorrd.run(RELEASE);
}
void right() {
  motorlu.setSpeed(50);
  motorld.setSpeed(50);
  motorru.setSpeed(50);
  motorrd.setSpeed(50);
  motorlu.run(FORWARD);
  motorld.run(FORWARD);
  motorrd.run(BACKWARD);
  motorru.run(BACKWARD);
}

void left() {
  motorlu.setSpeed(200);
  motorld.setSpeed(200);
  motorru.setSpeed(200);
  motorrd.setSpeed(200);
  motorlu.run(BACKWARD);
  motorld.run(BACKWARD);
  motorrd.run(FORWARD);
  motorru.run(FORWARD);
}
 
 void stap() {
  motorlu.setSpeed(200);
  motorld.setSpeed(200);
  motorru.setSpeed(200);
  motorrd.setSpeed(200);
  motorlu.run(RELEASE);
  motorld.run(RELEASE);
  motorru.run(RELEASE);
  motorrd.run(RELEASE);
}

void forward() {
  motorlu.setSpeed(200);
  motorld.setSpeed(200);
  motorru.setSpeed(200);
  motorrd.setSpeed(200);
  motorlu.run(FORWARD);
  motorlu.run(FORWARD);
  motorlu.run(FORWARD);
  motorlu.run(FORWARD);
}

void loop() {
  // put your main code here, to run repeatedly:
 forward();
 delay(1000);
 stap();
 delay(50);
 right();
 delay(500);
 forward();
 delay(50);
 left();
}
