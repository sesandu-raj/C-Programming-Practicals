#include<stdio.h>

// Function prototype
int positive(const char prompt[]);

// Main function to demonstrate the positive function
int main(void){
    int number = positive("Enter a positive integer: "); // Prompt the user for a positive integer and store it in number
    printf("You entered: %d\n", number);
    return 0;
}

// Function to prompt the user for a positive integer
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