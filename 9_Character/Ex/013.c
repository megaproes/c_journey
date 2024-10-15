#include <string.h>
void uppercase(char source[])
{
    int len = strlen(source);  // Store the length of the string once
    for (int i = 0; i < len; i++)
    {
        if (source[i] >= 'a' && source[i] <= 'z')
            source[i] = source[i] - ('a' - 'A');  // Avoid magic number
    }
}
