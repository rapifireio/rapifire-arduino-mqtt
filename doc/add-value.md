[Back to ToC](library.md)

# addValue()

### Description

Adds a new event with a numeric to the current [SenML](http://blog.rapifire.com/2015/12/21/introduction-to-senml/) message.

### Syntax

```c++
addValue(name, value);
```

```c++
addValue(name, unit, value);
```

### Parameters

* __name__ - a name of the value to add. It will be displayed in RAPIFIRE,
* __value__ - a value to send,
* __unit__ - a unit. 

### Returns

* __TRUE__ if the new event can be added. 
* __FALSE__ the message is too long and the another event cannot be added.

### Examples

An event with a numeric value without the unit specification.

```c++
rapifire.addValue("weight", 0.2);
```

A event with a numeric value with the unit specification.

```c++
rapifire.addValue("weight", "kg", 0.3);
```