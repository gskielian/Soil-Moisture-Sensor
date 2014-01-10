//a potentiometer may be used in place of the 56KOhm 
//as a hardware sensitivity dial

volatile long int count=0; // volatile allows it to be changed by the interrupt function

int accumulation_time=10000; //in microseconds

void setup() {
  Serial.begin(9600);

  //interrupt 1 is pin 3 on the Uno
  //attachInterrup(interrupt number, function-to-call, RISING/FALLING/CHANGE)

  attachInterrupt(1, add_to_count, CHANGE);
}

void loop() {

//reset the counter
  count=0;
//allow the counter to accumulate -- higher resistance means more clicks
  delayMicroseconds(accumulation_time);
//print
Serial.println(count);

}

void add_to_count() {
 count++;
}
