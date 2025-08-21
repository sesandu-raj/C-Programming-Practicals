#include<stdio.h>
#include <stdlib.h> // for malloc and realloc
#include <ctype.h> // for isspace()

char *get_string(const char *prompt);

int main (void){
    char *text = get_string("Enter a the name: ");
    if (!text) {
        printf("Memory error!\n");
        return 1;
    }


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