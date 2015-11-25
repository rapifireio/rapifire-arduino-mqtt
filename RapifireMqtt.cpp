#include "RapifireMqtt.h"

RapifireMqtt::RapifireMqtt(const char* thingId, const char* thingToken, const char* dataTopic, Client& client): pubsub(RAPIFIRE_HOST, RAPIFIRE_PORT, client)
{
  _thingId = thingId;
  _thingToken = thingToken;
  _dataTopic = dataTopic;
};

boolean RapifireMqtt::connect()
{
  return pubsub.connect( _thingId, _thingId, _thingToken);
};

boolean RapifireMqtt::connected()
{
  return pubsub.connected();
};

void RapifireMqtt::addValue(const char* name, const char* unit, float value)
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
};

boolean RapifireMqtt::publish()
{
  message = String(F("{\"e\":[")) + message + String(F("]}"));
  
  boolean result = pubsub.publish(_dataTopic, message.c_str());
  message = F("");
  
  return result;
};

boolean RapifireMqtt::loop()
{
  return pubsub.loop();
};

int RapifireMqtt::state()
{
  return pubsub.state();
};

