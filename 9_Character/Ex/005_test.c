// substring_test.c
#include <cmocka.h>
#include <string.h>
#include "005.c"

static void test_findString(void **state)
{
    assert_int_equal(findString("a chatterbox", "hat"), 3);
    assert_int_equal(findString("a chatterbox", "sadas"), -1);
}

int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_findString),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
