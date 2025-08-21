#include<stdio.h>
#include <stdlib.h> // for malloc and realloc
#include <ctype.h> // for isspace()

char *get_string(const char *prompt);
void string_length(const char *name);

int main (void) {

    char *name = get_string("Enter your name: ");
    if (!name) {
        printf("Memory error!\n");
        return 1;
    }

    string_length(name);

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

void string_length(const char *name){
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        if (!isspace(name[i])) {
            count++;
        }
    }
    printf("The length of your name is: %d\n", count);
}