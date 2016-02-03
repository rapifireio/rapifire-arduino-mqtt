[Back to ToC](library.md)

# connected()

### Description

The method checks if the client is still connected to RAPIFIRE.

### Syntax

```c++
connected()
```

### Parameters

The method has no parameters.

### Returns

__TRUE__ if the client is still connected to RAPIFIRE.

### Examples

```c++
#include <YunClient.h>
#include <PubSubClient.h>
#include <RapifireMqttClient.h>

YunClient client;
RapifireMqttClient rapifire("YOUR_THING_ID", "YOUR_THING_TOKEN", client);

void loop() {
	if (!rapifire.connected()) {
		rapifire.connect();
	}
}
```