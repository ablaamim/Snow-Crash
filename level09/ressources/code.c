#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        return 1; // Exit if the correct number of arguments is not provided
    }

    char *input = argv[1];
    int index = 0;

    // Process each character
    while (input[index] != '\0') {
        // Print the character after decrementing its ASCII value by index
        putchar(input[index] - index);
        index++;
    }
    
    // Print a newline for better formatting
    putchar('\n');

    return 0;
}
