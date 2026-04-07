/*
 * ============================================================
 * LINKED LIST 08: COMPLETE SINGLY LINKED LIST — ALL OPERATIONS
 * ============================================================
 * Topic: Singly Linked List
 * Language: C
 * Level: 1st Year BCA
 *
 * This file is a COMPLETE MENU-DRIVEN program combining:
 *   - Insert at Beginning
 *   - Insert at End
 *   - Insert at Position
 *   - Delete from Beginning
 *   - Delete from End
 *   - Delete at Position
 *   - Traverse / Display
 *   - Search
 *   - Count nodes
 *
 * This is a great revision program. Study the individual
 * programs first (01-07), then use this as a reference.
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
    if (!n) { printf("Memory error!\n"); return NULL; }
    n->data = value;
    n->next = NULL;
    return n;
}

/* ---- INSERT AT BEGINNING ---- */
void insertBeginning(struct Node **head, int val) {
    struct Node *n = createNode(val);
    if (!n) return;
    n->next = *head;
    *head = n;
    printf("  >> Inserted %d at beginning.\n", val);
}

/* ---- INSERT AT END ---- */
void insertEnd(struct Node **head, int val) {
    struct Node *n = createNode(val);
    if (!n) return;
    if (*head == NULL) { *head = n; printf("  >> Inserted %d (first node).\n", val); return; }
    struct Node *cur = *head;
    while (cur->next) cur = cur->next;
    cur->next = n;
    printf("  >> Inserted %d at end.\n", val);
}

/* ---- INSERT AT POSITION ---- */
void insertPosition(struct Node **head, int val, int pos) {
    if (pos < 1) { printf("  >> Invalid position!\n"); return; }
    struct Node *n = createNode(val);
    if (!n) return;
    if (pos == 1) { n->next = *head; *head = n; printf("  >> Inserted %d at pos 1.\n", val); return; }
    struct Node *cur = *head;
    int i;
    for (i = 1; i < pos - 1 && cur; i++) cur = cur->next;
    if (!cur) { printf("  >> Position out of range!\n"); free(n); return; }
    n->next = cur->next;
    cur->next = n;
    printf("  >> Inserted %d at position %d.\n", val, pos);
}

/* ---- DELETE FROM BEGINNING ---- */
void deleteBeginning(struct Node **head) {
    if (!*head) { printf("  >> List is empty!\n"); return; }
    struct Node *tmp = *head;
    int val = tmp->data;
    *head = (*head)->next;
    free(tmp);
    printf("  >> Deleted %d from beginning.\n", val);
}

/* ---- DELETE FROM END ---- */
void deleteEnd(struct Node **head) {
    if (!*head) { printf("  >> List is empty!\n"); return; }
    if (!(*head)->next) {
        int val = (*head)->data; free(*head); *head = NULL;
        printf("  >> Deleted %d (list now empty).\n", val); return;
    }
    struct Node *prev = NULL, *cur = *head;
    while (cur->next) { prev = cur; cur = cur->next; }
    printf("  >> Deleted %d from end.\n", cur->data);
    prev->next = NULL;
    free(cur);
}

/* ---- DELETE AT POSITION ---- */
void deletePosition(struct Node **head, int pos) {
    if (pos < 1 || !*head) { printf("  >> Invalid or empty!\n"); return; }
    struct Node *tmp;
    if (pos == 1) {
        tmp = *head; *head = (*head)->next;
        printf("  >> Deleted %d from pos 1.\n", tmp->data); free(tmp); return;
    }
    struct Node *prev = *head;
    int i;
    for (i = 1; i < pos - 1 && prev->next; i++) prev = prev->next;
    if (!prev->next || !prev->next) { printf("  >> Position out of range!\n"); return; }
    tmp = prev->next;
    prev->next = tmp->next;
    printf("  >> Deleted %d from position %d.\n", tmp->data, pos);
    free(tmp);
}

/* ---- TRAVERSE ---- */
void traverse(struct Node *head) {
    if (!head) { printf("  List: [EMPTY]\n"); return; }
    printf("  List: HEAD");
    struct Node *cur = head;
    while (cur) { printf(" -> [%d]", cur->data); cur = cur->next; }
    printf(" -> NULL\n");
}

