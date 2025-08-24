#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *get_string(const char *prompt);
char *ceaser_cipher_encoder (char message[],int key_value);
char *ceaser_cipher_decoder (char message[], int key_value);
int positive(const char prompt[]);

int main (void)
{
    char *message = get_string("Enter Your Message : ");
    int key = positive("Enter the key");

    printf("\n");
    
    char *encrypted_message = ceaser_cipher_encoder(message,key);
    printf("Your Secret Message : %s \n", encrypted_message);

    printf("\n");

    char *decrypted_message = ceaser_cipher_decoder(encrypted_message, key);
    printf("Decoded Message is : %s", decrypted_message);

    free(message);
    return 0;

}

char *ceaser_cipher_encoder (char message[], int key_value){
    int length = strlen(message);
    char *secret = malloc(strlen(message)+1);
    printf("Message Encoder\n");
    printf("Character\tASCII Value\n");
    for (int i=0; i < length; i++){
        printf("'%c'\t\t%d\n", message[i], (int)message[i]);
        secret[i] = message[i] + key_value;
    }
    printf("\n");
    printf("After Ciphered \n");
    printf("Character\tASCII Value\n");
    for(int i =0; i<strlen(secret); i++){
        printf("'%c'\t\t%d\n", secret[i], (int)secret[i]);
    }
    printf("\n");
    return secret;
    free(secret);
}
char *ceaser_cipher_decoder (char message[], int key_value){
    int length = strlen(message);
    char *secret = malloc(strlen(message)+1);
    printf("Message Decoder\n");
    printf("Character\tASCII Value\n");
    for (int i=0; i < length; i++){
        printf("'%c'\t\t%d\n", message[i], (int)message[i]);
        secret[i] = message[i] - key_value;
    }
    printf("\n");
    printf("After De-Ciphered\n");
    printf("Character\tASCII Value\n");
    for(int i =0; i<strlen(secret); i++){
        printf("'%c'\t\t%d\n", secret[i], (int)secret[i]);
    }
    printf("\n");
    return secret;
    free(secret);
}

char *get_string(const char *prompt) {
    printf("%s", prompt);
    int capacity = 16, length = 0;
    char *buffer = malloc(capacity); // Allocate initial memory for the string
    if (!buffer) return NULL; // Check if memory allocation was successful

    int c;
    while ((c = getchar()) != '\n' && c != EOF) // Read characters until newline or EOF
    {
        if (length >= capacity - 1) {
            capacity *= 2;
            char *temp = realloc(buffer, capacity);
            if (!temp) { free(buffer); return NULL; }
            buffer = temp;
        }
        buffer[length++] = (char)c; // Store the character in the buffer
    }
    buffer[length] = '\0'; // Null-terminate the string
    return buffer; // Return the dynamically allocated string
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
    while (success != 1 || value < 1); // Repeat until a valid positive integer is entered

    return value; // Return the valid positive integer
}