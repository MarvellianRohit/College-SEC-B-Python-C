/*
 * ============================================================
 *  Binary Search Tree (BST) - DSA SEM 2 Classwork
 *  Student : Rohit Chandra | SEC-B
 *  Topic   : Binary Search Tree using C
 * ============================================================
 *
 *  Operations implemented:
 *   1. Insert a node
 *   2. Inorder   Traversal (Left → Root → Right) → Sorted output
 *   3. Preorder  Traversal (Root → Left → Right)
 *   4. Postorder Traversal (Left → Right → Root)
 *   5. Search a value
 *   6. Find Minimum value in BST
 *   7. Find Maximum value in BST
 *   8. Delete a node
 *   9. Display menu-driven interface
 */

#include <stdio.h>   /* Include standard I/O library for printf, scanf */
#include <stdlib.h>  /* Include standard library for malloc, free, exit */

/* ─────────────────────────────────────────────
   NODE STRUCTURE
   Each node stores:
     - data  : integer value
     - left  : pointer to left child  (smaller values)
     - right : pointer to right child (larger values)
   ───────────────────────────────────────────── */
struct NODE {          /* Define a structure called NODE to represent each tree node */
  int data;            /* 'data' holds the integer value stored in this node */
  struct NODE *left;   /* 'left' is a pointer to the left child (holds smaller values) */
  struct NODE *right;  /* 'right' is a pointer to the right child (holds larger values) */
};                     /* End of struct NODE definition */

/* ─────────────────────────────────────────────
   CREATE A NEW NODE
   Allocates memory for a new node and sets its
   data; left and right children are NULL.
   ───────────────────────────────────────────── */
struct NODE *Create_Tree(int Info, struct NODE *Node) { /* Function to create a brand-new node; takes value (Info) and a node pointer */
  Node = (struct NODE *)malloc(sizeof(struct NODE));    /* Allocate memory from the heap for one NODE; cast the void* to struct NODE* */
  if (Node == NULL) {                                   /* Check if malloc failed (returns NULL when out of memory) */
    printf("Memory allocation failed!\n");              /* Print an error message if memory could not be allocated */
    exit(1);                                            /* Terminate the whole program with error code 1 */
  }                                                     /* End of NULL-check block */
  Node->data = Info;    /* Store the given value (Info) into the new node's data field */
  Node->left = NULL;    /* Set the left child pointer to NULL — no left child yet */
  Node->right = NULL;   /* Set the right child pointer to NULL — no right child yet */
  return Node;          /* Return the pointer to the newly created and initialised node */
}                       /* End of Create_Tree function */

/* ─────────────────────────────────────────────
   INSERT A NODE INTO BST
   Rule:
     - If Info < current node  → go LEFT
     - If Info > current node  → go RIGHT
     - If Info == current node → duplicate, skip
   Returns the (possibly updated) root pointer.
   ───────────────────────────────────────────── */
struct NODE *insert(struct NODE *root, int Info) { /* Recursive function to insert a value into the BST; returns updated root */
  /* Base case: empty spot found, create and place node here */
  if (root == NULL) {                    /* If the current node/position is empty (NULL), we insert here */
    return Create_Tree(Info, root);      /* Create and return a new node at this empty position */
  }                                      /* End of base-case block */

  if (Info < root->data) {              /* If the value to insert is smaller than the current node's value */
    /* Info is smaller → insert in LEFT subtree */
    root->left = insert(root->left, Info);   /* Recurse into the LEFT subtree and link the returned node back */
  } else if (Info > root->data) {           /* If the value to insert is larger than the current node's value */
    /* Info is larger → insert in RIGHT subtree */
    root->right = insert(root->right, Info); /* Recurse into the RIGHT subtree and link the returned node back */
  } else {                                   /* Otherwise, Info == root->data (duplicate value) */
    /* Duplicate value → BST does not allow duplicates */
    printf("  [!] Value %d already exists in the tree. Skipping.\n", Info); /* Inform the user that duplicate values are not allowed */
  }                                          /* End of if-else chain */

