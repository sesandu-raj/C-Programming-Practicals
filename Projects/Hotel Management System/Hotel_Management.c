#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

// Global 2D array for tables (4 rows x 8 columns)
// '0' represents available, 'X' represents booked
char tables[4][8];

// Structure to hold food information
typedef struct {
    char name[20];
    float price;
    int quantity;
} FoodItem;

// --- Function Prototypes ---
void viewFoodPrices(FoodItem foods[], int *count);
void placeOrder(FoodItem foods[], int count);
void bookTable();
void exitProgram();
void initializeTables();

int main() {
    int choice;
    FoodItem foods[10]; // Max 10 items
    int foodCount = 0;

    // Initialize tables to '0' at start
    initializeTables();

    // Main Menu Loop
    do {
        printf("\n========================================\n");
        printf("       Restaurant Management System     \n");
        printf("========================================\n");
        printf("1. View Food Prices\n");
        printf("2. Place an Order / View Final Bill\n");
        printf("3. Book a Table\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        
        if (scanf("%d", &choice) != 1) {
            // Clear input buffer if user types non-integer
            while(getchar() != '\n');
            choice = 0;
        }

        switch(choice) {
            case 1:
                // Pass pointer to foodCount to update it after reading file
                viewFoodPrices(foods, &foodCount);
                break;
            case 2:
                // Ensure data is loaded before ordering
                if (foodCount == 0) {
                    viewFoodPrices(foods, &foodCount); 
                }
                placeOrder(foods, foodCount);
                break;
            case 3:
                bookTable();
                break;
            case 4:
                exitProgram();
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// --- Function Implementations ---

// Initialize all tables to '0' (Available)
void initializeTables() {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 8; j++) {
            tables[i][j] = '0';
        }
    }
}

// 1. View Food Prices
void viewFoodPrices(FoodItem foods[], int *count) {
    FILE *file = fopen("foods.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open foods.txt.\n");
        return;
    }

    *count = 0; // Reset count
    // Read formatted data: Name Price Name Price ...
    while (fscanf(file, "%s %f", foods[*count].name, &foods[*count].price) != EOF) {
        (*count)++;
    }
    fclose(file);

    // Display formatted output
    printf("\n\"%-10s\",\"%s\"\n", "Food Item", "Price");
    printf(",\"===\"\n");
    
    for (int i = 0; i < *count; i++) {
        printf("\"%-10s\",\"%.2f\"\n", foods[i].name, foods[i].price);
    }
}

// 2. Place Order & Generate Bill
void placeOrder(FoodItem foods[], int count) {
    float grandTotal = 0.0;
    
    printf("\n--- Place Your Order ---\n");
    // Get quantities for each item
    for (int i = 0; i < count; i++) {
        printf("Enter quantity for %s: ", foods[i].name);
        scanf("%d", &foods[i].quantity);
    }

    // Display Bill on Screen
    printf("\n\"%-10s\",\"%-8s\",\"%-10s\",\"%s\"\n", "Food Item", "Quantity", "Unit Price", "Sub Total");
    printf("\"===\"\n");

    for (int i = 0; i < count; i++) {
        if (foods[i].quantity > 0) {
            float subTotal = foods[i].price * foods[i].quantity;
            grandTotal += subTotal;
            printf("\"%-10s\",\"%-8d\",\"%-10.2f\",\"%.2f\"\n", 
                   foods[i].name, foods[i].quantity, foods[i].price, subTotal);
        }
    }
    printf("\"%-10s\",,,\"%.2f\"\n", "Total", grandTotal);

    // Save Bill to File
    FILE *billFile = fopen("bill.txt", "w");
    if (billFile != NULL) {
        fprintf(billFile, "\"Food Item\",\"Quantity\",\"Unit Price\",\"Sub Total\"\n");
        fprintf(billFile, "\"===\"\n");
        
        for (int i = 0; i < count; i++) {
            if (foods[i].quantity > 0) {
                float subTotal = foods[i].price * foods[i].quantity;
                fprintf(billFile, "\"%s\",\"%d\",\"%.2f\",\"%.2f\"\n", 
                       foods[i].name, foods[i].quantity, foods[i].price, subTotal);
            }
        }
        fprintf(billFile, "\"Total\",,,\"%.2f\"\n", grandTotal);
        fclose(billFile);
        printf("\nBill saved to 'bill.txt' successfully.\n");
    } else {
        printf("Error saving bill file.\n");
    }
}

// 3. Book a Table
void bookTable() {
    int row_number, column_number;

    // Display Available Tables
    printf("\n==== Available Tables of the Restaurant ====\n");
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 8; j++) {
            printf("%c", tables[i][j]);
        }
        printf("\n");
    }
    printf("\nAvailable Tables - 0\nNot Available Tables - X\n");

    // Get User Input (1-based index for user friendliness, convert to 0-based)
    printf("\nEnter row number (1-4): ");
    scanf("%d", &row_number);
    printf("Enter column number (1-8): ");
    scanf("%d", &column_number);

    // Validate Input
    if (row_number < 1 || row_number > 4 || column_number < 1 || column_number > 8) {
        printf("Invalid seat selection!\n");
        return;
    }

    // Check availability
    if (tables[row_number - 1][column_number - 1] == 'X') {
        printf("Sorry, that table is already booked!\n");
    } else {
        // Update table to 'X'
        tables[row_number - 1][column_number - 1] = 'X';
        printf("Table booked successfully!\n");
    }

    // Display Updated Table Matrix
    printf("\n==== Selected Table of the Restaurant ====\n");
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 8; j++) {
            printf("%c", tables[i][j]);
        }
        printf("\n");
    }
    printf("\nAvailable Tables - 0\nNot Available Tables - X\n");
}

// 4. Exit Program
void exitProgram() {
    printf("\nHave a Nice Day!\n");
}