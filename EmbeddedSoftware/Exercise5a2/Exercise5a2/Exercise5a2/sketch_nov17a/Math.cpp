/*
 * Math.cpp
 *
 * Created: 17.11.2019 19.43.33
 *  Author: Joni
 */ 

#include <Arduino.h>
#include "Math.h"

int checkBit(unsigned int voltage){

if( ((~voltage) + 1) & 1) return 1; 
/* ~ is bitwise complement operator. We use unsigned int that are 8 bit long.

*/
else return 0;

}