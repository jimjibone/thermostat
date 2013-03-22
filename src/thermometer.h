// Thermometer reading file!
// Copyright, where applicable, James Reuss 2013.
// Created 22 March 2013.

#pragma once
#include "time.h"

static const int heartbeat_led = 13;

static bool heartbeat_state = 0;

uint16_t thermometer_latest = 0;

void thermometer_init(void);
void thermometer_update(void);
void thermometer_serial_print(void);

void thermometer_init(void) {
	pinMode(heartbeat_led, OUTPUT);
	digitalWrite(heartbeat_led, HIGH);
	heartbeat_state = 1;
	
	Serial.begin(9600);
}

void thermometer_update(void) {
	if (heartbeat_state == 0) {
		digitalWrite(heartbeat_led, LOW);
	} else {
		digitalWrite(heartbeat_led, HIGH);
	}
	heartbeat_state = !heartbeat_state;
}

void thermometer_serial_print(void) {
	Serial.println("hello");
	
	/*Serial.print("Current Time: ");
	Serial.print(time.hours, DEC);
	Serial.print(":");
	Serial.print(time.minutes, DEC);
	Serial.print(":");
	Serial.print(time.seconds, DEC);
	Serial.print("    -    Temp: ");
	Serial.print(thermometer_latest, DEC);
	Serial.println(" degC");*/
}
