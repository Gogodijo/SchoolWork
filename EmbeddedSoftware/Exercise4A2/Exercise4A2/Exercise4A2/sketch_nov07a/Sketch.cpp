/*
Name: Sketch.cpp
Description: Practice arduino interrupts
Author: Joni Vilokki
*/
#include <Arduino.h>

#define YELLOWLED 2
#define GREENLED 3
#define REDLED1 8
#define REDLED2 7

void handleFirstInterrupt();
void handleSecondInterrupt();

volatile int firstLedState = LOW;
volatile int secondLedState = LOW;

void setup() {
	pinMode(YELLOWLED, OUTPUT);
	pinMode(GREENLED, OUTPUT);
	pinMode(REDLED1, OUTPUT);
	pinMode(REDLED2,OUTPUT);
	attachInterrupt(digitalPinToInterrupt(YELLOWLED),handleFirstInterrupt,CHANGE);
	attachInterrupt(digitalPinToInterrupt(GREENLED),handleSecondInterrupt,CHANGE);
}

void loop() {
	digitalWrite(GREENLED,HIGH);
	digitalWrite(YELLOWLED,HIGH);
	delay(500);
	digitalWrite(YELLOWLED,LOW);
	delay(500);
	digitalWrite(GREENLED,LOW);
	digitalWrite(YELLOWLED,HIGH);
	delay(500);
	digitalWrite(YELLOWLED,LOW);
	delay(500);

}

void handleFirstInterrupt(){
	firstLedState = !firstLedState;
	digitalWrite(REDLED1,firstLedState);
}

void handleSecondInterrupt(){
	secondLedState = !secondLedState;
	digitalWrite(REDLED2,!secondLedState);
}
