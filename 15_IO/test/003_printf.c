#include <stdio.h>
#include <limits.h>
int main(int argc, char const *argv[])
{
	double val = 123.456;
	printf("|%+08.2f|\n", val); // |+0123.46|

	// Using flags, variable width, and variable precision together.
	printf("|%0*.*f|\n", 10, 3, 12.34567); // |000012.346|

	printf("|%+0*.*f|\n", 10, 3, 12.34567); // |+00012.346|

	printf("|%+0*.*f|\n", 10, 3, 12.34567); // |+00012.346|

	printf("|%+*.*f|\n", 10, 3, 12.34567); // |   +12.346|
	
	printf("|%-*.*f|\n", 10, 3, 12.34567); // |+12.346   |
	return 0;
}
