#include <stdlib.h>
// Definition of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node after a given node
struct Node* insertAfter(struct Node* prevNode, int newData) {
    if (prevNode == NULL) {
       
        return NULL;	
    }
    // Create a new node
    struct Node* newNode = createNode(newData);
    // Make the new node point to the next of prevNode
    newNode->next = prevNode->next;
    // Make the prevNode point to the new node
    prevNode->next = newNode;
    
    return newNode;
}

// Function to remove the node after the given node
void removeEntry(struct Node* node) {
    if (node == NULL || node->next == NULL) {
        return;  // Can't remove if node is NULL or if there's no next node
    }

    struct Node* temp = node->next;  // The node to be deleted
    node->next = node->next->next;         // Link the current node to the one after temp
    free(temp);                      // Free the memory of the node being removed
}