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

boolean RapifireMqttClient::addEvent(String& event)
{
  if (strlen(_dataTopic) + message.length() + event.length() + 1 <= RAPIFIRE_MAX_MSG_SIZE)
  {
    if (message != F("")) {
      message += F(",");
    }
    message += event;
    return true;
  } else {
    return false;
  }
}

boolean RapifireMqttClient::addValue(const char* name, float value)
{
  String event = F("{\"n\":\"");
  event += name;
  event += F("\",\"v\":");
  event += value;
  event += F("}");

  return addEvent(event);
}

boolean RapifireMqttClient::addValue(const char* name, const char* unit, float value)
{
  String event = F("{\"n\":\"");
  event += name;
  event += F("\",\"u\":\"");
  event += unit;
  event += F("\",\"v\": ");
  event += value;
  event += F("}");

  return addEvent(event);
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

