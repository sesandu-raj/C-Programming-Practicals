#include<stdio.h>

int main(void) {
    int x = 9;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            printf("%c ", (i == 0 || i == x - 1 || j == 0 || j == x - 1) ? '*' : ' ');
        }
        printf("\n");
    }
}