/*
 * ============================================================
 * LINKED LIST 04: DELETION FROM BEGINNING
 * ============================================================
 * Topic: Singly Linked List
 * Language: C
 * Level: 1st Year BCA
 *
 * WHAT IS "DELETION FROM BEGINNING"?
 * Removing the FIRST node (HEAD) from the list.
 * The second node becomes the new HEAD.
 *
 * Before: HEAD -> [10] -> [20] -> [30] -> NULL
 * Delete from beginning:
 *   Removed: 10
 * After:  HEAD -> [20] -> [30] -> NULL
 *
 * IMPORTANT: We must FREE the memory of the deleted node!
 * In C, memory allocated with malloc() must be released
 * with free() to prevent MEMORY LEAKS.
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

/* ---- FUNCTION: deleteFromBeginning ----
 * Removes the first node from the list.
 *
 * Steps:
 *   1. Check if list is empty
 *   2. Save HEAD in a temp pointer
 *   3. Move HEAD to next node
 *   4. Free the temp (old HEAD) node
 */
void deleteFromBeginning(struct Node **head) {
    /* Step 1: Check if list is empty */
    if (*head == NULL) {
        printf("  ERROR: List is empty, nothing to delete.\n");
        return;
    }

    struct Node *temp = *head;   /* Step 2: Save current HEAD */

    int deletedValue = temp->data;   /* Remember the value for printing */

    *head = (*head)->next;   /* Step 3: Move HEAD to the next node */

    free(temp);   /* Step 4: Release memory of old HEAD */
    temp = NULL;  /* Good practice: set to NULL after freeing */

    printf("  Deleted %d from the beginning.\n", deletedValue);
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

/* ---- FUNCTION: countNodes ---- */
int countNodes(struct Node *head) {
    int count = 0;
    struct Node *cur = head;
    while (cur != NULL) {
        count++;
        cur = cur->next;
    }
    return count;
}

/* ---- MAIN ---- */
int main() {
    struct Node *head = NULL;

    printf("=== SINGLY LINKED LIST: DELETION FROM BEGINNING ===\n\n");

    /* Build initial list */
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    printf("Initial list (%d nodes):\n", countNodes(head));
    traverse(head);

    /* Delete from beginning multiple times */
    printf("\nDeleting from beginning one by one:\n\n");

    deleteFromBeginning(&head);
    traverse(head);

    deleteFromBeginning(&head);
    traverse(head);

    deleteFromBeginning(&head);
    traverse(head);

    printf("\nDeleting remaining nodes:\n");
    deleteFromBeginning(&head);
    traverse(head);

    deleteFromBeginning(&head);
    traverse(head);

    printf("\nTrying to delete from an empty list:\n");
    deleteFromBeginning(&head);

    return 0;
}

/*
 * ============================================================
 * SAMPLE OUTPUT:
 * ============================================================
 * === SINGLY LINKED LIST: DELETION FROM BEGINNING ===
 *
 * Initial list (5 nodes):
 *   List: HEAD -> [10] -> [20] -> [30] -> [40] -> [50] -> NULL
 *
 * Deleting from beginning one by one:
 *
 *   Deleted 10 from the beginning.
 *   List: HEAD -> [20] -> [30] -> [40] -> [50] -> NULL
 *
 *   Deleted 20 from the beginning.
 *   List: HEAD -> [30] -> [40] -> [50] -> NULL
 *
 *   Deleted 30 from the beginning.
 *   List: HEAD -> [40] -> [50] -> NULL
 *
 * Deleting remaining nodes:
 *   Deleted 40 from the beginning.
 *   List: HEAD -> [50] -> NULL
 *
 *   Deleted 50 from the beginning.
 *   List: HEAD -> NULL (empty)
 *
 * Trying to delete from an empty list:
 *   ERROR: List is empty, nothing to delete.
 *
 * ============================================================
 * ALGORITHM — DELETION FROM BEGINNING:
 * ============================================================
 * Step 1: Check if head == NULL (empty list)
 *             If yes: print error and return
 *
 * Step 2: temp = head         (save current head)
 *
 * Step 3: head = head->next   (move head to second node)
 *
 * Step 4: free(temp)          (release memory of old head)
 *
 * Diagram (deleting 10 from [10]->[20]->[30]):
 *
 *   Before:  HEAD ---> [10 | *] ---> [20 | *] ---> [30 | NULL]
 *                temp = HEAD (saved)
 *
 *   Step 3:  HEAD ---> [20 | *] ---> [30 | NULL]
 *             (head moves to 20)
 *
 *   Step 4:  free(temp)  -> [10] node is GONE from memory
 *
 *   After:   HEAD -> [20] -> [30] -> NULL
 *
 * WHY free()?
 *   malloc() reserves a block of memory on the HEAP.
 *   If we just remove the pointer without freeing, the memory
 *   is wasted — this is called a MEMORY LEAK.
 *   free() tells the OS "this memory is no longer needed, reuse it."
 *
 * TIME COMPLEXITY: O(1) — constant time
 * SPACE COMPLEXITY: O(1) — we free one node
 * ============================================================
 */
