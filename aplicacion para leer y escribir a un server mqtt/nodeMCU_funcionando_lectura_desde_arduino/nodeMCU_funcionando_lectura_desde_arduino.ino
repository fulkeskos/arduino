#include <ESP8266WiFi.h>
#include <PubSubClient.h>


const char* ssid = "estay_isp";
const char* password = "123456789";
const char* mqtt_server = "192.168.0.106";


WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg1[50];
char msg2[50];
int value = 0;
String temp = "";
String pote = "";
void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  /*Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  */
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    //Serial.print(".");
  }

  randomSeed(micros());

  /*Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  */
}

void callback(char* topic, byte* payload, unsigned int length) {
  char* limite = "/";
  /*Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.println("] ");
  */
  char* texto = strtok(topic, limite);
  int longi = strlen(texto);
  //suelta el primero
  //Serial.print(texto[longi-1]);  
 
  for (int i = 0; i < length; i++) {
    //Serial.println((char)payload[i]);
  }

  if((char)payload[0] == '1'){
    Serial.println('1');
    }else{
      Serial.println('0');
    }
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      // Once connected, publish an announcement...
    //  client.publish("outTopic", "hello world");
      // ... and resubscribe
      client.subscribe("/grupo3/led");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(9600);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}


String split(String data, char separator, int index) {
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length() - 1;
  
  for(int i=0; i <= maxIndex && found <=index ; i++){
  if(data.charAt(i) == separator || i==maxIndex){
  found++;
  strIndex[0] = strIndex[1]+1;
  strIndex[1] = (i == maxIndex) ? i+1 : i;
   }
  }

return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  //if serial available creo revisar que wea 
  while(Serial.available()>0){
      Serial.readString();
      String data = Serial.readString();
      temp = split(data,';',0);
      pote = split(data,';',1);
      //Serial.println(temp + "---" + pote);
      
    }
    temp.toCharArray(msg1,50);
    pote.toCharArray(msg2,50);
    
    client.publish("/grupo3/temperatura",msg1);
    client.publish("/grupo3/potenciometro",msg2);
  
    
    delay(1000);  
}
