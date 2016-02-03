[Back to ToC](library.md)

# publish()

### Description

Sends the SenML message to RAPIFIRE.

### Syntax

```c++
publish();
```

### Parameters

The method has no parameters.

### Returns

* __TRUE__ if the message was successfully published.

### Examples

Compose a message with two events and send them to RAPIFIRE.

```
rapifire.addValue("temp", "Cel", 22.1);
rapifire.addStringValue("place", "living room");

rapifire.publish();
```