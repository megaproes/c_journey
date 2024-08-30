#include <stdio.h>

int main(int argc, char const *argv[])
{
	float x = 2.55f;
	float result = 3 * x * x * x - 5 * x * x + 6;
	printf("%.02f\n", result);
	return 0;
}

// more idiomatic:
// #include <stdio.h>
// #include <math.h>

// int main(int argc, char const *argv[])
// {
//     const float a = 3.0f;
//     const float b = -5.0f;
//     const float c = 6.0f;
//     const float x = 2.55f;
    
//     float result = a * pow(x, 3) + b * pow(x, 2) + c;
//     printf("%.02f\n", result);
//     return 0;
// }
// also it's preferred to use double instead of float