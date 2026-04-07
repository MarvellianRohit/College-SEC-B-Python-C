/*
 * ============================================================
 * LINKED LIST 10: CIRCULAR LINKED LIST — ALL OPERATIONS
 * ============================================================
 * Topic: Circular Linked List
 * Language: C
 * Level: 1st Year BCA
 *
 * WHAT IS A CIRCULAR LINKED LIST?
 * A linked list where the LAST node's next pointer points BACK
 * to the FIRST node (HEAD) instead of NULL.
 *
 * This creates a CIRCLE — there is no NULL at the end.
 *
 * Visualisation:
 *   HEAD -> [10] -> [20] -> [30] -> [40] --+
 *     ^-----------------------------------------+
 *   (40's next points back to 10)
 *
 * USE CASES:
 *   - Round-robin scheduling (CPU scheduling)
 *   - Circular queues (ring buffers)
 *   - Music player playlists that loop
 *
 * HOW TO DETECT END?
 * Since there's no NULL, we stop traversal when we come BACK
 * to HEAD: while (current->next != head)
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
    struct Node *n = (struct Node*) malloc(sizeof(struct Node));
    if (!n) { printf("Memory error!\n"); return NULL; }
    n->data = value;
    n->next = NULL;
    return n;
}

/* ---- FUNCTION: insertAtEnd ----
 * Inserts at end. Last node's next must point back to HEAD.
 * We need to find the last node and update it.
 */
void insertAtEnd(struct Node **head, int val) {
    struct Node *n = createNode(val);
    if (!n) return;

    if (*head == NULL) {
        *head = n;
        n->next = *head;   /* Points to itself — circle of one node */
        printf("  Inserted %d (first node, points to itself).\n", val);
        return;
    }

    /* Walk to the last node (its next == head) */
    struct Node *cur = *head;
    while (cur->next != *head) {
        cur = cur->next;
    }
    /* cur is now the LAST node */
    cur->next = n;        /* Last node points to new node */
    n->next = *head;      /* New node points back to HEAD (circular!) */
    printf("  Inserted %d at end.\n", val);
}

/* ---- FUNCTION: insertAtBeginning ----
 * Inserts a new node at the front.
 * New node's next = old head.
 * Last node's next must be updated to point to new head.
 */
void insertAtBeginning(struct Node **head, int val) {
    struct Node *n = createNode(val);
    if (!n) return;

    if (*head == NULL) {
        *head = n;
        n->next = *head;
        printf("  Inserted %d (first node).\n", val);
        return;
    }

    /* Find last node */
    struct Node *last = *head;
    while (last->next != *head) last = last->next;

    n->next = *head;      /* New node points to old head */
    *head = n;            /* Update head to new node */
    last->next = *head;   /* Last node points to NEW head (important!) */
    printf("  Inserted %d at beginning.\n", val);
}

/* ---- FUNCTION: deleteFromBeginning ---- */
void deleteFromBeginning(struct Node **head) {
    if (!*head) { printf("  List is empty!\n"); return; }

    int val = (*head)->data;

    /* Only one node */
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        printf("  Deleted %d (list now empty).\n", val);
        return;
    }

    /* Find last node (to update its next) */
    struct Node *last = *head;
    while (last->next != *head) last = last->next;

    struct Node *tmp = *head;
    *head = (*head)->next;    /* Move head forward */
    last->next = *head;       /* Last node points to new head */
    free(tmp);
    printf("  Deleted %d from beginning.\n", val);
}

/* ---- FUNCTION: deleteFromEnd ---- */
void deleteFromEnd(struct Node **head) {
    if (!*head) { printf("  List is empty!\n"); return; }

    /* Only one node */
    if ((*head)->next == *head) {
        printf("  Deleted %d (list now empty).\n", (*head)->data);
        free(*head);
        *head = NULL;
        return;
    }

    /* Walk to second-to-last node */
    struct Node *cur = *head;
    while (cur->next->next != *head) cur = cur->next;

    struct Node *last = cur->next;
    printf("  Deleted %d from end.\n", last->data);
    cur->next = *head;    /* Second-to-last now points back to HEAD */
    free(last);
}

/* ---- FUNCTION: traverse ----
 * In a circular list, stop when we come BACK to head.
 * We print HEAD's value, then walk until next == head again.
 */
