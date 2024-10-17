#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "003.c" // Include your linked list implementation

// Test case 1: Inserting into a non-empty list
static void test_insertEntry_non_empty_list(void **state)
{
    (void)state; // Unused parameter
    
    struct Node* n1 = createNode(10);
    struct Node* n2 = createNode(20);
    struct Node* n3 = createNode(30);
    
    n1->next = n2;
    n2->next = n3;
    
    insertAfter(n1, 15);
    assert_int_equal(n1->next->data, 15);
    assert_ptr_not_equal(n1->next, n2);
}

int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_insertEntry_non_empty_list),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
