#include <cmocka.h>
#include <string.h>
#include "008.c"
static void test_replaceString_edge_cases(void **state)
{
    char result[100] = {0};

    // Test case: str1 not found in source
    strcpy(result, "no match here");
    replaceString(result, "xyz", "abc");
    assert_string_equal(result, "no match here");  // Should remain unchanged

    // Test case: replace at the start of the string
    strcpy(result, "wrong choice");
    replaceString(result, "wrong", "right");
    assert_string_equal(result, "right choice");

    // Test case: replace at the end of the string
    strcpy(result, "this is wrong");
    replaceString(result, "wrong", "correct");
    assert_string_equal(result, "this is correct");

    // Test case: replacing with an empty string (removal)
    strcpy(result, "remove this part");
    replaceString(result, "this part", "");
    assert_string_equal(result, "remove ");

    // Test case: str1 is empty
    strcpy(result, "some text");
    replaceString(result, "", "inserted");
    assert_string_equal(result, "some text");  // Should remain unchanged
}

int main(void)
{
	const struct CMUnitTest tests[] = {
	    cmocka_unit_test(test_replaceString_edge_cases),
	};

	// Run the tests
	return cmocka_run_group_tests(tests, NULL, NULL);
}
