#include<stdio.h>

int positive(const char prompt[]); 

int main (void){
    int size = positive("Enter the size of the array: ");
    int numbers[size];

    for (int i =0; i < size; i++){
        numbers[i] = (i + 1) * (i + 1); // Store the square of (i+1) in the array
        //printf("Square of %d is %d\n", i + 1, numbers[i]); // Print the square
    }

    printf("The squares of the first %d natural numbers are:\n", size);
    for (int i =0; i < size; i++){
        printf("%d \n", numbers[i]); // Print the squares
    }
    printf("\n");
    return 0;

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