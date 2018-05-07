#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial finn(10, 11); // RX | TX

Servo base, onBase, arm, fing;

String Str = "";

//pin number
const int basePin = 9;
const int onbasePin = 6;
const int armPin = 7;
const int fingPin = 12;

//servo positions
int basePos = 60;
int onbasePos = 60;
int armPos = 60;
int fingPos = 60;

void setup() {
  base.attach(basePin);
  onBase.attach(onbasePin);
  arm.attach(armPin);
  fing.attach(fingPin);

  base.write(basePos);
  onBase.write(onbasePos);
  arm.write(armPos);
  fing.write(fingPos);

  Serial.begin(9600);
  finn.begin(9600);
}

//void init(int code) {
//  if ((basePos > 0 && basePos < 120) &&
//      (onbasePos > 0 && onbasePos < 120) &&
//      (armPos > 0 && armPos < 120) &&
//      (fingPos > 0 && fingPos < 120)) {
//    if (code == 1) {
//      base.write(basePos - 1);
//      delay(10);
//    }
//
//    else if (code == 2) {
//      onBase.write(onbasePos - 1);
//      delay(10);
//    }
//
//    else if (code == 3) {
//      arm.write(armPos - 1);
//      delay(10);
//    }
//
//    else if (code == 4) {
//      fing.write(fingPos - 1);
//      delay(10);
//    }
//    else if (code == -1) {
//      base.write(basePos + 1);
//      delay(10);
//    }
//
//    else if (code == -2) {
//      onBase.write(onbasePos + 1);
//      delay(10);
//    }
//
//    else if (code == -3) {
//      arm.write(armPos + 1);
//      delay(10);
//    }
//
//    else if (code == -4) {
//      fing.write(fingPos + 1);
//      delay(10);
//    }
//  }
//  else {
//
//  }
//}
//
////********************************************
//
//void reset() {
//  basePos = 60;
//  onbasePos = 60;
//  armPos = 60;
//  fingPos = 60;
//}
////----------------------------------------------------


void loop() {
  if (finn.available()) {
    char unit = finn.read();
    if (isDigit(unit)){
      Str += unit;
    }
    if (unit == 'b'){
      basePos = Str.toInt();
      base.write(basePos);
      Serial.print("basePos: ");
      Serial.println(basePos);
      Str = "";
    }
    else if (unit == 'o'){
      onbasePos = Str.toInt();
      onBase.write(onbasePos);
      Serial.print("onbasePos: ");
      Serial.println(onbasePos);
      Str = "";
    }
    else if (unit == 'a'){
      armPos = Str.toInt();
      arm.write(armPos);
      Serial.print("armPos: ");
      Serial.println(armPos);
      Str = "";
    }
    else if(unit == 'e') {
      fing.write(90);
      Serial.println("disengaged...");
    }
    else if(unit == 'd') {
      fing.write(30);
      Serial.println("engaged...");
    }
    else if (unit == 'x')
    {
      //do nothing
    }
  }

  

//  if (Serial.available()) {
//    finn.write(Serial.read());
//    Serial.write("\n");
//  }
}
