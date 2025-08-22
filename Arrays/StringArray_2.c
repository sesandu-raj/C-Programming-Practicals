#include <stdio.h>
#include <string.h> // for strlen

int main (void){
    char name[100]; // Allocate space for the string, No Dynamic Memory Allocation
    printf("Enter a string: ");
    scanf("%99s", name); // This will read input until the first space with a limit of 99 characters. 100th character is reserved for null terminator.
    printf("Your string is: %s\n", name);

    for(int i=0; i<strlen(name); i++){
        printf("%c %i\n", name[i], name[i]);
    }
    printf("\n");

    char secret[100]; // Allocate space for the string, No Dynamic Memory Allocation
    for(int i=0; i<strlen(name); i++){
        secret[i] = name[i] + 1; // Increment each character by 1
        printf("%c %i\n", secret[i], secret[i]);
    }
    secret[strlen(name)] = '\0'; // Null-terminate the secret string
    printf("Your secret string is: %s\n", secret);
    return 0;
}