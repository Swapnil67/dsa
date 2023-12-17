#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *head = NULL;

void insertBegin() {
  struct node *temp = (struct node*)malloc(sizeof(struct node));
  printf("Enter a Value: ");
  scanf("%d", &temp->data);
  temp->next = NULL;
  
  if(head == NULL) {
    // * In case of empty LL
    head = temp;
    printf("Address of my node: %p\n", temp);
    printf("Value of my node: %d\n", temp->data);
  } else {
    // * First point the temp node to head of the LL
    temp->next = head;
    // * This point the head to the temp as the first node of LL
    head = temp;
  }
}

int main() {
  printf("Insert in linked list\n");
  insertBegin();
  return 0;
}