void traverse(struct Node *head) {
    if (!head) { printf("  List: [EMPTY]\n"); return; }

    struct Node *cur = head;
    printf("  List: [HEAD:%d]", cur->data);
    cur = cur->next;

    while (cur != head) {    /* Stop when we're back at HEAD */
        printf(" -> [%d]", cur->data);
        cur = cur->next;
    }
    printf(" -> (back to HEAD:%d)\n", head->data);
}

/* ---- MAIN ---- */
int main() {
    struct Node *head = NULL;

    printf("=== CIRCULAR LINKED LIST ===\n\n");

    /* Build list */
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    printf("\n");

    printf("Initial circular list:\n");
    traverse(head);

    printf("\nInsert 5 at beginning:\n");
    insertAtBeginning(&head, 5);
    traverse(head);

    printf("\nInsert 50 at end:\n");
    insertAtEnd(&head, 50);
    traverse(head);

    printf("\nDelete from beginning:\n");
    deleteFromBeginning(&head);
    traverse(head);

    printf("\nDelete from end:\n");
    deleteFromEnd(&head);
    traverse(head);

    /* Show it's actually circular */
    printf("\nDEMONSTRATING CIRCULAR NATURE:\n");
    printf("Starting at HEAD and going 8 steps (more than list size):\n");
    struct Node *cur = head;
    int i;
    for (i = 1; i <= 8; i++) {
        printf("  Step %d: [%d]\n", i, cur->data);
        cur = cur->next;
    }
    printf("  (The list wraps around repeatedly!)\n");

    return 0;
}

/*
 * ============================================================
 * SAMPLE OUTPUT:
 * ============================================================
 * === CIRCULAR LINKED LIST ===
 *
 *   Inserted 10 (first node, points to itself).
 *   Inserted 20 at end.
 *   Inserted 30 at end.
 *   Inserted 40 at end.
 *
 * Initial circular list:
 *   List: [HEAD:10] -> [20] -> [30] -> [40] -> (back to HEAD:10)
 *
 * Insert 5 at beginning:
 *   Inserted 5 at beginning.
 *   List: [HEAD:5] -> [10] -> [20] -> [30] -> [40] -> (back to HEAD:5)
 *
 * Insert 50 at end:
 *   Inserted 50 at end.
 *   List: [HEAD:5] -> [10] -> [20] -> [30] -> [40] -> [50] -> (back to HEAD:5)
 *
 * Delete from beginning:
 *   Deleted 5 from beginning.
 *   List: [HEAD:10] -> [20] -> [30] -> [40] -> [50] -> (back to HEAD:10)
 *
 * Delete from end:
 *   Deleted 50 from end.
 *   List: [HEAD:10] -> [20] -> [30] -> [40] -> (back to HEAD:10)
 *
 * DEMONSTRATING CIRCULAR NATURE:
 * Starting at HEAD and going 8 steps (more than list size):
 *   Step 1: [10]
 *   Step 2: [20]
 *   Step 3: [30]
 *   Step 4: [40]
 *   Step 5: [10]  <- wrapped back!
 *   Step 6: [20]
 *   Step 7: [30]
 *   Step 8: [40]
 *   (The list wraps around repeatedly!)
 *
 * ============================================================
 * ALGORITHM — KEY DIFFERENCES from Singly Linked List:
 * ============================================================
 * In Singly LL:     last->next = NULL
 * In Circular LL:   last->next = head  (points back to start)
 *
 * TRAVERSAL DIFFERENCE:
 *   Singly:   while (current != NULL)
 *   Circular: while (current->next != head)
 *             -- we stop when we've gone full circle --
 *
 * INSERT AT END:
 *   1. Walk to last node (where cur->next == head)
 *   2. cur->next = newNode
 *   3. newNode->next = head  (point back to start — circular!)
 *
 * INSERT AT BEGINNING:
 *   1. Walk to last node (to update its next)
 *   2. new->next = head
 *   3. head = new
 *   4. last->next = head  (update last to point to NEW head)
 *
 *   WHY step 4? If we forget, last->next still points to the OLD head
 *   which is now the SECOND node — breaking the circle.
 *
 * REAL-WORLD ANALOGY:
 *   Think of students sitting in a circle. A teacher passes a
 *   question paper around — it keeps going around forever.
 *   Circular linked list is the same — the "next" from the last
 *   student goes back to the first student.
 * ============================================================
 */
