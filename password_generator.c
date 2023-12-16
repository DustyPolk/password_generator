#include <stdlib.h>
#include <string.h>
#include <openssl/rand.h>
#include "password_generator.h"

#define NUM_SPECIAL_CHARS 33
#define NUM_LETTERS 26

const char SPECIAL_CHARS[NUM_SPECIAL_CHARS] = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
const char LETTERS[NUM_LETTERS] = "abcdefghijklmnopqrstuvwxyz";

char* generate_password(size_t length, int include_special_chars, int include_capital_letters) {
    unsigned char random_data[length];
    if (RAND_bytes(random_data, length) != 1) {
        // handle error
        return NULL;
    }

    char* password = malloc(length + 1); // allocate memory for the password
    if (!password) {
        return NULL; // return NULL if malloc failed
    }

    for (size_t i = 0; i < length; i++) {
        int type = random_data[i] % (2 + include_special_chars + include_capital_letters);
        if (type == 0) {
            password[i] = LETTERS[random_data[i] % NUM_LETTERS];
        } else if (type == 1) {
            password[i] = LETTERS[random_data[i] % NUM_LETTERS] - 'a' + 'A';
        } else {
            password[i] = SPECIAL_CHARS[random_data[i] % NUM_SPECIAL_CHARS];
        }
    }

    password[length] = '\0'; // null-terminate the password
    return password;
}