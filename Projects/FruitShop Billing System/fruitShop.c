#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FRUITS 10
#define INPUT_FILE "fruits.txt"
#define OUTPUT_FILE "bill.txt"

// Structure to hold fruit details
typedef struct {
    char name[20];
    float price;
    int quantity;
} Fruit;

// Function Prototypes
void viewPrices(Fruit fruits[], int count);
void calculateBill(Fruit fruits[], int count);
void exitProgram();

int main() {
    Fruit fruits[MAX_FRUITS];
    int count = 0;
    int choice;
    FILE *file; // Declare the variable. This is a special data type defined in C (inside <stdio.h>). It contains all the information needed to control a file (like where the file starts, where the cursor is currently reading, etc.).

    // 1. Load data from text file
    file = fopen(INPUT_FILE, "r");
    if (file == NULL) {
        printf("Error: Could not open %s. Please create the file first.\n", INPUT_FILE);
        return 1;
    }

    // Read fruits until End Of File (EOF)
    while (fscanf(file, "%s %f", fruits[count].name, &fruits[count].price) != EOF) {
        count++;
    }
    fclose(file);

    // 2. Main Menu Loop
    printf("\nWelcome to ABC Shop\n");
    
    while (1) {
        printf("\n------------------------\n");
        printf("Press 1: Display the unit prices.\n");
        printf("Press 2: Calculate the total bill.\n");
        printf("Press 3: Exit the program.\n");
        printf("------------------------\n");
        printf("Select an option: ");
        
        if (scanf("%d", &choice) != 1) {
            // Handle non-integer input to prevent infinite loops
            while(getchar() != '\n'); 
            choice = 0;
        }

        switch (choice) {
            case 1:
                viewPrices(fruits, count);
                break;
            case 2:
                calculateBill(fruits, count);
                break;
            case 3:
                exitProgram();
                return 0; // End program
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}

// Function 1: View unit prices
void viewPrices(Fruit fruits[], int count) {
    printf("\n--- Unit Prices ---\n");
    printf("%-10s %s\n", "Item", "Price (Rs)");
    printf("-------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10s %.2f\n", fruits[i].name, fruits[i].price);
    }
}

// Function 2: Calculate bill and write to file
void calculateBill(Fruit fruits[], int count) {
    float total = 0.0;
    FILE *outFile;

    printf("\n--- Enter Quantities ---\n");
    
    // Get quantities from user
    for (int i = 0; i < count; i++) {
        printf("Enter the quantity of %s: ", fruits[i].name);
        scanf("%d", &fruits[i].quantity);
        total += fruits[i].price * fruits[i].quantity;
    }

    // Display Total on Screen
    printf("\nThe total is: Rs. %.2f\n", total);

    // Write to file (CSV format)
    outFile = fopen(OUTPUT_FILE, "w");
    if (outFile == NULL) {
        printf("Error: Could not save bill to file.\n");
        return;
    }

    // Writing header and data in CSV format (Comma Separated Values)
    fprintf(outFile, "\"Item\",\"Unit Price\",\"Quantity\",\"Total\"\n");
    
    for (int i = 0; i < count; i++) {
        float lineTotal = fruits[i].price * fruits[i].quantity;
        fprintf(outFile, "\"%s\",\"%.2f\",\"%d\",\"%.2f\"\n", 
                fruits[i].name, fruits[i].price, fruits[i].quantity, lineTotal);
    }
    
    fprintf(outFile, "\n\"Grand Total\",,,\"Rs. %.2f\"\n", total);
    
    fclose(outFile);
    printf("Bill saved successfully to %s\n", OUTPUT_FILE);
}

// Function 3: Exit message
void exitProgram() {
    printf("\nGood Bye!\n");
}