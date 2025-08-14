#include <stdio.h>
int main(void){
    int x = 5;
    for(int i = 0 ; i < x; i++){
        for(int j = 0; j < x; j++){
            if(j>=i)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}