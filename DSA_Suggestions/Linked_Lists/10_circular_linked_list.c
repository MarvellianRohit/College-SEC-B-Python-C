/*
 * ============================================================
 * LINKED LIST 10: CIRCULAR LINKED LIST
 * ============================================================
 * Topic: Circular Linked List (Simplified)
 * Language: C
 * Level: 1st Year BCA
 *
 * WHAT IS A CIRCULAR LINKED LIST?
 * A list where the LAST node's 'next' pointer points back 
 * to the HEAD instead of NULL.
 *
 * It forms a continuous loop!
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
