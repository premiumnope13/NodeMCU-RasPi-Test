#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

const int trigPin = 2;  //D4
const int echoPin = 0;  //D3

// defines variables
long duration;
int distance;

#define FIREBASE_HOST ""
#define FIREBASE_AUTH ""
#define WIFI_SSID ""
#define WIFI_PASSWORD ""

long randNumber;
unsigned long curentmilis;
int interval=1000;
unsigned long previousMillis=0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
 
  while (WiFi.status() != WL_CONNECTED) {
    
    Serial.print(".");
    delay(500);
  }
  
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  }

  

  int n = 0;
  

  
void loop() {


  // get value
  n = Firebase.getInt("LED_STATUS");
  // handle error
  
  if (n==1) {
    Serial.println("LED ON");
    digitalWrite(LED_BUILTIN,LOW);  
  }

  else {
    Serial.println("LED OFF");
    digitalWrite(LED_BUILTIN,HIGH);  
  }

    digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  Firebase.set("ULTRASONIC",distance);   
  delay(100);
}
