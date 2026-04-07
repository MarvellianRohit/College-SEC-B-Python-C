/*
 * ============================================================
 * LINKED LIST 07: TRAVERSAL — DISPLAY, COUNT, SEARCH, SUM
 * ============================================================
 * Topic: Singly Linked List
 * Language: C
 * Level: 1st Year BCA
 *
 * WHAT IS TRAVERSAL?
 * Traversal means VISITING every node in the list exactly once,
 * from HEAD to the last node (where next == NULL).
 *
 * We use a pointer 'current' that starts at HEAD and moves
 * forward with: current = current->next
 * until current == NULL (reached end).
 *
 * This file covers FOUR types of traversal operations:
 *   1. Display   — print all nodes
 *   2. Count     — count total nodes
 *   3. Search    — find a specific value
 *   4. Sum & Max — compute sum and maximum value
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

/* ---- TRAVERSAL 1: Display Forward ----
 * Visits each node and prints its data.
 */
void displayForward(struct Node *head) {
    struct Node *current = head;   /* Start at beginning */
    int position = 1;

    printf("  HEAD -> ");
    while (current != NULL) {
        printf("[%d](pos:%d)", current->data, position);
        if (current->next != NULL) printf(" -> ");
        current = current->next;   /* Move to next node */
        position++;
    }
    printf(" -> NULL\n");
}

/* ---- TRAVERSAL 2: Count Nodes ----
 * Counts the total number of nodes by traversing the entire list.
 */
int countNodes(struct Node *head) {
    struct Node *current = head;
    int count = 0;

    while (current != NULL) {
        count++;                    /* Increment count for each node visited */
        current = current->next;   /* Move forward */
    }
    return count;
}

/* ---- TRAVERSAL 3: Search for a value ----
 * Finds a value in the list.
 * Returns the position if found, -1 if not.
 */
int searchValue(struct Node *head, int value) {
    struct Node *current = head;
    int position = 1;

    while (current != NULL) {
        if (current->data == value) {
            return position;   /* Found at this position! */
        }
        current = current->next;   /* Not found here, move forward */
        position++;
    }
    return -1;   /* Value not found in the list */
}

/* ---- TRAVERSAL 4: Compute Sum and Maximum ----
 * Makes a single pass through the list to compute:
 *   - Sum of all values
 *   - Maximum value
 * Efficient: only one traversal needed.
 */
void computeSumMax(struct Node *head, int *sum, int *max) {
    struct Node *current = head;
    *sum = 0;
    *max = head->data;   /* Start with first node's value as max */

    while (current != NULL) {
        *sum += current->data;   /* Add to running sum */

        if (current->data > *max) {
            *max = current->data;   /* Update max if current is larger */
        }

        current = current->next;
    }
}

/* ---- MAIN ---- */
int main() {
    struct Node *head = NULL;

    printf("=== SINGLY LINKED LIST: TRAVERSAL OPERATIONS ===\n\n");

    /* Build list: 15, 7, 42, 3, 28, 19, 36 */
    insertAtEnd(&head, 15);
    insertAtEnd(&head, 7);
    insertAtEnd(&head, 42);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 28);
    insertAtEnd(&head, 19);
    insertAtEnd(&head, 36);

    printf("--- TRAVERSAL 1: Display ---\n");
    displayForward(head);

    printf("\n--- TRAVERSAL 2: Count ---\n");
    int count = countNodes(head);
    printf("  Total nodes in list: %d\n", count);

    printf("\n--- TRAVERSAL 3: Search ---\n");
    int targets[] = {28, 100, 15, 7, 3};
    int numTargets = 5;
    int i;
    for (i = 0; i < numTargets; i++) {
        int pos = searchValue(head, targets[i]);
        if (pos != -1) {
            printf("  Search %d: FOUND at position %d\n", targets[i], pos);
        } else {
            printf("  Search %d: NOT FOUND in the list\n", targets[i]);
        }
    }

    printf("\n--- TRAVERSAL 4: Sum and Maximum ---\n");
    if (head != NULL) {
        int sum, max;
        computeSumMax(head, &sum, &max);
        printf("  Sum of all values: %d\n", sum);
        printf("  Maximum value: %d\n", max);
        printf("  Average value: %.2f\n", (float)sum / count);
    }

    return 0;
}

/*
 * ============================================================
 * SAMPLE OUTPUT:
 * ============================================================
 * === SINGLY LINKED LIST: TRAVERSAL OPERATIONS ===
 *
 * --- TRAVERSAL 1: Display ---
 *   HEAD -> [15](pos:1) -> [7](pos:2) -> [42](pos:3) -> [3](pos:4)
 *        -> [28](pos:5) -> [19](pos:6) -> [36](pos:7) -> NULL
 *
 * --- TRAVERSAL 2: Count ---
 *   Total nodes in list: 7
 *
 * --- TRAVERSAL 3: Search ---
 *   Search 28: FOUND at position 5
 *   Search 100: NOT FOUND in the list
 *   Search 15: FOUND at position 1
 *   Search 7: FOUND at position 2
 *   Search 3: FOUND at position 4
 *
 * --- TRAVERSAL 4: Sum and Maximum ---
 *   Sum of all values: 150
 *   Maximum value: 42
 *   Average value: 21.43
 *
 * ============================================================
 * ALGORITHM — TRAVERSAL (Common Pattern):
 * ============================================================
 * ALL four operations use the SAME basic traversal pattern:
 *
 *   current = head           // Start from beginning
 *   WHILE current != NULL:   // Continue until end
 *       [process current->data]
 *       current = current->next   // Move forward
 *
 * What changes is what you DO inside the loop:
 *   Display: printf(current->data)
 *   Count:   count++
 *   Search:  if (current->data == target) return position
 *   Sum:     sum += current->data
 *   Max:     if (current->data > max) max = current->data
 *
 * TERMINATION CONDITION: current != NULL
 *   - The last node's .next is NULL
 *   - So current becomes NULL after the last node
 *   - The while loop exits when current == NULL
 *
 * TIME COMPLEXITY: O(n) — must visit every node
 *   (no way around this — you can't access middle nodes
 *    without going through the beginning ones first)
 *
 * COMPARISON WITH ARRAYS:
 *   Arrays: you can access any element in O(1) with index
 *   Linked Lists: you must traverse from HEAD — always O(n)
 *   This is a KEY trade-off of linked lists.
 * ============================================================
 */
