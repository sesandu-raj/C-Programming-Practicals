#include<stdio.h>
#include <stdlib.h> // for malloc and realloc
#include <ctype.h> // for isspace()

// This program demonstrates dynamic memory allocation for a string input
char *get_string(const char *prompt);

// Function to calculate the length of a string excluding spaces
int string_length(const char *name);

// Main function to demonstrate the usage of dynamic string input
int main (void){
    char *text = get_string("Enter a the name: "); // Prompt for user input and pass it to get_string
    if (!text) // Check if memory allocation was successful
    {
        printf("Memory error!\n");
        return 1;
    }
    
    for (int i = 0; i < string_length(text); i++) // Or you can use "for(int i = 0; array[i] != '\0'; i++)"
    {
        printf("Element %d: %c , %d,  %p \n", i+1,text[i],text[i], (void*)&text[i]);
    }

    printf("The length of the string excluding spaces is: %d \n", string_length(text));
    free(text); // Free the allocated memory
    return 0;
}

// Function to get a string input from the user
char *get_string(const char *prompt) {
    printf("%s", prompt);
    int capacity = 16, length = 0;
    char *buffer = malloc(capacity);
    if (!buffer) return NULL;

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        if (length >= capacity - 1) {
            capacity *= 2;
            char *temp = realloc(buffer, capacity);
            if (!temp) { free(buffer); return NULL; }
            buffer = temp;
        }
        buffer[length++] = (char)c;
    }
    buffer[length] = '\0';
    return buffer;
}

// Function to calculate the length of a string excluding spaces
int string_length(const char *name){
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        if (!isspace(name[i])) {
            count++;
        }
    }
    return count;
}