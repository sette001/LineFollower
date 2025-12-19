const int LA = 10;
const int LV = 9;
const int RA = 5;
const int RV = 6;
const int vert = 20;

void setup() {
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
}

void loop() {



//vooruit traploos
for (int i = 0; i <=5; i++){//vier modes
  digitalWrite(LV,LOW);
  digitalWrite(LA,LOW);
  digitalWrite(RV,LOW);
  digitalWrite(RA,LOW);

  if (i == 0){
    for (int j = 0; j <=255; j++){//LV
      analogWrite(LV,j);
      delay(vert);
    }
  }else if (i == 1){
    for (int j = 0; j <=255; j++){//RV
      analogWrite(RV,j);
      delay(vert);
    }
  } else if(i == 2){
    for (int j = 0; j <=255; j++){//LA
      analogWrite(LA,j);
      delay(vert);
    }
  }else if (i == 3){
    for (int j = 0; j <=255; j++){//RA
      analogWrite(RA,j);
      delay(vert);
    }
  }else if(i == 4){
    for (int j = 0; j <=255; j++){//LA
      analogWrite(LA,j);
      analogWrite(RA,j);
      delay(vert);
    }
  }else if (i == 5){
    for (int j = 0; j <=255; j++){//RA
      analogWrite(LV,j);
      analogWrite(RV,j);
      delay(vert);
    }
  }
}
}
