# Arduino Client for Rapifire MQTT

The library simplifies the integration of Arduino projects with the [rapifire.com](http://rapifire.com) platform.

# Examples

The library is provided with the following examples:

* __rapifire-mqtt-simple-publish__ - explains how to publish the data to the rapifire.com platform,
* __rapifire-mqtt-simple-subscribe__ - explains how to receives commands from the rapifire.com platform,
* __rapifire-mqtt-dht__ - simple project using the rapifire.com platform to visualize the data from DHT21 module.

# Dependencies

The library uses [PubSubClient](https://github.com/knolleary/pubsubclient). Please make sure that this library is installed in your IDE.

# Compatible Hardware

The library was tested on __Arduino YUN__ board. However it uses the Arduino Ethernet Client api so it will work with every board / shield that supports this api.

# License

This code is released under the MIT License.
