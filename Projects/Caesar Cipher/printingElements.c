#include <stdio.h>
#include <string.h>

int main() {
    char message[256];

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    // Remove newline character if present
    size_t len = strlen(message);
    if (len > 0 && message[len - 1] == '\n') {
        message[len - 1] = '\0';
    }

    printf("Character\tASCII Value\n");
    for (int i = 0; message[i] != '\0'; i++) {
        printf("'%c'\t\t%d\n", message[i], (int)message[i]);
    }

    return 0;
}