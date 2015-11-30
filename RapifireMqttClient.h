#ifndef RapifireMqttClient_h
#define RapifireMqttClient_h

#include <Client.h>
#include <PubSubClient.h>

/** 
 *  RAPIFIRE domain.
 */
const char RAPIFIRE_HOST[] = "mqtt.rapifire.com";
/**
 * Default MQTT port.
 */
const uint16_t RAPIFIRE_PORT = 1883;

/**
 * Max size of a single MQTT message.
 * 
 * 128 (MQTT_MAX_PACKET_SIZE) - 8 (MQTT Headers) - 8 (JSON const part) = 112
 */
const int RAPIFIRE_MAX_MSG_SIZE = 112;

/** 
 *  RAPIFIRE MQTT Client class.
 */
class RapifireMqttClient
{
  private:
    PubSubClient pubsub;
    const char* _thingId;
    const char* _thingToken;
    const char* _dataTopic;
    const char* _commandsTopic;
    
    String message = "";

    boolean addEvent(String& event);
  public:
    /** 
     *  The client constructor. It can be used if you don't need the subscription callback.
     *  
     *  @param thingId Thing ID. More details in RAPIFIRE.
     *  @param thingToken Thing Token. More details in RAPIFIRE.
     *  @param dataTopic Data Publishing Topic. More details in RAPIFIRE.
     *  @param client an implementation of Arduino's Client that provides the internet connection.
     */
    RapifireMqttClient(const char* thingId, const char* thingToken, const char* dataTopic, Client& client);

    /** 
     *  The client constructor.
     *  
     *  @param thingId Thing ID. More details in RAPIFIRE.
     *  @param thingToken Thing Token. More details in RAPIFIRE.
     *  @param dataTopic Data Publishing Topic. More details in RAPIFIRE.
     *  @param commandsTopic Command Receiving Topic. More details in RAPIFIRE.
     *  @param callback a callback function.
     *  @param client an implementation of Arduino's Client that provides the internet connection.
     */
    RapifireMqttClient(const char* thingId, const char* thingToken, const char* dataTopic, const char* commandsTopic, void (*callback)(char*, uint8_t*, unsigned int), Client& client);
    
    /** 
     *  The method initialize a connection with RAPIFIRE.
     *  
     *  @returns TRUE if the connection succeeded.
     */
    boolean connect();

    /** 
     *  The method checks if the client is still connected to RAPIFIRE.
     *  
     *  @returns TRUE if the client is still connected to RAPIFIRE.
     */ 
    boolean connected();

    /** Adds a new value to the current SenML message.
     *  
     *  @paran name a name of the value to add. It will be displayed in RAPIFIRE.
     *  @param value a value to send.
     *  
     *  @return FALSE if the message is too long and another event cannot be added.
     */
    boolean addValue(const char* name, float value);

    /** 
     *  Adds a new value to the current SenML message.
     *  
     *  @paran name a name of the value to add. It will be displayed in RAPIFIRE.
     *  @param unit a unit of the value. 
     *  @param value a value to send.
     *  
     *  @return FALSE if the message is too long and another event cannot be added.
     */
    boolean addValue(const char* name, const char* unit, float value);

    /** 
     *  Publishes the SenML message to the RAPIFIRE.
     *  
     *  @returns TRUE if the message was successfully published.
     */
    boolean publish();
    
    /** 
     *  The method muse be invoked in order to allow the Arduino to receive messages from RAPIFIRE.
     *  
     *  @returns TRUE if the client is still connected to RAPIFIRE.
     */
    boolean loop();

    /** 
     *  Provides the information about PubSubClient connection status.
     *  
     *  @returns PubSubClient connection status.
     */
    int state();
};

#endif
