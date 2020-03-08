/*
 * Led.cpp
 *
 * Created: 17.11.2019 19.41.32
 *  Author: Joni
 */ 

 #include <Arduino.h>
 #include "Led.h"

 #define REDLED 3
 #define GREENLED 4
 #define YELLOWLED 5


 void ledOn (int led){
	 digitalWrite(led, HIGH);
 }

 void ledOff (){
	 digitalWrite(REDLED, LOW);
	 digitalWrite(YELLOWLED, LOW);
	 digitalWrite(GREENLED, LOW);
 }
 void yellowLedOn(){
	ledOn(YELLOWLED);
 }

 void greenLedOn() {
	ledOn(GREENLED);
 }

 void redLedOn(){
	ledOn(REDLED);
 }

 void yellowLedBlink(int delayInMs){

 yellowLedOn();
 delay(delayInMs);
 ledOff();
 }