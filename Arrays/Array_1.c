#include<stdio.h>
#define array_size 5

int main (){
    // Declaration and initialization of an array
    int array[array_size];
    for (int i =0; i < array_size; i++){
        printf("Enter element %d: ", i + 1);
        scanf("%d", &array[i]); 
    }
    printf("\n");

    // Displaying the elements of the array
    for(int i = 0; i < array_size; i++){
        printf("Element %d: %d\n", i + 1, array[i]);
    }
    printf("\n");

    // Displaying memory addresses of the array elements
    printf("Memory addresses of the array elements:\n");
    for (int i = 0; i < array_size; i++) {
        printf("Memory address of array[%d]: %p\n", i, (void*)&array[i]);
        printf("Address of element %d: %p\n", i + 1, (void*)&array[i]);
        printf("\n");
    }
}