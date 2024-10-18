#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node
{
    int data;          // Data stored in the node
    struct Node *prev; // Pointer to the previous node
    struct Node *next; // Pointer to the next node
};

struct Node *createNode(int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1); // Or handle the error appropriately
    }
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// Function to insert a node at the front of the list
struct Node *insertAtFront(struct Node **head, int data)
{
    struct Node *new_node = createNode(data);
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    new_node->next = *head;
    (*head)->prev = new_node;
    *head = new_node;

    return new_node;
}

// Function to insert a node at the end of the list
struct Node *insertAtEnd(struct Node **head, int data)
{
    // Create a new node
    struct Node *new_node = createNode(data);

    // If the list is empty, new node becomes the head
    if (*head == NULL)
    {
        *head = new_node;
        return new_node;
    }

    // Traverse to the last node of the list
    struct Node *current = *head;
    while (current->next != NULL)
        current = current->next;

    // Update the next of the last node and prev of the new node
    current->next = new_node;
    new_node->prev = current;

    return new_node;
}

// Function to remove a node from the list
void removeNode(struct Node **head, struct Node *nodeToRemove)
{
    if (*head == NULL || nodeToRemove == NULL)
    {
        printf("Invalid operation: either the list is empty or the node to remove is NULL.\n");
        return;
    }

    // Case 1: Removing the head node
    if (*head == nodeToRemove)
    {
        *head = nodeToRemove->next; // Update head to the next node
    }
    // Case 2: Adjust the previous node's next pointer, if it exists
    if (nodeToRemove->prev != NULL)
    {
        nodeToRemove->prev->next = nodeToRemove->next;
    }

    // Case 3: Adjust the next node's prev pointer, if it exists
    if (nodeToRemove->next != NULL)
    {
        nodeToRemove->next->prev = nodeToRemove->prev;
    }

    free(nodeToRemove);
}

// Function to print the list from head to tail
void printList(struct Node *head)
{
    while (head->next != NULL)
    {
        printf("%i ", head->data);
        head = head->next;
    }
    printf("%i ", head->data);
    printf("\n\n");
}

// Function to print the list from tail to head (backwards)
void printListReverse(struct Node *head)
{
    // Traverse to the last node of the list
    while (head->next != NULL)
        head = head->next;

    printf("%i ", head->data);
    while (head->prev != NULL)
    {
        printf("%i ", head->data);
        head = head->prev;
    }
    printf("\n\n");
}
