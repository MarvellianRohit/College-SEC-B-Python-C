/*
 * ============================================================
 * LINKED LIST 09: DOUBLY LINKED LIST — ALL OPERATIONS
 * ============================================================
 * Topic: Doubly Linked List
 * Language: C
 * Level: 1st Year BCA
 *
 * WHAT IS A DOUBLY LINKED LIST?
 * Each node has THREE fields:
 *   prev  — pointer to the PREVIOUS node
 *   data  — the value stored
 *   next  — pointer to the NEXT node
 *
 * Unlike singly linked list, you can traverse BOTH directions:
 *   Forward:  HEAD -> ... -> TAIL
 *   Backward: TAIL -> ... -> HEAD
 *
 * Visualisation:
 *   NULL <-- [10] <--> [20] <--> [30] --> NULL
 *
 * ADVANTAGES over singly linked list:
 *   - Can delete a node given only a pointer (no need for prev)
 *   - Traverse in both directions
 *
 * DISADVANTAGE:
 *   - Extra memory per node (two pointers instead of one)
 * ============================================================
 */

#include <stdio.h>
#include <stdlib.h>

/* ---- STRUCTURE: Node ----
 * Each node now has BOTH prev and next pointers.
 */
struct Node {
    int data;
    struct Node *prev;   /* Points to PREVIOUS node */
    struct Node *next;   /* Points to NEXT node */
};

/* ---- FUNCTION: createNode ---- */
struct Node* createNode(int value) {
    struct Node *n = (struct Node*) malloc(sizeof(struct Node));
    if (!n) { printf("Memory error!\n"); return NULL; }
    n->data = value;
    n->prev = NULL;   /* No previous yet */
    n->next = NULL;   /* No next yet */
    return n;
}

/* ---- FUNCTION: insertAtBeginning ---- */
void insertAtBeginning(struct Node **head, int val) {
    struct Node *n = createNode(val);
    if (!n) return;

    n->next = *head;       /* New node's next = old head */
    if (*head != NULL) {
        (*head)->prev = n; /* Old head's prev = new node */
    }
    *head = n;             /* Update head */
    printf("  Inserted %d at beginning.\n", val);
}

/* ---- FUNCTION: insertAtEnd ---- */
void insertAtEnd(struct Node **head, int val) {
    struct Node *n = createNode(val);
    if (!n) return;

    if (*head == NULL) {
        *head = n;
        printf("  Inserted %d (first node).\n", val);
        return;
    }

    struct Node *cur = *head;
    while (cur->next != NULL) cur = cur->next;  /* Walk to last */

    cur->next = n;   /* Last node's next = new node */
    n->prev = cur;   /* New node's prev = old last node */
    printf("  Inserted %d at end.\n", val);
}

/* ---- FUNCTION: deleteFromBeginning ---- */
void deleteFromBeginning(struct Node **head) {
    if (!*head) { printf("  List is empty!\n"); return; }

    struct Node *tmp = *head;
    int val = tmp->data;

    *head = (*head)->next;      /* Move head forward */
    if (*head != NULL) {
        (*head)->prev = NULL;   /* New head's prev = NULL */
    }
    free(tmp);
    printf("  Deleted %d from beginning.\n", val);
}

/* ---- FUNCTION: deleteFromEnd ---- */
void deleteFromEnd(struct Node **head) {
    if (!*head) { printf("  List is empty!\n"); return; }

    struct Node *cur = *head;
    while (cur->next != NULL) cur = cur->next;  /* Walk to last */

    int val = cur->data;

    if (cur->prev != NULL) {
        cur->prev->next = NULL;   /* Second-to-last's next = NULL */
    } else {
        *head = NULL;             /* Was only one node */
    }
    free(cur);
    printf("  Deleted %d from end.\n", val);
}

/* ---- FUNCTION: traverseForward ---- */
void traverseForward(struct Node *head) {
    struct Node *cur = head;
    printf("  Forward:  NULL <-- ");
    while (cur != NULL) {
        printf("[%d]", cur->data);
        if (cur->next != NULL) printf(" <-> ");
        cur = cur->next;
    }
    printf(" --> NULL\n");
}

