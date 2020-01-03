#include <SoftwareSerial.h>

//int led = 8;
int boton = 5;

SoftwareSerial mySerial(2, 3);

int estadoBtn = 0;
void setup() {
  mySerial.begin(9600);
  //pinMode(led,OUTPUT);
  pinMode(boton, INPUT);
  Serial.begin(9600);
}

void loop() {
 estadoBtn = digitalRead(boton);

 if(estadoBtn == HIGH){
  mySerial.print("1");
  Serial.println("1");
 }else{
   mySerial.print("0");
  Serial.println("0");
 }
}
