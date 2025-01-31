#include <cmocka.h>
#include "008.c" // Assuming the implementation file is named "008.c"

static void test_bitpat_set(void **state)
{
	(void)state; // Unused variable

	unsigned int n_bits = sizeof(unsigned) * 8; // Dynamic bit width

	// Test case 1: Set leftmost 8 bits to 0x55
	unsigned x1 = 0xFFFFFFFF;
	bitpat_set(&x1, 0x55u, 0, 8);
	assert_int_equal(x1, (0x55u << (n_bits - 8)) | (0xFFFFFFFFu & ((1u << (n_bits - 8)) - 1)));

	// Test case 2: Set bits starting at position 2, size 5, to 0
	unsigned x2 = 0xFFFFFFFF;
	bitpat_set(&x2, 0u, 2, 5);
	unsigned mask2 = ~(((1u << 5) - 1) << (n_bits - 5 - 2));
	assert_int_equal(x2, 0xFFFFFFFF & mask2);

	// Test case 3: Set middle bits
	unsigned x3 = 0x12345678;
	bitpat_set(&x3, 0xABCDu, 8, 16);
	unsigned expected3 = (0x12345678 & ~(((1u << 16) - 1) << (n_bits - 16 - 8))) | ((0xABCDu & ((1u << 16) - 1)) << (n_bits - 16 - 8));
	assert_int_equal(x3, expected3);

	// // Test case 4: Set bits beyond the size of value
	unsigned x4 = 0xFFFFFFFF;
	bitpat_set(&x4, 0x55u, 12, 20);			 // Size is 20 bits, value is 0x55 (8 bits)
	unsigned shift_amount4 = n_bits - 20 - 12;	 // shift_amount4 = 0
	unsigned value_prepared4 = 0x55u << (20 - 8); // Shift left by 12 bits
	unsigned mask4 = ((1u << 20) - 1) << shift_amount4;
	unsigned expected4 = (0xFFFFFFFF & ~mask4) | (value_prepared4 << shift_amount4);
	assert_int_equal(x4, expected4);
	
	
	// Test case 5: Set all bits
	unsigned x5 = 0x0;
	bitpat_set(&x5, 0xFFFFFFFFu, 0, n_bits);
	assert_int_equal(x5, 0xFFFFFFFFu);

	// Test case 6: Set zero bits (should have no effect)
	unsigned x6 = 0x12345678;
	bitpat_set(&x6, 0x0u, 5, 0);
	assert_int_equal(x6, 0x12345678);

	// Test case 7: Start position out of bounds
	unsigned x7 = 0xFFFFFFFF;
	bitpat_set(&x7, 0x0u, n_bits, 1); // Start position beyond bit width
	assert_int_equal(x7, 0xFFFFFFFF);

	// Test case 8: Start position plus size exceeds bit width
	unsigned x8 = 0xFFFFFFFF;
	bitpat_set(&x8, 0x0u, n_bits - 2, 5); // Only bits n_bits - 2 and n_bits - 1 can be set
	unsigned expected8 = x8 & ~((1u << 2) - 1);
	assert_int_equal(x8, expected8);

	// Test case 9: Set last bit
	unsigned x9 = 0x0;
	bitpat_set(&x9, 0x1u, n_bits - 1, 1);
	assert_int_equal(x9, 0x1u);

	// Test case 10: Set first bit
	unsigned x10 = 0x0;
	bitpat_set(&x10, 0x1u, 0, 1);
	assert_int_equal(x10, 1u << (n_bits - 1));

	// Test case 11: Set bits with value larger than size (value should be truncated)
	unsigned x11 = 0x0;
	bitpat_set(&x11, 0xFFFFu, 8, 8); // Value has more bits than size
	assert_int_equal(x11, (0xFFu << (n_bits - 16)));

	// Test case 12: Set bits with size zero (should have no effect)
	unsigned x12 = 0xFFFFFFFF;
	bitpat_set(&x12, 0x0u, 10, 0);
	assert_int_equal(x12, 0xFFFFFFFF);

	// Test case 13: Set bits in the middle
	unsigned x13 = 0xAAAAAAAA;
	bitpat_set(&x13, 0x55555555u, 4, n_bits - 8);
	unsigned mask13 = ((1u << (n_bits - 8)) - 1) << 4;
	unsigned expected13 = (x13 & ~mask13) | ((0x55555555u & ((1u << (n_bits - 8)) - 1)) << 4);
	assert_int_equal(x13, expected13);

	// Test case 14: Overwrite entire source with zeros
	unsigned x14 = 0xF0F0F0F0;
	bitpat_set(&x14, 0x0u, 0, n_bits);
	assert_int_equal(x14, 0x0u);

	// Test case 15: Set bits with start position zero and size zero (no effect)
	unsigned x15 = 0x12345678;
	bitpat_set(&x15, 0x0u, 0, 0);
	assert_int_equal(x15, 0x12345678);

	// Test case 16: Set bits when value is zero
	unsigned x16 = 0xFFFFFFFF;
	bitpat_set(&x16, 0x0u, 16, 8);
	unsigned mask16 = ((1u << 8) - 1) << (n_bits - 8 - 16);
	unsigned expected16 = x16 & ~mask16;
	assert_int_equal(x16, expected16);

	// Test case 17: Set bits with value needing to be truncated
	unsigned x17 = 0x0;
	bitpat_set(&x17, 0xFFFFu, 0, 8);
	assert_int_equal(x17, 0xFFu << (n_bits - 8));

	// Corrected Test case 18: Set bits beyond available bits (only available bits are set)
	unsigned x18 = 0x0;
	bitpat_set(&x18, 0x1u, n_bits - 2, 5);
	assert_int_equal(x18, 0x1u);

	// Test case 19: Set bits with size greater than available bits from start
	unsigned x19 = 0xFFFFFFFF;
	bitpat_set(&x19, 0x0u, n_bits - 1, 5);
	unsigned expected19 = x19 & ~(1u << 0);
	assert_int_equal(x19, expected19);

	// Test case 20: Overwrite entire bitfield with zero
	unsigned x20 = 0xDEADBEEF;
	bitpat_set(&x20, 0x0u, 0, n_bits);
	assert_int_equal(x20, 0x0u);
}

int main(void)
{
	const struct CMUnitTest tests[] = {
	    cmocka_unit_test(test_bitpat_set),
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}
