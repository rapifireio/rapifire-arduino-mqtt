[Back to ToC](library.md)

# connect()

### Description

The method initialize a connection with RAPIFIRE.

### Syntax

```c++
connect()
```

### Parameters

The method has no parameters.

### Returns

__TRUE__ if the connection succeeded.

### Examples

The example code for __Arduino YUN__.


```c++
#include <YunClient.h>
#include <PubSubClient.h>
#include <RapifireMqttClient.h>

YunClient client;
RapifireMqttClient rapifire("YOUR_THING_ID", "YOUR_THING_TOKEN", client);

void setup() {
	// Initialize serial data transmission
	Serial.begin(9600);
	
	// Starts YUN's Bridge
	Bridge.begin();
	
	// Initialize the connection with RAPIFIRE
	rapifire.connect();
}
```