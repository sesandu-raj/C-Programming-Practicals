#include<stdio.h>

int positive(const char prompt[]);
int multiplication_table(int number,int table_size, int array[]);

int main (void) {
    printf("Multiplication Table\n");
    int number = positive("Enter a positive integer for the multiplication table: ");
    int table_size = positive("Enter the size of the multiplication table: ");

    int array[table_size];

    multiplication_table(number, table_size, array);
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

int multiplication_table(int number,int table_size, int array[]) {
    for(int i = 0; i < table_size; i++) {
        array[i] = number * (i + 1);
    }
    printf("Multiplication table of %d:\n", number);
    for(int i = 0; i < table_size; i++) {
        printf("%d x %d = %d\n", number, i + 1, array[i]);
    }
    return 0;
}