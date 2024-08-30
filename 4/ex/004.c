#include <stdio.h>

int main(int argc, char const *argv[])
{
    for (int i = 1; i <= 10; i++)
    {
        unsigned long long fact = 1;  // Use unsigned long long for larger factorials
        for (int j = 1; j <= i; j++)
        {
            fact *= j;
        }
        printf("%2i\t%llu\n", i, fact);  // Use %llu for unsigned long long output
    }

    return 0;
}
