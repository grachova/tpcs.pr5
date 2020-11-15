#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

char auth[] = "47c9d3d8bc924cc1b592cd64d63dss23";

char ssid[] = "TPLINK1236";
char pass[] = "pass12365478";

Servo servo;

BLYNK_WRITE(V3)
{
  servo.write(param.asInt());
}

void setup()
{

  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);

  servo.attach(9);
}

void loop()
{
  Blynk.run();
}
