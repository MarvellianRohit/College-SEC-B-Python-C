/*
 * ============================================================
 * LINKED LIST 05: DELETION FROM END
 * ============================================================
 * Topic: Singly Linked List
 * Language: C
 * Level: 1st Year BCA
 *
 * WHAT IS "DELETION FROM END"?
 * Removing the LAST node from the list.
 * The second-to-last node becomes the new last node.
 *
 * Before: HEAD -> [10] -> [20] -> [30] -> [40] -> NULL
 * Delete from end:
 *   Removed: 40
 * After:  HEAD -> [10] -> [20] -> [30] -> NULL
 *
 * HOW?
 * We need to find the node JUST BEFORE the last one (second-to-last).
 * Then set second-to-last->next = NULL (cuts off the last node).
 * Then free the last node.
 *
 * To do this, we walk using TWO pointers:
 *   prev  = the node before current
 *   current = the node we're checking
 * When current->next == NULL, current is last. prev is second-to-last.
 * ============================================================
 */

#include <stdio.h>
#include <stdlib.h>

/* ---- STRUCTURE: Node ---- */
struct Node {
    int data;
    struct Node *next;
};

/* ---- FUNCTION: createNode ---- */
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) { printf("Memory error!\n"); return NULL; }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

/* ---- FUNCTION: insertAtEnd ---- */
void insertAtEnd(struct Node **head, int value) {
    struct Node *newNode = createNode(value);
    if (*head == NULL) { *head = newNode; return; }
    struct Node *cur = *head;
    while (cur->next != NULL) cur = cur->next;
    cur->next = newNode;
}

/* ---- FUNCTION: deleteFromEnd ----
 * Removes the LAST node from the list.
 *
 * Uses two pointers:
 *   prev    = one step behind current
 *   current = walks to find last node
 *
 * Cases:
 *   a) Empty list: error
 *   b) Only one node: free it, head = NULL
 *   c) Multiple nodes: walk to last, update second-to-last
 */
void deleteFromEnd(struct Node **head) {
    /* Case a: empty list */
    if (*head == NULL) {
        printf("  ERROR: List is empty, nothing to delete.\n");
        return;
    }

    /* Case b: only one node */
    if ((*head)->next == NULL) {
        int val = (*head)->data;
        free(*head);         /* Free the only node */
        *head = NULL;        /* Head is now NULL (empty list) */
        printf("  Deleted %d from end (list now empty).\n", val);
        return;
    }

    /* Case c: more than one node */
    struct Node *current = *head;   /* Will walk to last node */
    struct Node *prev = NULL;       /* Will track one node behind current */

    /* Walk until current is the LAST node */
    while (current->next != NULL) {
        prev = current;          /* prev trails one step behind */
        current = current->next; /* current moves forward */
    }

    /* Now current = last node, prev = second-to-last */
    int val = current->data;  /* Remember the value */

    prev->next = NULL;   /* Disconnect the last node */
    free(current);       /* Free the last node's memory */

    printf("  Deleted %d from the end.\n", val);
}

/* ---- FUNCTION: traverse ---- */
void traverse(struct Node *head) {
    printf("  List: HEAD -> ");
    if (head == NULL) { printf("NULL (empty)\n"); return; }
    struct Node *cur = head;
    while (cur != NULL) {
        printf("[%d]", cur->data);
        if (cur->next != NULL) printf(" -> ");
        cur = cur->next;
    }
    printf(" -> NULL\n");
}

/* ---- MAIN ---- */
int main() {
    struct Node *head = NULL;

    printf("=== SINGLY LINKED LIST: DELETION FROM END ===\n\n");

    /* Build list */
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    printf("Initial list:\n");
    traverse(head);

    printf("\nDeleting from end one by one:\n\n");

    deleteFromEnd(&head);
    traverse(head);

    deleteFromEnd(&head);
    traverse(head);

    deleteFromEnd(&head);
    traverse(head);

    deleteFromEnd(&head);
    traverse(head);

    printf("\nLast deletion (only one node left):\n");
    deleteFromEnd(&head);
    traverse(head);

    printf("\nAttempting to delete from empty list:\n");
    deleteFromEnd(&head);

    return 0;
}

/*
 * ============================================================
 * SAMPLE OUTPUT:
 * ============================================================
 * === SINGLY LINKED LIST: DELETION FROM END ===
 *
 * Initial list:
 *   List: HEAD -> [10] -> [20] -> [30] -> [40] -> [50] -> NULL
 *
 * Deleting from end one by one:
 *
 *   Deleted 50 from the end.
 *   List: HEAD -> [10] -> [20] -> [30] -> [40] -> NULL
 *
 *   Deleted 40 from the end.
 *   List: HEAD -> [10] -> [20] -> [30] -> NULL
 *
 *   Deleted 30 from the end.
 *   List: HEAD -> [10] -> [20] -> NULL
 *
 *   Deleted 20 from the end.
 *   List: HEAD -> [10] -> NULL
 *
 * Last deletion (only one node left):
 *   Deleted 10 from end (list now empty).
 *   List: HEAD -> NULL (empty)
 *
 * Attempting to delete from empty list:
 *   ERROR: List is empty, nothing to delete.
 *
 * ============================================================
 * ALGORITHM — DELETION FROM END:
 * ============================================================
 * Step 1: If head == NULL: ERROR (empty list)
 *
 * Step 2: If head->next == NULL (only one node):
 *             free(head)
 *             head = NULL
 *             STOP
 *
 * Step 3: Walk to the second-to-last node using TWO pointers:
 *             prev    = NULL     (initialise before head)
 *             current = head     (start at head)
 *
 *             WHILE current->next != NULL:
 *                 prev = current
 *                 current = current->next
 *
 *             After loop: current = last node, prev = second-to-last
 *
 * Step 4: prev->next = NULL    (disconnect last node)
 * Step 5: free(current)        (release memory)
 *
 * Diagram example: deleting from [10]->[20]->[30]->[40]:
 *
 *   Walk 1: prev=10, current=20  (current->next != NULL, keep going)
 *   Walk 2: prev=20, current=30  (current->next != NULL, keep going)
 *   Walk 3: prev=30, current=40  (current->next == NULL, STOP!)
 *
 *   prev(30)->next = NULL  -> disconnects 40
 *   free(current = 40)     -> memory released
 *
 * TIME COMPLEXITY: O(n) — must walk to end
 * SPACE COMPLEXITY: O(1) — no extra space
 *
 * TRICK: We use TWO POINTERS moving together so that when
 * 'current' reaches the end, 'prev' is one step behind it.
 * ============================================================
 */
