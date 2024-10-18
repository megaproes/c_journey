void sort3(int *a, int *b, int *c)
{
    // Swap a and b if a > b
    if (*a > *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    // Swap a and c if a > c
    if (*a > *c) {
        int temp = *a;
        *a = *c;
        *c = temp;
    }

    // Swap b and c if b > c
    if (*b > *c) {
        int temp = *b;
        *b = *c;
        *c = temp;
    }
}
