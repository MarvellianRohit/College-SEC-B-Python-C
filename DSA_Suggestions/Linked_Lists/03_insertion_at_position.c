/*
 * ============================================================
 * LINKED LIST 03: INSERTION AT POSITION
 * ============================================================
 * Topic: Singly Linked List (Simple Version)
 * Language: C
 * Level: 1st Year BCA
 *
 * WHAT IS "INSERTION AT POSITION"?
 * Adding a node at a specific place, e.g., position 3.
 *
 * Steps:
 * 1. If position is 1, use "Insert at Beginning" logic.
 * 2. Otherwise, walk to node at (position - 1).
 * 3. Connect new Node to the old next node.
 * 4. Connect (position - 1) node to our new Node.
 * ============================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

/* 
 * Function to insert at a specific position.
 * Returns the head of the list.
 */
struct Node* insertAtPosition(struct Node *head, int value, int pos) {
    /* Step 1: Handle insertion at position 1 (Beginning) */
    if (pos == 1) {
        struct Node *newNode = createNode(value);
        newNode->next = head;
        printf("  >> Inserted %d at position 1.\n", value);
        return newNode;
    }

    struct Node *temp = head;
    /* Walk to (pos - 1) */
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    /* Check if position is valid */
    if (temp == NULL) {
        printf("  >> Position %d is out of range!\n", pos);
        return head;
    }

    /* Step 3 & 4: Link the new node */
    struct Node *newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;

    printf("  >> Inserted %d at position %d.\n", value, pos);
    return head;
}

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
    struct Node *head = NULL;

    printf("=== SINGLY LINKED LIST: INSERT AT POSITION ===\n\n");

    /* Create initial list: 10 -> 20 -> 30 */
    head = insertAtPosition(head, 10, 1);
    head = insertAtPosition(head, 20, 2);
    head = insertAtPosition(head, 30, 3);
    displayList(head);

    /* Insert 15 at position 2 */
    printf("\nInserting 15 at position 2:\n");
    head = insertAtPosition(head, 15, 2);
    displayList(head);

    /* Insert 25 at position 4 */
    printf("\nInserting 25 at position 4:\n");
    head = insertAtPosition(head, 25, 4);
    displayList(head);

    return 0;
}

/*
 * ============================================================
 * STUDENT NOTE:
 * ============================================================
 * Why do we walk to (pos - 1)?
 * Because to insert a node at position 'n', we need to modify 
 * the 'next' pointer of the node at position 'n-1'.
 *
 * Example: To insert at pos 3, we need to change pos 2's next.
 * ============================================================
 */
