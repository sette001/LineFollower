const int inputs[] = {A0,A1,A2,A3,A4,A5,A6,A7};//sensore
const byte stop = 3;  

const int outputs [] = {5,6,9,10,13,11};
const byte RA = 5; //motoren
const byte RV = 6;
const byte LV = 9;
const byte LA = 10;

const byte LED = 13; //Ledpin
const byte LEDIR =11; //IRLED

volatile bool start = false; //intr
volatile unsigned long vorigeStop  = 0;
const unsigned long debounce = 200; 

int sensorWaarde[8];//uitlezen sensoren
int tresH = 800;
float Kp = 0.079;//proportioneel
int power = 60;

float Kd = 0.027;       //diffirentieel
float prevError = 0;
unsigned long prevTime = 0;

int linksV =0;//snelheden
int rechtsV =0;

void setup() {
  attachInterrupt(digitalPinToInterrupt(stop),stopISR,FALLING); //intr
  for(byte i =0 ;i <= 7;i++){//inputs
  pinMode(inputs[i],INPUT);
  }
  for(byte i =0; i <= 5;i++){//outputs
  pinMode(outputs[i],OUTPUT);
  }
  pinMode(stop,INPUT);
  digitalWrite(LEDIR,HIGH);

  power = map(power,0,100,0,255);
  LEDSeq(); //visu 
}

void loop() {
digitalWrite(LED,start);

if (start) {//start
  int positie = sensorUit();

  if(positie != 5000 ){
    unsigned long now = millis();
    float dt = (now - prevTime) / 1000;
    if (dt <= 0) dt = 0.001;   
    float diff = (positie - prevError) / dt;
    int corr =(int) (Kp * positie + Kd * diff);
    prevError = positie;
    prevTime = now;

    corr = constrain(corr,-510,+255);
    linksV = power - corr;
    rechtsV = power + corr;

    linksV = constrain(linksV,-255,255);
    rechtsV = constrain(rechtsV,-255 ,255);

    if(linksV >=0){
      analogWrite(LA,0);
      analogWrite(LV,linksV);
    }else{
      analogWrite(LV,0);
      analogWrite(LA,(-linksV));
    }
    
    if(rechtsV >=0){
      analogWrite(RA,0);
      analogWrite(RV,rechtsV);
    }else{
      analogWrite(RV,0);
      analogWrite(RA,(-rechtsV));
    }
  }else if (linksV > rechtsV ){//lijn kwijt
      analogWrite(LA,0);
      analogWrite(LV,200);
      analogWrite(RV,0);
      analogWrite(RA,200);

  }else if (linksV < rechtsV ){
     analogWrite(LA,200);
      analogWrite(LV,0);
      analogWrite(RV,200);
      analogWrite(RA,0);
  }   
} else {//stop
    digitalWrite(RA,LOW);
    digitalWrite(RV,LOW);
    digitalWrite(LA,LOW);
    digitalWrite(LV,LOW);
  }
}

int sensorUit(){ //sensorwaarden lezen 
long somTot = 0;
int som = 0;

for (byte i = 0; i <= 7; i++) {
    sensorWaarde[i] = analogRead(inputs[i]);

    if (sensorWaarde[i] > tresH) {
      int gewicht = (i * 1000) - 3500;  // center = 0
      somTot += gewicht;
      som++;
    }
  }
  if (som == 0) {
    // lijn kwijt
    return 5000;
  }
  return somTot / som;
}

void stopISR() { //intr
  unsigned long time = millis();
  
  if (time - vorigeStop > debounce) {//debounce
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
