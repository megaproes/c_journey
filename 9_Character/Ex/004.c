#include <stdio.h>
#include <string.h>

void substring(const char string[], int start, int count, char result[])
{
    // Get the length of the input string
    int length = strlen(string);
    
    // If start is out of bounds, return an empty string
    if (start >= length || start < 0 || count < 0) {
        result[0] = '\0'; // Set result as an empty string
        return;
    }

    int i;
    for (i = 0; i < count && string[start] != '\0'; i++) {
        result[i] = string[start++];
    }

    result[i] = '\0'; // Ensure result is null-terminated
}

// int main(void)
// {
//     char result[100];
//     substring("hello world", 50, 100, result);
//     printf("Result: '%s'\n", result);  // Should print an empty string
//     return 0;
// }
