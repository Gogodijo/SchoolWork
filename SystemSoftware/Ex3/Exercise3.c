/*
 *Name:		Exercise3.c
 *Authors: 	Joni Vilokki & Markus Klemelä
 *Description:	Reading from file and sum large numbers without using
 *		any prebuild libaries for that
 */

#include <stdio.h>
#include <ctype.h>
#define ROWS 100
#define COLUMNS 50
int main() {
	//Initialize all variables and arrays.
	FILE *file = NULL;
	int carry = 0;
	int sum = 0;
	int result[51];
	char ch;
	int line = 0;
	int column = 0;
	int numberArray[COLUMNS][ROWS];
	file = fopen("Numbers.txt", "r");
	int num = 0;

	/*Read through the file char by char. Check if char is number. If it is then add it to array.
	Also when char is not number check that it's not right after last not number. For some reason
	line change count's as two characters. If you don't check it then it will do line++ and there is not
	number in file.*/
	while((ch = getc(file)) != EOF) {
		if(isdigit(ch)){
			num = ch - '0';
			numberArray[column][line] = num;
			column++;
		}		
		else{	
			if(column != 0){
				line++;
				column=0;
			}
		}
	
	}

	/*Go through each column in reversed order. And inside every column go through every row
	And add numbers to sum. Also when you start every column. Make last columns carry as this columns sum,
	then reset carry. */
	 for ( int i = COLUMNS-1; i >= 0; --i){
		sum = carry;
		carry = 0;
		for (int j = 0; j < ROWS; ++j){
			sum = sum + (numberArray[i][j]);
		}
		//Calculate carry and last number from sum
		if(i != 0){
			carry = sum / 10;
			sum = sum - carry*10;
		}
		result[i] = sum;
		
	}

	//Add final carry to result. Final result is 3 digits long so your result only needs to be 51.
	result[0] = sum;
	
	//Print out result in for loop and close file.
	for ( int i = 0; i < 50; ++i){
		printf("%d",result[i]);
	}
	printf("\n");
	fclose(file);
	return 0;
}

