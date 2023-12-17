// * A c program to insert the node in linked list at any postition

#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *head = NULL;

int length() {
  int length = 0;
  struct node *q = head;
  while(q != NULL) {
    length++;
    q = q->next;
  }
  return length;
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

void insertAfterPos(pos) {
  printf("\nGo to position: %d\n", pos);
  
  struct node *temp = head;
  // printf("HEAD pointer %p: \n", head);
  // printf("temp pointer %p: \n", temp);

  int index = 0;
  while (index < pos) {
    index++;
    printf("\ncur pointer temp %p: \n", temp);

    if(temp != NULL) {
      printf("Head not null");
      if(temp->next != NULL) {
        temp = temp->next;
      }
      printf("\n next Temp %p %p\n", temp, temp->next);
    }
  }

  printf("\n final Temp %p \n", temp);

  struct node *temp2 = (struct node*)malloc(sizeof(struct node));
  printf("Enter the value of new node: ");
  scanf("%d", &temp2->data);
  
  if(temp != NULL) {
    printf("1");
    temp2->next = temp;
    temp = temp2;
    // head = temp2;
  } else {
    printf("2");
    head = temp2;
  }
}

int main() {
  int pos, len, i = 0;
  char ans = 'y';
  while(i < 5) {
    printf("\nEnter the position of new node: ");
    scanf("%d", &pos);
    len = length();
    printf("Linked list length: %d", len);

    if(pos > len) {
      printf("The list has only %d nodes", len);
    } else {
      insertAfterPos(pos);
    }
    i++;
    printf("\n--------- Linked List ------------\n");
    printLL();
  }
  return 0;
}

// int main() {
//   int pos, len;
//   char ans = 'y';
//   do
//   {
//     printf("\nEnter the position of new node: ");
//     scanf("%d", &pos);
//     len = length();

//     if(pos > len) {
//       printf("The list has only %d nodes", len);
//     } else {
//       insertAfterPos(pos);
//       printf("\nEnter more [y/n]: ");
//       scanf(" %c", &ans);
//     }
//   } while (ans == 'y');

//   printf("--------- Linked List ------------\n");
//   printLL();
//   return 0;
// }

/*

1 2 3
0x13af04080  0x13b804080 0x13c804080

head = 0x13af04080
pos = 0x13b804080

temp = 0x13b804080


temp2 = 0x13e804080

tem2->next = temp
temp = temp2
*/