/*
Name:		Exercise2.c
Author:		Joni Vilokki And Markus Klemelä
Description: 	Random number generator, collaz sequenze and prime check
*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int collaz (int number);
int random();
void isPrime(int number);

int main() {
	srand(time(NULL));
	isPrime(collaz(random()));
	return 0;
}

int random() {
	/*Make random number mod 10001 so it's between 1-100*/
	
	int randomInt = rand() % 10001;
	return randomInt;
}

int collaz (int number) {
	int collazLength = 1;
	printf("%d ", number);
	/* Loop through numbers while it's not 1. Using conditions
	mentioned on the problem. Keep count on how many operations
	we need to do */
	while (number != 1){
		
		if ( number % 2 == 0 && number > 0){
			number = number >> 1;
			collazLength = collazLength + 1;
			printf("- %d ", number);
		}
			
		else if (number % 2 == 1 && number > 0){
			number =  3 * number + 1;
			collazLength = collazLength + 1;
			printf("- %d ",number);
		}
		
		else{
			printf("Something went horribly wrong here! \n");
			break;
		}
		
	 }
	if(collazLength > 1){
	 	printf("\nLength of collaz sequense is: %d. \n\n", collazLength);
	}

	else{
		printf("\nThere is no collaz length here. Your number was less than 1.\n\n");
	}
	return collazLength;
}

void isPrime (int number){
	int isNotPrime = 0;

	/*Loops through number untill number/2. Check is it's divisible by any
	number. If it is then break loop and set isNotPrime to true. if it is
	not divisible by any number until loop ends we know number is prime*/

	for( int i = 2; i <= number / 2; ++i){
	
		if (number % i == 0){
			isNotPrime = 1;
			break;
		}
	}
	
	if (number == 1){
		printf("1 is not a prime. But it's not a composite number either. Funny isn't it?\n");
	}
	
	else {
		if (isNotPrime == 0){
			printf("%d is a prime number. \n", number);
		}
		
		else{
			printf("%d isn't a prime number. \n", number);
		}
	}
}


