#include <stdio.h>
#include <stdalign.h>
struct Inner
{
	char x;
	int y;
};
struct S2
{
	char a;
	char b;
	int c;
};
struct Inner2
{
	char x;
	int y;
};

struct S7
{
	int a;
	struct Inner2 b;
};
struct Inner3
{
	short x;
	char y;
};

struct S8
{
	struct Inner3 a;
	double b;
};
union U9
{
	int a;
	char b[4];
};

struct S9
{
	char c;
	union U9 u;
};
struct S13
{

	char a;
	unsigned int b : 3;
	unsigned int c : 5;
	unsigned int d : 8;
};

int main(int argc, char const *argv[])
{
	printf("size  is %i\n", sizeof(unsigned int));
	printf("int align is %i\n", alignof(int));
	printf("short align is %i\n", alignof(short));
	printf("double align is %i\n", alignof(double));
	printf("char align is %i\n", alignof(char));
	printf("long align is %i\n", alignof(long));
	printf("float align is %i\n", alignof(float));
	printf("S7 size is %i\n", sizeof(struct S7));
	printf("S8 size is %i\n", sizeof(struct S8));
	printf("S8 size is %i\n", sizeof(struct S9));
	printf("S13 size is %i\n", sizeof(struct S13));
	return 0;
}
