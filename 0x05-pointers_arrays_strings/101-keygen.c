#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * generatePassword - Generates a random password
 * @password: Pointer to the password buffer
 * @length: Length of the password
 */
void generatePassword(char *password, int length) {
    /* Define the characters allowed in the password */
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    /* Seed the random number generator with the current time */
    srand((unsigned int)time(NULL));

    for (int i = 0; i < length; i++) {
        /* Generate a random index to select a character from the charset */
        int index = rand() % (sizeof(charset) - 1);

        /* Append the selected character to the password */
        password[i] = charset[index];
    }

    /* Null-terminate the password string */
    password[length] = '\0';
}

int main() {
    int passwordLength = 12; /* Change this to match your desired password length */
    char password[passwordLength + 1]; /* +1 for the null terminator */

    generatePassword(password, passwordLength);

    printf("Generated Password: %s\n", password);

    return 0;
}

