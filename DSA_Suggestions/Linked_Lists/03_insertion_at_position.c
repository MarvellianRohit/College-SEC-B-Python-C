/*
 * ============================================================
 * LINKED LIST 03: INSERTION IN THE MIDDLE (AT GIVEN POSITION)
 * ============================================================
 * Topic: Singly Linked List
 * Language: C
 * Level: 1st Year BCA
 *
 * WHAT IS "INSERTION IN THE MIDDLE"?
 * Adding a new node at a SPECIFIC POSITION in the list.
 * Positions are 1-indexed: position 1 = beginning.
 *
 * Example: Insert 25 at position 3 in:
 *   HEAD -> [10] -> [20] -> [30] -> [40] -> NULL
 *   Becomes:
 *   HEAD -> [10] -> [20] -> [25] -> [30] -> [40] -> NULL
 *
 * HOW?
 * Walk to position (pos-1), the node BEFORE the insertion point.
 * Then:
 *   1. newNode->next = prevNode->next   (link new to rest of list)
 *   2. prevNode->next = newNode         (link prev to new node)
 *
 * The ORDER of these two steps is CRITICAL.
 * If you do step 2 before step 1, you LOSE the rest of the list!
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

/* ---- FUNCTION: insertAtEnd (helper to build initial list) ---- */
void insertAtEnd(struct Node **head, int value) {
    struct Node *newNode = createNode(value);
    if (*head == NULL) { *head = newNode; return; }
    struct Node *cur = *head;
    while (cur->next != NULL) cur = cur->next;
    cur->next = newNode;
}

/* ---- FUNCTION: insertAtPosition ----
 * Inserts a new node at the given position (1-indexed).
 * Position 1 = insert at beginning.
 * Position 2 = insert after first node.
 * etc.
 *
 * Steps:
 *   1. Validate position
 *   2. If position == 1: insert at beginning
 *   3. Otherwise: walk to node at (position - 1)
 *   4. Insert new node between that node and its successor
 */
void insertAtPosition(struct Node **head, int value, int pos) {
    if (pos < 1) {
        printf("  ERROR: Position must be >= 1.\n");
        return;
    }

    struct Node *newNode = createNode(value);  /* Create new node */
    if (newNode == NULL) return;

    /* Special case: insert at position 1 (beginning) */
    if (pos == 1) {
        newNode->next = *head;   /* New node points to current head */
        *head = newNode;         /* Head is updated to new node */
        printf("  Inserted %d at position 1 (beginning).\n", value);
        return;
    }

    /* General case: walk to the node JUST BEFORE the insertion point */
    struct Node *current = *head;   /* Start from head */
    int i;

    for (i = 1; i < pos - 1; i++) {   /* Walk (pos-1) nodes forward */
        if (current == NULL) {
            printf("  ERROR: Position %d is beyond list length!\n", pos);
            free(newNode);
            return;
        }
        current = current->next;
    }

    /* current now points to node at position (pos-1) */
    /* Insert newNode between current and current->next */

    newNode->next = current->next;   /* Step 1: New node points to next node */
    current->next = newNode;         /* Step 2: Previous node points to new node */

    printf("  Inserted %d at position %d.\n", value, pos);
}

/* ---- FUNCTION: traverse ---- */
void traverse(struct Node *head) {
    struct Node *cur = head;
    int pos = 1;
    printf("  ");
    if (cur == NULL) { printf("List is empty.\n"); return; }
    printf("HEAD -> ");
    while (cur != NULL) {
        printf("[%d](%d)", cur->data, pos);  /* Show data and position */
        if (cur->next != NULL) printf(" -> ");
        cur = cur->next;
        pos++;
    }
    printf(" -> NULL\n");
}

/* ---- MAIN ---- */
int main() {
    struct Node *head = NULL;

    printf("=== SINGLY LINKED LIST: INSERTION AT GIVEN POSITION ===\n\n");

    /* Build initial list: 10, 20, 30, 40 */
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    printf("Initial list:\n");
    traverse(head);

    /* Insert at various positions */
    printf("\nInserting 25 at position 3:\n");
    insertAtPosition(&head, 25, 3);
    traverse(head);

    printf("\nInserting 5 at position 1 (beginning):\n");
    insertAtPosition(&head, 5, 1);
    traverse(head);

    printf("\nInserting 99 at position 7 (end):\n");
    insertAtPosition(&head, 99, 7);
    traverse(head);

    printf("\nTrying invalid position 0:\n");
    insertAtPosition(&head, 100, 0);

    printf("\nTrying out-of-range position 50:\n");
    insertAtPosition(&head, 100, 50);

    return 0;
}

/*
 * ============================================================
 * SAMPLE OUTPUT:
 * ============================================================
 * === SINGLY LINKED LIST: INSERTION AT GIVEN POSITION ===
 *
 * Initial list:
 *   HEAD -> [10](1) -> [20](2) -> [30](3) -> [40](4) -> NULL
 *
 * Inserting 25 at position 3:
 *   Inserted 25 at position 3.
 *   HEAD -> [10](1) -> [20](2) -> [25](3) -> [30](4) -> [40](5) -> NULL
 *
 * Inserting 5 at position 1 (beginning):
 *   Inserted 5 at position 1 (beginning).
 *   HEAD -> [5](1) -> [10](2) -> [20](3) -> [25](4) -> [30](5) -> [40](6) -> NULL
 *
 * Inserting 99 at position 7 (end):
 *   Inserted 99 at position 7.
 *   HEAD -> [5](1) -> [10](2) -> [20](3) -> [25](4) -> [30](5) -> [40](6) -> [99](7) -> NULL
 *
 * Trying invalid position 0:
 *   ERROR: Position must be >= 1.
 *
 * Trying out-of-range position 50:
 *   ERROR: Position 50 is beyond list length!
 *
 * ============================================================
 * ALGORITHM — INSERTION AT POSITION p:
 * ============================================================
 * Step 1: Create newNode
 *
 * Step 2: If p == 1 (insert at beginning):
 *           newNode->next = head
 *           head = newNode
 *           STOP
 *
 * Step 3: Walk to node at position (p-1):
 *           current = head
 *           repeat (p-2) times:
 *               current = current->next
 *               if current == NULL: ERROR (out of bounds)
 *
 * Step 4: Link new node:
 *           newNode->next = current->next   [MUST BE FIRST!]
 *           current->next = newNode         [MUST BE SECOND!]
 *
 * CRITICAL: Why is order important in Step 4?
 *   If we do current->next = newNode FIRST:
 *     - We lose the reference to the rest of the list!
 *     - newNode->next = current->next would point to newNode itself!
 *   Always link the NEW node before updating the previous node.
 *
 * TIME COMPLEXITY: O(p) — walk p-1 steps to reach insertion point
 * SPACE COMPLEXITY: O(1) — one new node
 * ============================================================
 */
