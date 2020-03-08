/*
File:			Sketch.cpp
Author:			Joni Vilokki
Description:	Traffic ligt demonstarion for Arduino Uno.
*/
#include <Arduino.h>


// Define macros for led pins and delays in ms
#define GREEN 7
#define YELLOW 8
#define RED 4
#define DELAY_GREEN 4000
#define DELAY_YELLOW 1000
#define DELAY_RED 2000
#define DELAY_TOGREEN 500

// basic functions
void setup() {
	//Setup led pins to output mode
	pinMode(GREEN, OUTPUT);
	pinMode(YELLOW, OUTPUT);
	pinMode(RED, OUTPUT);
}

void loop()
{
	
	// High turns things on
	// Low turns things off
	digitalWrite(GREEN, HIGH);
	digitalWrite(YELLOW, LOW);
	digitalWrite(RED, LOW);
	// how long we want the green led on
	delay(DELAY_GREEN);
	
	digitalWrite(GREEN, LOW);
	digitalWrite(YELLOW, HIGH);
	digitalWrite(RED, LOW);
	// how long we want the yellow led on
	delay(DELAY_YELLOW);

	digitalWrite(GREEN, LOW);
	digitalWrite(YELLOW, LOW);
	digitalWrite(RED, HIGH);
	// how long we want the red led on
	delay(DELAY_RED);
	digitalWrite(GREEN, LOW);
	digitalWrite(YELLOW, HIGH);
	digitalWrite(RED, HIGH);
	delay(DELAY_TOGREEN);
	
}