#include <stdio.h>
#include <string.h> // for strlen

int main (void){
    char name[100]; // Allocate space for the string, No Dynamic Memory Allocation
    printf("Enter a string: ");
    scanf("%99s", name); // This will read input until the first space with a limit of 99 characters. 100th character is reserved for null terminator.
    printf("Your string is: %s\n", name);

    for(int i=0; i<strlen(name); i++){
        printf("%c\n", name[i]);
    }
    return 0;
}