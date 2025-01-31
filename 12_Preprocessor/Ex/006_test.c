#include <cmocka.h>
#include "006.h" // The header where IS_UPPER_CASE is defined

static void test_is_upper_case(void **state)
{
	(void)state; // Unused parameter

	// Test uppercase letters
	assert_true(IS_UPPER_CASE('A'));
	assert_true(IS_UPPER_CASE('Z'));
	assert_true(IS_UPPER_CASE('M'));

	// Test lowercase letters (should return 0)
	assert_false(IS_UPPER_CASE('a'));
	assert_false(IS_UPPER_CASE('z'));
	assert_false(IS_UPPER_CASE('m'));

	// Test numbers (should return 0)
	assert_false(IS_UPPER_CASE('0'));
	assert_false(IS_UPPER_CASE('9'));

	// Test special characters (should return 0)
	assert_false(IS_UPPER_CASE('!'));
	assert_false(IS_UPPER_CASE('@'));
	assert_false(IS_UPPER_CASE('['));
	assert_false(IS_UPPER_CASE('`'));
}

int main(void)
{
	const struct CMUnitTest tests[] = {
	    cmocka_unit_test(test_is_upper_case),
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}
