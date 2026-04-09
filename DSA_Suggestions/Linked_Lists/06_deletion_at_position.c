/*
 * ============================================================
 * LINKED LIST 06: DELETION AT POSITION
 * ============================================================
 * Topic: Singly Linked List (Simple Version)
 * Language: C
 * Level: 1st Year BCA
 *
 * WHAT IS "DELETION AT POSITION"?
 * Removing a node from a specific place (e.g., position 2).
 *
 * Steps:
 * 1. If position is 1, use "Delete from Beginning" logic.
 * 2. Otherwise, walk to node at (position - 1).
 * 3. Link (position - 1) node to (position + 1) node.
 * 4. Free the node at the specified position.
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
 * Function to delete at a specific position.
 * Returns the head of the list.
 */
struct Node* deleteAtPosition(struct Node *head, int pos) {
    if (head == NULL) {
        printf("  >> List is empty!\n");
        return NULL;
    }

    /* Step 1: Deleting position 1 */
    if (pos == 1) {
        struct Node *temp = head;
        head = head->next;
        printf("  >> Deleted %d from position 1.\n", temp->data);
        free(temp);
        return head;
    }

    /* Step 2: Walk to (pos - 1) */
    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    /* Check if target node exists */
    if (temp == NULL || temp->next == NULL) {
        printf("  >> Position %d out of range!\n", pos);
        return head;
    }

    /* Step 3: Link over the node to be deleted */
    struct Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;

    /* Step 4: Free memory */
    printf("  >> Deleted %d from position %d.\n", nodeToDelete->data, pos);
    free(nodeToDelete);

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

    /* Build: 10 -> 20 -> 30 -> 40 */
    head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    printf("=== SINGLY LINKED LIST: DELETE AT POSITION ===\n\n");
    printf("Original list:\n");
    displayList(head);

    printf("\nDeleting from position 2:\n");
    head = deleteAtPosition(head, 2);
    displayList(head);

    printf("\nDeleting from position 1:\n");
    head = deleteAtPosition(head, 1);
    displayList(head);

    return 0;
}

/*
 * ============================================================
 * STUDENT NOTE:
 * ============================================================
 * To delete node 'n', you must reach node 'n-1'.
 * You then point 'n-1' to 'n+1'. This "skips" 'n' in the chain.
 * Finally, you 'free' node 'n' so its memory is released.
 * ============================================================
 */