/* ---- COUNT ---- */
int count(struct Node *head) {
    int c = 0;
    while (head) { c++; head = head->next; }
    return c;
}

/* ---- SEARCH ---- */
void search(struct Node *head, int val) {
    struct Node *cur = head;
    int pos = 1;
    while (cur) {
        if (cur->data == val) { printf("  >> %d found at position %d.\n", val, pos); return; }
        cur = cur->next; pos++;
    }
    printf("  >> %d NOT found in list.\n", val);
}

/* ---- MENU ---- */
void printMenu() {
    printf("\n========== MENU ==========\n");
    printf("1. Insert at Beginning\n");
    printf("2. Insert at End\n");
    printf("3. Insert at Position\n");
    printf("4. Delete from Beginning\n");
    printf("5. Delete from End\n");
    printf("6. Delete at Position\n");
    printf("7. Display List\n");
    printf("8. Count Nodes\n");
    printf("9. Search Value\n");
    printf("0. Exit\n");
    printf("==========================\n");
    printf("Enter choice: ");
}

/* ---- MAIN ---- */
int main() {
    struct Node *head = NULL;
    int choice, val, pos;

    printf("=== COMPLETE SINGLY LINKED LIST PROGRAM ===\n");

    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("  Enter value: "); scanf("%d", &val);
                insertBeginning(&head, val);
                break;
            case 2:
                printf("  Enter value: "); scanf("%d", &val);
                insertEnd(&head, val);
                break;
            case 3:
                printf("  Enter value: "); scanf("%d", &val);
                printf("  Enter position: "); scanf("%d", &pos);
                insertPosition(&head, val, pos);
                break;
            case 4:
                deleteBeginning(&head);
                break;
            case 5:
                deleteEnd(&head);
                break;
            case 6:
                printf("  Enter position: "); scanf("%d", &pos);
                deletePosition(&head, pos);
                break;
            case 7:
                traverse(head);
                break;
            case 8:
                printf("  Total nodes: %d\n", count(head));
                break;
            case 9:
                printf("  Enter value to search: "); scanf("%d", &val);
                search(head, val);
                break;
            case 0:
                printf("  Exiting...\n");
                break;
            default:
                printf("  Invalid choice. Try again.\n");
        }

        if (choice != 7 && choice != 0) traverse(head);

    } while (choice != 0);

    return 0;
}

/*
 * ============================================================
 * SAMPLE OUTPUT (interactive session):
 * ============================================================
 * === COMPLETE SINGLY LINKED LIST PROGRAM ===
 *
 * ========== MENU ==========
 * 1. Insert at Beginning   2. Insert at End    3. Insert at Position
 * 4. Delete from Beginning 5. Delete from End  6. Delete at Position
 * 7. Display List          8. Count Nodes      9. Search Value
 * 0. Exit
 * ==========================
 * Enter choice: 2
 *   Enter value: 10
 *   >> Inserted 10 (first node).
 *   List: HEAD -> [10] -> NULL
 *
 * Enter choice: 2
 *   Enter value: 20
 *   >> Inserted 20 at end.
 *   List: HEAD -> [10] -> [20] -> NULL
 *
 * Enter choice: 1
 *   Enter value: 5
 *   >> Inserted 5 at beginning.
 *   List: HEAD -> [5] -> [10] -> [20] -> NULL
 *
 * Enter choice: 3
 *   Enter value: 15    Enter position: 3
 *   >> Inserted 15 at position 3.
 *   List: HEAD -> [5] -> [10] -> [15] -> [20] -> NULL
 *
 * Enter choice: 8
 *   Total nodes: 4
 *
 * Enter choice: 9
 *   Enter value to search: 15
 *   >> 15 found at position 3.
 *
 * ============================================================
 * ALGORITHM SUMMARY — ALL OPERATIONS:
 * ============================================================
 * Insert Beginning:  O(1) — just update head
 * Insert End:        O(n) — traverse to last node
 * Insert Position p: O(p) — traverse to position p-1
 * Delete Beginning:  O(1) — just update head
 * Delete End:        O(n) — traverse to second-to-last
 * Delete Position p: O(p) — traverse to position p-1
 * Traverse:          O(n) — visit all nodes
 * Count:             O(n) — visit all nodes
 * Search:            O(n) — visit until found or end
 * ============================================================
 */
