#include<stdio.h>
#include <stdlib.h> // for malloc and free
#include <ctype.h> // for isspace()

// This program calculates the average marks of students in multiple subjects and determines their positions based on the average marks.
int positive(const char prompt[]);
float calculate_average(int score[], int size);
char *get_string(const char *prompt);
void Position(double average[],char *student_names[], int No_of_Students);

int main (void){
    printf("Average Counter\n");

    int No_of_Students = positive("Enter the number of students: ");
    char *student_names[No_of_Students];

    int subjects = positive("Enter the number of subjects: ");
    int subject[subjects];

    double average_marks[No_of_Students];

    for(int i=0; i<No_of_Students; i++){
        printf("Enter the name of student %d:\n", i + 1);
        char *name = get_string("Name: ");
        if (!name) {
            printf("Memory error!\n");
            return 1;
        }
        student_names[i] = name; // Store the pointer

        printf("Marks for %s:\n", name);

        for(int j=0; j<subjects; j++){
            printf("Subject %d: ", j + 1);
            subject[j] = positive(" ");
        }

        int average = calculate_average(subject, subjects);
        average_marks[i] = average; // Store the average for each student
        printf("Average marks for %s: %.2f\n", name, average_marks[i]);
    }

    printf("\n");
    Position(average_marks, student_names, No_of_Students);

    // Free memory for names after loop
    for(int i=0; i<No_of_Students; i++){
        free(student_names[i]);
    }
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

float calculate_average(int score[], int size) { //Pass the array as score and its size
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += score[i];
    }
    return (float)sum / size;
}

char *get_string(const char *prompt) {
    printf("%s", prompt);
    int capacity = 16, length = 0;
    char *buffer = malloc(capacity);
    if (!buffer) return NULL;

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        if (length >= capacity - 1) {
            capacity *= 2;
            char *temp = realloc(buffer, capacity);
            if (!temp) { free(buffer); return NULL; }
            buffer = temp;
        }
        buffer[length++] = (char)c;
    }
    buffer[length] = '\0';
    return buffer;
}

void Position(double average[],char *student_names[], int No_of_Students){
    for (int i =0; i< No_of_Students; i++){

        if (average[i] > average[i+1]){
            printf("%s is in position %d\n", student_names[i], i + 1);
        } else if (average[i] < average[i+1]){
            printf("%s is in position %d\n", student_names[i+1], i + 1);
        } else {
            printf("%s and %s are in the same position %d\n", student_names[i], student_names[i+1], i + 1);
        }

    }
    
}