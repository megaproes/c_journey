#include <cmocka.h>
#include "006.c"

static void test_bitpat_search(void **state)
{
	(void)state; // Unused variable

	// Test case 1: Corrected example from problem description
	assert_int_equal(bitpat_search(0xe1f4, 0x5, 3), 27);

	// Test case 2: Pattern found at index 16
	assert_int_equal(bitpat_search(0xe1f4, 0x7, 3), 16);

	// Test case 3: Pattern at the start (bits 0-2)
	assert_int_equal(bitpat_search(0xC0000000, 0x6, 3), 0); // 110 at bits 0-2

	// Test case 4: Pattern at the end (bits 29-31)
	assert_int_equal(bitpat_search(0x00000005, 0x5, 3), 29); // 101 at bits 29-31

	// Test case 5: Pattern occurs multiple times, return first occurrence
	assert_int_equal(bitpat_search(0xAAAAAAAA, 0x5, 3), 0); // Pattern '101' in '101010...'

	// Test case 6: Zero-length pattern (n = 0)
	assert_int_equal(bitpat_search(0xFFFFFFFF, 0x0, 0), 0);

	// Test case 7: Pattern matches entire source
	assert_int_equal(bitpat_search(0xFFFFFFFF, 0xFFFFFFFF, 32), 0);

	// Test case 8: Pattern larger than source
	assert_int_equal(bitpat_search(0xF, 0x1F, 5), -1);

	// Test case 9: Pattern in the middle
	unsigned int source = 0x0F0F0F0F;
	unsigned int pattern = 0xF0F;
	unsigned int n = 12;
	assert_int_equal(bitpat_search(source, pattern, n), 4);

	// Test case 10: Source and pattern are zeros
	assert_int_equal(bitpat_search(0x0, 0x0, 0), 0);
	// Test case 11: Pattern with leading zeros
	assert_int_equal(bitpat_search(0x00100000, 0x1, 5), 7); // Pattern '00001' at bits 7-11

	// Test case 12: Source is zero, non-zero pattern
	assert_int_equal(bitpat_search(0x0, 0x1, 1), -1);

	// Test case 13: Full bit width, pattern matching source
	unsigned int source2 = 0x12345678;
	unsigned int pattern2 = 0x12345678;
	assert_int_equal(bitpat_search(source2, pattern2, 32), 0);

	// Test case 14: Full bit width, pattern not matching source
	unsigned int pattern3 = 0x87654321;
	assert_int_equal(bitpat_search(source2, pattern3, 32), -1);

	// Test case 15: Pattern not in source
	assert_int_equal(bitpat_search(0xAAAAAAAA, 0x55555555, 32), -1);

	// Test case 16: Pattern at multiple positions, return first occurrence
	unsigned int source3 = 0xF0F0F0F0;
	unsigned int pattern4 = 0xF0F;
	assert_int_equal(bitpat_search(source3, pattern4, 12), 0);

	// Corrected Test case 17: Pattern overlaps with itself
	unsigned int source4 = 0b00000000000000000000000000011111;
	unsigned int pattern5 = 0b111;
	assert_int_equal(bitpat_search(source4, pattern5, 3), 27);

	// Corrected Test case 18: Pattern at the very end
	assert_int_equal(bitpat_search(0x80000001, 0x1, 1), 0);

	// Test case 19: Pattern is zero, non-zero source
	assert_int_equal(bitpat_search(0xFFFFFFFF, 0x0, 1), -1);

	// Corrected Test case 20: Pattern with leading zeros at the start
	assert_int_equal(bitpat_search(0x08000000, 0x1, 5), 0); // Pattern '00001' at bits 0-4
}

int main(void)
{
	const struct CMUnitTest tests[] = {
	    cmocka_unit_test(test_bitpat_search),
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}
