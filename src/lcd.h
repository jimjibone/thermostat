// Writing to the crappy LCD
// For a Hitachi HD44780-type display.
// Copyright, where applicable, James Reuss 2013.
// Created 31 March 2013.

#pragma once
#include <LiquidCrystal.h>
#include "thermometer.h"

#define buffer_size 7

// private vars
static char buffer[buffer_size] = {'0', '0', '.', '0', '0', (char)223, 'C'};

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void lcd_init(void)
{
	lcd.begin(16, 2);
}

void lcd_update(void)
{
	if (thermo_value_changed > 0) {
		thermo_value_changed = 0;
		buffer[0] = (char)(thermo_value_celsius / 10.0) + 48;
		buffer[1] = (char)((int)(thermo_value_celsius + 0.001) % 10) + 48;
		buffer[3] = (char)((int)(thermo_value_celsius * 10 + 0.01) % 10) + 48;
		buffer[4] = (char)((int)(thermo_value_celsius * 100 + 0.1) % 10) + 48;
		
		lcd.clear();
		lcd.setCursor(0, 0);
		for (int i = 0; i < buffer_size; i++) {
			lcd.write(buffer[i]);
		}
	}
}