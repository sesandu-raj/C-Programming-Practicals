#include <stdio.h>
#include <stdlib.h>

// Function prototype
char *get_string(const char *prompt);

// Function to get a string from the user
int main (void){
    char *text = get_string("Enter a sentence: ");
    if (!text) {
        printf("Memory error!\n");
        return 1;
    }

    printf("You entered: %s\n", text);

    free(text);
    return 0;
}

// Function to read a string from standard input
char *get_string(const char *prompt) {
    printf("%s", prompt);
    int capacity = 16, length = 0;
    char *buffer = malloc(capacity); // Allocate initial memory for the string
    if (!buffer) return NULL; // Check if memory allocation was successful

    int c;
    while ((c = getchar()) != '\n' && c != EOF) // Read characters until newline or EOF
    {
        if (length >= capacity - 1) {
            capacity *= 2;
            char *temp = realloc(buffer, capacity);
            if (!temp) { free(buffer); return NULL; }
            buffer = temp;
        }
        buffer[length++] = (char)c; // Store the character in the buffer
    }
    buffer[length] = '\0'; // Null-terminate the string
    return buffer; // Return the dynamically allocated string
}