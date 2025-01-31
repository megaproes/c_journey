#include <stdio.h>
void printString(const char **str) {
    *str = "Another string"; // Okay
}

int main(int argc, char const *argv[])
{
	const char* sa = "sasa";
	
	printString(&sa);
	printf("%s\n", sa);
	return 0;
}
