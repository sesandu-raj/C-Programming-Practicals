#include<stdio.h>

int positive(const char prompt[]);

int main (void){
    int number = 5;
    printf("Guess the number between 1 and 10. You have 3 tries.\n");
    for (int i =0; i<3; i++){
        int geuss = positive("What's your guess? : ");

        if (i == 2 && geuss != number){
            printf("Sorry, you've used all your chances. The correct number was %d.\n", number);
            return 0;
        }
        else if (geuss != number){
            printf("Wrong! Try again. You have %d more chances.\n", 3-(i+1));
        }
        else{
            printf("Correct! You guessed the number.\n");
            return 0;
        }
    }
}

int positive(const char prompt[]){
    int value;
    int success;

    do{
        printf("%s", prompt);
        success = scanf("%d", &value);

        //clear leftover characters in the input buffer
        while (getchar() != '\n');

        if(success!= 1){
            printf("Invalid input. Letters are not allowed. Please enter a positive integer.\n");
        }

        else if (value < 1){
            printf("Invalid input. Please enter a positive integer.\n");
        }
    }
    while (success != 1 || value < 1); // Repeat until a valid positive integer is entered

    return value; // Return the valid positive integer
}