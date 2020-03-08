/*
Name: Exercise5.c
Authors: Joni Vilokki & Markus Klemelä
Description: Struct where you can add elements and then function for printing them
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//Struct decleration
struct language
{
    char name[50];
    char isoCode[10];
    char family[50];
    float numberOfSpeakers;

};
//Function declerations
void addLanguage(int count,struct language *pointer, char *name, char *isoCode, char *family, float numberofSpeakers);
void printLanguages(int count, struct language *pointer);
int isInputDigit(char *arr);
void clearInputBuffer();

int main (){
    //Variable initializations
    struct language *pointer = NULL;
    int numberOfLanguages = 0;
    char userInputNumber[10];
    char givenName[50];
    char givenIsoCode[10];
    char givenFamily[50];
    float givenNumberOfSpeakers = 0.0;
    int isNameSet = 0;

    //Get user input to char array. Pass that char array to isInputDigit function wich returns true if
    //char array contains only integers.
    printf("How many languages you want to add? ");
    scanf("%s", userInputNumber);
    if(!isInputDigit(userInputNumber)){
        printf("\nIncorrect input. Exiting from program \n");
        return 0;
    }
    
    else{
            //cast char array to integer with atoi function
            numberOfLanguages = atoi(userInputNumber);
            //Allocate memory for language structs.
            pointer = (struct language*) malloc(numberOfLanguages * sizeof(struct language));
            //Clear input because reasons
            clearInputBuffer();

            //Check if memory allocation was succesful. if not pointer is null and we need to exit from program
            if(pointer == NULL){
                printf("Memory Allocation was not succesful. Exiting from program\n");
                return 0;
            
            }
            else{
                //Loop number of times according to user input. in each loop ask for infomation and save them to local variables
                //at the end of each loop add information to struct
                for(int i = 0; i < numberOfLanguages; i++){
                    printf("Enter language name: ");
                    fgets(givenName,sizeof(givenName),stdin);

                    if(givenName[0] == 10){
                        isNameSet = 0;

                        while(!isNameSet){
                            printf("Please Enter Correct name: ");
                            fgets(givenName,sizeof(givenName),stdin);

                            if(givenName[0] != 10){
                                isNameSet = 1;
                            }
                        }
                    }

                    printf("Enter ISO 639-1 code: ");
                    fgets(givenIsoCode, sizeof(givenIsoCode),stdin);
                    
                    printf("Enter family: ");
                    fgets(givenFamily, sizeof(givenFamily),stdin);

                    printf("Give number of speakers in million: ");
                    scanf("%f", &givenNumberOfSpeakers);

                    clearInputBuffer();
                    addLanguage(i,pointer,givenName,givenIsoCode,givenFamily,givenNumberOfSpeakers);
                    printf("\n");
                }
            
            printLanguages(numberOfLanguages, pointer);
            
            free(pointer);

            printf("\n");
            return 0;
        }
    }
}
//FUnction for adding language information to struct
void addLanguage(int count,struct language *pointer, char *name, char *isoCode, char *family, float numberofSpeakers){
        
    strcpy((pointer + count)->name, name);
    strcpy((pointer + count)->family,family);
    strcpy((pointer + count)->isoCode, isoCode);
    (pointer + count)->numberOfSpeakers = numberofSpeakers;

}
//Function for printing the whole struct array
void printLanguages(int count, struct language *pointer){
    printf("\n *** LIST OF LANGUAGES  ***");
    for(int i = 0; i < count; i++){
        printf("\n");
        printf("\nName:\t\t%s", (pointer + i)->name);
        printf("ISO:\t\t%s", (pointer + i) ->isoCode);
        printf("Family:\t\t%s", (pointer + i)->family);
        printf("Speakers:\t%.2f", (pointer + i)->numberOfSpeakers);
    }
    
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
//Clears stdin buffer. Use this after every scanf
void clearInputBuffer(){
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF) { }
}
