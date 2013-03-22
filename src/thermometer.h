// Thermometer reading file!
// Copyright, where applicable, James Reuss 2013.
// Created 22 March 2013.

const int heartbeat_led = 13;

bool heartbeat_state = 0;

void heartbeat_init(void) {
	pinMode(heartbeat_led, OUTPUT);
	digitalWrite(heartbeat_led, HIGH);
	heartbeat_state = 1;
}

void heartbeat_flash(void) {
	if (heartbeat_state == 0) {
		digitalWrite(heartbeat_led, LOW);
	} else {
		digitalWrite(heartbeat_led, HIGH);
	}
	heartbeat_state = !heartbeat_state;
}