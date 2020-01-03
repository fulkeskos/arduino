#include <Wire.h>
int led = 7;
//maestro

void setup() {
  Wire.begin();
  pinMode(led,OUTPUT);
}

void loop() {
  Wire.requestFrom(0x01,1);
  while(Wire.available()){
      char c = Wire.read();
      if(c == '1'){
        digitalWrite(led,HIGH);
        }else{
          digitalWrite(led,LOW);
          }
    }
  // put your main code here, to run repeatedly:

}
