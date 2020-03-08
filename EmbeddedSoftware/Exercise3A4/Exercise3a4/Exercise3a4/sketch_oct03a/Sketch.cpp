/*
Name: Sketch.cpp
Author: Joni Vilokki
Description: Get room teprerature with 1kohm termistor. Dispaly it with seven segment display
*/
#include <Arduino.h>
#include "DisplayFunctions.h"

void blinkE3Threetimes();
void clockWiseThreeTimes();

#define LOOKUPSIZE 32
#define THERMISTORPIN A0
#define FLOAT_TO_INT(x) ((x)>=0?(int)((x)+0.5):(int)((x)-0.5))

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



//Macro definitions
#define LEDA 2
#define LEDF 3
#define LEDE 4
#define LEDD 5
#define LEDC 6
#define LEDG 7
#define LEDB 8
#define LED_DELAY 2000


void setup() {
  pinMode(LEDA, OUTPUT);
  pinMode(LEDF, OUTPUT);
  pinMode(LEDE, OUTPUT);
  pinMode(LEDD, OUTPUT);
  pinMode(LEDC, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  
}

void loop() {
	
	blinkE3Threetimes();
	
	volatile float temperature = 0.0f;
	int sensorReading = analogRead(THERMISTORPIN);
	temperature = getTemperature(sensorReading);

	 volatile int fisrNum = 0;
	 volatile int secondNum = 0;


	 int numberInt = FLOAT_TO_INT(temperature);
	 if(numberInt/10 > 0){
		 fisrNum = numberInt/10;
		 secondNum = numberInt - fisrNum*10;
	 }
	 else secondNum = numberInt;

	 drawNumber(fisrNum);
	 delay(2000);
	 drawNumber(secondNum);
	 delay(2000);
	 clockWiseThreeTimes();
	 delay(2000);

}


float getTemperature(int sensorReading){

	float temperature = 0.0;

	if (sensorReading < 1000){
		for (int i = 0; i < LOOKUPSIZE -1; ++i )
		{
			if (LookUpTable[i].sensorReading <= sensorReading && LookUpTable[i+1].sensorReading > sensorReading){
				temperature = LookUpTable[i].temperature;
				break;
			}
		}
	}
	else temperature = 139.5;

	return temperature;
}

void blinkE3Threetimes(){

	for (int i = 0; i < 3 ; i++){
		delay(500);
		drawThree();
		delay(500);
		drawE();
	}
}

void clockWiseThreeTimes(){

	for (int i = 0; i < 3; i++){
		clocWise();
		}
}