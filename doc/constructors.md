[Back to ToC](library.md)

# RapifireMqttClient()

### Description
Constructors used to create an instance of the class.

### Syntax
RapifireMqttClient(thingId, thingToken, client)
RapifireMqttClient(thingId, thingToken, callback, client)

### Parameters
__thingId__ - RAPIFIRE Thing ID,
__thingToken__ - RAPIFIRE Thing Token,
__client__ - an implementation of Arduino's __Client__ that provides the internet connection,
__callback__ - a pointer to the callback function.

### Examples
```
#include <YunClient.h>
#include <PubSubClient.h>
#include <RapifireMqttClient.h>

#define THING_ID "YOUR_THING_ID"
#define THING_KEY "YOUR_THING_KEY"

YunClient client;
RapifireMqttClient rapifire(THING_ID, THING_KEY, client);
```

```
#include <YunClient.h>
#include <PubSubClient.h>
#include <RapifireMqttClient.h>

#define THING_ID "YOUR_THING_ID"
#define THING_KEY "YOUR_THING_KEY"

void callback(char* topic, uint8_t* bytes, unsigned int length)
{
  // Your processing code
}

YunClient client;
RapifireMqttClient rapifire(THING_ID, THING_KEY, client);
```