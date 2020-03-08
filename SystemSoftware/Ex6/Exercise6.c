/*
Name:       Exercise6.c
Authors:    Joni Vilokki & Markus Klemelä
Description: Check if given input is integer and
             then determine if it's palindrome in binary
             or decimal system.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int isInputDigit(char *arr);
int isPalindromeInDecimal(int number);
int reverseBit(int number);
int isPalindromeInBinary(int number);
char *decimalToBinary(int number);

int main (){

    int number = 0;
    char userInput[20];
    char *binaryNumber = NULL;
    
    printf("Give 1 integer less than 65535.\n Program will determine if number is palindrome in binary or decimal systems \n");
    scanf("%s", userInput);

    if(!isInputDigit(userInput)){
        printf("Incorrect input. Exiting from program.");
        return 0;
    }

    else{
         number = atoi(userInput);
        if (number > 65535 || atoi(userInput) == -1){
            printf(" Too large number. Maximum number of 16bit decimal is 65535 \n");
            exit(0);
        }
        binaryNumber = decimalToBinary(number);

        if(binaryNumber == NULL){
            printf("Something went wrong. Exiting from program");
            return 0;
        }

        if (isPalindromeInDecimal(number) && isPalindromeInBinary(number)){
            printf("Number %d (%s) is double palindrome\n", number, binaryNumber);
        }
        else if (isPalindromeInBinary(number)){
           printf("Number %d (%s) is palindrome in binary system.\n", number, binaryNumber);
        }

        else if (isPalindromeInDecimal(number)){
           printf("Number %d (%s) is palindrome in decimal system.\n", number, binaryNumber);
        }
        else{
            printf("Number %d (%s) is not palindrome.\n", number, binaryNumber);
        }
        
    }
    free(binaryNumber);
    return 0;

}
//Check if char array contains only digits.
int isInputDigit(char *arr){
    int len = strlen(arr);
    for(int i = 0; i < len; i++)
    {
        if(!isdigit(arr[i])){
            return 0;
        }
    }
    return 1;
}

int isPalindromeInDecimal(int number){

    int reversedNumber = 0;
    int rem = 0;
    int originalNumber = 0;

    originalNumber = number;

    while(number!=0){
        rem = number%10;
        reversedNumber = reversedNumber*10 + rem;
        number = number/10;
    }

    if(originalNumber == reversedNumber){
        return 1;
    }

    else{
        return 0;
    }

}

int isPalindromeInBinary(int number){
    int reversed = reverseBit(number);

    if (number == reversed){
        return 1;
    }
    else{
        return 0;
    }
}

int reverseBit(int number){
    int reversed = 0;

    while(number > 0){

        reversed <<= 1;

        if((number & 1) == 1){
            reversed ^= 1;
        }

        number >>= 1;
    }
    return reversed;    
}

char *decimalToBinary(int number) {
    int counter = 0;
    int div = 0;

    char *pointer = NULL;
    pointer = (char*)malloc(16+1);

    if(pointer == NULL){
        printf("Memory allocation was not succesful. Exiting from program");
        exit(1);
    }

    for (int i = 15; i >= 0; i--){
        div = number >> i;

        if(div & 1){
            *(pointer + counter) = 1 + '0';
        }
        else{
            *(pointer + counter) = 0 + '0';
        }
        
        counter++;
    }
    *(pointer + counter) = '\0';

    return pointer;

}