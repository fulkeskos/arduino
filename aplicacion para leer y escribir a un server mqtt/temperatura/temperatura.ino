#include <LM35.h>

LM35 lm35(0);

void setup() {
  Serial.begin(9600);
}

void loop() {
  float t = lm35.getTemp();
  Serial.println(t);
  delay(40);

}
