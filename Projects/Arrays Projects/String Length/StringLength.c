#include<stdio.h>
#include <stdlib.h> // for malloc and realloc

char *get_string(const char *prompt);

int main (void) {

    char *name = get_string("Enter your name: ");
    if (!name) {
        printf("Memory error!\n");
        return 1;
    }
    
    int length = 0;
    while (name[length] != '\0') {
        length++;
    }

    printf("The length of your name is: %d\n", length);

    free(name); // Free the allocated memory
    return 0;
    
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

// This program counts the length of a string entered by the user, with space characters included in the count.