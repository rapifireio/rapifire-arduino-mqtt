#include <YunClient.h>
#include <PubSubClient.h>
#include <RapifireMqtt.h>

#define THING_ID "YOUR_THING_ID"
#define THING_KEY "YOUR_THING_KEY"
#define DATA_TOPIC "YOUR_DATA_TOPIC"

YunClient client;

RapifireMqtt rapifire(THING_ID, THING_KEY, DATA_TOPIC, client);
int counter = 0;

void setup() {
  Serial.begin(9600);
  
  Serial.println(F("Starting bridge..."));
  Bridge.begin();
  
  Serial.println(F("Bridge ready."));
}

void loop() {
  if (!rapifire.connected()) {
    Serial.println(F("Connecting to RAPIFIRE.."));

    if (rapifire.connect()) {
      Serial.println(F("Connected."));
    }
  }

  rapifire.addValue("test", "", counter++);
  rapifire.publish();

  Serial.print("counter: ");
  Serial.println(counter);

  delay(1000);
}

