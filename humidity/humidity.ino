#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"           
#include <SimpleTimer.h>  
#define DHTTYPE DHT11      
#define dht_dpin 14
DHT dht(dht_dpin, DHTTYPE); 
SimpleTimer timer;
char auth[] = "47c9d3d8bc924cc1b592cd64d63dss23";                       
char ssid[] = "TPLINK1236";    
char pass[] = "pass12365478";  

float h;

void setup()
{
    Serial.begin(9600);
    Blynk.begin(auth, ssid, pass);
    dht.begin();
    timer.setInterval(2000, sendUptime);
}

void sendUptime()
{
  float h = dht.readHumidity();
  Serial.print("Current humidity = ");
  Serial.print(h);
  Blynk.virtualWrite(V1, h);
}

void loop()
{
  Blynk.run();
  timer.run();
}
