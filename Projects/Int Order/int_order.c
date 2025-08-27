#include<stdio.h>

void accending_order(int list[], int size); 

int main (void){
    int size;
    printf("Enther the Sie of the List : ");
    scanf("%d",&size);
    int numbber_list[size];

    for(int i=0; i<size; i++){
        printf("Enter the Number %d : ",i+1);
        scanf("%d",&numbber_list[i]);
    }

    printf("\n");

    printf("Let's make the Numbers in Ascending Order\n");
    printf("Your Number List is as follows \n");
    for(int i=0; i<size; i++){
        printf("%d \n",numbber_list[i]);
    }

    printf("\n");
    printf("The Numbers in Ascending Order is as follows\n");
    accending_order(numbber_list,size);
    for(int i=0; i<size; i++){
        printf("%d ",numbber_list[i]);
    }
    
    return 0;

}

void accending_order(int list[], int size){
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(list[i]>list[j]){
                int temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}