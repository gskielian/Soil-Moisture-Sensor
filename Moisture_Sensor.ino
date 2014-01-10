//

volatile long int count=0;
int accumulation_time=10000; //in microseconds

void setup() {
  
  Serial.begin(9600);
  //attachInterrupt(0, add_to_count, RISING);
  attachInterrupt(0, add_to_count, CHANGE); //CHANGE this will ensure to count both RISING and FALLING edges, doubling our sensor's sensitivity
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
