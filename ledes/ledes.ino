void setup() {
 Serial.begin(9600);
 pinMode(7,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(3,OUTPUT);

}
bool led1 = false;
bool led2 = false;
bool led3 = false;

void loop() {
  while(Serial.available()>0){
    char val = (char) Serial.read();
    switch(val){
      case '1':
        led1 = !led1;
        digitalWrite(7,led1 ? HIGH : LOW);
        break;
      case '2':
        led2 = !led2;
        digitalWrite(5,led2 ? HIGH : LOW);
        break;
      case '3':
        led3 = !led3;
        digitalWrite(3,led3 ? HIGH : LOW);
        break;
      }}
  
}
