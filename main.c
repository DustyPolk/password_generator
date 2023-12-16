#include <stdio.h>
#include <stdlib.h>
#include "password_generator.h"
#include <string.h>

#define MAX_PASSWORD_LENGTH 256

void clear_input_buffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int get_input(const char* prompt, int min, int max) {
    int value;
    int result;
    do {
        printf("%s", prompt);
        result = scanf("%d", &value);
        clear_input_buffer();
        if (result != 1 || value < min || value > max) {
            printf("Invalid input. Please enter a number between %d and %d.\n", min, max);
        }
    } while (result != 1 || value < min || value > max);
    return value;
}

int main() {
    size_t length = get_input("Enter password length: ", 1, MAX_PASSWORD_LENGTH);
    int include_special_chars = get_input("Include special characters? (0 = No, 1 = Yes): ", 0, 1);
    int include_capital_letters = get_input("Include capital letters? (0 = No, 1 = Yes): ", 0, 1);

    char* password = generate_password(length, include_special_chars, include_capital_letters);

    if (password) {
        printf("Generated password: %s\n", password);
        memset(password, 0, length); // overwrite the password in memory
        free(password); // remember to free the allocated memory
    } else {
        printf("Failed to generate password.\n");
    }

    return 0;
}