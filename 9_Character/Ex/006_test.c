#include <cmocka.h>
#include <string.h>
#include "006.c"

// Test function for removeString
static void test_removeString(void **state)
{
    char result[100] = {0}; // Initialize the array

    // Test case 1: Normal removal of a substring in the middle
    strcpy(result, "the wrong son");
    removeString(result, 4, 6);
    assert_string_equal(result, "the son");
    
    // Test case 2: Removing a small substring from a string with special characters
    strcpy(result, "omg_suka daun )+OK");
    removeString(result, 14, 2);
    assert_string_equal(result, "omg_suka daun OK");
    
    // Test case 3: Removing from the very end of the string
    strcpy(result, "out of bounds");
    removeString(result, 10, 5); // Trying to remove "bounds"
    assert_string_equal(result, "out of bou");
    
    // Test case 4: Trying to remove more than exists from the end
    strcpy(result, "out of bounds");
    removeString(result, 10, 50); // Removing "bounds", exceeding length
    assert_string_equal(result, "out of bou");
    
    // Test case 5: Removing with invalid index (out of bounds)
    strcpy(result, "out of bounds"); 
    removeString(result, 20, 3); // Invalid start index
    assert_string_equal(result, "out of bounds");

    // Test case 6: Empty string test
    strcpy(result, "");
    removeString(result, 0, 1);
    assert_string_equal(result, "");
    
    // Test case 7: Negative start_index or length should do nothing
    strcpy(result, "negative test");
    removeString(result, -1, 3);
    assert_string_equal(result, "negative test");
    
    removeString(result, 5, -2);
    assert_string_equal(result, "negative test");
}

int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_removeString),
    };

    // Run the tests
    return cmocka_run_group_tests(tests, NULL, NULL);
}
