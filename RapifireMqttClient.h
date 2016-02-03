#ifndef RapifireMqttClient_h
#define RapifireMqttClient_h

#ifndef MQTT_MAX_PACKET_SIZE
#define MQTT_MAX_PACKET_SIZE 256
#endif

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
 * 256 (MQTT_MAX_PACKET_SIZE) - 8 (MQTT Headers) - 8 (JSON const part)
 */
const int RAPIFIRE_MAX_MSG_SIZE = MQTT_MAX_PACKET_SIZE - 16;

/** 
 *  RAPIFIRE MQTT Client class.
 */
class RapifireMqttClient
{
  private:
    PubSubClient pubsub;
    const char* _thingId;
    const char* _thingToken;
    String _dataTopic = "/";
    String _commandsTopic = "/";
    
    String message = "";

    boolean addEvent(const char* name, const char* type, String value);
    boolean addEvent(const char* name, const char* type, String value, const char* unit);
    boolean addEvent(String& event);
  public:
    /** 
     *  The client constructor. It can be used if you don't need the subscription callback.
     *  
     *  @param thingId Thing ID. More details in RAPIFIRE.
     *  @param thingToken Thing Token. More details in RAPIFIRE.
     *  @param client an implementation of Arduino's Client that provides the internet connection.
     */
    RapifireMqttClient(const char* thingId, const char* thingToken, Client& client);

    /** 
     *  The client constructor.
     *  
     *  @param thingId Thing ID. More details in RAPIFIRE.
     *  @param thingToken Thing Token. More details in RAPIFIRE.
     *  @param callback a callback function.
     *  @param client an implementation of Arduino's Client that provides the internet connection.
     */
    RapifireMqttClient(const char* thingId, const char* thingToken, void (*callback)(char*, uint8_t*, unsigned int), Client& client);
    
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

    /** 
     *  Adds a new number value to the current SenML message.
     *  
     *  @paran name a name of the value to add. It will be displayed in RAPIFIRE.
     *  @param value a value to send.
     *  
     *  @return FALSE if the message is too long and another event cannot be added.
     */
    boolean addValue(const char* name, double value);

    /** 
     *  Adds a new number value to the current SenML message.
     *  
     *  @paran name a name of the value to add. It will be displayed in RAPIFIRE.
     *  @param unit a unit of the value. 
     *  @param value a value to send.
     *  
     *  @return FALSE if the message is too long and another event cannot be added.
     */
    boolean addValue(const char* name, const char* unit, double value);

    /** 
     *  Adds a new string value to the current SenML message.
     *  
     *  @paran name a name of the value to add. It will be displayed in RAPIFIRE.
     *  @param value a value to send.
     *  
     *  @return FALSE if the message is too long and another event cannot be added.
     */
    boolean addStringValue(const char* name, const char* value);

    /** 
     *  Adds a new string value to the current SenML message.
     *  
     *  @paran name a name of the value to add. It will be displayed in RAPIFIRE.
     *  @param unit a unit of the value. 
     *  @param value a value to send.
     *  
     *  @return FALSE if the message is too long and another event cannot be added.
     */
    boolean addStringValue(const char* name, const char* unit, const char* value);
    
    /** 
     *  Adds a new boolean value to the current SenML message.
     *  
     *  @paran name a name of the value to add. It will be displayed in RAPIFIRE.
     *  @param value a value to send.
     *  
     *  @return FALSE if the message is too long and another event cannot be added.
     */
    boolean addBooleanValue(const char* name, boolean value);

    /** 
     *  Adds a new boolean value to the current SenML message.
     *  
     *  @paran name a name of the value to add. It will be displayed in RAPIFIRE.
     *  @param unit a unit of the value. 
     *  @param value a value to send.
     *  
     *  @return FALSE if the message is too long and another event cannot be added.
     */
    boolean addBooleanValue(const char* name, const char* unit, boolean value);

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
     *  Provides the information about PubSubClient connection status. The method can return one of the following values:
     *  
     *  #define MQTT_CONNECTION_TIMEOUT     -4
     *  #define MQTT_CONNECTION_LOST        -3
     *  #define MQTT_CONNECT_FAILED         -2
     *  #define MQTT_DISCONNECTED           -1
     *  #define MQTT_CONNECTED               0
     *  #define MQTT_CONNECT_BAD_PROTOCOL    1
     *  #define MQTT_CONNECT_BAD_CLIENT_ID   2
     *  #define MQTT_CONNECT_UNAVAILABLE     3
     *  #define MQTT_CONNECT_BAD_CREDENTIALS 4
     *  #define MQTT_CONNECT_UNAUTHORIZED    5
     *  
     *  @returns PubSubClient connection status.
     */
    int state();
};

#endif
