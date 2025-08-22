#include<stdio.h>

int positive(const char prompt[]);
float calculate_average(int score[], int size);

int main (void) {
    int size = positive("Enter the number of subjects: ");
    int array[size];

    for(int i=0; i<size; i++){
        printf("Enter marks for subject %d: ", i + 1);
        array[i] = positive(" ");
    }
    for(int i=0; i<size; i++){
        printf("Subject %d: %d\n", i+1, array[i]);
    }
    printf("\n");
    float average = calculate_average(array, size); //In C, when passing an array to a function, you should use just the array name (e.g., array), not array[]. 
    printf("Average marks: %.4f\n", average); // %.4f or %0.4f for 4 decimal places
    printf("\n");

    // Or You can Use 
    // printf("Average Marks: %2f\n", calculate_average(array, size));
}

// Function to ensure a positive integer input
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

// Function to calculate the average of an array of scores
float calculate_average(int score[], int size) { //Pass the array as score and its size
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += score[i];
    }
    return (float)sum / size;
}