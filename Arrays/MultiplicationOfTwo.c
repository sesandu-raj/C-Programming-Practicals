#include<stdio.h>
#define table_size 12

int main (void){
    printf("Lets find the multiplication table of 2\n");
    int array[table_size];

    for(int i = 0; i < table_size; i++){
        array[i] = 2 * (i + 1);
    }

    printf("Multiplication table of 2:\n");
    for(int i = 0; i < table_size; i++){
        printf("2 x %d = %d\n", i + 1, array[i]);
    }
}