#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function returning a string literal (safe)
const char *getStringLiteral() {
    return "Hello from getStringLiteral!";
}

// Function returning dynamically allocated memory (safe, but you must free it)
char *getDynamicString() {
    char *str = (char *)malloc(20 * sizeof(char));
    if (!str) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(str, "Dynamic String");
    return str;
}

// Function demonstrating const parameters
void printString(const char *str) {
    // str[0] = 'X'; // Uncommenting this causes a compiler error because str is const
    printf("String from function: %s\n", str);
}

int main() {
    // 1. String literal: modification causes undefined behavior
    const char *strLiteral = "This is a string literal";
    // strLiteral[0] = 'X'; // Uncomment to see compilation or runtime error

    // 2. Using char array for modifiable strings
    char modifiableString[] = "Modifiable String";
    modifiableString[0] = 'M'; // Safe modification
    printf("Modified string: %s\n", modifiableString);

    // 3. `const char *` vs `char *const` vs `const char *const`
    const char *ptrToConstChar = "Pointer to const char";
    // ptrToConstChar[0] = 'P'; // Error: Cannot modify const data
    ptrToConstChar = "New String"; // Okay: pointer can change

    char *const constPtrToChar = modifiableString;
    constPtrToChar[0] = 'C'; // Okay: data can be modified
    // constPtrToChar = "Oops"; // Error: pointer cannot change

    const char *const constPtrToConstChar = "Fully constant";
    // constPtrToConstChar[0] = 'X'; // Error: cannot modify const data
    // constPtrToConstChar = "Oops"; // Error: pointer cannot change

    // 4. Returning a string literal (safe)
    const char *returnedLiteral = getStringLiteral();
    printf("Returned string literal: %s\n", returnedLiteral);

    // 5. Returning dynamically allocated string (safe, but requires free)
    char *dynamicString = getDynamicString();
    printf("Dynamically allocated string: %s\n", dynamicString);
    free(dynamicString); // Freeing allocated memory

    // 6. Pointer arithmetic with const
    const char *stringWithConst = "Hello, World!";
    printf("Pointer arithmetic: %s\n", stringWithConst + 7); // Prints "World!"

    // 7. const char ** example
    const char *str1 = "First String";
    const char *str2 = "Second String";
    const char **doublePointer = &str1;
    *doublePointer = str2; // Okay: Changing where the pointer points
    // **doublePointer = 'S'; // Error: Cannot modify const data
    printf("Double pointer points to: %s\n", *doublePointer);

    // 8. Avoiding returning local arrays
    // char *invalidString() {
    //     char localString[] = "Local Array";
    //     return localString; // Unsafe: pointer becomes invalid
    // }

    return 0;
}
