/*
 * ============================================================
 * LINKED LIST 02: INSERTION AT END
 * ============================================================
 * Topic: Singly Linked List
 * Language: C
 * Level: 1st Year BCA
 *
 * WHAT IS "INSERTION AT END"?
 * Adding a new node at the TAIL (last position) of the list.
 * The new node becomes the new last node (its next = NULL).
 *
 * Before: HEAD -> [10] -> [20] -> [30] -> NULL
 * Insert 40: HEAD -> [10] -> [20] -> [30] -> [40] -> NULL
 *
 * DIFFERENCE FROM INSERTION AT BEGINNING:
 *   - At beginning: O(1) — no traversal needed
 *   - At end: O(n) — we must walk to the LAST node first
 *
 * The LAST node is the one whose .next == NULL.
 * We change its .next to point to the new node.
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
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;    /* Always NULL when just created */
    return newNode;
}

/* ---- FUNCTION: insertAtEnd ----
 * Adds a new node at the LAST position of the list.
 *
 * Steps:
 *   1. Create the new node
 *   2. If list is empty, new node becomes HEAD
 *   3. Otherwise, walk to the last node (last->next == NULL)
 *   4. Set last->next = newNode
 */
void insertAtEnd(struct Node **head, int value) {
    struct Node *newNode = createNode(value);  /* Step 1 */
    if (newNode == NULL) return;

    /* Step 2: If list is empty, new node is HEAD */
    if (*head == NULL) {
        *head = newNode;
        printf("  Inserted %d at end (list was empty, now HEAD).\n", value);
        return;
    }

    /* Step 3: Walk to the last node */
    struct Node *current = *head;   /* Start from HEAD */

    while (current->next != NULL) {   /* Keep going until .next is NULL */
        current = current->next;      /* Move one step forward */
    }

    /* Step 4: current is now the LAST node, connect to new node */
    current->next = newNode;   /* Last node now points to new node */

    printf("  Inserted %d at end.\n", value);
}

/* ---- FUNCTION: traverse ---- */
void traverse(struct Node *head) {
    struct Node *current = head;
    printf("  List: HEAD -> ");
    if (current == NULL) {
        printf("NULL (list is empty)\n");
        return;
    }
    while (current != NULL) {
        if (current->next == NULL) {
            printf("[%d] -> NULL\n", current->data);   /* Last node */
        } else {
            printf("[%d] -> ", current->data);
        }
        current = current->next;
    }
}

/* ---- MAIN ---- */
int main() {
    struct Node *head = NULL;

    printf("=== SINGLY LINKED LIST: INSERTION AT END ===\n\n");

    printf("Inserting elements at END one by one:\n\n");

    insertAtEnd(&head, 10);
    traverse(head);

    insertAtEnd(&head, 20);
    traverse(head);

    insertAtEnd(&head, 30);
    traverse(head);

    insertAtEnd(&head, 40);
    traverse(head);

    insertAtEnd(&head, 50);
    traverse(head);

    printf("\nFinal List:\n");
    traverse(head);

    /* Find and show the last node */
    struct Node *temp = head;
    while (temp->next != NULL) temp = temp->next;
    printf("\nLast node value: %d\n", temp->data);

    return 0;
}

/*
 * ============================================================
 * SAMPLE OUTPUT:
 * ============================================================
 * === SINGLY LINKED LIST: INSERTION AT END ===
 *
 * Inserting elements at END one by one:
 *
 *   Inserted 10 at end (list was empty, now HEAD).
 *   List: HEAD -> [10] -> NULL
 *
 *   Inserted 20 at end.
 *   List: HEAD -> [10] -> [20] -> NULL
 *
 *   Inserted 30 at end.
 *   List: HEAD -> [10] -> [20] -> [30] -> NULL
 *
 *   Inserted 40 at end.
 *   List: HEAD -> [10] -> [20] -> [30] -> [40] -> NULL
 *
 *   Inserted 50 at end.
 *   List: HEAD -> [10] -> [20] -> [30] -> [40] -> [50] -> NULL
 *
 * Final List:
 *   List: HEAD -> [10] -> [20] -> [30] -> [40] -> [50] -> NULL
 *
 * Last node value: 50
 *
 * ============================================================
 * ALGORITHM — INSERTION AT END:
 * ============================================================
 * Step 1: Create new node
 *         newNode->data = value
 *         newNode->next = NULL
 *
 * Step 2: If head == NULL (empty list):
 *         head = newNode   [done]
 *
 * Step 3: Otherwise, traverse to last node:
 *         current = head
 *         WHILE current->next != NULL:
 *             current = current->next
 *         (Now current points to the last node)
 *
 * Step 4: current->next = newNode
 *         (New node is now the last node)
 *
 * Diagram (inserting 40 after [10]->[20]->[30]):
 *
 *   HEAD -> [10 | *] -> [20 | *] -> [30 | NULL]
 *
 *   Walk: 10 -> 20 -> 30  (stop when next is NULL)
 *
 *   [30 | NULL]  becomes  [30 | *] -> [40 | NULL]
 *
 *   HEAD -> [10] -> [20] -> [30] -> [40] -> NULL
 *
 * TIME COMPLEXITY: O(n) — must walk entire list to reach end
 * SPACE COMPLEXITY: O(1) — one new node allocated
 *
 * HOW TO MAKE IT O(1)?
 * Maintain a TAIL pointer in addition to HEAD.
 * Then you can directly access the last node without traversal.
 * ============================================================
 */
