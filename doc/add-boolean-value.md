[Back To ToC](library.md)

# addBooleanValue()

### Description

Adds a new event with a boolean value to the current [SenML](http://blog.rapifire.com/2015/12/21/introduction-to-senml/) message.

### Syntax

```c++
addBooleanValue(name, value);
```

```c++
addBooleanValue(name, unit, value);
```

### Parameters

* __name__ - a name of the value to add. It will be displayed in RAPIFIRE,
* __value__ - a value to send,
* __unit__ - a unit. 

### Returns

* __TRUE__ if the new event can be added. 
* __FALSE__ the message is too long and the another event cannot be added.

### Examples

An event with a boolean value and without the unit specification.

```c++
rapifire.addBooleanValue("enabled", true);
```

An event with a boolean value and the unit specification.

```c++
rapifire.addBooleanValue("temp", "Cel", false);
```