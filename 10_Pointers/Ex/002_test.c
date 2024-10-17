#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "002.c"  // Include your linked list implementation

// Test case 1: Inserting into a non-empty list
static void test_insertEntry_non_empty_list(void **state) {
    (void) state;  // Unused parameter

    // Create linked list entries
    struct entry e1 = {1, NULL};
    struct entry e2 = {2, NULL};
    struct entry newEntry = {3, NULL};  // New entry to insert

    // Link the list
    e1.next = &e2;

    // Insert newEntry after e1
    insertEntry(&newEntry, &e1);

    // Check if the new entry is correctly inserted
    assert_ptr_equal(e1.next, &newEntry);
    assert_ptr_equal(newEntry.next, &e2);
    assert_int_equal(e1.value, 1);
    assert_int_equal(newEntry.value, 3);
    assert_int_equal(e2.value, 2);
    
    assert_int_equal(e1.next->next->value, 2);
    assert_int_equal(e2.next, NULL);
    
}

// Test case 2: Inserting at the end of the list
static void test_insertEntry_end_of_list(void **state) {
    (void) state;  // Unused parameter

    // Create linked list entries
    struct entry e1 = {1, NULL};
    struct entry e2 = {2, NULL};
    struct entry newEntry = {3, NULL};  // New entry to insert

    // Link the list
    e1.next = &e2;

    // Insert newEntry after e2 (end of list)
    insertEntry(&newEntry, &e2);

    // Check if the new entry is correctly inserted
    assert_ptr_equal(e2.next, &newEntry);
    assert_null(newEntry.next);  // newEntry should point to NULL (end of list)
    assert_int_equal(e2.value, 2);
    assert_int_equal(newEntry.value, 3);
}

// Test case 3: Inserting into an empty list (edge case)
static void test_insertEntry_empty_list(void **state) {
    (void) state;  // Unused parameter

    // Create the entry to insert
    struct entry newEntry = {1, NULL};

    // Insert into an empty list (this test depends on how you want to handle empty lists)
    // Here, we simulate an "after" entry as NULL for the test's purpose
    struct entry dummy = {0, NULL};
    insertEntry(&newEntry, &dummy);  // Insert after dummy

    // Check if the new entry is correctly inserted after dummy
    assert_ptr_equal(dummy.next, &newEntry);
    assert_null(newEntry.next);
    assert_int_equal(newEntry.value, 1);
}

// Test case 4: Insert when _after is NULL (edge case)
static void test_insertEntry_null_after(void **state) {
    (void) state;  // Unused parameter

    // Create the entry to insert
    struct entry newEntry = {1, NULL};

    // Call insertEntry with a NULL _after (should not crash)
    insertEntry(&newEntry, NULL);

    // Ensure no modifications or crashes happen
    assert_null(newEntry.next);  // Ensure next of newEntry remains unchanged
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_insertEntry_non_empty_list),
        cmocka_unit_test(test_insertEntry_end_of_list),
        cmocka_unit_test(test_insertEntry_empty_list),
        cmocka_unit_test(test_insertEntry_null_after),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
