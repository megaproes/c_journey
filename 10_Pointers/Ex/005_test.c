#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "005.c" // Include your linked list implementation

// Test case: Inserting at the front of the list
static void test_insertAtFront(void **state)
{
    (void)state; // Unused parameter

    // Initialize head to NULL
    struct Node *head = NULL;

    insertAtFront(&head, 28);
    assert_non_null(head);
    assert_int_equal(head->data, 28);
    assert_null(head->next);

    // Now insert another element
    insertAtFront(&head, 42);
    assert_int_equal(head->data, 42);
    assert_non_null(head->next);
    assert_int_equal(head->next->data, 28);
    assert_null(head->next->next);
    assert_ptr_equal(head->next->prev, head);
}

// Test case: Inserting at the end of the list
static void test_insertAtEnd(void **state)
{
    (void)state; // Unused parameter

    // Initialize head to NULL
    struct Node *head = NULL;

    // Insert a node at the end of the list (list is empty)
    insertAtEnd(&head, 15);
    assert_non_null(head);
    assert_int_equal(head->data, 15);
    assert_null(head->next);

    // Insert another node at the end
    insertAtEnd(&head, 30);
    assert_non_null(head->next);
    assert_int_equal(head->next->data, 30);
    assert_ptr_equal(head->next->prev, head);
    assert_null(head->next->next);

    // Insert another node at the end
    insertAtEnd(&head, 45);
    assert_non_null(head->next->next);
    assert_int_equal(head->next->next->data, 45);
    assert_ptr_equal(head->next->next->prev, head->next);
    assert_null(head->next->next->next);
}

int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_insertAtFront),
        cmocka_unit_test(test_insertAtEnd),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
