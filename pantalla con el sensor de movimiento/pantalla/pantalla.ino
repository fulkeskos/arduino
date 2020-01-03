#include <LiquidCrystal.h>
const int LEDPin = 13;        // pin para el LED
const int PIRPin = 8;         // pin de entrada (for PIR sensor)
 
int pirState = LOW;           // de inicio no hay movimiento
int val = 0;                  // estado del pin
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() 
{

   pinMode(LEDPin, OUTPUT); 
   pinMode(PIRPin, INPUT);
   Serial.begin(9600);
   lcd.begin(16,2);
}
 
void loop()
{
   val = digitalRead(PIRPin);
   if (val == HIGH)   //si está activado
   { 
      digitalWrite(LEDPin, HIGH);  //LED ON
      if (pirState == LOW)  //si previamente estaba apagado
      {
        Serial.println("Sensor activado");
        if(Serial.available()>0){
          String textoRecibido = Serial.readString();
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print(textoRecibido);
          
          }
        pirState = HIGH;
        
      }
   } 
   else   //si esta desactivado
   {
      digitalWrite(LEDPin, LOW); // LED OFF
      if (pirState == HIGH)  //si previamente estaba encendido
      {
        
        Serial.println("Sensor parado");
        lcd.setCursor(0,0);
        lcd.clear();
        lcd.print("sensor, off");  
        pirState = LOW;
      }
   }
}
