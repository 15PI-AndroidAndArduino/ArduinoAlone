#include <SPI.h>
#include <WiFi101.h>

const int LED = 6;
const int BUTTON = 5;
const int LED1 = 7;
const int BUTTON1 = 4;
const int LED2 = 8;
const int BUTTON2 = 3;
const int LED3 = 9;
const int BUTTON3 = 2;

char ssid[] = SSID;     //  your network SSID (name) 
char pass[] = password;    // your network password
int status = WL_IDLE_STATUS;     // the Wifi radio's status
WiFiServer server(80);

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(BUTTON1, INPUT);
  pinMode(LED2, OUTPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(LED3, OUTPUT);
  pinMode(BUTTON3, INPUT);

    // initialize serial:
  Serial.begin(9600);
  // attempt to connect using WPA2 encryption:
  Serial.println("Attempting to connect to WPA network...");
  status = WiFi.begin(ssid, pass);
  // if you're not connected, stop here:
  if ( status != WL_CONNECTED) { 
    Serial.println("Couldn't get a wifi connection");
    while(true);
  } 
  // if you are connected, print out info about the connection:
  else {
    server.begin();
    Serial.print("Connected to wifi. My address:");
    IPAddress myAddress = WiFi.localIP();
    Serial.println(myAddress);
  }
  Serial.println(LED);
}

void loop() {
  int LedToSend = 0;
  WiFiClient client = server.available();
  // put your main code here, to run repeatedly:
  if(digitalRead(BUTTON) == LOW)
  {
    digitalWrite(LED,LOW);
  }
  else
  {
    digitalWrite(LED, HIGH);
    LedToSend = LED;
  }
   if(digitalRead(BUTTON1) == LOW)
  {
    digitalWrite(LED1,LOW);
  }
  else
  {
    digitalWrite(LED1, HIGH);
    LedToSend = LED1;
  }
   if(digitalRead(BUTTON2) == LOW)
  {
    digitalWrite(LED2,LOW);
  }
  else
  {
    digitalWrite(LED2, HIGH);
    LedToSend = LED2;
  }
  if(digitalRead(BUTTON3) == LOW)
  {
    digitalWrite(LED3,LOW);
  }
  else
  {
    digitalWrite(LED3, HIGH);
    LedToSend = LED3;
  }
  Serial.println("sended");
  Serial.println(LedToSend);
  // listen for incoming clients
  if (client)
  {
    if (client.connected())
    {
      server.write(LedToSend);
    }
  }
}
