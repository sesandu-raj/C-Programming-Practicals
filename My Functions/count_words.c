#include<stdio.h>
#include <stdlib.h>
#include <ctype.h> // for isspace()

char *get_string(const char *prompt);
int count_words(const char *str);

int main (void) {
    char *paragraph = get_string("Enter a sentence: ");
    if (!paragraph) {
        printf("Memory error!\n");
        return 1;
    }
    int words = count_words(paragraph);
    printf("Word count: %d\n", words);

    free(paragraph);
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

int count_words(const char *str) {
    int count = 0;
    int in_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i])) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            count++;
        }
    }
    return count;
}