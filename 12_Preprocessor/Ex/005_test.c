#include <cmocka.h>
#include "005.h" // The header where SHIFT is defined

static void test_shift_basic(void **state)
{
	(void)state; // Unused parameter

	unsigned int a1 = 0b00000001;
	assert_int_equal(SHIFT(a1, 5), 0b00100000); // 1 << 5 = 32

	unsigned int a2 = 0b00100101;
	assert_int_equal(SHIFT(a2, 5), 0b10010100000); // 0b00100101 << 5

	unsigned int a3 = 0b10000000;
	assert_int_equal(SHIFT(a3, -3), 0b00010000); // Right shift by 3
}

int main(void)
{
	const struct CMUnitTest tests[] = {
	    cmocka_unit_test(test_shift_basic),
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}
