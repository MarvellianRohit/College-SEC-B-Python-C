#include <stdio.h>
#include <stdlib.h>

// Node Structure
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
struct Node* createList(int n);
struct Node* reverseList(struct Node* head);
void displayList(struct Node* head);

int main() {
    int n;
    struct Node* head = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input!\n");
        return 0;
    }

    // Step 1: Create the list
    head = createList(n);

    printf("\nOriginal List:\n");
    displayList(head);

    // Step 2: Reverse the list
    head = reverseList(head);

    printf("\nReversed List:\n");
    displayList(head);

    return 0;
}

// Function to create 'n' nodes
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL;

    for (int i = 1; i <= n; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &(newNode->data));
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    return head;
}

// Function to reverse the list
struct Node* reverseList(struct Node* head) {
    /* 
       Logic: We need 3 pointers to flip links without losing the rest of the list.
       1. prevNode: Points to the node *before* the current one.
       2. currentNode: Points to the node we are currently flipping.
       3. nextNode: Temporarily stores the *next* node so we don't lose it.
    */
    struct Node* prevNode = NULL;
    struct Node* currentNode = head;
    struct Node* nextNode = NULL;

    while (currentNode != NULL) {
        // Step 1: Save the next node
        nextNode = currentNode->next;

        // Step 2: Reverse the link (current now points to previous)
        currentNode->next = prevNode;

        // Step 3: Move pointers forward
        prevNode = currentNode;
        currentNode = nextNode;
    }

    // New head is the last node we processed (prevNode)
    return prevNode;
}

// Function to display the list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
