#include <cmocka.h>
#include "010.c"

static void test_compareStrings(void **state)
{
    // Test case where strings are equal
    assert_int_equal(compareStrings("hello", "hello"), 0);
    assert_int_equal(compareStrings("", ""), 0);
    assert_int_equal(compareStrings("123", "123"), 0);

    // Test case where first string is less than the second
    assert_int_equal(compareStrings("hello", "hello2"), -1);
    assert_int_equal(compareStrings(" ", ""), 1);  // Space is lexicographically greater than an empty string
    assert_int_equal(compareStrings("123 ", "123"), 1);  // "123 " is greater than "123" because of the space
}

int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_compareStrings),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
