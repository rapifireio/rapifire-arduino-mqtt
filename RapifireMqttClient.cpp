#include "RapifireMqttClient.h"

const char VALUE[] = "v";
const char STRING_VALUE[] = "sv";
const char BOOL_VALUE[] = "bv";

const char TRUE[] = "true";
const char FALSE[] = "false";

RapifireMqttClient::RapifireMqttClient(const char* thingId, const char* thingToken, Client& client): pubsub(RAPIFIRE_HOST, RAPIFIRE_PORT, client)
{
  _thingId = thingId;
  _thingToken = thingToken;
  
  _dataTopic += thingId;
  _dataTopic += F("/data");
}

RapifireMqttClient::RapifireMqttClient(const char* thingId, const char* thingToken, void (*callback)(char*, uint8_t*, unsigned int), Client& client): pubsub(RAPIFIRE_HOST, RAPIFIRE_PORT, callback, client)
{
  _thingId = thingId;
  _thingToken = thingToken;
  
  _dataTopic += thingId;
  _dataTopic += F("/data");
  
  _commandsTopic += thingId; 
  _commandsTopic += F("/commands?accept=text");
}

boolean RapifireMqttClient::connect()
{
  if (pubsub.connect( _thingId, _thingId, _thingToken)) {
    pubsub.subscribe(_commandsTopic.c_str());

    return true;
  } else {
    return false;
  }
}

boolean RapifireMqttClient::connected()
{
  return pubsub.connected();
}

boolean RapifireMqttClient::addEvent(const char* name, const char* type, String value)
{
  String event = F("{\"n\":\"");
  event += name;
  event += F("\",\"");
  event += type;
  event += F("\":");
  event += value;
  event += F("}");

  return addEvent(event);
}

boolean RapifireMqttClient::addEvent(const char* name, const char* type, String value, const char* unit)
{
  String event = F("{\"n\":\"");
  event += name;
  event += F("\",\"");
  event += type;
  event += F("\":");
  event += value;
  event += F(",\"u\":\"");
  event += unit;
  event += F("\"}");

  return addEvent(event);
}

boolean RapifireMqttClient::addEvent(String& event)
{
  if (_dataTopic.length() + message.length() + event.length() + 1 <= RAPIFIRE_MAX_MSG_SIZE)
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

boolean RapifireMqttClient::addValue(const char* name, double value)
{
  return addEvent(name, VALUE, String(value));
}

boolean RapifireMqttClient::addValue(const char* name, const char* unit, double value)
{
  return addEvent(name, VALUE, String(value), unit);
}

boolean RapifireMqttClient::addStringValue(const char* name, const char* value)
{
  String text = F("\"");
  text += value;
  text += F("\"");
  
  return addEvent(name, STRING_VALUE, text);
}

boolean RapifireMqttClient::addBooleanValue(const char* name, boolean value)
{
  if (value) {
    addEvent(name, BOOL_VALUE, TRUE);
  } else {
    addEvent(name, BOOL_VALUE, FALSE);
  }
}

boolean RapifireMqttClient::publish()
{
  message = String(F("{\"e\":[")) + message + String(F("]}"));

  boolean result = pubsub.publish(_dataTopic.c_str(), message.c_str());
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

