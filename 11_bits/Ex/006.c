#include <limits.h>

int bitpat_search(unsigned source, unsigned pattern, unsigned n)
{
	unsigned n_bits = sizeof(unsigned) * CHAR_BIT;

	// Check for invalid n
	if (n == 0 || n > n_bits)
		return -1;

	// Create a mask with n ones in the least significant bits
	unsigned mask;
	if (n == n_bits)
		mask = ~0U; // All ones
	else
		mask = (1U << n) - 1;

	// Get the rightmost n bits of pattern
	pattern &= mask;

	// Loop over possible starting positions in source
	for (unsigned i = 0; i <= n_bits - n; i++)
	{
		unsigned shift = n_bits - n - i;
		unsigned temp = (source >> shift) & mask;
		if (temp == pattern)
			return i;
	}

	return -1;
}
