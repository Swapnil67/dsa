#include<iostream>

class Node {

public:
  int data;
  Node* next;
  Node* prev;

  // * Constructor
  Node(int d, Node* n, Node* p) {
    this->data = d;
    this->next = n;
    this->prev = p;
  }

  // * Constructor
  Node(int d) {
    this->data = d;
    this->next = nullptr;
    this->prev = nullptr;
  }

};


Node* arrayToDLL(std::vector<int> arr) {
  Node* head = new Node(arr[0]);
  Node* prev = head;

  for(int i=1; i<=arr.size(); i++) {
    Node* temp = new Node(arr[i], nullptr, prev);
    prev->next = temp;
    prev = temp;
  }
  return head;
}

// * Print LL
void printDLL(Node* head) {
  Node* temp = head;
  while(temp->next) {
    std::cout<<temp->data<<std::endl;
    temp = temp->next;
  }
}

int main() {
  std::vector<int> arr = { 1,2,3,4,5 };
  Node* head = arrayToDLL(arr);
  printDLL(head);
  return 0;
}
