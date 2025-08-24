#include <stdio.h>
#include <string.h>

int main() {
    char input[100];

    printf("Enter a string: ");
    
    fgets(input, sizeof(input), stdin);
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }
    printf("You entered: \"%s\"\n", input);

    return 0;
}