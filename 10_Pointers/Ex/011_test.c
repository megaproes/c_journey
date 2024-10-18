#include <cmocka.h>
#include "011.c"

static void test_dateUpdate(void **state)
{
    // Create a test date (for example, December 31, 2023)
    struct date today = {12, 31, 2023};

    // Call dateUpdate to increment the date
    dateUpdate(&today);

    // Assert that the date is updated correctly (January 1, 2024)
    assert_int_equal(today.day, 1);
    assert_int_equal(today.month, 1);
    assert_int_equal(today.year, 2024);

    // Another test case: February 28, 2024 (leap year)
    struct date leapYearDate = {2, 28, 2024};
    dateUpdate(&leapYearDate);

    // Assert that the date is updated correctly (February 29, 2024)
    assert_int_equal(leapYearDate.day, 29);
    assert_int_equal(leapYearDate.month, 2);
    assert_int_equal(leapYearDate.year, 2024);
}

int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_dateUpdate),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
