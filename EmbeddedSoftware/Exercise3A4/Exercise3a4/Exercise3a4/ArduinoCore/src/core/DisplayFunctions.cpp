/*
Name:Displayfunctions.cpp
Author: Joni Vilokki
Description: Functions to draw any number and few other things with 7 segment display
*/

#include <Arduino.h>
#include "DisplayFunctions.h"

//Macro definitions
#define LEDA 2
#define LEDF 3
#define LEDE 4
#define LEDD 5
#define LEDC 6
#define LEDG 7
#define LEDB 8
#define DELAY_BETWEEN_LEDS_CIRCLE 200

void turnLedOn (int led){
	digitalWrite(led, LOW);
}

void turnLedOff (int led){
	digitalWrite(led, HIGH);
}

void turnAllLedsOff(){
	turnLedOff(LEDA);
	turnLedOff(LEDB);
	turnLedOff(LEDC);
	turnLedOff(LEDD);
	turnLedOff(LEDE);
	turnLedOff(LEDF);
	turnLedOff(LEDG);
}

void turnAllLedsON(){
	turnLedOn(LEDA);
	turnLedOn(LEDB);
	turnLedOn(LEDC);
	turnLedOn(LEDD);
	turnLedOn(LEDE);
	turnLedOn(LEDF);
	turnLedOn(LEDG);

}

void drawThree() {
	turnAllLedsOff();
	turnLedOn(LEDA);
	turnLedOn(LEDB);
	turnLedOn(LEDC);
	turnLedOn(LEDG);
	turnLedOn(LEDD);
	turnLedOff(LEDF);
	turnLedOff(LEDE);
}

void drawE(){
	turnAllLedsOff();
	turnLedOn(LEDA);
	turnLedOn(LEDG);
	turnLedOn(LEDF);
	turnLedOn(LEDE);
	turnLedOn(LEDD);
	turnLedOff(LEDB);
	turnLedOff(LEDC);
}

void counterClockwise(){
	//  A-F-E-D-C-B
	turnLedOn(LEDA);
	delay(DELAY_BETWEEN_LEDS_CIRCLE);
	turnLedOn(LEDF);
	delay(DELAY_BETWEEN_LEDS_CIRCLE);
	turnLedOn(LEDE);
	delay(DELAY_BETWEEN_LEDS_CIRCLE);
	turnLedOn(LEDD);
	delay(DELAY_BETWEEN_LEDS_CIRCLE);
	turnLedOn(LEDC);
	delay(DELAY_BETWEEN_LEDS_CIRCLE);
	turnLedOn(LEDB);
	delay(DELAY_BETWEEN_LEDS_CIRCLE);
	turnAllLedsOff();
	
}

void offOneByOne(){

	turnAllLedsON();
	delay(300);
	turnLedOff(LEDF);
	delay(DELAY_BETWEEN_LEDS_CIRCLE);
	turnLedOff(LEDE);
	delay(DELAY_BETWEEN_LEDS_CIRCLE);
	turnLedOff(LEDG);
	delay(DELAY_BETWEEN_LEDS_CIRCLE);
	turnLedOff(LEDD);
	delay(DELAY_BETWEEN_LEDS_CIRCLE);
	turnLedOff(LEDB);
	delay(DELAY_BETWEEN_LEDS_CIRCLE);
	turnLedOff(LEDA);
	delay(DELAY_BETWEEN_LEDS_CIRCLE);
	turnLedOff(LEDC);
	delay(DELAY_BETWEEN_LEDS_CIRCLE);
}

void clocWise(){
	turnAllLedsOff();

	turnLedOn(LEDA);
	delay(DELAY_BETWEEN_LEDS_CIRCLE);
	turnLedOn(LEDB);
	delay(DELAY_BETWEEN_LEDS_CIRCLE);
	turnLedOn(LEDC);
	delay(DELAY_BETWEEN_LEDS_CIRCLE);
	turnLedOn(LEDD);
	delay(DELAY_BETWEEN_LEDS_CIRCLE);
	turnLedOn(LEDE);
	delay(DELAY_BETWEEN_LEDS_CIRCLE);
	turnLedOn(LEDF);
	delay(DELAY_BETWEEN_LEDS_CIRCLE);
}

void drawNumber(int number){
	switch(number){
		case 0:
			drawZero();
			break;
		case 1: 
			drawOne();
			break;
		case 2:
			drawTwo();
			break;
		case 3:
			drawThree();
			break;
		case 4:
			drawFour();
			break;
		case 5:
			drawFive();
			break;
		case 6:
			drawSix();
			break;
		case 7:
			drawSeven();
			break;
		case 8:
			drawEight();
			break;
		case 9:
			drawNine();
			break;
		default:
			turnAllLedsOff();
			break;
	}
}

void drawZero(){
	turnAllLedsOff();
	turnLedOn(LEDA);
	turnLedOn(LEDB);
	turnLedOn(LEDC);
	turnLedOn(LEDD);
	turnLedOn(LEDE);
	turnLedOn(LEDF);
}

void drawOne(){
	turnAllLedsOff();
	turnLedOn(LEDB);
	turnLedOn(LEDC);
}

void drawTwo(){
	turnAllLedsOff();
	turnLedOn(LEDA);
	turnLedOn(LEDB);
	turnLedOn(LEDG);
}

void drawFour(){
	turnAllLedsOff();
	turnLedOn(LEDF);
	turnLedOn(LEDG);
	turnLedOn(LEDB);
	turnLedOn(LEDC);
	
}
	
void drawFive(){
	turnAllLedsOff();
	turnLedOn(LEDA);
	turnLedOn(LEDF);
	turnLedOn(LEDG);
	turnLedOn(LEDC);
	turnLedOn(LEDD);

}

void drawSix(){
	turnAllLedsOff();
	turnLedOn(LEDF);
	turnLedOn(LEDG);
	turnLedOn(LEDE);
	turnLedOn(LEDD);
	turnLedOn(LEDC);
}

void drawSeven(){
	turnAllLedsOff();
	turnLedOn(LEDA);
	turnLedOn(LEDB);
	turnLedOn(LEDC);
}

void drawEight(){
	turnAllLedsOff();
	turnAllLedsON();
}

void drawNine(){
	turnAllLedsOff();
	turnAllLedsON();
	turnLedOff(LEDE);
	turnLedOff(LEDD);
}
	
