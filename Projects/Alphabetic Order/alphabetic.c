#include<stdio.h>
#include<string.h>
#include<ctype.h> // for isalpha()

int main (int argc, char *argv[]){
    if (argc < 2){
        printf("Please provide a list of words as command-line arguments.\n");
        return 101;
    }

    char *text = argv[1];

    for (int i = 0; i < strlen(text); i++){
        if(!isalpha(text[i])){
            printf("Invalid input. Please enter only alphabetic characters.\n");
            return 102;
        }
    }

    // Simple bubble sort to sort the words in alphabetical order
    for (int i = 1; i < strlen(text); i++){
        if (text[i]<text[i-1]){
            printf("The words are not in alphabetical order.\n");
            return 0;
        }
        else{
            printf("The words are in alphabetical order.\n");
            return 0;
        }
    }

}