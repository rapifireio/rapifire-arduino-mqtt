#include <YunClient.h>
#include <PubSubClient.h>
#include <RapifireMqtt.h>
#include <DHT.h>

#define THING_ID "YOUR THING ID"
#define THING_KEY "YOUR THING KEY"
#define DATA_TOPIC "YOUR DATA TOPIC"

#define DHTPIN 2
#define DHTTYPE DHT21

YunClient yunClient;
DHT dht(DHTPIN, DHTTYPE);

RapifireMqtt client(THING_ID, THING_KEY, DATA_TOPIC, yunClient);

void setup() {
  Serial.begin(9600);

  Serial.println(F("Starting bridge..."));
  Bridge.begin();

  Serial.println(F("Bridge ready."));
}

void loop() {
  if (!client.connected()) {
    Serial.println(F("Connecting to RAPIFIRE.."));

    if (client.connect()) {
      Serial.println(F("Connected."));
    }
  }

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  client.addValue("temperature", "C", temperature);
  client.addValue("humidity", "%RH", dht.readHumidity());

  if (client.publish()) {
    Serial.print(F("Message published, temp: "));
    Serial.print(temperature);
    Serial.print(F("C, humidity: "));
    Serial.print(humidity);
    Serial.println(F("%RH"));
  }

  delay(10000);
}
