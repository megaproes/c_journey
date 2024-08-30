#include <stdio.h>

int main(int argc, char const *argv[])
{
    int res_1 = 365 + 7 - 365 % 7;
    printf("result1 = %d\n", res_1);

    int res_2 = 12258 + 23 - 12258 % 23;
    printf("result2 = %d\n", res_2);
    
    int res_3 = 996 + 4 - 996 % 4;  // Corrected this line
    printf("result3 = %d\n", res_3);

    return 0;
}
