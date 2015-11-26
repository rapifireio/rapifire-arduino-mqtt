#include <YunClient.h>
#include <PubSubClient.h>
#include <RapifireMqttClient.h>
#include <DHT.h>

#define THING_ID "YOUR_THING_ID"
#define THING_KEY "YOUR_THING_KEY"
#define DATA_TOPIC "YOUR_DATA_TOPIC"

#define DHTPIN 2
#define DHTTYPE DHT21

YunClient client;
DHT dht(DHTPIN, DHTTYPE);

RapifireMqttClient rapifire(THING_ID, THING_KEY, DATA_TOPIC, client);

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

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  rapifire.addValue("temperature", "C", temperature);
  rapifire.addValue("humidity", "%RH", dht.readHumidity());

  if (rapifire.publish()) {
    Serial.print(F("Message published, temp: "));
    Serial.print(temperature);
    Serial.print(F("C, humidity: "));
    Serial.print(humidity);
    Serial.println(F("%RH"));
  }

  delay(10000);
}
