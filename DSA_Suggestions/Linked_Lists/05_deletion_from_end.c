/*
 * ============================================================
 * LINKED LIST 05: DELETION FROM END
 * ============================================================
 * Topic: Singly Linked List (Simple Version)
 * Language: C
 * Level: 1st Year BCA
 *
 * WHAT IS "DELETION FROM END"?
 * Removing the very last node from the list.
 *
 * Steps:
 * 1. If list is empty, nothing to do.
 * 2. If only one node exists, delete it and set Head to NULL.
 * 3. Otherwise, walk to the SECOND-TO-LAST node.
 * 4. Free the last node and set the second-to-last's 'next' to NULL.
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
 * Function to delete from the end.
 * Returns the head of the list.
 */
struct Node* deleteEnd(struct Node *head) {
    /* Step 1: Empty list case */
    if (head == NULL) {
        printf("  >> List is empty!\n");
        return NULL;
    }

    /* Step 2: Only one node case */
    if (head->next == NULL) {
        printf("  >> Deleted %d (only node).\n", head->data);
        free(head);
        return NULL;
    }

    /* Step 3: General case (walk to second-to-last node) */
    struct Node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    /* temp is now the SECOND-TO-LAST node */
    struct Node *lastNode = temp->next;
    printf("  >> Deleted %d from the end.\n", lastNode->data);
    
    /* Step 4: Free last node and cut the connection */
    free(lastNode);
    temp->next = NULL;

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

    /* Build: 10 -> 20 -> 30 */
    head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);

    printf("=== SINGLY LINKED LIST: DELETE FROM END ===\n\n");
    printf("Original list:\n");
    displayList(head);

    head = deleteEnd(head);
    displayList(head);

    head = deleteEnd(head);
    displayList(head);

    head = deleteEnd(head);
    displayList(head);

    return 0;
}

/*
 * ============================================================
 * STUDENT NOTE:
 * ============================================================
 * Why 'while (temp->next->next != NULL)'?
 * We want to stop at the node BEFORE the last node. 
 * 'temp->next' is the last node, and 'temp->next->next' is NULL.
 * This is how we find the second-to-last node.
 * ============================================================
 */
