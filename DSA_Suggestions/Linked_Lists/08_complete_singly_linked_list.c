/*
 * ============================================================
 * LINKED LIST 08: COMPLETE SINGLY LINKED LIST (MENU DRIVEN)
 * ============================================================
 * Topic: Singly Linked List (Simplified)
 * Language: C
 * Level: 1st Year BCA
 * 
 * DETAILED EXPLANATION:
 * This program is a comprehensive tool that allows the user to 
 * interactively manage a Singly Linked List. It provides functions 
 * for multiple types of insertion and deletion, demonstrating 
 * how a single head pointer can be used to control the entire list 
 * structure through various operations.
 *
 * ALGORITHM:
 * 1. START
 * 2. Initialize head = NULL.
 * 3. Display a list of options (Insertion, Deletion, Display, Exit).
 * 4. WHILE (true):
 *    a. Input choice from user.
 *    b. IF choice is INSERT: Get value and position, update head.
 *    c. IF choice is DELETE: Update head after removing node.
 *    d. IF choice is DISPLAY: Traverse and print the list.
 *    e. IF choice is EXIT: Break the loop and STOP.
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
    struct Node *n = (struct Node*) malloc(sizeof(struct Node));
    n->data = value;
    n->next = NULL;
    return n;
}

/* --- INSERTION FUNCTIONS --- */

struct Node* insertFront(struct Node *head, int val) {
    struct Node *newNode = createNode(val);
    newNode->next = head;
    return newNode;
}

struct Node* insertEnd(struct Node *head, int val) {
    struct Node *newNode = createNode(val);
    if (head == NULL) return newNode;
    struct Node *temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    return head;
}

struct Node* insertPos(struct Node *head, int val, int pos) {
    if (pos == 1) return insertFront(head, val);
    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) temp = temp->next;
    if (temp == NULL) { printf("Error: Position out of range!\n"); return head; }
    struct Node *newNode = createNode(val);
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

/* --- DELETION FUNCTIONS --- */

struct Node* deleteFront(struct Node *head) {
    if (head == NULL) return NULL;
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Node* deleteEnd(struct Node *head) {
    if (head == NULL || head->next == NULL) {
        if (head) free(head);
        return NULL;
    }
    struct Node *temp = head;
    while (temp->next->next != NULL) temp = temp->next;
    free(temp->next);
    temp->next = NULL;
    return head;
}

/* --- UTILITY --- */

void display(struct Node *head) {
    struct Node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("[%d] -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    int choice, value, pos;

    while (1) {
        printf("\n--- SINGLY LINKED LIST MENU ---\n");
        printf("1. Insert Front    2. Insert End    3. Insert at Position\n");
        printf("4. Delete Front    5. Delete End    6. Display\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Value: "); scanf("%d", &value);
                head = insertFront(head, value);
                break;
            case 2:
                printf("Value: "); scanf("%d", &value);
                head = insertEnd(head, value);
                break;
            case 3:
                printf("Value: "); scanf("%d", &value);
                printf("Position: "); scanf("%d", &pos);
                head = insertPos(head, value, pos);
                break;
            case 4:
                head = deleteFront(head);
                break;
            case 5:
                head = deleteEnd(head);
                break;
            case 6:
                display(head);
                break;
            case 0:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

/*
 * ============================================================
 * EXPECTED OUTPUT (Sample Run):
 * =--- SINGLY LINKED LIST MENU ---
 * 1. Insert Front    2. Insert End    3. Insert at Position
 * 4. Delete Front    5. Delete End    6. Display
 * 0. Exit
 * Choice: 1
 * Value: 10
 *
 * --- SINGLY LINKED LIST MENU ---
 * Choice: 2
 * Value: 20
 *
 * --- SINGLY LINKED LIST MENU ---
 * Choice: 6
 * List: [10] -> [20] -> NULL
 *
 * --- SINGLY LINKED LIST MENU ---
 * Choice: 4
 *
 * --- SINGLY LINKED LIST MENU ---
 * Choice: 6
 * List: [20] -> NULL
 *
 * Choice: 0
 * Exiting...
 * ============================================================
 */