  return root; /* Return the (unchanged) current root after insertion is complete in the subtree */
}              /* End of insert function */

/* ─────────────────────────────────────────────
   INORDER TRAVERSAL  →  Left, Root, Right
   Visits nodes in ASCENDING (sorted) order.
   ───────────────────────────────────────────── */
void inorder(struct NODE *root) {    /* Function for inorder traversal: Left → Root → Right */
  if (root == NULL)                  /* Base case: if the current node is NULL, the subtree is empty — stop recursion */
    return;                          /* Return immediately, doing nothing for empty subtree */
  inorder(root->left);              /* Recursively visit the LEFT subtree first */
  printf("%d ", root->data);        /* Then PRINT the current node's data (this gives sorted output) */
  inorder(root->right);             /* Then recursively visit the RIGHT subtree */
}                                   /* End of inorder function */

/* ─────────────────────────────────────────────
   PREORDER TRAVERSAL  →  Root, Left, Right
   Useful for copying/cloning a tree.
   ───────────────────────────────────────────── */
void preorder(struct NODE *root) {  /* Function for preorder traversal: Root → Left → Right */
  if (root == NULL)                 /* Base case: if the current node is NULL, stop recursion */
    return;                         /* Return immediately for an empty subtree */
  printf("%d ", root->data);       /* PRINT the current (root) node's data FIRST */
  preorder(root->left);            /* Then recursively visit the LEFT subtree */
  preorder(root->right);           /* Then recursively visit the RIGHT subtree */
}                                  /* End of preorder function */

/* ─────────────────────────────────────────────
   POSTORDER TRAVERSAL  →  Left, Right, Root
   Useful for deleting a tree safely.
   ───────────────────────────────────────────── */
void postorder(struct NODE *root) { /* Function for postorder traversal: Left → Right → Root */
  if (root == NULL)                 /* Base case: if the current node is NULL, stop recursion */
    return;                         /* Return immediately for an empty subtree */
  postorder(root->left);           /* Recursively visit the LEFT subtree first */
  postorder(root->right);          /* Then recursively visit the RIGHT subtree */
  printf("%d ", root->data);       /* Then PRINT the current node's data LAST (root is visited after children) */
}                                  /* End of postorder function */

/* ─────────────────────────────────────────────
   SEARCH A VALUE IN BST
   Returns pointer to node if found, else NULL.
   ───────────────────────────────────────────── */
struct NODE *search(struct NODE *root, int value) { /* Function to search for a value in BST; returns the node or NULL */
  /* Base cases: not found OR found */
  if (root == NULL || root->data == value) { /* If root is NULL (not found) OR data matches (found) */
    return root;                             /* Return the current node (NULL if not found, node pointer if found) */
  }                                          /* End of base-case check */

  if (value < root->data) {         /* If the target value is smaller than the current node's data */
    /* Search in left subtree */
    return search(root->left, value);  /* Recursively search in the LEFT subtree */
  } else {                             /* Otherwise, the target value must be larger */
    /* Search in right subtree */
    return search(root->right, value); /* Recursively search in the RIGHT subtree */
  }                                    /* End of direction decision */
}                                      /* End of search function */

/* ─────────────────────────────────────────────
   FIND MINIMUM VALUE IN BST
   The leftmost node always holds the minimum.
   ───────────────────────────────────────────── */
struct NODE *findMin(struct NODE *root) { /* Function to find the node with the minimum (smallest) value in the BST */
  if (root == NULL)                       /* If the tree is empty, there is no minimum */
    return NULL;                          /* Return NULL to indicate no minimum exists */
  /* Keep going left until we hit the last left node */
  while (root->left != NULL) { /* As long as there is still a left child to go to ... */
    root = root->left;        /* Move to the left child (going further left finds smaller values) */
  }                           /* End of while loop — we've reached the leftmost (smallest) node */
  return root;                /* Return the pointer to the leftmost (minimum) node */
}                             /* End of findMin function */

/* ─────────────────────────────────────────────
   FIND MAXIMUM VALUE IN BST
   The rightmost node always holds the maximum.
   ───────────────────────────────────────────── */
