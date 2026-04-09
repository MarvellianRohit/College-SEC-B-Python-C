/*
 * ============================================================
 * LINKED LIST 04: DELETION FROM BEGINNING
 * ============================================================
 * Topic: Singly Linked List (Simple Version)
 * Language: C
 * Level: 1st Year BCA
 * 
 * DETAILED EXPLANATION:
 * Deletion from the beginning involves removing the first node 
 * of the list (the head). To do this safely, we must store the 
 * head's address in a temporary pointer before updating the head 
 * to point to the second node, then free the memory of the 
 * old head.
 *
 * ALGORITHM:
 * 1. START
 * 2. IF (head == NULL):
 *    a. Print "List is empty, deletion impossible".
 *    b. STOP.
 * 3. Save the current head in a temporary pointer (temp = head).
 * 4. Update head to the next node (head = head->next).
 * 5. Free the memory assigned to the old head (free(temp)).
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
 * Function to delete from the beginning.
 * Returns the NEW head of the list.
 */
struct Node* deleteBeginning(struct Node *head) {
    /* Step 1: Check if list is empty */
    if (head == NULL) {
        printf("  >> List is empty, nothing to delete!\n");
        return NULL;
    }

    /* Step 2: Save the current head */
    struct Node *temp = head;
    int deletedVal = temp->data;

    /* Step 3: Move head to the next node */
    head = head->next;

    /* Step 4: Free the memory */
    free(temp);
    printf("  >> Deleted %d from the beginning.\n", deletedVal);

    /* Return the updated head */
    return head;
}

void displayList(struct Node *head) {
    if (head == NULL) {
        printf("  List: [EMPTY]\n");
        return;
    }
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

    /* Manually build list: 10 -> 20 -> 30 */
    head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);

    printf("=== SINGLY LINKED LIST: DELETE FROM FRONT ===\n\n");
    printf("Original list:\n");
    displayList(head);

    /* Deleting nodes */
    head = deleteBeginning(head);
    displayList(head);

    head = deleteBeginning(head);
    displayList(head);

    head = deleteBeginning(head);
    displayList(head);

    return 0;
}

/*
 * ============================================================
 * STUDENT NOTE:
 * ============================================================
 * Why use free(temp)?
 * In C, memory allocated with malloc() doesn't disappear 
 * automatically. If we don't use free(), the memory stays 
 * occupied forever (this is called a "Memory Leak").
 * ============================================================
 * 
 * EXPECTED OUTPUT:
 * === SINGLY LINKED LIST: DELETE FROM FRONT ===
 *
 * Original list:
 *   List: [10] -> [20] -> [30] -> NULL
 *
 *   >> Deleted 10 from the beginning.
 *   List: [20] -> [30] -> NULL
 *
 *   >> Deleted 20 from the beginning.
 *   List: [30] -> NULL
 *
 *   >> Deleted 30 from the beginning.
 *   List: [EMPTY]
 * ============================================================
 */
