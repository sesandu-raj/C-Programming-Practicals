# include <stdio.h>

void Box(int column, int row);
int positive(const char promte[]);

int main(void){
    int column = positive("Enter the number of columns :");
    int row = positive("Enter the number of rows :");
    Box(column, row);
}

int positive(const char prompt[]){
    int value;
    int success;

    do{
        printf("%s", prompt);
        success = scanf("%d", &value);

        //clear leftover characters in the input buffer
        while (getchar() != '\n');

        if(success!= 1){
            printf("Invalid input. Letters are not allowed. Please enter a positive integer.\n");
        }

        else if (value < 1){
            printf("Invalid input. Please enter a positive integer.\n");
        }
    }
    while (success != 1 || value < 1);

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
