#include<stdio.h>
#include<string.h>

int main (void){
    int no_of_students;
    printf("Enter the number of students: ");
    scanf("%d", &no_of_students);

    char names[no_of_students][50];
    int name_lengths[no_of_students];

    for(int i = 0; i < no_of_students; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%49s", names[i]); 
        int length = strlen(names[i]);
        name_lengths[i] = length;
        printf("Length of name %s: %d\n",names[i], name_lengths[i]);
    }

    printf("Names of students:\n");
    for(int i = 0; i < no_of_students; i++) {
        printf("%s\n", names[i]);
    }

    printf("%c, %c, %c\n", names[0][0], names[0][1], names[0][2]);
    printf("%c, %c, %c\n", names[1][0], names[1][1], names[1][2]);
    printf("%c, %c, %c\n", names[2][0], names[2][1], names[2][2]);  

    return 0;

}
