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

// * ------------------- Utility Functions ---------------------

void printDLL(Node* head) {
  Node* temp = head;
  while(temp->next != nullptr) {
    std::cout<<temp->data<<std::endl;
    temp = temp->next;
  }
}

Node* arrayToDLL(std::vector<int>arr) { 
  Node* head = new Node(arr[0]);
  Node* prev = head;
  for(int i=1; i<=arr.size(); i++) {
    Node* temp = new Node(arr[i], nullptr, prev);
    prev->next = temp;
    prev = temp;
  }
  return head;
}

Node* deleteHead(Node* head) {
  if(head == nullptr) return nullptr;
  if(head->next == nullptr) return nullptr;

  Node* prev = head;
  head = head->next; // * Move the head
  head->prev = nullptr; // * head back point to nullptr

  // * free the head pointer
  prev->next = nullptr; 
  delete prev;

  return head;

}

int main() {
  std::vector<int> arr = { 1,2,3,4,5 };
  Node* head = arrayToDLL(arr);
  std::cout<<"------- Before Deleting Head ------"<<std::endl;
  printDLL(head);

  head = deleteHead(head);
  std::cout<<"------ After Deleteting Head ------"<<std::endl;
  printDLL(head);
  return 0;
}


// *  g++ -std=c++17 01-delete-head.cpp -o 01-delete-head