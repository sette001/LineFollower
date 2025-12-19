
const byte stop = 3;   //int

const byte LED = 13; //Ledpin

volatile bool start = false; //intr
volatile unsigned long vorigeStop  = 0;
const unsigned long debounce = 200; 

void setup() {
  attachInterrupt(digitalPinToInterrupt(stop),stopISR,FALLING); //intr
  pinMode(3,INPUT);
  pinMode(13,OUTPUT);
   
  LEDSeq(); //visu 
}

void loop() {
  if (start) {
    digitalWrite(13,1);
} else {
    digitalWrite(13,0);
   
  }
}




void stopISR() { //intr
  unsigned long time = millis();

  // Debounce
  if (time - vorigeStop > debounce) {
    start = !start;  //start-sto
    vorigeStop = time;
  }
}

void LEDSeq() { //visu

digitalWrite(LED,LOW);
delay(500);
digitalWrite(LED,HIGH);
delay(500);
digitalWrite(LED,LOW);
delay(500);
digitalWrite(LED,HIGH);
delay(1000);
digitalWrite(LED,LOW);
delay(500);
digitalWrite(LED,HIGH);
delay(500);
digitalWrite(LED,LOW);
}
