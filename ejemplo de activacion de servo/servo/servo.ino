#include <Servo.h>
Servo myservo;  // crea el objeto servo

int val = 0;
int pos = 0;
 
void setup() {
  //cambiar pin si corresponde
   myservo.attach(4);  // vincula el servo al pin 4
   Serial.begin(9600);
   //posicion inicial
   myservo.write(0);
  
}
 
void loop() {
  //while
  while(Serial.available()>0)
  {
   char val = Serial.read(); 
     switch (val){
        case '1':
           moverServo();
           break;
      
  
    }
  }
  delay(500);

  
}
void moverServo(){
   for (pos = 0; pos <= 100; pos += 10) 
   {
      myservo.write(pos);              
      delay(2);                       
   }
   delay(900);
   //considerar el tema del sensor en este lugar 
     for (pos = 100; pos >= 0; pos -= 10) 
   {
      myservo.write(pos);              
      delay(2);                       
   }
   if(pos <= 0){
     Serial.println("cerrado");
  }
}
