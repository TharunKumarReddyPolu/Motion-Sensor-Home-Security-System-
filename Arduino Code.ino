#include <ESP8266WiFi.h>
#define BLYNK_PRINT Serial
// Comment this out to disable prints and save space
#include <BlynkSimpleEsp8266.h>
char auth[] = "9kl8MjGTBX9wFp9H-0nOLQz11wQziJWO";

/* WiFi credentials /
char ssid[] = "Sriprahasita";
char pass[] = "**";

/ HC-SR501 Motion Detector */
int ledPin =13; 
int pirPin =5; // Input for HC-S501
int pirValue; // Place to store read PIR Value

void setup()
{
  Serial.begin(9600);
  delay(10);
  Blynk.begin(auth, ssid, pass);
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
  digitalWrite(ledPin, LOW);
}

void loop()
{
  getPirValue();
  Blynk.run();
}
// Get PIR data
void getPirValue(void)
{
  pirValue = digitalRead(pirPin);
  if (pirValue) 
  { 
    Serial.println("==> Motion detected");
    Blynk.notify("T==> Motion detected");
    digitalWrite(ledPin, pirValue);
  }
  else
  {
    Serial.println("++>motion absent");
    digitalWrite(ledPin, pirValue);
  }
}
