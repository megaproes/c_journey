#include <cmocka.h>
#include "008.h" // The header where IS_DIGIT and IS_SPECIAL are defined

static void test_is_digit(void **state)
{
	(void)state; // Unused parameter

	// Test digit characters (should return nonzero)
	assert_true(IS_DIGIT('0'));
	assert_true(IS_DIGIT('5'));
	assert_true(IS_DIGIT('9'));

	// Test non-digit characters (should return 0)
	assert_false(IS_DIGIT('a'));
	assert_false(IS_DIGIT('Z'));
	assert_false(IS_DIGIT('!'));
	assert_false(IS_DIGIT(' '));
}

static void test_is_special(void **state)
{
	(void)state; // Unused parameter

	// Test special characters (should return nonzero)
	assert_true(IS_SPECIAL('!'));
	assert_true(IS_SPECIAL('@'));
	assert_true(IS_SPECIAL('#'));
	assert_true(IS_SPECIAL(' '));	 // Space should be considered special
	assert_true(IS_SPECIAL('\n')); // Newline should be considered special
	assert_true(IS_SPECIAL('\t')); // Tab should be considered special
	assert_true(IS_SPECIAL('['));
	assert_true(IS_SPECIAL('`'));

	// Test alphabetic characters (should return 0)
	assert_false(IS_SPECIAL('A'));
	assert_false(IS_SPECIAL('z'));

	// Test digits (should return 0)
	assert_false(IS_SPECIAL('0'));
	assert_false(IS_SPECIAL('5'));
	assert_false(IS_SPECIAL('9'));
}
static void test_is_special_fail(void **state)
{
    (void) state; // Unused parameter

    // This should return 1 (true), but it incorrectly returns 0 (false)
    assert_true(IS_SPECIAL('!')); 
}

int main(void)
{
	const struct CMUnitTest tests[] = {
	    cmocka_unit_test(test_is_digit),
	    cmocka_unit_test(test_is_special),
	    cmocka_unit_test(test_is_special_fail),
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}
