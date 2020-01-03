#include <Wire.h>
//esclavo 
int boton = 8;
int estadoBtn = 0;

void setup() {
  pinMode(boton,INPUT);
  Wire.begin(0x01);
  Wire.onRequest(orden);
  Serial.begin(9600);
  
}

void loop() {
 
}


void orden(){
  estadoBtn = digitalRead(boton);  
  if(estadoBtn == HIGH){
    Wire.write("1");
    Serial.println("1");
    }else{
     Wire.write("0");
     Serial.println("0");
    }
}
