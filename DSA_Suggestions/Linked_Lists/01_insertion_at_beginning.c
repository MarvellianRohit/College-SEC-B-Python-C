/*
 * ============================================================
 * LINKED LIST 01: INSERTION AT BEGINNING
 * ============================================================
 * Topic: Singly Linked List (Simple Version)
 * Language: C
 * Level: 1st Year BCA
 *
 * WHAT IS "INSERTION AT BEGINNING"?
 * It means adding a new node at the very FRONT of the list.
 * The new node becomes the new "HEAD".
 *
 * Steps:
 * 1. Create a new Node.
 * 2. Point new Node's 'next' to the current Head.
 * 3. The new Node is now the official Head of the list.
 * ============================================================
 */

#include <stdio.h>
#include <stdlib.h>

/* The structure for a single node */
struct Node {
    int data;
    struct Node *next;
};

/* Function to create a new node and return its address */
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

/* 
 * Function to insert at the beginning.
 * Returns the NEW head of the list.
 */
struct Node* insertAtBeginning(struct Node *head, int value) {
    struct Node *newNode = createNode(value);

    /* Step 2: New node points to the current head */
    newNode->next = head;

    /* Step 3: New node is now the head */
    printf("  >> Inserted %d at beginning.\n", value);
    return newNode; 
}

/* Function to print the entire list */
void displayList(struct Node *head) {
    struct Node *temp = head;
    printf("  List: ");
    while (temp != NULL) {
        printf("[%d] -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;  /* Start with an empty list */

    printf("=== SINGLY LINKED LIST: INSERT AT FRONT ===\n\n");

    /* Inserting nodes one by one */
    head = insertAtBeginning(head, 30);
    displayList(head);

    head = insertAtBeginning(head, 20);
    displayList(head);

    head = insertAtBeginning(head, 10);
    displayList(head);

    printf("\nFinal list after all insertions:\n");
    displayList(head);

    return 0;
}

/*
 * ============================================================
 * STUDENT NOTE:
 * ============================================================
 * In this version, we use "head = insertAtBeginning(head, val)".
 * This is simpler than using double pointers (**head).
 *
 * Why do we need the 'next' pointer?
 * Because nodes are scattered in memory. The 'next' pointer acts 
 * like a map that tells us where the next piece of data is.
 *
 * Time Complexity: O(1) - Fast because we don't need to loop.
 * ============================================================
 */
