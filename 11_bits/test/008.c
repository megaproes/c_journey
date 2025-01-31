#include <stdio.h>
#include <stddef.h>

struct S13 {
    char a;
    unsigned int b : 3;
    unsigned int c : 5;
    unsigned int d : 17;
};

int main() {
    printf("Size of S13: %lu bytes\n", sizeof(struct S13));
    printf("Offset of a: %lu\n", offsetof(struct S13, a));
  
    return 0;
}
