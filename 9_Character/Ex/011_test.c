#include <cmocka.h>
#include <string.h>
#include "011.c"
static void test_strToInt(void **state)
{
}

int main(void)
{
	const struct CMUnitTest tests[] = {
	    cmocka_unit_test(test_strToInt),
	};

	// Run the tests
	return cmocka_run_group_tests(tests, NULL, NULL);
}
