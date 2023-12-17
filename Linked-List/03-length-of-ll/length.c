#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *head = NULL;

int lengthLL() {
  int count = 0;
  if(head == NULL) {
    return count;
  } else {
    struct node *q = head;
    // do {
    //   printf("\n++ %p, %p %d\n", q, q->next, q->data);
    //   count++;
    //   if(q) {
    //     q = q->next;
    //   }
    // } while (q != NULL);
    // * OR
    while(q != NULL) {
      printf("\n=====>>>>%p, %p %d\n", q, q->next, q->data);
      count++;
      q = q->next;
    }
  }
  return count;
}

void printLL() {
  if(head == NULL) {
    printf("Linked list is empty.");
  } else {
    struct node *temp = head;
    while(temp != NULL) {
      printf("Address: %p, Data: %d\n", temp, temp->data);
      temp = temp->next;
    }
  }
}

void append() {
  // * Allocating the heap memory of size node & type casting it to structure node type
  struct node *temp = (struct node*)malloc(sizeof(struct node));
  printf("\nEnter a Value: ");
  scanf("%d", &temp->data);
  temp->next = NULL;
  printf("Address of my node: %p\n", temp);
  printf("Value of my node: %d\n", temp->data);

  if(head == NULL) {
    // * Linked list does not contain any node.
    printf("Linked list is empty\n");
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
  printf("Length of linked list\n");
  int lengthOfLL1 = lengthLL();
  printf("Initial Length of LL: %d\n", lengthOfLL1);
  printf("------------------------------------");
  append();
  append();
  printf("------------------------------------\n");
  int lengthOfLL2 = lengthLL();
  printf("Length of LL: %d\n", lengthOfLL2);
  printf("------------------------------------\n");
  printLL();
  return 0;
}