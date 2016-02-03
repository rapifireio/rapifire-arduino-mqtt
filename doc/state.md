[Back to ToC](library.md)

# state()

### Description

The method provides a more detailed information about the connection status.

### Syntax

```c++
state()
```

### Parameters

The method has no parameters.

### Returns

* the current connection status.

The status is a number which may have one of the following values:

```
#define MQTT_CONNECTION_TIMEOUT     -4
#define MQTT_CONNECTION_LOST        -3
#define MQTT_CONNECT_FAILED         -2
#define MQTT_DISCONNECTED           -1
#define MQTT_CONNECTED               0
#define MQTT_CONNECT_BAD_PROTOCOL    1
#define MQTT_CONNECT_BAD_CLIENT_ID   2
#define MQTT_CONNECT_UNAVAILABLE     3
#define MQTT_CONNECT_BAD_CREDENTIALS 4
#define MQTT_CONNECT_UNAUTHORIZED    5
```

### Examples

```
int status = rapifire.state();
```