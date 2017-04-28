#include <Servo.h>

Servo backServo, rightServo, leftServo;
String inputString = "";         
boolean stringComplete = false;
int backSpeed = 3;
int rlSpeed = 2;
int posBack = 90;
int posRL = 20;

void setup() {
  Serial.begin(9600);
  inputString.reserve(20);
  backServo.attach(6);
  leftServo.attach(7);
  rightServo.attach(5);
  backServo.write(posBack);
  leftServo.write(posRL);
  rightServo.write(posRL);
}

void loop() {
  delay(100);
}

void serialEvent() {
  inputString = "";
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;
  }
  if (inputString.charAt(0)=='l')
  {
    if (posBack <= (175-backSpeed)) posBack = posBack + backSpeed;
    backServo.write(posBack);
  } else if (inputString.charAt(0)=='r') 
  {
    if (posBack >= (5+backSpeed)) posBack = posBack - backSpeed;
    backServo.write(posBack);
  }
  if (inputString.charAt(1)=='d')
  {
    if (posRL <= (175-rlSpeed)) posRL = posRL + rlSpeed;
    leftServo.write(posRL);
    rightServo.write(posRL);
  } else if (inputString.charAt(1)=='u')
  {
    if (posRL >= (5+rlSpeed)) posRL = posRL - rlSpeed;
    leftServo.write(posRL);
    rightServo.write(posRL);
  }
  Serial.flush(); 
}
