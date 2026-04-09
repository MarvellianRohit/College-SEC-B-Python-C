/*
 * ============================================================
 * LINKED LIST 09: DOUBLY LINKED LIST
 * ============================================================
 * Topic: Doubly Linked List (Simplified)
 * Language: C
 * Level: 1st Year BCA
 * 
 * DETAILED EXPLANATION:
 * A Doubly Linked List (DLL) is a complex type of linked list in 
 * which each node contains a pointer to the next node as well 
 * as a pointer to the previous node. This allows for traversal 
 * in both forward and backward directions.
 *
 * ALGORITHM (Insertion at Beginning):
 * 1. START
 * 2. Create a new Node (newNode).
 * 3. Set newNode->data = value, newNode->prev = NULL, 
 *    and newNode->next = head.
 * 4. IF (head != NULL):
 *    a. Set head->prev = newNode.
 * 5. Update head = newNode.
 * 6. STOP
 * ============================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

/* Create a new doubly linked node */
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

/* Insert at beginning - returns new head */
struct Node* insertFront(struct Node *head, int val) {
    struct Node *newNode = createNode(val);
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;  /* Point old head's back to new node */
    }

    printf("  >> Inserted %d at beginning.\n", val);
    return newNode;
}

/* Insert at end - returns head */
struct Node* insertEnd(struct Node *head, int val) {
    struct Node *newNode = createNode(val);
    if (head == NULL) return newNode;

    struct Node *temp = head;
    while (temp->next != NULL) temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    printf("  >> Inserted %d at end.\n", val);
    return head;
}

/* Traverse forward */
void displayForward(struct Node *head) {
    struct Node *temp = head;
    printf("  Forward:  ");
    while (temp != NULL) {
        printf("[%d] <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* Traverse backward */
void displayBackward(struct Node *head) {
    if (head == NULL) return;
    struct Node *temp = head;
    /* First, go to the last node */
    while (temp->next != NULL) temp = temp->next;

    printf("  Backward: ");
    while (temp != NULL) {
        printf("[%d] <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;

    printf("=== DOUBLY LINKED LIST ===\n\n");

    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    
    displayForward(head);
    displayBackward(head);

    printf("\nInserting 5 at front:\n");
    head = insertFront(head, 5);
    displayForward(head);

    return 0;
}

/*
 * ============================================================
 * EXPECTED OUTPUT:
 * === DOUBLY LINKED LIST ===
 *
 *   >> Inserted 10 at end.
 *   >> Inserted 20 at end.
 *   >> Inserted 30 at end.
 *   Forward:  [10] <-> [20] <-> [30] <-> NULL
 *   Backward: [30] <-> [20] <-> [10] <-> NULL
 *
 * Inserting 5 at front:
 *   >> Inserted 5 at beginning.
 *   Forward:  [5] <-> [10] <-> [20] <-> [30] <-> NULL
 * ============================================================
 */
