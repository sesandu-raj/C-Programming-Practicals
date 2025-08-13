# include <stdio.h>

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

    if (column > 1) {
        return column;
    } else {
        printf("Invalid input. Please enter a number greater than 1.\n");
        return getColumns();
    }
   
}

int getRows(void) {
    int row;
    printf("Enter the number of rows :");
    scanf("%d", &row);

    if (row > 1) {
        return row;
    } else {
        printf("Invalid input. Please enter a number greater than 1.\n");
        return getRows();
    }
   
}

void Box(int column, int row) {
    for (int i = 0; i < row; i++) {
        for (int j =0; j < column; j++) {
            printf("*");
        }
        printf("\n");
    }
}
