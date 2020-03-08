/* File: Exercise1.c
 * Authors: Joni Vilokki and Markus Klemelä
 * Description: Practicing loops
 */

#include <stdio.h>

/* Do not change these. */
void oddNumbers(int lower, int upper);
void divisibleNumbers();
void sumOfMultiples();


/* Do not change main function at all. */
int main() {

	printf("Print out odd numbers between 40 and 0:\n");

	oddNumbers(0, 40);

	printf("\n\nPrint out numbers divisible by both 2 and 3 between 0 and 100:\n");

	divisibleNumbers();

	printf("\n\nPrint out the sum of multiples of 4 and 7 between 0 and 999:\n");

	sumOfMultiples();

	return 0;

}

void oddNumbers(int lower, int upper) {

	/* Your code here */

	for(int a = upper ; a > lower; a = a - 1 ) {
		if (a % 2 == 1) {
			printf("%i ", a);
		}
	}

}

void divisibleNumbers() {

	/* Your code here */
	
	for(int a = 0; a < 100; a = a + 1 ) {
		if ((a % 2 == 0) && (a % 3 == 0))
		{  
			printf("%i ", a);
		}
	}
}

void sumOfMultiples() {
	
	/* Your code here */
	
	int result = 0;
	for (int a = 0; a < 999; a + = 1) {
		if ( (a % 4 == 0) || (a % 7 == 0) ) {
			result += a;
		}

	}
	printf("Sum is:  %i \n", result);
}

