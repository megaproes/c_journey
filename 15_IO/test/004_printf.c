#include <stdio.h>

int main(void)
{
	int i = 42;
	double d = 3.14159;
	char *str = "Hello";

	printf("Integer default: %d\n", i);
	printf("Integer with width=5: |%5d|\n", i); // |   42|
	printf("Integer left-justified (width=5): |%-5d|\n", i); // |42   |
	printf("Integer with leading zeros (width=5): |%05d|\n", i); // |00042|
	printf("Integer with precision=4: |%.4d|\n", i);			 // |0042|

	printf("\nFloating default: %f\n", d);
	printf("Floating with precision=2: %.2f\n", d);
	printf("Floating with width=8, prec=3: |%8.3f|\n", d);
	printf("Floating with leading zeros: |%08.3f|\n", d);
	printf("Floating forcing sign '+': |%+8.3f|\n", d);

	printf("\nString default: %s\n", str);
	printf("String with max 3 chars: %.3s\n", str);
	printf("String with width=10, left-justified: |%-10s|\n", str);

	return 0;
}
