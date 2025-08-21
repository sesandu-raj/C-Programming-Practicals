#include <stdio.h>

int main (void){
    // Declaration and initialization of a character array
    char array[] = "SESANDU";
    
    // Displaying the elements of the character array
    for(int i = 0; array[i] != '\0'; i++){
        printf("Element %d: %c\n", i + 1, array[i]);
        printf("Memory address of array[%d]: %p\n", i, (void*)&array[i]);
        printf("\n");
    }

    // Displaying the elements of the character array as integers and characters
    printf("Elements of the character array as integers and characters:\n");
    for(int i = 0; array[i] != '\0'; i++){
        printf("%i ", array[i] );
        printf("%c ", array[i] );
        printf("\n");
    }
    

    
}