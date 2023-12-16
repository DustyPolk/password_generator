### Documentation for Password Generator Project

This documentation covers the Password Generator project, which consists of three C source files (`password_generator.h`, `password_generator.c`, `main.c`) and a `Makefile`. The project is designed to generate passwords with optional inclusion of special characters and capital letters.

#### `password_generator.h` (Header File)

-   Purpose: Declares the interface for the password generation functionality.
-   Functions:
    -   `char* generate_password(size_t length, int include_special_chars, int include_capital_letters)`:
        -   Generates a password of specified `length`.
        -   `include_special_chars`: If set to 1, includes special characters in the password.
        -   `include_capital_letters`: If set to 1, includes capital letters in the password.
        -   Returns a pointer to a dynamically allocated string containing the generated password.

#### `password_generator.c` (Source File)

-   Dependencies: `openssl/rand.h` for random number generation, `stdlib.h`, `string.h`.
-   Constants:
    -   `NUM_SPECIAL_CHARS`: Number of special characters available.
    -   `NUM_LETTERS`: Number of letters in the alphabet.
    -   `SPECIAL_CHARS` and `LETTERS`: Arrays holding the special characters and letters, respectively.
-   Function Implementation:
    -   `generate_password`:
        -   Utilizes `RAND_bytes` from OpenSSL for random data generation.
        -   Dynamically allocates memory for the password.
        -   Iterates over the length of the password, selecting characters based on random data.
        -   Handles character selection logic based on input flags.
        -   Null-terminates the password string.

#### `main.c` (Main Program File)

-   Functionality: Interacts with the user to specify password generation criteria and displays the generated password.
-   Functions:
    -   `void clear_input_buffer()`: Clears the input buffer to handle newline characters.
    -   `int get_input(const char* prompt, int min, int max)`: Fetches user input within a specified range.
    -   `int main()`: The main function.
        -   Gets user input for password criteria.
        -   Calls `generate_password` and handles the result.
        -   Secures password handling by overwriting and freeing memory.

#### `Makefile` (Build Script)

-   Compiler: `gcc`
-   Flags: Includes the current directory for header files.
-   Dependencies: Links with the OpenSSL libraries (`-lssl -lcrypto`).
-   Targets:
    -   `%.o: %.c $(DEPS)`: Compiles `.c` files to object files.
    -   `password_generator`: Links object files and dependencies to create the executable.
    -   `clean`: Removes object files and the executable for a clean rebuild.

### Compilation and Execution

1.  Compile: Run `make` to compile the project.
2.  Execute: Run `./password_generator` to start the program.

### Notes

-   Security Consideration: The use of `RAND_bytes` from OpenSSL ensures strong randomness for password generation.
-   Memory Management: It's crucial to free dynamically allocated memory to avoid leaks.
-   User Input Validation: The `main.c` file robustly handles user input, ensuring valid data for password generation.
