#include <stdio.h>
#include <stdlib.h>

struct slinklist {
  int data;
  struct slinklist *next;
};

struct slinklist *start = NULL;
struct slinklist *getnode() {
  struct slinklist *newnode;
  newnode = (struct slinklist *)malloc(sizeof(struct slinklist));
  printf("\nEnter the data: ");
  scanf("%d", &newnode->data);
  newnode->next = NULL;
  return newnode;
}

void traverse() {
  struct slinklist *temp = start;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
}
