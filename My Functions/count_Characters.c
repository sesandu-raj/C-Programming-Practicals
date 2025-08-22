#include <stdio.h>
#include <string.h> // for strlen

int count_characters(const char *str); 

int main (void) {
    printf("Enter a string: ");
    char name[100]; // Allocate space for the string
    fgets(name, sizeof(name), stdin); // Read the whole line
    // Remove trailing newline if present
    size_t len = strlen(name);
    if (len > 0 && name[len - 1] == '\n') {
        name[len - 1] = '\0';
    }
    printf("Your string is: %s\n", name);
    printf("Character count (excluding spaces): %d\n", count_characters(name));
    return 0;
}

int count_characters(const char *str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            count++;
        }
    }
    return count;
}