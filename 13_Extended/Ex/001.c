#include <stdio.h>

typedef int (*FunctionPtr)(void);

typedef FunctionPtr int (*)(void);

int suka(void)
{
	printf("hello!!!\n");
}
int main(int argc, char const *argv[])
{
	int (*fnptr)(void);

	FunctionPtr fnptr2 = suka;
	fnptr2();

	return 0;
}
