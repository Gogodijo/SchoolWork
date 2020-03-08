/*
    Name: Exercise4.c
    Authors: Joni Vilokki & Markus Klemelä
    Description: Take one integer from user as commandline argument.
    Make Array as long as input, and fill it with random integers. Find largest
    prime factor for each integer in array.
*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "PrimeFactors.h"

int random();
int isInt(char* str);
int isValidArgument(int argc, char *ar);

int main(int argc, char *argv[]){
    /* Initialize all variables */
    int arraySize = 0;
    int *numbers = NULL;
    int *largestPrimes = NULL;
    int temp = 0;
    /*Check that user has correct input. It has to be convertable to int and there can only be 1 parameter
    if input was not correct, print error and exit from program*/ 
    if(!isValidArgument(argc, argv[1])){
        exit(0);
    }
    /*If user has entered correct input*/
    else{
        /* Initialize random timer and allocate memory for array*/
        srand(time(NULL));
        arraySize = atoi(argv[1]);
        numbers = (int*) calloc(arraySize, sizeof(int));
        largestPrimes = (int*) calloc(arraySize, sizeof(int));
        
    
        /*If memory allocation was not succesful print error and exit from program*/
        if(numbers == NULL || largestPrimes == NULL){
            printf("Unable to allocate memory. Exiting from program");
            exit(0);
        }

        /*Memory allocation was succesful. Fill array with random ints*/
        else{
            for(int i = 0; i < arraySize; i++){
                temp = random();
                *(numbers + i) = temp;
                *(largestPrimes + i) = primeFactor(temp);
            }
            //Commented section only for demonstration purposes. 
            for(int i = 0; i < arraySize; i++)
            {
                if(*(numbers+i) == 0 || *(numbers+i) == 1 ){
                    printf("By definition there is no primefactor for %d \n", *(numbers+i));
                }
                else
                {
                   printf("Largest prime factor of %d is %d \n", *(numbers+ i), *(largestPrimes + i) );
                }
                
            }
            
        }
        free(numbers);
        free(largestPrimes);
    }
    
    return 0;
}
/*Return random integer*/
int random(){
    int rnd = rand() % 1000001;
    return rnd;
}
/*Return 0 if input is not only positive integers. return 1 if input is only positive integers*/
int isInt (char* str){
    int a = strlen(str);
    for(int i = 0; i < a; i++)
    {
        if(!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

int isValidArgument(int argc, char *ar){
       if(argc != 2){
        printf("Invalid amount of commandline arguments \n");
        return 0;
    }
    
    else if(!isInt(ar)){
        printf("Argument is not positive integer \n");
        return 0;
    }
    return 1;

}
