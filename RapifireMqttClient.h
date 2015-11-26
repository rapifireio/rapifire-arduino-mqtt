#ifndef RapifireMqttClient_h
#define RapifireMqttClient_h

#include <Client.h>
#include <PubSubClient.h>

const char RAPIFIRE_HOST[] = "mqtt.rapifire.com";
const uint16_t RAPIFIRE_PORT = 1883;

class RapifireMqttClient
{
  private:
    PubSubClient pubsub;
    const char* _thingId;
    const char* _thingToken;
    const char* _dataTopic;
    const char* _commandsTopic;
    
    String message = "";
  public:
    RapifireMqttClient(const char* thingId, const char* thingToken, const char* dataTopic, Client& client);
    RapifireMqttClient(const char* thingId, const char* thingToken, const char* dataTopic, const char* commandsTopic, void (*callback)(char*, uint8_t*, unsigned int), Client& client);
    
    boolean connect();
    boolean connected();

    void addValue(const char* name, const char* unit, float value);
    boolean publish();
    
    boolean loop();

    int state();
};

#endif
