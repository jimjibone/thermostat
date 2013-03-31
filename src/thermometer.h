// Thermometer reading file!
// Copyright, where applicable, James Reuss 2013.
// Created 22 March 2013.

#pragma once
#include "time.h"
// http://www.pjrc.com/teensy/td_libs_OneWire.html
#include "OneWire.h"

static const uint8_t thermo_addr[] = 
	{0x28, 0x56, 0x9, 0x9C, 0x4, 0x0, 0x0, 0x1C, 0x28};
	// Address of the DS18B20 in question.
	// Must be redetermined for new components.
	// Is possible to calculate inline.
static const int heartbeat_led = 13;

OneWire thermo(10);	// DS18B20+ on pin "10"
static bool thermo_read_state = 0;

float thermo_value_celsius = 0;
bool thermo_value_changed = 0;

void thermometer_init(void);
void thermometer_update(void);
void thermometer_serial_print(void);

void thermometer_init(void) {
	pinMode(heartbeat_led, OUTPUT);
	digitalWrite(heartbeat_led, HIGH);
	thermo_read_state = 1;
	
	Serial.begin(9600);
	
	thermo.reset();
	// Only need to do once if only using the one 1-wire device.
	thermo.select((uint8_t*)thermo_addr);
}

void thermometer_update(void) {
	// Update the heartbeat
	if (thermo_read_state == 0) {
		digitalWrite(heartbeat_led, LOW);
		// Start the thermometer conversion.
		thermo.reset();
		thermo.skip();
		thermo.write(0x44);	// start conversion.
		
		// Should be a 750ms delay until read to give
		// time for the conversion.
	} else {
		digitalWrite(heartbeat_led, HIGH);
		// Read scratchpad.
		byte data[2];
		thermo.reset();
		thermo.skip();
		thermo.write(0xBE);
		for (int i = 0; i < 2; i++) {
			data[i] = thermo.read();
		}
		// Convert.
		unsigned int raw = (data[1] << 8) | data[0];	// 12 bit
		thermo_value_celsius = (float)raw/16.0;
		thermo_value_changed = 1;
	}
	thermo_read_state = !thermo_read_state;
	
	
}

void thermometer_serial_print(void) {
	Serial.print("Current Time: ");
	Serial.print(time.hours, DEC);
	Serial.print(":");
	Serial.print(time.minutes, DEC);
	Serial.print(":");
	Serial.print(time.seconds, DEC);
	Serial.print("    -    Temp: ");
	Serial.print(thermo_value_celsius);
	Serial.println(" degC");
}
