#include <LM35.h>
#include <SoftwareSerial.h>

int led = 13;
LM35 sensorT(1);
//0 el potenciometro
String poten = "";
String tempu = "";
//3 RX 2 TX
SoftwareSerial serialArduino(3, 2);

void setup() {
  pinMode(led, OUTPUT);
  digitalWrite(led,LOW);
  serialArduino.begin(9600);
  Serial.begin(9600);

}

void loop() {
  int pote = analogRead(0);
  poten = (String) pote;
  float t = sensorT.getTemp();
  tempu = (String) t;
  String tempote = (tempu +  ";" + poten);

  serialArduino.print(tempote);
  //Serial.write(tempote);
  //Serial.println(tempote);.
  
  

  if (serialArduino.available() > 0) {
    char prenderLed = serialArduino.read();
    Serial.print(prenderLed);
    if (prenderLed == '1') {
      digitalWrite(led, HIGH);
    } else if(prenderLed == '0') {
      digitalWrite(led, LOW);
      
    }
  }
  delay(1000);
}
