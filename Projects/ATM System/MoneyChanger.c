#include <stdio.h>

int main() {
    int amount;
    int n5000, n1000, n500, n100, n50, n20;

    // 1. Input the amount
    printf("Enter the amount to withdraw: ");
    if (scanf("%d", &amount) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    // 2. Check the maximum limit
    if (amount > 50000) {
        printf("Error: The maximum amount you can withdraw is Rs. 50000 per transaction.\n");
    } else {
        // 3. Calculate the number of notes
        // Integer division (/) gives the count
        // Modulo (%) gives the remaining amount
        
        n5000 = amount / 5000;
        amount = amount % 5000;

        n1000 = amount / 1000;
        amount = amount % 1000;

        n500 = amount / 500;
        amount = amount % 500;

        n100 = amount / 100;
        amount = amount % 100;

        n50 = amount / 50;
        amount = amount % 50;

        n20 = amount / 20;
        amount = amount % 20; // Remaining amount after 20s (if any)

        // 4. Output the results
        printf("5000 notes : %d\n", n5000);
        printf("1000 notes : %d\n", n1000);
        printf("500 notes : %d\n", n500);
        printf("100 notes : %d\n", n100);
        printf("50 notes : %d\n", n50);
        printf("20 notes : %d\n", n20);
        
        // Optional: If there is a small remainder (like Rs. 5 or 10) that cannot be dispensed
        if (amount > 0) {
            printf("(Remaining balance not dispensable in available notes: %d)\n", amount);
        }
    }

    return 0;
}