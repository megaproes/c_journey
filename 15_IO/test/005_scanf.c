#include <stdio.h>

int main(int argc, char const *argv[])
{
	int hours, minutes;
	int res = scanf("%d\n:%d", &hours, &minutes);
	if (res == 1)
		printf("minutes will contain garbage value\n");

	printf("hours = %d\tminutes = %d\n", hours, minutes);
	
	return 0;
}
