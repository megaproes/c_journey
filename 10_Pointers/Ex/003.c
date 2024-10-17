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
void insertAfter(struct Node* prevNode, int newData) {
    if (prevNode == NULL) {
       
        return;	
    }
    // Create a new node
    struct Node* newNode = createNode(newData);
    // Make the new node point to the next of prevNode
    newNode->next = prevNode->next;
    // Make the prevNode point to the new node
    prevNode->next = newNode;
}