struct NODE *findMax(struct NODE *root) { /* Function to find the node with the maximum (largest) value in the BST */
  if (root == NULL)                       /* If the tree is empty, there is no maximum */
    return NULL;                          /* Return NULL to indicate no maximum exists */
  /* Keep going right until we hit the last right node */
  while (root->right != NULL) { /* As long as there is still a right child to go to ... */
    root = root->right;         /* Move to the right child (going further right finds larger values) */
  }                             /* End of while loop — we've reached the rightmost (largest) node */
  return root;                  /* Return the pointer to the rightmost (maximum) node */
}                               /* End of findMax function */

/* ─────────────────────────────────────────────
   DELETE A NODE FROM BST
   Three cases:
     Case 1: Node has NO children (leaf) → just delete
     Case 2: Node has ONE child         → replace with child
     Case 3: Node has TWO children      → replace data with
             inorder successor (min of right subtree),
             then delete that successor
   ───────────────────────────────────────────── */
struct NODE *deleteNode(struct NODE *root, int value) { /* Recursive function to delete a node with given value from the BST */
  if (root == NULL) {                                   /* If root is NULL, the value does not exist in the tree */
    printf("  [!] Value %d not found in tree.\n", value); /* Inform user that the value to delete was not found */
    return root;                                           /* Return NULL — nothing to delete */
  }                                                        /* End of not-found check */

  if (value < root->data) {                        /* If the value to delete is smaller than current node's data */
    /* Target is in LEFT subtree */
    root->left = deleteNode(root->left, value);    /* Recursively delete from LEFT subtree; link back the new left child */
  } else if (value > root->data) {                 /* If the value to delete is larger than current node's data */
    /* Target is in RIGHT subtree */
    root->right = deleteNode(root->right, value);  /* Recursively delete from RIGHT subtree; link back the new right child */
  } else {                                         /* Otherwise, we found the exact node to delete */
    /* ── FOUND the node to delete ── */

    /* Case 1 & 2: Node has 0 or 1 child */
    if (root->left == NULL) {             /* If the node has NO left child (it has 0 or only a right child) */
      struct NODE *temp = root->right;    /* Save the right child (or NULL if none) in a temp pointer */
      free(root);                         /* Free the current node's memory — deallocate it from the heap */
      return temp;                        /* Return the right child to replace the deleted node in its parent */
    } else if (root->right == NULL) {     /* If the node has NO right child (it only has a left child) */
      struct NODE *temp = root->left;     /* Save the left child in a temp pointer */
      free(root);                         /* Free the current node's memory */
      return temp;                        /* Return the left child to replace the deleted node in its parent */
    }                                     /* End of Case 1 & 2 handling */

    /* Case 3: Node has 2 children
       Find inorder successor = min value in right subtree */
    struct NODE *successor = findMin(root->right); /* Find the inorder successor: smallest node in the RIGHT subtree */

    /* Copy successor's data into this node */
    root->data = successor->data;                  /* Overwrite current node's data with the successor's data */

    /* Delete the inorder successor from right subtree */
    root->right = deleteNode(root->right, successor->data); /* Now delete the inorder successor from the right subtree */
  }                                                          /* End of found-node block */

  return root; /* Return the (possibly restructured) current root after deletion */
}              /* End of deleteNode function */

/* ─────────────────────────────────────────────
   PRINT TREE STRUCTURE (sideways)
   Prints the tree rotated 90° — right side up.
   Helps visualize the tree shape.
   ───────────────────────────────────────────── */
void printTree(struct NODE *root, int space) { /* Function to print the BST sideways; 'space' controls indentation level */
  int gap = 5;            /* Set gap to 5 spaces — this is the indentation increment per tree level */
  if (root == NULL)       /* Base case: if the current node is NULL, nothing to print */
    return;               /* Return immediately — empty subtree, do nothing */

  space += gap;           /* Increase the current indentation level by 'gap' before printing this node */

  /* Print right subtree first (top of screen = right side) */
  printTree(root->right, space); /* Recursively print the RIGHT subtree first so it appears at the top */

  printf("\n");                          /* Print a newline to separate tree levels visually */
  for (int i = gap; i < space; i++)     /* Loop to print the correct number of leading spaces for indentation */
    printf(" ");                         /* Print one space per iteration to create the indentation */
  printf("%d\n", root->data);           /* Print the current node's data at the correct indentation level */

  /* Print left subtree */
  printTree(root->left, space); /* Recursively print the LEFT subtree so it appears at the bottom */
}                               /* End of printTree function */

