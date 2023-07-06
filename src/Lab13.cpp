/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/michaeljosephcherchi/Desktop/labs/Lab13/src/Lab13.ino"
#include "MQTT.h"
#include "oled-wing-adafruit.h"

void setup();
void loop();
#line 4 "/Users/michaeljosephcherchi/Desktop/labs/Lab13/src/Lab13.ino"
SYSTEM_THREAD(ENABLED);

OledWingAdafruit display;

void callback(char *topic, byte *payload, unsigned int length);

MQTT client("lab.thewcl.com", 1883, callback);

void callback(char *topic, byte *payload, unsigned int length)
{
  Serial.println("Got it");

  char p[length + 1];
  memcpy(p, payload, length);
  p[length] = NULL;
  Serial.printf("%s", p);

  Serial.println("13");
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.printf("%s", p);
  display.println("");
  display.display();
}

void setup()
{
  display.setup();
}

void loop()
{
  if (client.isConnected())
  {
    client.loop();
    delay(10000);
    client.publish("mjcIn13", "Hello13");
  }
  else
  {
    client.connect(System.deviceID());
    client.subscribe("mjcOut13");
  }
}