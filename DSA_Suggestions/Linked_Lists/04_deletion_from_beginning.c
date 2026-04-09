/*
 * ============================================================
 * LINKED LIST 04: DELETION FROM BEGINNING
 * ============================================================
 * Topic: Singly Linked List (Simple Version)
 * Language: C
 * Level: 1st Year BCA
 *
 * WHAT IS "DELETION FROM BEGINNING"?
 * Removing the very first node (the HEAD) from the list.
 *
 * Steps:
 * 1. Check if the list is empty.
 * 2. Save the current Head in a temporary pointer.
 * 3. Move Head to the next node.
 * 4. Free the memory of the old Head (using free()).
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
 */
