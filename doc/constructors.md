[Back to ToC](library.md)

# RapifireMqttClient()

### Description

Constructors used to create an instance of the class.

### Syntax

* RapifireMqttClient(thingId, thingToken, client)
* RapifireMqttClient(thingId, thingToken, callback, client)

### Parameters

* __thingId__ - RAPIFIRE Thing ID,
* __thingToken__ - RAPIFIRE Thing Token,
* __client__ - an implementation of Arduino's __Client__ that provides the internet connection,
* __callback__ - a pointer to the callback function.

### Examples

The constructor usage without the callback function. You can use it if you only planing to send the data to  RAPIFIRE.

```c++
#include <YunClient.h>
#include <PubSubClient.h>
#include <RapifireMqttClient.h>

YunClient client;
RapifireMqttClient rapifire("YOUR_THING_ID", "YOUR_THING_KEY", client);
```

The constructor usage example when you are plaing to receive messages from RAPIFIRE.

```c++
#include <YunClient.h>
#include <PubSubClient.h>
#include <RapifireMqttClient.h>

void callback(char* topic, uint8_t* bytes, unsigned int length)
{
  // Your processing code
}

YunClient client;
RapifireMqttClient rapifire("YOUR_THING_ID", "YOUR_THING_KEY", client);
```