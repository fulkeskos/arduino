#include <LM35.h>

int ledRojo = 7;
int ledVerde = 3;
int buzzer = 11;
LM35 sensorT(0);

void setup() {
  pinMode(ledRojo,OUTPUT);
  pinMode(ledVerde,OUTPUT);
  Serial.begin(9600);
}

void loop() {
 float t = sensorT.getTemp();
 Serial.println(t);
 delay(20);
 if(t < 20){
    digitalWrite(ledVerde,HIGH);
    digitalWrite(ledRojo,LOW);
    noTone(buzzer);
  }else{
    digitalWrite(ledVerde,LOW);
    digitalWrite(ledRojo,HIGH);  
    tone(buzzer,440);
  }
}
