#include <stdio.h>

enum month {
    January, February, March, April, May, June,
    July, August, September, October, November, December
};

const char* monthName(enum month m) {
    // Array of month names indexed by enum values
    static const char* monthNames[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    // Ensure the month index is within a valid range
    if (m >= January && m <= December) {
        return monthNames[m];
    } else {
        return "Invalid Month";
    }
}

int main() {
    enum month aMonth = February;
    printf("%s\n", monthName(aMonth)); // Output: February

    return 0;
}
