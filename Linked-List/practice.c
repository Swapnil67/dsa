#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList LinkedList;

struct LinkedList {
  int data;
  LinkedList* next;
};

// * Array To LinkedList
LinkedList* arrayToLL(int *arr, int n) {
  // * Create a head node
  LinkedList *head = malloc(sizeof(LinkedList));
  head->data = *arr;
  *arr += 1;

  // * Create a tail node
  LinkedList *tail = malloc(sizeof(LinkedList));
  tail = head;
  
  int i = 1;
  while (i < n) {
    // * Create a node
    LinkedList *node = malloc(sizeof(LinkedList));
    node->data = *arr;
    tail->next = node;
    // * Make current node new tail of ll
    tail = node; 
    *arr += 1;
    i += 1;
  }
  
  return head;
}

int main(void) {
  int n = 10;
  int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  LinkedList *ll = arrayToLL(a, n);

  while(ll != NULL) {
    printf("%d\n", ll->data);
    ll = ll->next;
  }

  printf("Linked List\n");
  return 0;
}

// * Run the program
// * gcc practice.c -o output