/* ─────────────────────────────────────────────
   MAIN FUNCTION — Menu Driven Program
   ───────────────────────────────────────────── */
int main() {                          /* Entry point of the program — execution starts here */
  struct NODE *root = NULL;           /* Declare a root pointer and set it to NULL (tree starts empty) */
  int choice, value;                  /* Declare 'choice' for menu option and 'value' for user input values */

  printf("╔══════════════════════════════════════════╗\n"); /* Print the top border of the welcome banner */
  printf("║     Binary Search Tree — DSA SEM 2       ║\n"); /* Print the title inside the banner */
  printf("║     Rohit Chandra | SEC-B                ║\n"); /* Print student name inside the banner */
  printf("╚══════════════════════════════════════════╝\n"); /* Print the bottom border of the welcome banner */

  do {  /* Start a do-while loop so the menu is shown at least once, and keeps running until user exits */
    printf("\n┌─────────────── MENU ───────────────┐\n");  /* Print the top border of the menu box */
    printf("│  1. Insert a node                  │\n");    /* Print menu option 1: Insert */
    printf("│  2. Inorder   Traversal (sorted)   │\n");    /* Print menu option 2: Inorder traversal */
    printf("│  3. Preorder  Traversal             │\n");    /* Print menu option 3: Preorder traversal */
    printf("│  4. Postorder Traversal             │\n");    /* Print menu option 4: Postorder traversal */
    printf("│  5. Search a value                 │\n");    /* Print menu option 5: Search */
    printf("│  6. Find Minimum                   │\n");    /* Print menu option 6: Find minimum */
    printf("│  7. Find Maximum                   │\n");    /* Print menu option 7: Find maximum */
    printf("│  8. Delete a node                  │\n");    /* Print menu option 8: Delete */
    printf("│  9. Display Tree (sideways view)   │\n");    /* Print menu option 9: Display tree */
    printf("│  0. Exit                           │\n");    /* Print menu option 0: Exit */
    printf("└────────────────────────────────────┘\n");    /* Print the bottom border of the menu box */
    printf("  Enter your choice: ");                        /* Prompt the user to enter their menu choice */
    scanf("%d", &choice);                                   /* Read the user's menu choice from keyboard input */

    switch (choice) { /* Switch on the user's choice to call the matching operation */

    case 1:                                  /* User chose option 1: Insert a node */
      printf("  Enter value to insert: ");   /* Prompt user to enter the value they want to insert */
      scanf("%d", &value);                   /* Read the value to insert from the user */
      root = insert(root, value);            /* Call insert() and update root (root may change if tree was empty) */
      printf("  [✓] %d inserted successfully.\n", value); /* Confirm successful insertion to the user */
      break;                                 /* Break out of the switch — go back to the menu */

    case 2:                                        /* User chose option 2: Inorder traversal */
      if (root == NULL) {                          /* Check if the tree is currently empty */
        printf("  Tree is empty!\n");              /* If empty, print a message and skip the traversal */
      } else {                                     /* Otherwise, the tree has nodes — proceed with traversal */
        printf("  Inorder (Left→Root→Right): ");   /* Print the label for inorder traversal output */
        inorder(root);                             /* Call inorder() to print all values in sorted (ascending) order */
        printf("\n");                              /* Print a newline after all values are printed */
      }                                            /* End of empty-check block */
      break;                                       /* Break out of the switch */

    case 3:                                          /* User chose option 3: Preorder traversal */
      if (root == NULL) {                            /* Check if the tree is empty */
        printf("  Tree is empty!\n");                /* If empty, print message */
      } else {                                       /* Otherwise, tree has nodes */
        printf("  Preorder (Root→Left→Right): ");    /* Print the label for preorder traversal output */
        preorder(root);                              /* Call preorder() to print: root first, then left, then right */
        printf("\n");                                /* Print newline after output */
      }                                              /* End of empty-check block */
      break;                                         /* Break out of the switch */

    case 4:                                          /* User chose option 4: Postorder traversal */
      if (root == NULL) {                            /* Check if the tree is empty */
        printf("  Tree is empty!\n");                /* If empty, print message */
      } else {                                       /* Otherwise, tree has nodes */
        printf("  Postorder (Left→Right→Root): ");   /* Print the label for postorder traversal output */
        postorder(root);                             /* Call postorder() to print: left first, then right, then root */
        printf("\n");                                /* Print newline after output */
      }                                              /* End of empty-check block */
      break;                                         /* Break out of the switch */

    case 5:                                            /* User chose option 5: Search a value */
      printf("  Enter value to search: ");             /* Prompt user to enter the value to find */
      scanf("%d", &value);                             /* Read the search value from the user */
      if (search(root, value) != NULL) {               /* Call search(); if returned pointer is not NULL, value was found */
        printf("  [✓] Value %d FOUND in the tree.\n", value);     /* Print success — value found */
      } else {                                         /* Otherwise, search returned NULL — not found */
        printf("  [✗] Value %d NOT found in the tree.\n", value); /* Print failure — value not found */
      }                                                /* End of search result check */
      break;                                           /* Break out of the switch */

    case 6:                                                           /* User chose option 6: Find minimum */
      if (root == NULL) {                                             /* Check if the tree is empty */
        printf("  Tree is empty!\n");                                 /* If empty, print message */
      } else {                                                        /* Otherwise, tree has nodes */
        printf("  Minimum value in tree: %d\n", findMin(root)->data); /* Call findMin() and print the smallest value */
      }                                                               /* End of empty-check block */
      break;                                                          /* Break out of the switch */

    case 7:                                                           /* User chose option 7: Find maximum */
      if (root == NULL) {                                             /* Check if the tree is empty */
        printf("  Tree is empty!\n");                                 /* If empty, print message */
      } else {                                                        /* Otherwise, tree has nodes */
        printf("  Maximum value in tree: %d\n", findMax(root)->data); /* Call findMax() and print the largest value */
      }                                                               /* End of empty-check block */
      break;                                                          /* Break out of the switch */

    case 8:                                          /* User chose option 8: Delete a node */
      printf("  Enter value to delete: ");           /* Prompt user to enter the value to delete */
      scanf("%d", &value);                           /* Read the value to be deleted from the user */
      root = deleteNode(root, value);                /* Call deleteNode(); update root in case the root itself was deleted */
      printf("  [✓] Deletion operation done.\n");   /* Confirm the deletion operation is complete */
      break;                                         /* Break out of the switch */

    case 9:                                                              /* User chose option 9: Display tree */
      if (root == NULL) {                                                /* Check if the tree is empty */
        printf("  Tree is empty!\n");                                    /* If empty, print message */
      } else {                                                           /* Otherwise, tree has nodes */
        printf("\n  Tree Structure (rotated 90°, right is top):\n");    /* Print header for tree visual */
        printTree(root, 0);                                              /* Call printTree() with initial indent 0 to draw the tree */
        printf("\n");                                                    /* Print newline after the tree diagram */
      }                                                                  /* End of empty-check block */
      break;                                                             /* Break out of the switch */

    case 0:                                          /* User chose option 0: Exit the program */
      printf("\n  Exiting... Goodbye!\n\n");         /* Print farewell message before exiting the loop */
      break;                                         /* Break out of the switch */

    default:                                               /* User entered a choice that is not 0-9 */
      printf("  Invalid choice! Please enter 0-9.\n");    /* Print error message for invalid input */
    }                                                      /* End of switch statement */

  } while (choice != 0); /* Keep looping as long as the user has NOT chosen option 0 (Exit) */

  return 0; /* Return 0 to the operating system — signals that the program completed successfully */
}           /* End of main function */
