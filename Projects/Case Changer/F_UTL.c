#include<stdio.h>
#include<string.h> //for strlen
#include <stdlib.h> // for malloc and free
#include <ctype.h> // for isspace()

char *get_string(const char *prompt);
char *f_utl(char ToLower[]);

int main (void) {

    char *text = get_string("Enter a the name: "); // Prompt for user input and pass it to get_string
    if (!text) // Check if memory allocation was successful
    {
        printf("Memory error!\n");
        return 1;
    }
    
    for (int i = 0; i < strlen(text); i++) // Or you can use "for(int i = 0; array[i] != '\0'; i++)"
    {
        printf("Element %d: %c , %d,  %p \n", i+1, text[i], text[i], (void*)&text[i]);
    }

    printf("The length of the string excluding spaces is: %lu \n", strlen(text));

    printf("Before : %s\n", text); // Print the string
    //Lets convert the text to UPPERCASE
    printf("Covert string to UPPERCASE:\n");
    printf("After : %s\n", f_utl(text));

    free(text); // Free the allocated memory
}

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

char *f_utl(char ToLower[]){
    char *upper_text = malloc(strlen(ToLower) + 1);
    if (!upper_text) {
        printf("Memory error!\n");
        free(ToLower);
        return NULL;
    }

    for(int i = 0; i < strlen(ToLower); i++) {
        if(ToLower[i] >= 'A' && ToLower[i] <= 'Z') {
            upper_text[i] = ToLower[i] + 32;  // Convert to uppercase
        } else {
            upper_text[i] = ToLower[i]; // Copy as is
        }
    }
    upper_text[strlen(ToLower)] = '\0'; // Null-terminate

    // printf("After : %s\n", upper_text);

    // for (int i = 0; i < strlen(upper_text); i++) 
    // {
        // printf("Element %d: %c , %d,  %p \n", i+1, upper_text[i], upper_text[i], (void*)&upper_text[i]);
    // }
    return upper_text;
    free(upper_text);
}