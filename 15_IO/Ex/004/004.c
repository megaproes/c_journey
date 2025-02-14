#include <stdio.h>

int main(void)
{
	FILE *in1 = fopen("in1.txt", "r");
	FILE *in2 = fopen("in2.txt", "r");

	if (!in1 || !in2)
	{
		perror("Error opening input files");
		return 1;
	}

	char buffer1[1024], buffer2[1024];
	_Bool in1_end = 1, in2_end = 1;

	while (in1_end || in2_end)
	{
		if (fgets(buffer1, sizeof(buffer1), in1))
			fputs(buffer1, stdout);
		else
			in1_end = 0;

		if (fgets(buffer2, sizeof(buffer2), in2))
			fputs(buffer2, stdout);
		else
			in2_end = 0;
	}

	fclose(in1);
	fclose(in2);

	return 0;
}
