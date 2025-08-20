#include<stdio.h>

int positive(const char prompt[]);
char *get_string(const char *prompt);

int main (void) {

    int size = positive("Enter the number of elements in the array: ");
    int array[size];

    for(int i=0; i<size; i++){
        array[i] = positive("Enter a positive integer: ");
    }

    for(int i=0; i<size; i++){
        printf("Element %d: %d\n", i+1, array[i]);
    }

}

int positive(const char prompt[]){
int value;
int success;

do{
    printf("%s", prompt);
    success = scanf("%d", &value);

    //clear leftover characters in the input buffer
    while (getchar() != '\n');

    if(success!= 1){
        printf("Invalid input. Letters are not allowed. Please enter a positive integer.\n");
    }

    else if (value < 1){
        printf("Invalid input. Please enter a positive integer.\n");
    }
}
while (success != 1 || value < 1);

return value;
}

