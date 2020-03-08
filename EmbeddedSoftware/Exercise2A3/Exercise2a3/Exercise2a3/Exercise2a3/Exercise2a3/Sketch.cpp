/*
Name: Sketch.cpp
Author: Joni Vilokki
Description: Exercsice 2A3. Demonstrate working with 7 segment display.
*/

#include <Arduino.h>

// Function declarations
void turnLedOn(int led);
void turnLedOff(int led);
void drawE();
void drawThree();
void turnAllLedsOff();
void counterClockwise();
void turnAllLedsON();
void clocWise();
void offOneByOne();


//Macro definitions
#define LEDA 2
#define LEDF 3
#define LEDE 4
#define LEDD 5
#define LEDC 6
#define LEDG 7
#define LEDB 8
#define DELAY_BETWEEN_LEDS_CIRCLE 140


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
 
	for (int i = 0; i <3; i++ ){
		drawE();
		delay(500);
		drawThree();
		delay(500);
	}

	turnAllLedsOff();
	delay(1000);

	for (int i = 0; i <3; i++){
		counterClockwise();
	}
	
	delay(1000);
	
	for (int i = 0; i <3; i++){
		offOneByOne();
	}

	delay(1000);

	for (int i = 0; i < 3; i++){
		clocWise();
	}
	
	delay(1000);
	turnAllLedsON();
	delay(1000);
}
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
	turnLedOn(LEDA);
	turnLedOn(LEDB);
	turnLedOn(LEDC);
	turnLedOn(LEDG);
	turnLedOn(LEDD);
	turnLedOff(LEDF);
	turnLedOff(LEDE);
}

void drawE(){
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
