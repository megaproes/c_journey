#include <cmocka.h>
#include <string.h>
#include "012.c"
static void test_strToInt(void **state)
{
	char str[] = "-867.6921";
	assert_float_equal(strToFloat(str), -867.6921, 0.00001);
	
}

int main(void)
{
	const struct CMUnitTest tests[] = {
	    cmocka_unit_test(test_strToInt),
	};

	// Run the tests
	return cmocka_run_group_tests(tests, NULL, NULL);
}
