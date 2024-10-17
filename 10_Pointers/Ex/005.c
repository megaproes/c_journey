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
struct Node* insertAtFront(struct Node **head, int data)
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
struct Node* insertAtEnd(struct Node **head, int data)
{
    // Create a new node
    struct Node *new_node = createNode(data);

    // If the list is empty, new node becomes the head
    if (*head == NULL)
    {
        *head = new_node;
        return;
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
    
}

// Function to print the list from head to tail
void printList(struct Node *head);

// Function to print the list from tail to head (backwards)
void printListReverse(struct Node *tail);
