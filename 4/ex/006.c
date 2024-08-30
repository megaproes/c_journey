#include <stdio.h>

int main() {
    int num = 42;
    char str[] = "Hello";

    // Right-justified examples
    printf("Right-justified integer: %5d\n", num);   // Right-justified within a width of 5
    printf("Right-justified string:  %10s\n", str);  // Right-justified within a width of 10

    // Left-justified examples
    printf("Left-justified integer:  %-5d\n", num);  // Left-justified within a width of 5
    printf("Left-justified string:   %-10s\n", str); // Left-justified within a width of 10

    return 0;
}
