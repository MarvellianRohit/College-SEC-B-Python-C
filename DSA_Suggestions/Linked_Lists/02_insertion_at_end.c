/*
 * ============================================================
 * LINKED LIST 02: INSERTION AT END
 * ============================================================
 * Topic: Singly Linked List (Simple Version)
 * Language: C
 * Level: 1st Year BCA
 *
 * WHAT IS "INSERTION AT END"?
 * It means adding a new node after the current last node.
 * Unlike insertion at beginning, we have to LOOP (traverse)
 * to find the last node first.
 *
 * Steps:
 * 1. Create a new Node.
 * 2. If the list is empty, the new Node becomes the Head.
 * 3. Otherwise, walk to the last node.
 * 4. Connect the last node's 'next' to our new Node.
 * ============================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

/* Helper function to create a node */
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

/* 
 * Function to insert at the end.
 * Returns the head of the list.
 */
struct Node* insertAtEnd(struct Node *head, int value) {
    struct Node *newNode = createNode(value);

    /* Case 1: If list is empty, new node is the head */
    if (head == NULL) {
        printf("  >> Inserted %d (first node).\n", value);
        return newNode;
    }

    /* Case 2: Traversing to the last node */
    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;  /* Move to the next node */
    }

    /* Link the last node to our new node */
    temp->next = newNode;
    printf("  >> Inserted %d at the end.\n", value);
    
    return head; /* Return the same head */
}

void displayList(struct Node *head) {
    if (head == NULL) {
        printf("  List: [EMPTY]\n");
        return;
    }
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

    printf("=== SINGLY LINKED LIST: INSERT AT END ===\n\n");

    head = insertAtEnd(head, 10);
    displayList(head);

    head = insertAtEnd(head, 20);
    displayList(head);

    head = insertAtEnd(head, 30);
    displayList(head);

    printf("\nFinal list after all insertions:\n");
    displayList(head);

    return 0;
}

/*
 * ============================================================
 * STUDENT NOTE:
 * ============================================================
 * Why do we use 'while (temp->next != NULL)'?
 * Because we want to stop at the LAST node. 
 * If we used 'while (temp != NULL)', we would stop AFTER the 
 * last node (at NULL), and we wouldn't have a way to connect 
 * the old last node to the new one.
 *
 * Time Complexity: O(n) - We have to visit all nodes to reach the end.
 * ============================================================
 */
