#include <stdio.h>
#include <stdlib.h>

/* 
   TOPIC: Polynomial Representation
   Polynomial to represent: 3x^5 + 4x^3 + 5
   (Note: 5 is 5x^0)
*/

// --- 1. ARRAY REPRESENTATION ---
// We use a structure to store each term: (coefficient, exponent)
struct Term {
    int coeff;
    int exp;
};

// --- 2. LINKED LIST REPRESENTATION ---
// Each node stores a term and a pointer to the next term
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Function prototypes
void displayArrayForm(struct Term poly[], int n);
void displayLinkedListForm(struct Node* head);

int main() {
    printf("DSA Assignment 5: Polynomial Representation\n");
    printf("==========================================\n\n");

    // --- ARRAY FORM IMPLEMENTATION ---
    // We create an array of 3 terms
    struct Term polyArray[3] = {
        {3, 5}, // 3x^5
        {4, 3}, // 4x^3
        {5, 0}  // 5x^0
    };
    
    printf("1. ARRAY REPRESENTATION:\n");
    displayArrayForm(polyArray, 3);
    printf("\n");


    // --- LINKED LIST FORM IMPLEMENTATION ---
    // Step 1: Create nodes manually for clarity
    struct Node *n1, *n2, *n3;

    n1 = (struct Node*)malloc(sizeof(struct Node));
    n2 = (struct Node*)malloc(sizeof(struct Node));
    n3 = (struct Node*)malloc(sizeof(struct Node));

    // Step 2: Assign values
    n1->coeff = 3; n1->exp = 5;
    n2->coeff = 4; n2->exp = 3;
    n3->coeff = 5; n3->exp = 0;

    // Step 3: Link them together
    n1->next = n2;
    n2->next = n3;
    n3->next = NULL; // Last term points to NULL

    printf("2. LINKED LIST REPRESENTATION:\n");
    displayLinkedListForm(n1);

    return 0;
}

// Function to print the array-based polynomial
void displayArrayForm(struct Term poly[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%dx^%d", poly[i].coeff, poly[i].exp);
        if (i < n - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Function to print the linked-list-based polynomial
void displayLinkedListForm(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("(%d, %d)", temp->coeff, temp->exp);
        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf(" -> NULL\n");
}

/*
EXPECTED OUTPUT:
DSA Assignment 5: Polynomial Representation
==========================================

1. ARRAY REPRESENTATION:
3x^5 + 4x^3 + 5x^0

2. LINKED LIST REPRESENTATION:
(3, 5) -> (4, 3) -> (5, 0) -> NULL
*/
