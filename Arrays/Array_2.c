#include<stdio.h>
#define array_size 5

int main (void){
    // Declaration and initialization of an array
    int score[array_size];
    score[0] = 10;
    score[1] = 20;
    score[2] = 30;
    score[3] = 40;
    score[4] = 50;

    // Displaying the elements of the array
    int sum = 0;

    for(int i =0; i < array_size; i++){
        printf("Element %d: %d\n", i + 1, score[i]);
        sum += score[i];
    }
    // Displaying the sum and average of the elements
    printf("Sum of all elements: %d\n", sum);

    printf("Average of all elements: %.2f\n", (float)sum / array_size);

    //or you can use 
    //printf("Average of all elements: %.2f\n", (float)(score[0] + score[1] + score[2] + score[3] + score[4]) / (float)array_size);
}