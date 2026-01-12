#include <stdio.h>

int main() {
    // Parallel Arrays
    // names[i] stores the name, ages[i] stores the age for the same student
    char names[10][50]; 
    int ages[10];
    
    int i;

    // 1. Input Loop
    printf("--- Enter Data for 10 Students ---\n");
    for (i = 0; i < 10; i++) {
        printf("Student %d Name: ", i + 1);
        scanf("%s", names[i]); // Reads a single word name
        
        do
        {
            printf("Student %d Age: ", i + 1);
        scanf("%d", &ages[i]);
        } while (ages[i]<0);
        printf("\n");
    }

    // 2. Processing/Output Loop
    printf("\n--- Students between 15 and 25 years old ---\n");
    
    int found = 0; // Flag to check if we found anyone
    
    for (i = 0; i < 10; i++) {
        // Check the condition: Age must be >= 15 AND <= 25
        // Condition ? (True Action 1, True Action 2) : (False Action)
        (ages[i] >= 15 && ages[i] <= 25) ? (printf("%s (Age: %d)\n", names[i], ages[i]), found = 1) : 0;
    }

    // You can even do the final check with a ternary operator
    (found == 0) ? printf("No students found in this age range.\n") : 0;

    return 0;
}