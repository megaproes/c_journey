#include <stdio.h>
#include <limits.h>
#include <limits.h>
void bitpat_set(unsigned *source, unsigned value, unsigned start, unsigned size)
{
	unsigned n_bits = sizeof(unsigned) * CHAR_BIT;

	// Step 2: Handle edge cases
	if (size == 0 || start >= n_bits)
		return;
	if (start + size > n_bits)
		size = n_bits - start;

	// Step 3: Create a mask for the bits to modify
	unsigned mask = size == n_bits ? UINT_MAX : (1U << size) - 1;
	unsigned shift_amount = n_bits - size - start;
	mask <<= shift_amount;

	// Step 4: Prepare the value for insertion
	unsigned value_mask = size == n_bits ? UINT_MAX : ((1U << size) - 1);

	unsigned shift_amount2 = 0;
	if (size < start && start + size == n_bits)
		shift_amount2 = shift_amount;
	else
		shift_amount2 = n_bits - size;

	unsigned value_prepared = (value & value_mask) << shift_amount2;

	// Step 5: Clear the target bits in source
	*source &= ~mask;

	// Step 6: Insert the prepared value into source
	*source |= value_prepared;
}

int main(int argc, char const *argv[])
{
	unsigned x4 = 0xFFFFFFFF;
	bitpat_set(&x4, 0x55u, 12, 20);

	unsigned i = UINT_MAX;
	return 0;
}
