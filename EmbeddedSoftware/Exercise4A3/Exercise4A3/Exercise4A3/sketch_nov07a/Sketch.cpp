/*
Name: Sketch.cpp
Description: Traffic lights with interrupts
Author: Joni Vilokki
*/
#include <Arduino.h>

#define REDLED 3
#define YELLOWLED 8
#define GREENLED 2

void redFalling();
void greenFalling();

volatile int greenLedState = LOW;
volatile int yellowLedState = LOW;

void setup() {
	
pinMode(REDLED,OUTPUT);
pinMode(YELLOWLED,OUTPUT);
pinMode(GREENLED,OUTPUT);
attachInterrupt(digitalPinToInterrupt(REDLED),redFalling,FALLING);
attachInterrupt(digitalPinToInterrupt(GREENLED),greenFalling,FALLING);
}

void loop() {
	digitalWrite(REDLED,HIGH);
	delay(1500);
	digitalWrite(YELLOWLED,HIGH);
	delay(600);
	digitalWrite(REDLED,LOW);
	digitalWrite(YELLOWLED,LOW);
	delay(2000);
	digitalWrite(GREENLED, LOW);
	delay(400);
	digitalWrite(YELLOWLED,LOW);
}
void redFalling(){
	greenLedState = HIGH;
	digitalWrite(GREENLED,greenLedState);
	greenLedState = LOW;
}

void greenFalling(){
	yellowLedState = HIGH;
	digitalWrite(YELLOWLED,yellowLedState);
	yellowLedState = LOW;
}
