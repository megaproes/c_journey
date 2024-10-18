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
void test_removeNode(void **state)
{
    struct Node *head = NULL;

    struct Node *n1 = insertAtEnd(&head, 45);
    struct Node *n2 = insertAtEnd(&head, 55);
    struct Node *n3 = insertAtEnd(&head, 65);
    struct Node *n4 = insertAtEnd(&head, 75);
    struct Node *n5 = insertAtEnd(&head, 85);

    removeNode(&head, n2);

    // Ensure the list structure is correct after removal
    assert_int_equal(n1->next->data, 65);
    assert_ptr_equal(n1->next, n3);
    assert_ptr_equal(n3->prev, n1);
    assert_ptr_equal(n3->next, n4);

    // n2 pointer is not guaranteed to be NULL, so remove this check
}
void test_print(void **state)
{
    struct Node *head = NULL;
    
    struct Node *n1 = insertAtEnd(&head, 45);
    struct Node *n2 = insertAtEnd(&head, 55);
    struct Node *n3 = insertAtEnd(&head, 65);
    struct Node *n4 = insertAtEnd(&head, 75);
    struct Node *n5 = insertAtEnd(&head, 85);
    printf("In normal order:\t");
    printList(head);
    
    printf("In reverse order:\t");
    printListReverse(head);
}
int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_insertAtFront),
        cmocka_unit_test(test_insertAtEnd),
        cmocka_unit_test(test_removeNode), 
        cmocka_unit_test(test_print)

    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
