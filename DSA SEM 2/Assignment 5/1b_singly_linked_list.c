#include <stdio.h>
#include <stdlib.h>

// Structure for a Node
struct Node {
    int data;
    struct Node* next;
};

// Global Head pointer
struct Node* head = NULL;

// Function prototypes
void insertAtBeginning(int value);
void insertAtEnd(int value);
void deleteFromBeginning();
void deleteFromEnd();
void display();

int main() {
    int choice, value;

    while (1) {
        printf("\n--- SINGLY LINKED LIST MENU ---");
        printf("\n1. Insert at Beginning");
        printf("\n2. Insert at End");
        printf("\n3. Delete from Beginning");
        printf("\n4. Delete from End");
        printf("\n5. Display List");
        printf("\n6. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                deleteFromBeginning();
                break;
            case 4:
                deleteFromEnd();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Function to insert at the front
void insertAtBeginning(int value) {
    // 1. Create a new node in memory
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // 2. Put data in the node
    newNode->data = value;
    
    // 3. Link new node to the current head
    newNode->next = head;
    
    // 4. Update head to point to the new node
    head = newNode;
    
    printf("Inserted %d at the beginning.\n", value);
}

// Function to insert at the back
void insertAtEnd(int value) {
    // 1. Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL; // New last node always points to NULL

    // 2. If list is empty, new node becomes the head
    if (head == NULL) {
        head = newNode;
    } else {
        // 3. Traverse to the very last node
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        // 4. Link the last node to our new node
        temp->next = newNode;
    }
    printf("Inserted %d at the end.\n", value);
}

// Function to delete the first node
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    // 1. Keep track of the node we want to delete
    struct Node* temp = head;
    
    // 2. Move head to the next node
    head = head->next;
    
    // 3. Free the memory of the old first node
    free(temp);
    
    printf("Deleted first node.\n");
}

// Function to delete the last node
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    // Case: Only one node in the list
    if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        // Find the second-to-last node
        struct Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        
        // Free the last node
        free(temp->next);
        
        // Disconnect the last link
        temp->next = NULL;
    }
    printf("Deleted last node.\n");
}

// Function to show the list
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
