#include <cmocka.h>
#include "003.h"

static void test_min_basic(void **state)
{
	assert_int_equal(MIN(1, 2), 1);
	assert_int_equal(MIN(-5, 0), -5);
	assert_int_equal(MIN(0, 0), 0);
}

int main(void)
{
	const struct CMUnitTest tests[] = {
	    cmocka_unit_test(test_min_basic),
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}
