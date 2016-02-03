[Back to ToC](library.md)

# loop()

### Description

The method must be invoked inside the __void loop()__ in order to allow Arduino to handle incomming messages.

### Syntax

```c++
loop()
```

### Parameters

The method has no parameters.

### Returns

* __TRUE__ if the client is still connected to RAPIFIRE.

### Examples

```
void loop() {
	// the other code
	
	rapifire.loop();
}

```