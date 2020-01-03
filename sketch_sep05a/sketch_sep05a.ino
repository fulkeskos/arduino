const int botonpin = 5;
const int ledBtnpin = 8;
int estadoBoton = 0;

void setup() {
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(ledBtnpin,OUTPUT);
pinMode(botonpin,INPUT);  
//supongo ingresar el boton de input
Serial.begin(9600);
}

void loop() {
  int sensor = analogRead(0);
  Serial.println(sensor);
  delay(100);
  if(sensor >= 255){
    digitalWrite(2, HIGH);
  }else{
    digitalWrite(2, LOW);
    }
  if(sensor >= 511){
    digitalWrite(3,HIGH);
    }else{
      digitalWrite(3,LOW);
    }
  if(sensor >= 767){
    digitalWrite(4,HIGH);
    } else{
    digitalWrite(4,LOW);
    }
  estadoBoton = digitalRead(botonpin);

  if (estadoBoton == HIGH){
    digitalWrite(ledBtnpin,HIGH);
    }else{
    digitalWrite(ledBtnpin,LOW);
    }
    
}
