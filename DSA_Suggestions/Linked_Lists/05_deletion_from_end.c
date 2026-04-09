/*
 * ============================================================
 * LINKED LIST 05: DELETION FROM END
 * ============================================================
 * Topic: Singly Linked List (Simple Version)
 * Language: C
 * Level: 1st Year BCA
 * 
 * DETAILED EXPLANATION:
 * Deletion from the end requires us to reach the second-to-last 
 * node. We set its 'next' pointer to NULL, effectively 
 * disconnecting the last node, and then free the memory of 
 * the disconnected last node.
 *
 * ALGORITHM:
 * 1. START
 * 2. IF (head == NULL):
 *    a. Print "List is empty, deletion impossible" and STOP.
 * 3. IF (head->next == NULL):
 *    a. Save head in temp.
 *    b. Set head = NULL.
 *    c. Free temp.
 * 4. ELSE:
 *    a. Create temp pointer starting at head.
 *    b. WHILE (temp->next->next != NULL):
 *       i. Move temp to the next node.
 *    c. Save the last node (lastNode = temp->next).
 *    d. Set temp->next = NULL.
 *    e. Free lastNode.
 * 5. STOP
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
 * 
 * EXPECTED OUTPUT:
 * === SINGLY LINKED LIST: DELETE FROM END ===
 *
 * Original list:
 *   List: [10] -> [20] -> [30] -> NULL
 *
 *   >> Deleted 30 from the end.
 *   List: [10] -> [20] -> NULL
 *
 *   >> Deleted 20 from the end.
 *   List: [10] -> NULL
 *
 *   >> Deleted 10 (only node).
 *   List: [EMPTY]
 * ============================================================
 */
