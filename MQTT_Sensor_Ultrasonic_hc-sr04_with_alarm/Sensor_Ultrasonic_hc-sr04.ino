// include external method
#include <DHT.h>   
#include <WiFi.h>
#include <PubSubClient.h>

#define echoPin 19 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 18 //attach pin D3 Arduino to pin Trig of HC-SR04
#define LED_BUILTIN 2

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
int jarak1;
int jarak2;
char str_value[8];
const char *SSID = "WIFI";
const char *PASSWORD = "12345678";
const char* mqttServer= "soldier.cloudmqtt.com";
const int mqttPort = 13836;
const char* mqttUser = "username";
const char* mqttPassword = "password";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  pinMode(LED_BUILTIN, OUTPUT);
  WiFi.disconnect(true);
  delay(2000);
  connectToHotSpot();
  connectToMqttCloud();
}
void loop() {
  connectToMqttCloud();
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  sprintf(str_value,"%6.2f", distance);
  client.publish("TINGGI_AIR", str_value);
  if(distance<10){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
  }else{
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
  }
  delay(2000);

}

void connectToHotSpot() {
  WiFi.begin( SSID, PASSWORD );
  Serial.print("Trying to establish connection to WiFi Router");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("Connected! IP: ");
  Serial.println(WiFi.localIP());
}

void connectToMqttCloud() {
  client.setServer(mqttServer, mqttPort);
  while ( !client.connected() ) {
    if (client.connect("ESP32Client", mqttUser, mqttPassword )) {
      Serial.println("MQTT Successfull Connected");
    } else {
      Serial.println("Still Try..");
      delay(5000); // coba 5 detik lagi
    }
  }
}
