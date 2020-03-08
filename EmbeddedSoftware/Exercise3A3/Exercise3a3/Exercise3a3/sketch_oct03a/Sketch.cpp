/*
Name: Sketch.cpp
Author: Joni Vilokki
Description: Get room temperature with 1kohm termistor and use atmel debugger to show it
*/

#include <Arduino.h>

#define LOOKUPSIZE 32
#define THERMISTORPIN A0

float getTemperature(int sensorReading);

struct TemperatureLookUP{
	int sensorReading;
	float temperature;
};

struct TemperatureLookUP LookUpTable[LOOKUPSIZE] = {
	{250, 1.4},
	{275, 4.0},
	{300, 6.4},
	{325, 8.8},
	{350, 11.1},
	{375, 13.4},
	{400, 15.6},
	{425, 17.8},
	{450, 20.0},
	{475, 22.2},
	{500, 24.4},
	{525, 26.7},
	{550, 29.0},
	{575, 31.3},
	{600, 33.7},
	{625, 36.1},
	{650, 38.7},
	{675, 41.3},
	{700, 44.1},
	{725, 47.1},
	{750, 50.2},
	{775, 53.7},
	{784, 55.0},
	{825, 61.5},
	{850, 66.2},
	{875, 71.5},
	{900, 77.9},
	{925, 85.7},
	{937, 90.3},
	{950, 96.0},
	{975, 111.2},
	{1000, 139.5}
};


void setup() {

}

void loop() {
	volatile float temperature = 0.0f;
	int sensorReading = analogRead(THERMISTORPIN);

	temperature = getTemperature(sensorReading);
}

float getTemperature(int sensorReading){

	float temperature = 0.0;

	if (sensorReading < 1000){
		for (int i = 0; i < LOOKUPSIZE -1; ++i ){
			if (LookUpTable[i].sensorReading <= sensorReading && LookUpTable[i+1].sensorReading > sensorReading){
				temperature = LookUpTable[i].temperature;
				break;
			}
		}
	}
	else temperature= 139.5;

	return temperature;
}