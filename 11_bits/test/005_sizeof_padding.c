#include <stdio.h>
#include <stddef.h>

struct alignment_example
{
	int b;
	char a;

	char c;
};
struct mixed
{
	char a;	// 1 byte
	int b;	// 4 bytes, requires 4-byte alignment
	double c; // 8 bytes, requires 8-byte alignment
};
struct packed_struct
{
	unsigned int : 3;
	unsigned int f1 : 1;
	unsigned int f2 : 1;
	unsigned int f3 : 1;
	unsigned int type : 8;
	unsigned int index : 18;

	unsigned int f4 : 1;
};
int main()
{
	printf("Size of struct: %zu\n", sizeof(struct alignment_example));
	printf("Offset of a: %zu\n", offsetof(struct alignment_example, a));
	printf("Offset of b: %zu\n", offsetof(struct alignment_example, b));
	printf("Offset of c: %zu\n", offsetof(struct alignment_example, c));

	printf("Size of struct: %zu\n", sizeof(struct mixed));

	printf("Size of struct: %zu\n", sizeof(struct packed_struct));
	return 0;
}
