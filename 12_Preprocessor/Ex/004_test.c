#include <cmocka.h>
#include "004.h" // The header where MAX3 is defined

static void test_max3_basic(void **state)
{
	(void)state; // Unused parameter

	assert_int_equal(MAX3(1, 2, 3), 3);
	assert_int_equal(MAX3(10, 5, 8), 10);
	assert_int_equal(MAX3(-1, -5, -3), -1);
	assert_int_equal(MAX3(0, 0, 0), 0);
	assert_int_equal(MAX3(7, 7, 7), 7);
	assert_int_equal(MAX3(5, 10, 5), 10);
	assert_int_equal(MAX3(-10, -5, -7), -5);
	assert_int_equal(MAX3(100, 50, 200), 200);
}

int main(void)
{
	const struct CMUnitTest tests[] = {
	    cmocka_unit_test(test_max3_basic),
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}
