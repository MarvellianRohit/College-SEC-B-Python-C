/*
 * ============================================================
 * LINKED LIST 06: DELETION FROM GIVEN POSITION
 * ============================================================
 * Topic: Singly Linked List
 * Language: C
 * Level: 1st Year BCA
 *
 * WHAT IS "DELETION FROM A GIVEN POSITION"?
 * Removing the node at a specific position (1-indexed).
 *
 * Example: Delete node at position 3 from:
 *   HEAD -> [10] -> [20] -> [30] -> [40] -> NULL
 *   Node at position 3 is [30].
 *   After deletion:
 *   HEAD -> [10] -> [20] -> [40] -> NULL
 *
 * HOW?
 * Walk to the node just BEFORE position p (i.e., node at p-1).
 * Save a reference to node at position p.
 * Link p-1 directly to p+1 (skip p).
 * Free node p.
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
    if (n == NULL) { printf("Memory error!\n"); return NULL; }
    n->data = value;
    n->next = NULL;
    return n;
}

/* ---- FUNCTION: insertAtEnd ---- */
void insertAtEnd(struct Node **head, int value) {
    struct Node *newNode = createNode(value);
    if (*head == NULL) { *head = newNode; return; }
    struct Node *cur = *head;
    while (cur->next != NULL) cur = cur->next;
    cur->next = newNode;
}

/* ---- FUNCTION: deleteAtPosition ----
 * Deletes the node at the given position (1-indexed).
 *
 * Steps:
 *   1. Validate: position must be >= 1
 *   2. If position == 1: delete beginning (special case)
 *   3. Otherwise: walk to node at (position - 1) using 'prev'
 *   4. Check that position is valid (not beyond list)
 *   5. Save reference to node at position 'pos' as 'target'
 *   6. Link prev->next = target->next (skip target)
 *   7. Free target
 */
void deleteAtPosition(struct Node **head, int pos) {
    /* Step 1: Validate */
    if (pos < 1) {
        printf("  ERROR: Position must be >= 1.\n");
        return;
    }

    /* Step 2: Check empty list */
    if (*head == NULL) {
        printf("  ERROR: List is empty.\n");
        return;
    }

    struct Node *target;   /* Node to be deleted */
    int deletedValue;

    /* Step 2: Delete first node */
    if (pos == 1) {
        target = *head;              /* target = first node */
        deletedValue = target->data;
        *head = (*head)->next;       /* Head moves to second node */
        free(target);
        printf("  Deleted node at position 1 (value: %d).\n", deletedValue);
        return;
    }

    /* Step 3: Walk to node just BEFORE position pos */
    struct Node *prev = *head;
    int i;

    for (i = 1; i < pos - 1; i++) {
        if (prev->next == NULL) {
            printf("  ERROR: Position %d is out of range!\n", pos);
            return;
        }
        prev = prev->next;   /* Move forward */
    }

    /* Step 4: Check that the target node exists */
    if (prev->next == NULL) {
        printf("  ERROR: Position %d is out of range!\n", pos);
        return;
    }

    /* Step 5: target is the node at position 'pos' */
    target = prev->next;
    deletedValue = target->data;

    /* Step 6: Bypass target — link prev to the node after target */
    prev->next = target->next;

    /* Step 7: Free target's memory */
    free(target);

    printf("  Deleted node at position %d (value: %d).\n", pos, deletedValue);
}

/* ---- FUNCTION: traverse ---- */
void traverse(struct Node *head) {
    printf("  Pos:  ");
    struct Node *cur = head;
    int p = 1;
    while (cur != NULL) { printf("  (%d) ", p++); cur = cur->next; }
    printf("\n");

    printf("  List: HEAD -> ");
    cur = head;
    if (cur == NULL) { printf("NULL (empty)\n"); return; }
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

    printf("=== SINGLY LINKED LIST: DELETION AT GIVEN POSITION ===\n\n");

    /* Build list */
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    insertAtEnd(&head, 60);

    printf("Initial list:\n");
    traverse(head);

    printf("\nDelete node at position 3 (should remove 30):\n");
    deleteAtPosition(&head, 3);
    traverse(head);

    printf("\nDelete node at position 1 (should remove 10 - first):\n");
    deleteAtPosition(&head, 1);
    traverse(head);

    printf("\nDelete node at position 4 (should remove 60 - last):\n");
    deleteAtPosition(&head, 4);
    traverse(head);

    printf("\nTry position 10 (out of range):\n");
    deleteAtPosition(&head, 10);

    printf("\nTry position 0 (invalid):\n");
    deleteAtPosition(&head, 0);

    return 0;
}

/*
 * ============================================================
 * SAMPLE OUTPUT:
 * ============================================================
 * === SINGLY LINKED LIST: DELETION AT GIVEN POSITION ===
 *
 * Initial list:
 *   Pos:    (1)   (2)   (3)   (4)   (5)   (6)
 *   List: HEAD -> [10] -> [20] -> [30] -> [40] -> [50] -> [60] -> NULL
 *
 * Delete node at position 3 (should remove 30):
 *   Deleted node at position 3 (value: 30).
 *   Pos:    (1)   (2)   (3)   (4)   (5)
 *   List: HEAD -> [10] -> [20] -> [40] -> [50] -> [60] -> NULL
 *
 * Delete node at position 1 (should remove 10 - first):
 *   Deleted node at position 1 (value: 10).
 *   Pos:    (1)   (2)   (3)   (4)
 *   List: HEAD -> [20] -> [40] -> [50] -> [60] -> NULL
 *
 * Delete node at position 4 (should remove 60 - last):
 *   Deleted node at position 4 (value: 60).
 *   Pos:    (1)   (2)   (3)
 *   List: HEAD -> [20] -> [40] -> [50] -> NULL
 *
 * Try position 10 (out of range):
 *   ERROR: Position 10 is out of range!
 *
 * Try position 0 (invalid):
 *   ERROR: Position must be >= 1.
 *
 * ============================================================
 * ALGORITHM — DELETION AT POSITION p:
 * ============================================================
 * Step 1: If p < 1: invalid, return
 * Step 2: If list empty: error, return
 * Step 3: If p == 1 (delete beginning):
 *             target = head
 *             head   = head->next
 *             free(target)
 *             STOP
 * Step 4: Walk prev to position (p-1):
 *             prev = head
 *             repeat (p-2) times: prev = prev->next
 *             if prev->next == NULL: position out of range
 * Step 5: target = prev->next      (node to delete)
 * Step 6: prev->next = target->next  (link around target)
 * Step 7: free(target)
 *
 * Diagram: Deleting position 3 from [10]->[20]->[30]->[40]->[50]:
 *
 *   prev starts at position 1 (10)
 *   Walk 1 step: prev = position 2 (20)
 *   target = prev->next = position 3 (30)
 *   prev->next = target->next = position 4 (40)
 *   free(30)
 *
 *   Result: [10] -> [20] -> [40] -> [50]  (30 is gone)
 *
 * TIME COMPLEXITY: O(p) — walk to position p
 * SPACE COMPLEXITY: O(1) — one freed node
 * ============================================================
 */
