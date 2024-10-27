#include <cmocka.h>
#include "005.c"

static void test_bit_test(void **state)
{
	int a = 0b0001;
	assert_int_equal(1, bit_test(a, 31));

	int b = 0x80000000;
	assert_int_equal(1, bit_test(b, 0));

	int c = 0x8000;
	assert_int_equal(1, bit_test(c, 16));

	int d = 0b0011;
	assert_int_equal(1, bit_test(d, 31));
	assert_int_equal(1, bit_test(d, 30));
	assert_int_equal(0, bit_test(d, 29));
}

static void test_bit_set(void **state)
{
	int a = 0b0000;
	assert_int_equal(1, bit_set(a, 31));

	int b = 0x80000000;
	assert_int_equal(0x80000001, bit_set(b, 31));

	int c = 0x8000;
	assert_int_equal(0x80008000, bit_set(c, 0));

	int d = 0b0011;
	assert_int_equal(d, bit_set(d, 30));
	assert_int_equal(7, bit_set(d, 29));
}
int main(void)
{
	const struct CMUnitTest tests[] = {
	    cmocka_unit_test(test_bit_test),
	    cmocka_unit_test(test_bit_set),
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}
