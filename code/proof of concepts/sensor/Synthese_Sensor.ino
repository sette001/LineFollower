
void setup() {
  Serial.begin(9600);
}

void loop() {
Serial.println();
Serial.print("sensor 1:"); 
Serial.println(analogRead(A1)); 
Serial.print("sensor 2:"); 
Serial.println(analogRead(A2)); 
Serial.print("sensor 3:"); 
Serial.println(analogRead(A3)); 
Serial.print("sensor 4:"); 
Serial.println(analogRead(A4)); 
Serial.print("sensor 5:"); 
Serial.println(analogRead(A5)); 
Serial.print("sensor 6:"); 
Serial.println(analogRead(A6)); 
Serial.print("sensor 7:"); 
Serial.println(analogRead(A7)); 
Serial.println();
delay(5000);
}
