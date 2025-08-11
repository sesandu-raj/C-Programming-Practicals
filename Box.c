# include <stdio.h>

int positive(void);
void Box(int column, int row);

int main(void){
    int column = positive();
    int row = positive();
    Box(column, row);
}

int positive(void) {
    int row;
    do
    {
        printf("Enter the number of rows :");
        scanf("%d", &row);
    } 
    while (row<1);
    return row;
}

int positive(void) {
    int column;
    do
    {
        printf("Enter the number of columns :");
        scanf("%d", &column);
    } 
    while (column<1);
    return column;
}

void Box(int column, int row) {
    for (int i = 0; i < row; i++) {
        for (int j =0; j < column; j++) {
            printf("*");
        }
        printf("\n");
    }
}
