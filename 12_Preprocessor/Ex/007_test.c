#include <cmocka.h>
#include "007.h" // The header where IS_ALPHABETIC is defined

static void test_is_alphabetic(void **state)
{
	(void)state; // Unused parameter

	// Test uppercase letters (should return nonzero)
	assert_true(IS_ALPHABETIC('A'));
	assert_true(IS_ALPHABETIC('Z'));
	assert_true(IS_ALPHABETIC('M'));

	// Test lowercase letters (should return nonzero)
	assert_true(IS_ALPHABETIC('a'));
	assert_true(IS_ALPHABETIC('z'));
	assert_true(IS_ALPHABETIC('m'));

	// Test numbers (should return 0)
	assert_false(IS_ALPHABETIC('0'));
	assert_false(IS_ALPHABETIC('9'));

	// Test special characters (should return 0)
	assert_false(IS_ALPHABETIC('!'));
	assert_false(IS_ALPHABETIC('@'));
	assert_false(IS_ALPHABETIC('['));
	assert_false(IS_ALPHABETIC('`'));
	assert_false(IS_ALPHABETIC(' ')); // Space should not be alphabetic
}

int main(void)
{
	const struct CMUnitTest tests[] = {
	    cmocka_unit_test(test_is_alphabetic),
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}
