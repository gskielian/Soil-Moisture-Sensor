void setup() {

  Serial.begin(115200);

}


void loop() {

  Serial.println("testing pre measurement");
  Serial.println(analogRead(1));

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
  Serial.println("measurement stabilizing");
  Serial.println(analogRead(1));

//LAST we set all pins to 0V to remove hysterisis

  digitalWrite(14,LOW);
  pinMode(16,OUTPUT);
  digitalWrite(16,LOW);

//this delay allows the charge to fully drain to gnd (should be fairly rapid

  delay(1000);

}
