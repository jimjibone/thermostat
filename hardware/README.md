Hardware 'n' That
=================

Bootloading fresh ATmega328P's
------------------------------

> This took a long time and a painful amount of coffee and late nights and blood and sweat and tears to get working... not really but it was a mega pain. The internet sucks with this. So here's my answer.

How to bootload an **ATmega328P** using nothing but a real Arduino:

1. Get the adaLoader files [here](https://github.com/adafruit/Standalone-Arduino-AVR-ISP-programmer)
1. Get Arduino IDE 0023 (anything newer fails and makes life sad) [here](http://arduino.cc/en/Main/Software)
1. Rename the adaLoader unzipped folder to `adaLoader`
1. Open `adaLoader.pde` using Arduino 0023
1. In the IDE open the `images.cpp` file and make sure that the signature for the 328P is `0x950F`
1. Using a real Arduino UNO build this (just to note, the round thing is a piezo speaker) ![adaLoader Breadboard](ATMEGA328P%20AdaLoader.png)
1. Insert your fresh ATMEGA328P
1. Plug in the Arduino UNO via USB and upload adaLoader
1. Open the Serial Monitor
1. Press the tactile button on your breadboard, or send a `G` over serial to bootload the fresh ATMEGA
1. If it makes a nice short beep then everything went well. If it makes a loooong nasty beep and the red LED glows then some bad stuff has happened. The serial monitor may help you here.


Creating a simple breadboard for FTDI USB power and programming
---------------------------------------------------------------

Now you have a bootloaded ATMEGA you're gonna want to upload stuff to it. Do this stuff:

1. Make this simple board up to get you going
	- Capacitors are 2 x 10uF electrlytic and 2 x 22pF ceramic (for XTAL)
![adaLoader Breadboard](ATMEGA328P%20Simple.png)
1. And using a FTDI cable (I have a TTL-232R-3V3 cable)
1. In the Arduino IDE, on the menu bar go into `Tools > Board` and select `Arduino Duemilanove or Nano w/ ATmega328` (or similar)
1. Select the serial port for the FTDI cable
1. Upload the simple Blink example or whatever you fancy.

Hope it works
