#include <stdio.h>

void star_arrow() {
    int x = 11; // arrow head size

    // --- Arrow Head (Pyramid) ---
    for (int i = 0; i < x; i++) {
        for (int space = 0; space < (x - i - 1); space++) {
            printf("  ");
        }
        for (int j = 0; j < (2 * i + 1); j++) {
            printf("* ");
        }
        printf("\n");
    }

    // --- Arrow Tail ---
    int tail_height = x;   // length of tail
    int tail_width = ((2*x-1)/3);    // width of tail (stars per row)
    for (int i = 0; i < tail_height; i++) {
        for (int space = 0; space < x - tail_width/2 - 1; space++) {
            printf("  ");
        }
        for (int j = 0; j < tail_width; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

int main() {
    star_arrow();
    return 0;
}
