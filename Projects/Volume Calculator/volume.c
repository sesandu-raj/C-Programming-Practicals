#include <stdio.h>

// Function 1: Volume of a Cube
// Uses pointers to accept the address of length and result
void calcCube(float *len, float *result) {
    *result = (*len) * (*len) * (*len);
}

// Function 2: Volume of a Cylinder
// Uses pointers to accept address of radius, height, and result
void calcCylinder(float *radius, float *height, float *result) {
    *result = 3.14 * (*radius) * (*radius) * (*height);
}

int main() {
    int choice;
    float val1, val2, volume;

    // Display Menu
    printf("--- Volume Calculator ---\n");
    printf("1. Calculate Volume of Cube\n");
    printf("2. Calculate Volume of Cylinder\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    // Ternary Operator to check validity and print status
    // Condition ? True Action : False Action
    (choice == 1 || choice == 2) 
        ? printf("\nYou selected %s calculation.\n", (choice == 1) ? "Cube" : "Cylinder")
        : printf("\nInvalid Choice!\n");

    // Logic implemented using ONLY Ternary and Comma operators (No if-else)
    (choice == 1) ? (
        printf("Enter the length: "),
        scanf("%f", &val1),
        calcCube(&val1, &volume),
        printf("Volume of Cube: %.2f\n", volume)
    ) : (choice == 2) ? (
        printf("Enter the radius: "),
        scanf("%f", &val1),
        printf("Enter the height: "),
        scanf("%f", &val2),
        calcCylinder(&val1, &val2, &volume),
        printf("Volume of Cylinder: %.2f\n", volume)
    ) : 0; // Final 'else' does nothing

    return 0;
}