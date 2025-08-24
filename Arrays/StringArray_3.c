#include<stdio.h>
#include <stdlib.h> // for malloc and realloc
#include <string.h> // for strlen

int main (void){
    char *array = malloc(50 * sizeof(char)); // Allocate memory for 50 characters. Equivalent to char array[50];
    if (!array) // Check if memory allocation was successful
    {
        printf("Memory error!\n");
        return 1;   
    }

    printf("Enter Your Name: ");
    scanf("%49s", array); // Read a string from user input with a limit of 49 characters to prevent overflow

    printf("You entered: %s\n", array); // Print the entered string
    printf("Address of array: %p\n", (void*)array); // Print the address of the array[0] because array is a pointer to the first element

    printf("\n");
    printf("The length of the string is: %lu \n", strlen(array)); // Print the length of the string
    printf("\n");

    for (int i =0; array[i] != '\0'; i++) // Iterate through the string until the null terminator
    {
        printf("Element %d: %c , %d,  %p \n", i+1, array[i], array[i], (void*)&array[i]);
    }

    free(array); // Free the allocated memory
    return 0;
}