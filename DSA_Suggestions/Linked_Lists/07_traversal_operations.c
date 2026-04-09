/*
 * ============================================================
 * LINKED LIST 07: SEARCH AND COUNT OPERATIONS
 * ============================================================
 * Topic: Singly Linked List (Simple Version)
 * Language: C
 * Level: 1st Year BCA
 * 
 * DETAILED EXPLANATION:
 * Traversal means visiting every node in the list starting from 
 * the head. This is the foundation for many operations like 
 * displaying node data, counting the number of nodes, or 
 * searching for a specific value.
 *
 * ALGORITHM (for Searching):
 * 1. START
 * 2. Create temp pointer starting at head.
 * 3. Initialize position counter (pos = 1).
 * 4. WHILE (temp != NULL):
 *    a. IF (temp->data == target):
 *       i. Return pos (Found).
 *    b. Move temp to next node.
 *    c. Increment pos.
 * 5. Return -1 (Not Found).
 * 6. STOP
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
 * Function to count total nodes in the list.
 */
int countNodes(struct Node *head) {
    int count = 0;
    struct Node *temp = head;
    
    while (temp != NULL) {
        count++;            /* Count this node */
        temp = temp->next;  /* Move to the next node */
    }
    return count;
}

/* 
 * Function to search for a value in the list.
 * Returns the position if found, or -1 if not found.
 */
int searchValue(struct Node *head, int target) {
    struct Node *temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == target) {
            return pos;  /* Found it! */
        }
        temp = temp->next;
        pos++;
    }
    return -1;  /* Not found */
}

/* Function to print the list */
void displayList(struct Node *head) {
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

    /* Build: 10 -> 25 -> 50 -> 75 */
    head = createNode(10);
    head->next = createNode(25);
    head->next->next = createNode(50);
    head->next->next->next = createNode(75);

    printf("=== LINKED LIST: SEARCH AND COUNT ===\n\n");
    displayList(head);

    /* 1. Count Nodes */
    int total = countNodes(head);
    printf("\nTotal number of nodes: %d\n", total);

    /* 2. Search for 50 */
    int target = 50;
    int pos = searchValue(head, target);
    if (pos != -1)
        printf("Value %d found at position %d.\n", target, pos);
    else
        printf("Value %d NOT found in the list.\n", target);

    /* 3. Search for 100 */
    target = 100;
    pos = searchValue(head, target);
    if (pos != -1)
        printf("Value %d found at position %d.\n", target, pos);
    else
        printf("Value %d NOT found in the list.\n", target);

    return 0;
}

/*
 * ============================================================
 * STUDENT NOTE:
 * ============================================================
 * SEARCHING:
 * Because a Linked List is not indexed like an array, we 
 * cannot jump to a specific node (e.g., list[5] doesn't exist).
 * We MUST start from the Head and check nodes one by one.
 *
 * Time Complexity: O(n) for both searching and counting.
 * ============================================================
 * 
 * EXPECTED OUTPUT:
 * === LINKED LIST: SEARCH AND COUNT ===
 *
 *   List: [10] -> [25] -> [50] -> [75] -> NULL
 *
 * Total number of nodes: 4
 *
 * Value 50 found at position 3.
 * Value 100 NOT found in the list.
 * ============================================================
 */
