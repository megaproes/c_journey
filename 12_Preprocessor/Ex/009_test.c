#include <cmocka.h>
#include "009.h" // The header where ABSOLUTE_VALUE is defined

static void test_absolute_value(void **state)
{
    (void) state; // Unused parameter

    // Basic positive and negative values
    assert_int_equal(ABSOLUTE_VALUE(5), 5);
    assert_int_equal(ABSOLUTE_VALUE(-5), 5);
    assert_int_equal(ABSOLUTE_VALUE(0), 0);

    // Expressions inside the macro
    assert_int_equal(ABSOLUTE_VALUE(3 - 7), 4);
    assert_int_equal(ABSOLUTE_VALUE(-10 + 2), 8);
    assert_int_equal(ABSOLUTE_VALUE(4 * -3), 12);

    // Large negative number
    assert_int_equal(ABSOLUTE_VALUE(-2147483647), 2147483647);

    // Check with floating point numbers (if macro supports it)
    assert_true(ABSOLUTE_VALUE(-5.5) == 5.5);
    assert_true(ABSOLUTE_VALUE(3.14) == 3.14);
}

int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_absolute_value),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
