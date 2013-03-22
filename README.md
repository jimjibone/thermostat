Thermostat Peripheral
=====================

Building and Uploading
----------------------

To get the Arduino IDE or Ino to build and upload you have to make it think you want to upload to a Arduino Duemilanove w/ ATmega328.

To do this with Ino:
1. `ino build -m atmega328`
1. `ino upload -m atmega 328`
1. Done.

Things that need doing
----------------------

- [ ] Finding a thermocouple component worthy of accurately determining the temperature of a room.
- [ ] Use [Averclock](https://github.com/naggie/averclock) to help produce a timer for the Arduino mircocontroller.
- [ ] Develop a system that allows the microcontroller to communicate with a computer.
- [ ] Create a low cost battery and charging system for power cut protection.

Temperature Sensors
-------------------

- Can use TMP36 (I own one)
- [DS18B20 Digital Temp Sensor](https://www.sparkfun.com/products/245) Calibrated temperature readings. Temperature reading sent over data line as serial equivalent using [1-Wire](http://playground.arduino.cc/Learning/OneWire) protocol.

Parts List
----------
- [DS18B20 Digital Temp Sensor](http://uk.rs-online.com/web/p/temperature-humidity-sensors/5402805/)


- [7-seg by 4 Serial Display?](http://proto-pic.co.uk/7-segment-serial-display-red/)



Guides
------
- Simple ["Shrimp"](http://hackaday.com/2012/11/10/the-ultimate-low-cost-dev-board/) Arduino
- Someones done somthing similar?! [here](http://www.instructables.com/id/Tempduino-Arduino-Based-Temp-and-Humidity-Displa/)
