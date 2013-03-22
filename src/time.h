// Creds from this go to @naggie > averclock on github.
// Copyright, where applicable, James Reuss 2013.
// Created 22 March 2013.

#pragma once

#include "../config.h"
#include "some_time.h"

// define a struct to hold the time
typedef struct {
	uint8_t hours;
	uint8_t minutes;
	uint8_t seconds;
} _time;

// define some functions
void time_inc_sec(void);
void time_inc_min(void);
void time_inc_hour(void);
void time_dec_sec(void);
void time_dec_min(void);
void time_dec_hour(void);

#ifdef AUTO_TIME
	// initialise with compile-time time with an offset to account for build/upload time
	_time time = {HOURS,MINUTES,SECONDS};
#else
	_time time = {0,0,0};
#endif




// call at 1Hz
void time_inc_sec (void) {
	if (++time.seconds == 60) {
		time_inc_min();
		time.seconds = 0;
	}
}

void time_inc_min (void) {
	if (++time.minutes == 60) {
		time_inc_hour();
		time.minutes = 0;
	}
}
void time_inc_hour (void) {
	if (++time.hours == 24)
		time.hours = 0;
}




void time_dec_sec(void) {
	if (--time.seconds == 255) {
		time_dec_min();
		time.seconds = 59;
	}
}

void time_dec_min (void) {
	if (--time.minutes == 255) {
		time_dec_hour();
		time.minutes = 59;
	}
}

void time_dec_hour (void) {
	if (--time.hours == 255)
		time.hours = 23;
}
