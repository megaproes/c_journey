#include <cmocka.h>
#include "007.c" 

static void test_bitpat_get(void **state)
{
	(void)state; // Unused variable

	// Test case 1: Extract leftmost 3 bits
	assert_int_equal(bitpat_get(0xF0F0F0F0, 0, 3), 0b111);

	// Corrected Test case 2: Extract bits starting at position 3, count 5
	assert_int_equal(bitpat_get(0xF0F0F0F0, 3, 5), 0b10000);

	// Test case 3: Extract bits from the middle
	assert_int_equal(bitpat_get(0x12345678, 8, 8), 0x34);

	// Test case 4: Extract bits from the end
	assert_int_equal(bitpat_get(0x12345678, 28, 4), 0x8);

	// Test case 5: Extract all bits
	unsigned source = 0xDEADBEEF;
	unsigned n_bits = sizeof(unsigned) * 8;
	assert_int_equal(bitpat_get(source, 0, n_bits), source);

	// Test case 6: Extract zero bits
	assert_int_equal(bitpat_get(0xFFFFFFFF, 0, 0), 0);

	// Test case 7: Start position out of bounds (greater than bit width)
	// Expected behavior might be to return 0 or handle error
	assert_int_equal(bitpat_get(0xFFFFFFFF, 32, 1), 0);

	// Test case 8: Start position plus n exceeds bit width
	assert_int_equal(bitpat_get(0xFFFFFFFF, 30, 5), 0b11);

	// Test case 9: Extract bits with start at last bit
	assert_int_equal(bitpat_get(0x80000001, 31, 1), 0x1);

	// Test case 10: Extract bits with n = 1
	assert_int_equal(bitpat_get(0xAAAAAAAA, 0, 1), 0x1);

	// Test case 11: Extract bits with n = bit width
	assert_int_equal(bitpat_get(0x12345678, 0, sizeof(unsigned) * 8), 0x12345678);

	// Test case 12: Extract bits when source is zero
	assert_int_equal(bitpat_get(0x0, 10, 5), 0x0);

	// Test case 13: Extract bits with start position in the middle
	assert_int_equal(bitpat_get(0xFFFFFFFF, 16, 8), 0xFF);

	// Test case 14: Extract bits from a pattern of alternating bits
	assert_int_equal(bitpat_get(0xAAAAAAAA, 4, 8), 0xAA);

	// Test case 15: Extract bits when n is zero
	assert_int_equal(bitpat_get(0x12345678, 10, 0), 0x0);

	// Test case 16: Extract bits beyond the range
	assert_int_equal(bitpat_get(0xFFFFFFFF, 31, 2), 0x1);

	// Test case 17: Extract bits with start position zero and n zero
	assert_int_equal(bitpat_get(0x12345678, 0, 0), 0x0);

	// Test case 18: Extract bits with start position at maximum and n = 1
	assert_int_equal(bitpat_get(0x80000000, 0, 1), 0x1);

	// Test case 19: Extract bits with start position at maximum valid value
	assert_int_equal(bitpat_get(0x1, sizeof(unsigned) * 8 - 1, 1), 0x1);

	// Test case 20: Extract bits with n greater than available bits
	assert_int_equal(bitpat_get(0xFFFFFFFF, 28, 8), 0xF);
}

int main(void)
{
	const struct CMUnitTest tests[] = {
	    cmocka_unit_test(test_bitpat_get),
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}
