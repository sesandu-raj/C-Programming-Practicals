#include <stdio.h>

int main() {
    int i, j;
    int n = 6; // size of the heart

    for(i = n/2; i <= n; i += 2) {
        // left spaces
        for(j = 1; j < n-i; j += 2)
            printf(" ");
        // left stars
        for(j = 1; j <= i; j++)
            printf("*");
        // middle spaces
        for(j = 1; j <= n-i; j++)
            printf(" ");
        // right stars
        for(j = 1; j <= i; j++)
            printf("*");
        printf("\n");
    }

    // lower part
    for(i = n; i >= 1; i--) {
        // left spaces
        for(j = 0; j < n-i; j++)
            printf(" ");
        // stars
        for(j = 1; j <= (i*2)-1; j++)
            printf("*");
        printf("\n");
    }

    return 0;
}