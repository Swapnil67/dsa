#include<stdio.h>
#include <stdlib.h>

// * Linked List Structure
struct node
{
  int data;
  struct node *next;
};

// * Point Head to NULL (For Start i.e., ll with 0 elements)
struct node *head = NULL;

void append() {
  // * Allocating the heap memory of size node & type casting it to structure node type
  struct node *temp = (struct node*)malloc(sizeof(struct node));
  printf("Enter a Value: ");
  scanf("%d", &temp->data);
  temp->next = NULL;
  printf("Address of my node: %p\n", temp);
  printf("Value of my node: %d\n", temp->data);

  if(head == NULL) {
    // * Linked list does not contain any node.
    head = temp;
  } else {
    // * Create a temporary node which has value of head
    struct node *q = head;
    // * now here we have starting addr of linked list in 'q' 
    // * Now we have to traverse till the end and append our temp node to end of 'q' 
    while(q->next != NULL) {
      q = q->next;
    }
    q->next = temp;
  }
}

int main() {
  printf("Append in linked list\n");
  append();
  return 0;
}
