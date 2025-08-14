#include<stdio.h>

int main(void){
    int x = 5;
    for(int i = 0; i<x; i++){
        for(int space = 0; space < (x-i-1); space++){
                printf("  ");
            }
        for(int j = 0; j < (2*i+1); j++){
            printf("* ");
        }
        printf("\n");
    }

    for(int i = (x-2); i>=0; i--){
        for(int space = 0; space < (x-i-1); space++){
                printf("  ");
            }
        for(int j = 0; j < (2*i+1); j++){
            printf("* ");
        }
        printf("\n");
    }
}