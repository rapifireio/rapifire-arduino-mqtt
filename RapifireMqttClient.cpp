#include "RapifireMqttClient.h"

RapifireMqttClient::RapifireMqttClient(const char* thingId, const char* thingToken, const char* dataTopic, Client& client): pubsub(RAPIFIRE_HOST, RAPIFIRE_PORT, client)
{
  _thingId = thingId;
  _thingToken = thingToken;
  _dataTopic = dataTopic;
}

RapifireMqttClient::RapifireMqttClient(const char* thingId, const char* thingToken, const char* dataTopic, const char* commandsTopic, void (*callback)(char*, uint8_t*, unsigned int), Client& client): pubsub(RAPIFIRE_HOST, RAPIFIRE_PORT, callback, client)
{
  _thingId = thingId;
  _thingToken = thingToken;
  _dataTopic = dataTopic;
  _commandsTopic = commandsTopic;
}

boolean RapifireMqttClient::connect()
{
  if (pubsub.connect( _thingId, _thingId, _thingToken)) {
    pubsub.subscribe(_commandsTopic);

    return true;
  } else {
    return false;
  }
}

boolean RapifireMqttClient::connected()
{
  return pubsub.connected();
}

void RapifireMqttClient::addValue(const char* name, float value)
{
  if (message != F("")) {
    message += F(",");
  }

  message += F("{\"n\": \"");
  message += name;
  message += F("\",\"v\": ");
  message += value;
  message += F("}");
}

void RapifireMqttClient::addValue(const char* name, const char* unit, float value)
{
  if (message != F("")) {
    message += F(",");
  }

  message += F("{\"n\": \"");
  message += name;
  message += F("\",\"u\": \"");
  message += unit;
  message += F("\",\"v\": ");
  message += value;
  message += F("}");
}

boolean RapifireMqttClient::publish()
{
  message = String(F("{\"e\":[")) + message + String(F("]}"));

  boolean result = pubsub.publish(_dataTopic, message.c_str());
  message = F("");

  return result;
}

boolean RapifireMqttClient::loop()
{
  return pubsub.loop();
}

int RapifireMqttClient::state()
{
  return pubsub.state();
}

