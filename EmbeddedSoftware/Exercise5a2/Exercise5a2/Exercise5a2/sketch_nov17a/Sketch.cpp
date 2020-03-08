/*
Name: Skecth.cpp
Author: Joni Vilokki & Tuomas Maanpää
Description: 
*/


#include <Arduino.h>
#include "Led.h"
#include "Thermistor.h"
#include "Math.h"

#define REDLED 3
#define GREENLED 4
#define YELLOWLED 5

void setup() {

pinMode(REDLED, OUTPUT);
pinMode(GREENLED, OUTPUT);
pinMode(YELLOWLED, OUTPUT);

}

void loop() {

	if(getTemperature() < 25.0) greenLedOn();
	else redLedOn();

	delay(500);
	ledOff();

	if(checkBit(getVoltage())) yellowLedBlink(1000);
	else yellowLedBlink(200);

}
