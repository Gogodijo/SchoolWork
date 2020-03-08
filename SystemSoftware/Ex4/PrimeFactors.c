/*
    Name: PrimeFactors.c
    Authors: Joni Vilokki & Markus Klemelä
    Description: Find and return largerst prime factor of input number.
*/
#include <stdio.h>
#include "PrimeFactors.h"

int primeFactor(int n){

    int maxPrime = 2;
    //While n is larger than max prime check if n divides max prime. If it does divide n by n/maxprime and set maxprime = 2; if that is not case increment maxprime.
    while ( n > maxPrime){
        if (n % maxPrime == 0){
            n = n / maxPrime;
            maxPrime = 2;
        }
        else
        {
            maxPrime++;
        }
        
    }

    return maxPrime;
    
}
