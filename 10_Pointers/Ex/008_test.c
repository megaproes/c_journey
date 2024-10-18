#include <cmocka.h>
#include "008.c"

static void test_sort3(void **state)
{
	int a = 5, b = 4, c = 3;

	// Call sort3() with three integer variables
	sort3(&a, &b, &c);

	// Check if they are correctly sorted
	assert_int_equal(a, 3);
	assert_int_equal(b, 4);
	assert_int_equal(c, 5);
}

int main(void)
{
	const struct CMUnitTest tests[] = {
	    cmocka_unit_test(test_sort3),

	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}
