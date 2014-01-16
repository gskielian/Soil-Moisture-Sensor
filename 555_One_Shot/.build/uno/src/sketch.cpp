#include <Arduino.h>
#include <Servo.h>
void setup();
void loop();
#line 1 "src/sketch.ino"
//#include <Servo.h>

Servo hack;

char ch;
unsigned long duration;

void setup()
{
  hack.attach(9);
  pinMode(2,INPUT);
  digitalWrite(4, HIGH);
  Serial.begin(115200);
}

void loop()
{
  if (Serial.available()) {
    ch = Serial.read();
    if (ch == '1') {
      //digitalWrite(4, LOW);
      //digitalWrite(4, HIGH);
      hack.write(180);
      duration = pulseIn(2,HIGH);
      Serial.println(duration);
      duration = pulseIn(2,HIGH);
      Serial.println(duration);
      duration = pulseIn(2,HIGH);
      Serial.println(duration);
      delay(3000);
    }
    else {
    delay(1);
    }
  }
}

