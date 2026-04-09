/*
 * ============================================================
 * LINKED LIST 03: INSERTION AT POSITION
 * ============================================================
 * Topic: Singly Linked List (Simple Version)
 * Language: C
 * Level: 1st Year BCA
 * 
 * DETAILED EXPLANATION:
 * Insertion at a position means adding a new node at a specific 
 * index (e.g., 2nd or 3rd position). To do this, we must reach 
 * the node just BEFORE that position (position - 1) and rework 
 * the pointers to include the new node in the middle.
 *
 * ALGORITHM:
 * 1. START
 * 2. Create a newNode and assign data.
 * 3. IF (position == 1):
 *    a. Set newNode->next = head.
 *    b. Return newNode as the new head.
 * 4. ELSE:
 *    a. Create temp pointer at head.
 *    b. Traverse the list for (position - 2) nodes.
 *    c. IF (temp == NULL):
 *       i. Print "Invalid position" and STOP.
 *    d. Set newNode->next = temp->next.
 *    e. Set temp->next = newNode.
 * 5. Return head.
 * 6. STOP
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
 * 
 * EXPECTED OUTPUT:
 * === SINGLY LINKED LIST: INSERT AT POSITION ===
 *
 *   >> Inserted 10 at position 1.
 *   >> Inserted 20 at position 2.
 *   >> Inserted 30 at position 3.
 *   List: [10] -> [20] -> [30] -> NULL
 *
 * Inserting 15 at position 2:
 *   >> Inserted 15 at position 2.
 *   List: [10] -> [15] -> [20] -> [30] -> NULL
 *
 * Inserting 25 at position 4:
 *   >> Inserted 25 at position 4.
 *   List: [10] -> [15] -> [20] -> [25] -> [30] -> NULL
 * ============================================================
 */
