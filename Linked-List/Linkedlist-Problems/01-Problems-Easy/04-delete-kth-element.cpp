/*
 *  Delete a Node from Linked List
 */

#include<iostream>

class Node {
  public:
    int data;
    Node* next;

    Node(int d) {
      this->data = d;
      this->next = NULL;
    }
};

Node* arrayToLL(std::vector<int> arr) {
  Node* head = new Node(arr[0]);
  Node* mover = head;
  for(int i=1; i<arr.size(); i++) {
    Node* temp = new Node(arr[i]);
    mover->next = temp;
    mover = temp;
  }
  return head;
}

int lengthOfLL(Node* head) {
  int c = 0;
  if(head == NULL) return c;
  Node* temp = head;
  while(temp) {
    c++;
    temp = temp->next;
  }
  return c;
}

void printLL(Node* head) {
  Node* temp = head;
  while(temp) {
    std::cout<<temp->data<<std::endl;
    temp = temp->next; 
  }
}

Node* deleteHead(Node* head) {
  Node* temp = head;
  head = head->next;
  free(temp);
  return head;
}

void deleteNode(Node* head, int k) {
  Node* temp = head;
  Node* prev = NULL;
  int i = 0;
  while(temp) {
    i++;
    if(i == k) {
      prev->next = prev->next->next;
      free(temp);
      break;
    }
    prev = temp;
    temp = temp->next;
  }
}

Node* deleteKNode(Node* head, int deleteIndex) {
  if(head == NULL) return head;

  if(deleteIndex == 1) {
    return deleteHead(head);
  }

  int lenOfLL = lengthOfLL(head);
  if(lenOfLL < deleteIndex) {
    std::cout<<"Out of Bound Index of deletion"<<std::endl;
    return head;
  }
  
  deleteNode(head, deleteIndex);
  return head;
}

int main() {
  // std::vector<int> arr = {1,2,3,4,5};
  std::vector<int> arr = {3, 4, 5, 2, 6, 1, 9, -1};
  Node* head = arrayToLL(arr);
 
  std::cout<<"Before Deleteing: "<<std::endl;
  printLL(head);

  int delIdx;
  std::cout<<"Enter the index of node you want to delete: ";
  std::cin>>delIdx;
  std::cout<<"\nAfter Deleteing: "<<std::endl;
  head = deleteKNode(head, delIdx);
  
  printLL(head);
}