/* ---- FUNCTION: traverseBackward ---- */
void traverseBackward(struct Node *head) {
    if (!head) { printf("  Backward: NULL\n"); return; }

    /* First, walk to the LAST node */
    struct Node *cur = head;
    while (cur->next != NULL) cur = cur->next;

    /* Now walk backward using prev pointer */
    printf("  Backward: NULL --> ");
    while (cur != NULL) {
        printf("[%d]", cur->data);
        if (cur->prev != NULL) printf(" <-> ");
        cur = cur->prev;   /* Move backward using prev */
    }
    printf(" <-- NULL\n");
}

/* ---- MAIN ---- */
int main() {
    struct Node *head = NULL;

    printf("=== DOUBLY LINKED LIST ===\n\n");

    /* Build list */
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    printf("\n");

    /* Show forward and backward traversal */
    printf("Full list (both directions):\n");
    traverseForward(head);
    traverseBackward(head);

    /* Insert at beginning */
    printf("\nInsert 5 at beginning:\n");
    insertAtBeginning(&head, 5);
    traverseForward(head);

    /* Insert at end */
    printf("\nInsert 50 at end:\n");
    insertAtEnd(&head, 50);
    traverseForward(head);

    /* Delete from beginning */
    printf("\nDelete from beginning:\n");
    deleteFromBeginning(&head);
    traverseForward(head);

    /* Delete from end */
    printf("\nDelete from end:\n");
    deleteFromEnd(&head);
    traverseForward(head);

    /* Show backward again */
    printf("\nFinal backward traversal:\n");
    traverseBackward(head);

    return 0;
}

/*
 * ============================================================
 * SAMPLE OUTPUT:
 * ============================================================
 * === DOUBLY LINKED LIST ===
 *
 *   Inserted 10 (first node).
 *   Inserted 20 at end.
 *   Inserted 30 at end.
 *   Inserted 40 at end.
 *
 * Full list (both directions):
 *   Forward:  NULL <-- [10] <-> [20] <-> [30] <-> [40] --> NULL
 *   Backward: NULL --> [40] <-> [30] <-> [20] <-> [10] <-- NULL
 *
 * Insert 5 at beginning:
 *   Inserted 5 at beginning.
 *   Forward:  NULL <-- [5] <-> [10] <-> [20] <-> [30] <-> [40] --> NULL
 *
 * Insert 50 at end:
 *   Inserted 50 at end.
 *   Forward:  NULL <-- [5] <-> [10] <-> [20] <-> [30] <-> [40] <-> [50] --> NULL
 *
 * Delete from beginning:
 *   Deleted 5 from beginning.
 *   Forward:  NULL <-- [10] <-> [20] <-> [30] <-> [40] <-> [50] --> NULL
 *
 * Delete from end:
 *   Deleted 50 from end.
 *   Forward:  NULL <-- [10] <-> [20] <-> [30] <-> [40] --> NULL
 *
 * Final backward traversal:
 *   Backward: NULL --> [40] <-> [30] <-> [20] <-> [10] <-- NULL
 *
 * ============================================================
 * ALGORITHM — DOUBLY LINKED LIST OPERATIONS:
 * ============================================================
 * INSERT AT BEGINNING:
 *   1. new->next = head
 *   2. if head != NULL: head->prev = new
 *   3. head = new
 *
 * INSERT AT END:
 *   1. Walk cur to last node
 *   2. cur->next = new
 *   3. new->prev = cur
 *
 * DELETE FROM BEGINNING:
 *   1. tmp = head
 *   2. head = head->next
 *   3. if head != NULL: head->prev = NULL
 *   4. free(tmp)
 *
 * DELETE FROM END:
 *   1. Walk cur to last node
 *   2. if cur->prev != NULL: cur->prev->next = NULL
 *      else: head = NULL (was only node)
 *   3. free(cur)
 *
 * BACKWARD TRAVERSAL:
 *   1. Walk cur to last node (cur->next == NULL)
 *   2. While cur != NULL:
 *        print cur->data
 *        cur = cur->prev    <-- use PREV pointer!
 *
 * KEY DIFFERENCE from Singly Linked List:
 *   Singly: each node has only NEXT pointer (one direction)
 *   Doubly: each node has PREV + NEXT (two directions)
 *   This allows backward traversal and faster certain deletions.
 *
 * TIME COMPLEXITY: Same as singly — O(n) for end operations
 * SPACE COMPLEXITY: O(n) for list + O(2n) pointers (prev + next each node)
 * ============================================================
 */
