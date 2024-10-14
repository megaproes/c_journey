#include <stdbool.h>
#include <string.h>
#include <stdbool.h>

int findString(const char str[], const char to_find[])
{
    int str_len = strlen(str);
    int find_len = strlen(to_find);

    // If the substring is longer than the original string, no match is possible
    if (find_len > str_len || to_find == "")
        return -1;

    // Loop through the main string
    for (int i = 0; i <= str_len - find_len; i++) {
        int j;

        // Check if substring matches
        for (j = 0; j < find_len; j++) {
            if (str[i + j] != to_find[j]) {
                break;
            }
        }

        // If we completed the loop, it means the substring matches
        if (j == find_len)
            return i;  // Return the starting index of the match
    }

    return -1;  // If no match was found
}
