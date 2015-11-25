#ifndef RapifireMqtt_h
#define RapifireMqtt_h

#include <Client.h>
#include <PubSubClient.h>

const char RAPIFIRE_HOST[] = "mqtt.rapifire.com";
const uint16_t RAPIFIRE_PORT = 1883;

class RapifireMqtt
{
  private:
    PubSubClient pubsub;
    const char* _thingId;
    const char* _thingToken;
    const char* _dataTopic;

    String message = "";
  public:
    RapifireMqtt(const char* thingId, const char* thingToken, const char* dataTopic, Client& client);
    
    boolean connect();
    boolean connected();

    void addValue(const char* name, const char* unit, float value);
    boolean publish();
    
    boolean loop();

    int state();
};

#endif
