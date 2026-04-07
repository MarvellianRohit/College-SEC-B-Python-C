/*
 * ============================================================
 * LINKED LIST 01: INSERTION AT BEGINNING
 * ============================================================
 * Topic: Singly Linked List
 * Language: C
 * Level: 1st Year BCA
 *
 * WHAT IS A LINKED LIST?
 * A linked list is a chain of NODES where each node contains:
 *   1. DATA   - the actual value stored
 *   2. NEXT   - a pointer (address) to the next node in the chain
 *
 * Unlike arrays, linked list nodes are NOT stored in consecutive
 * memory. They can be anywhere in memory, connected by pointers.
 *
 * Visualisation:
 *   HEAD -> [10 | *] -> [20 | *] -> [30 | NULL]
 *
 * WHAT IS "INSERTION AT BEGINNING"?
 * Adding a new node at the FRONT of the list so it becomes the
 * new HEAD node.
 *
 * Before: HEAD -> [20] -> [30] -> NULL
 * Insert 10: HEAD -> [10] -> [20] -> [30] -> NULL
 * ============================================================
 */

#include <stdio.h>
#include <stdlib.h>   /* For malloc() and free() */

/* ---- STRUCTURE: Node ----
 * Each node has two fields:
 *   data: the integer value stored in this node
 *   next: a pointer to the next node (or NULL if it's the last)
 */
struct Node {
    int data;           /* The value stored in this node */
    struct Node *next;  /* Pointer to the next node */
};

/* ---- FUNCTION: createNode ----
 * Allocates memory for a new node and sets its data.
 * Returns a pointer to the new node.
 */
struct Node* createNode(int value) {
    /* malloc allocates memory dynamically (at runtime) */
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    newNode->data = value;    /* Store the value */
    newNode->next = NULL;     /* Next is NULL by default (no connection yet) */

    return newNode;
}

/* ---- FUNCTION: insertAtBeginning ----
 * Adds a new node at the FRONT of the list.
 *
 * Steps:
 *   1. Create a new node with the given value
 *   2. Make the new node's next point to current HEAD
 *   3. Update HEAD to point to the new node
 *
 * We pass HEAD by pointer (struct Node **head) so we can modify it.
 */
void insertAtBeginning(struct Node **head, int value) {
    struct Node *newNode = createNode(value);  /* Step 1: Create new node */

    if (newNode == NULL) return;

    newNode->next = *head;   /* Step 2: New node points to current first node */
    *head = newNode;         /* Step 3: HEAD now points to the new node */

    printf("  Inserted %d at beginning.\n", value);
}

/* ---- FUNCTION: traverse ----
 * Visits every node in the list from HEAD to end, printing each value.
 * We use a pointer 'current' that walks through the list.
 */
void traverse(struct Node *head) {
    struct Node *current = head;  /* Start from HEAD */

    printf("  List: HEAD -> ");

    if (current == NULL) {
        printf("NULL (list is empty)\n");
        return;
    }

    /* Loop until current becomes NULL (end of list) */
    while (current != NULL) {
        printf("[%d] -> ", current->data);  /* Print current node's data */
        current = current->next;            /* Move to next node */
    }

    printf("NULL\n");  /* End of list */
}

/* ---- MAIN ---- */
int main() {
    struct Node *head = NULL;  /* Initially, list is empty (HEAD = NULL) */

    printf("=== SINGLY LINKED LIST: INSERTION AT BEGINNING ===\n\n");

    printf("Starting with an empty list.\n\n");

    /* Insert multiple elements at beginning */
    printf("Inserting elements one by one:\n");

    insertAtBeginning(&head, 30);
    traverse(head);

    insertAtBeginning(&head, 20);
    traverse(head);

    insertAtBeginning(&head, 10);
    traverse(head);

    insertAtBeginning(&head, 5);
    traverse(head);

    insertAtBeginning(&head, 1);
    traverse(head);

    printf("\nFinal List after all insertions:\n");
    traverse(head);

    printf("\nTotal nodes: 5\n");
    printf("First node value: %d\n", head->data);

    return 0;
}

/*
 * ============================================================
 * SAMPLE OUTPUT:
 * ============================================================
 * === SINGLY LINKED LIST: INSERTION AT BEGINNING ===
 *
 * Starting with an empty list.
 *
 * Inserting elements one by one:
 *   Inserted 30 at beginning.
 *   List: HEAD -> [30] -> NULL
 *
 *   Inserted 20 at beginning.
 *   List: HEAD -> [20] -> [30] -> NULL
 *
 *   Inserted 10 at beginning.
 *   List: HEAD -> [10] -> [20] -> [30] -> NULL
 *
 *   Inserted 5 at beginning.
 *   List: HEAD -> [5] -> [10] -> [20] -> [30] -> NULL
 *
 *   Inserted 1 at beginning.
 *   List: HEAD -> [1] -> [5] -> [10] -> [20] -> [30] -> NULL
 *
 * Final List after all insertions:
 *   List: HEAD -> [1] -> [5] -> [10] -> [20] -> [30] -> NULL
 *
 * Total nodes: 5
 * First node value: 1
 *
 * ============================================================
 * ALGORITHM — INSERTION AT BEGINNING:
 * ============================================================
 * Step 1: Create a new node
 *         newNode->data = value
 *         newNode->next = NULL
 *
 * Step 2: Link new node to current head
 *         newNode->next = head
 *
 * Step 3: Update head to point to new node
 *         head = newNode
 *
 * Diagrammatically (inserting 10 into [20]->[30]):
 *
 *   Before:  HEAD -> [20 | *---> ] [30 | NULL]
 *
 *   Step 1:  newNode = [10 | NULL]
 *   Step 2:  [10 | *-->] [20 | *-->] [30 | NULL]
 *   Step 3:  HEAD -> [10] -> [20] -> [30] -> NULL
 *
 * TIME COMPLEXITY: O(1) - constant time, no traversal needed!
 * SPACE COMPLEXITY: O(1) - one new node allocated
 *
 * WHY O(1)?
 * We only modify two pointers regardless of list size.
 * This is BETTER than arrays where inserting at front is O(n)
 * (because all elements need to shift right).
 * ============================================================
 */
