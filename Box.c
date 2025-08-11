# include <stdio.h>

int positive(void);
void Box(int column, int row);

int main(void){
    int column = positive();
    int row = positive();
    Box(column, row);
}

int positive(void) {
    int value;
    do
    {
        printf("Enter the number of rows :");
        scanf("%d", &value);
    } 
    while (value<1);
    return value;
}

void Box(int column, int row) {
    for (int i = 0; i < row; i++) {
        for (int j =0; j < column; j++) {
            printf("*");
        }
        printf("\n");
    }
}
