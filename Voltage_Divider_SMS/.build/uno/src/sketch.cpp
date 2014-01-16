#include <Arduino.h>

void setup();
void loop();
void forward_measurement();
void reverse_measurement();
#line 1 "src/sketch.ino"
char ch;
void setup() {
  Serial.begin(115200);
}


void loop() {

  if (Serial.available()) {
    ch = Serial.read();
    if (ch == '1') {
      forward_measurement();
    } else if (ch == '2') {
      reverse_measurement();
    } else {
      delay(1);
    }
  }

}




void forward_measurement() {

//this was here for debugging
//Serial.println("testing pre measurement");
//Serial.println(analogRead(1));

//FIRST we make the voltage divider

//16 to be an input (not really necessary the first time)
pinMode(16, INPUT);

//we set 14 and 18 (aka a0 and a4) to outputs
pinMode(14, OUTPUT);
digitalWrite(14,HIGH);

pinMode(18, OUTPUT);
digitalWrite(18,LOW);

//NEXT we poll for voltage reading
delay(500);
Serial.print("Forward Measurement, "); Serial.println(analogRead(1));

//LAST we set all pins to 0V to remove hysterisis

digitalWrite(14,LOW);
pinMode(16,OUTPUT);
digitalWrite(16,LOW);

//will do in python a 1 second delay here

}


void reverse_measurement() {

  Serial.println("testing pre measurement");
  Serial.println(analogRead(1));

  //FIRST we make the voltage divider

  //16 to be an input (not really necessary the first time)
  pinMode(16, INPUT);

  //we set 14 and 18 (aka a0 and a4) to outputs
  pinMode(14, OUTPUT);
  digitalWrite(14,LOW);

  pinMode(18, OUTPUT);
  digitalWrite(18,HIGH);

  //NEXT we poll for voltage reading
  delay(500);
  Serial.print("Reverse_Measurement"); Serial.println(1023-analogRead(1));

  //LAST we set all pins to 0V to remove hysterisis

  digitalWrite(18,LOW);
  pinMode(16,OUTPUT);
  digitalWrite(16,LOW);

  //again a python delay of one second goes after this
}
