#include <stdio.h>
#include <string.h>

// Function to check if the string is in alphabetical order
int is_alphabetical(const char str[]) {
    for (int i = 0; str[i + 1] != '\0'; i++) {
        if (str[i] > str[i + 1]) {
            return 0; // Not in order
        }
    }
    return 1; // In order
}

// Function to sort the string in alphabetical order
void sort_alphabetical(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main() {
    char input[100], sorted[100];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    strcpy(sorted, input);

    if (is_alphabetical(input)) {
        printf("The string is already in alphabetical order: %s\n", input);
    } else {
        sort_alphabetical(sorted);
        printf("The string in alphabetical order: %s\n", sorted);
    }

    return 0;
}