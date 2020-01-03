#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3);
int led = 8;

void setup() {
  mySerial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  while(mySerial.available()>0){
   char veri = mySerial.read();
    if (veri == '1'){
      digitalWrite(led,HIGH);
      }else{
        digitalWrite(led, LOW);
      }
    }
}
