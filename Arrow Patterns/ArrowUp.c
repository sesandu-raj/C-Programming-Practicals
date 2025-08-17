#include<stdio.h>

int main(void)
{
    int height = 9;
    int centerColumn = height / 2;

    for(int i = 0; i < height; i++)
    {
        for(int j=0; j< height; j++)
        {
            // Arrow shaft
            int isShaft = (j == height / 2);

            // Arrow head (bottom half)
            int isHeadLeft = (i <= height / 2) && (j == i + height / 2);
            int isHeadRight = (i <= height / 2) && (j == height - (i + height / 2) - 1);

            // Print '*' if current position is part of the shaft or head
            if (isShaft || isHeadLeft || isHeadRight)
            {
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}