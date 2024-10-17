#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "004.c" // Include your linked list implementation

// Test case: Removing the first real element
static void test_removeFirstElement(void **state) {
    (void)state; // Unused parameter

    struct Node* dummy = createNode(0);
    struct Node* n1 = insertAfter(dummy, 10);
    struct Node* n2 = insertAfter(n1, 20);

    // Remove the first real element (10)
    removeEntry(dummy);

    // Verify that the first element (dummy->next) is now 20
    assert_int_equal(dummy->next->data, 20);
}

// Test case: Removing a middle element
static void test_removeMiddleElement(void **state) {
    (void)state; // Unused parameter

    struct Node* dummy = createNode(0);
    struct Node* n1 = insertAfter(dummy, 10);
    struct Node* n2 = insertAfter(n1, 20);
    struct Node* n3 = insertAfter(n2, 30);

    // Remove the element after n1 (which is 20)
    removeEntry(n1);

    // Verify that the list looks like 0 (dummy) -> 10 -> 30 -> NULL
    assert_int_equal(n1->next->data, 30);
}

// Test case: Removing the last element
static void test_removeLastElement(void **state) {
    (void)state; // Unused parameter

    struct Node* dummy = createNode(0);
    struct Node* n1 = insertAfter(dummy, 10);
    struct Node* n2 = insertAfter(n1, 20);

    // Remove the element after n1 (which is the last element, 20)
    removeEntry(n1);

    // Verify that n1->next is now NULL
    assert_null(n1->next);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_removeFirstElement),
        cmocka_unit_test(test_removeMiddleElement),
        cmocka_unit_test(test_removeLastElement),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
