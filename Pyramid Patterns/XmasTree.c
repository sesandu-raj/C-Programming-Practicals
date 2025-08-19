#include <stdio.h>

void printXmasTree(int height) {
    int i, j, k;
    int width = 2 * height - 1;

    // Print tree leaves
    for (i = 1; i <= height; i++) {
        for (j = 1; j <= height - i; j++)
            printf(" ");
        for (k = 1; k <= 2 * i - 1; k++)
            printf("*");
        printf("\n");
    }

    // Print trunk
    for (i = 0; i < height / 3; i++) {
        for (j = 1; j <= height - 2; j++)
            printf(" ");
        printf("***\n");
    }
}

int main() {
    int height;
    printf("Enter the height of the Xmas tree: ");
    scanf("%d", &height);

    printXmasTree(height);

    return 0;
}