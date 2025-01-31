#include <limits.h>

unsigned bitpat_get(unsigned source, unsigned start, unsigned n)
{
	unsigned n_bits = sizeof(unsigned) * CHAR_BIT;

	// If n is zero or start position is beyond the bit width, return 0
	if (n == 0 || start >= n_bits)
		return 0;

	// Adjust n if the requested bits exceed the available bits
	if (start + n > n_bits)
		n = n_bits - start;

	// Create a mask with n ones in the least significant bits
	unsigned mask;
	if (n >= n_bits)
		mask = ~0U; // All ones
	else
		mask = (1U << n) - 1;

	// Calculate the shift amount
	unsigned shift_amount = n_bits - n - start;

	// Ensure the shift amount is within valid range
	if (shift_amount >= n_bits)
		shift_amount = 0;

	// Shift and mask to extract the bits
	unsigned result = (source >> shift_amount) & mask;

	return result;
}
