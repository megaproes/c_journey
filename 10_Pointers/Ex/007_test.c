#include <cmocka.h>
#include "007.c"

static void test_sort(void **state)
{
	int array[] = {5, 4, 3, 2, 1};
	
	int *a_ptr = array;
	sort(a_ptr, 5);
	
	assert_int_equal(*a_ptr, 1);
	assert_int_equal(*(a_ptr + 1), 2);
	assert_int_equal(*(a_ptr + 2), 3);
	assert_int_equal(*(a_ptr + 3), 4);
	assert_int_equal(*(a_ptr + 4), 5);
}

int main(void)
{
	const struct CMUnitTest tests[] = {
	    cmocka_unit_test(test_sort),

	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}
