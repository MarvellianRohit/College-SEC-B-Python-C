/*
 * ============================================================
 * LINKED LIST 10: CIRCULAR LINKED LIST
 * ============================================================
 * Topic: Circular Linked List (Simplified)
 * Language: C
 * Level: 1st Year BCA
 * 
 * DETAILED EXPLANATION:
 * A Circular Linked List is a variation of a Linked List in which 
 * the last node points back to the first node (head) instead of 
 * NULL. This creates a circular loop, allowing the list to be 
 * traversed infinitely.
 *
 * ALGORITHM (Insertion at End):
 * 1. START
 * 2. Create a new Node (newNode) and assign data.
 * 3. IF (head == NULL):
 *    a. Set head = newNode.
 *    b. Set newNode->next = head.
 * 4. ELSE:
 *    a. Create temp pointer starting at head.
 *    b. WHILE (temp->next != head):
 *       i. Move temp to next node.
 *    c. Set temp->next = newNode.
 *    d. Set newNode->next = head.
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

/* Insert at end - returns head */
struct Node* insertCircular(struct Node *head, int val) {
    struct Node *newNode = createNode(val);
    
    if (head == NULL) {
        newNode->next = newNode; /* Points to itself! */
        printf("  >> Inserted %d (first node).\n", val);
        return newNode;
    }

    struct Node *temp = head;
    /* Find the last node (the one pointing to head) */
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;     /* Old last node points to new node */
    newNode->next = head;     /* New node points back to head */

    printf("  >> Inserted %d at end.\n", val);
    return head;
}

/* Print circular list */
void displayCircular(struct Node *head) {
    if (head == NULL) {
        printf("  List: [EMPTY]\n");
        return;
    }

    struct Node *temp = head;
    printf("  List: ");
    
    /* We use a do-while loop because the condition 
       'temp != head' is already false at the start! */
    do {
        printf("[%d] -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(Back to Head: %d)\n", head->data);
}

int main() {
    struct Node *head = NULL;

    printf("=== CIRCULAR LINKED LIST ===\n\n");

    head = insertCircular(head, 10);
    head = insertCircular(head, 20);
    head = insertCircular(head, 30);
    
    displayCircular(head);

    return 0;
}

/*
 * ============================================================
 * EXPECTED OUTPUT:
 * === CIRCULAR LINKED LIST ===
 *
 *   >> Inserted 10 (first node).
 *   >> Inserted 20 at end.
 *   >> Inserted 30 at end.
 *   List: [10] -> [20] -> [30] -> (Back to Head: 10)
 * ============================================================
 */
