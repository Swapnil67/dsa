/*
* Delete the Head from Linked List
*/

#include<iostream>

class Node {
  public: 
    int data;
    Node* next;

    Node(int value) {
      this->data = value;
      this->next = NULL;
    }

};

Node* LLFromArray(std::vector<int> arr) {
  Node* head = NULL;
  head = new Node(arr[0]);
  Node* mover = head;
  for(int i=1; i<=arr.size(); i++) {
    Node* temp = new Node(arr[i]);
    mover->next = temp;
    mover = temp;
  }
  return head;
}

void PrintLL(Node* head) {
  Node* temp = head;
  while(temp->next != NULL) {
    std::cout<<temp->data<<std::endl;
    temp = temp->next;
  }
}

Node* deleteHead(Node* head) {
  if(head == NULL) return NULL;
  Node* temp = head;
  temp = temp->next;
  free(head);
  return temp;
}

int main() {
  std::vector<int> arr = { 1, 2, 3, 4, 5 };
  Node* head = LLFromArray(arr); 
  std::cout<<"Before Deleting the Head of LL"<<std::endl;
  PrintLL(head); 
  std::cout<<"After Deleting the Head of LL"<<std::endl;
  head = deleteHead(head);
  PrintLL(head);
  return 0;
}
