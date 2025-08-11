# include <stdio.h>

int positive(void);
void Box(int column, int row);
int getColumns(void);
int getRows(void);

int main(void){
    int column = getColumns();
    int row = getRows();
    Box(column, row);
}

int getColumns(void) {
    int column;
    printf("Enter the number of columns :");
    scanf("%d", &column);
    return positive();
}

int getRows(void) {
    int row;
    printf("Enter the number of rows :");
    scanf("%d", &row);
    return positive();
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
