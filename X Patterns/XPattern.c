#include<stdio.h>

int main(void) {
    int x = 5;
    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < x; j++)
        {
            if((i==j) || ((i+j)==(x-1)))
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}