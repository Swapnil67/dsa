#include<iostream>

class Node {
  public: 
    int data;
    Node* next;
    Node* prev;

  Node(int d) {
    this->data = d;
    this->next = nullptr;
    this->prev = nullptr;
  }

  Node(int d, Node* n, Node* p) {
    this->data = d;
    this->next = n;
    this->prev = p;
  }

};

// * ------------------- Utility Functions ---------------------

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

void printDLL(Node* head) {
  Node* temp = head;
  while(temp->next != NULL) {
    std::cout<<temp->data<<" ";
    temp = temp->next;
  }
  std::cout<<std::endl;
}

void deleteTail(Node* head) {
  Node* temp = head;
  while(temp->next != NULL) {
    temp = temp->next;
  }

  Node* prev = temp->prev;
  temp->prev = nullptr;
  prev->next = nullptr;
  delete temp;
}

int main() {

  std::vector<int> arr = { 1,2,3,4,5 };
  Node* head = arrayToDLL(arr);

  std::cout<<"------- Before Deleting Tail ------"<<std::endl;
  printDLL(head);

  deleteTail(head);

  std::cout<<"------ After Deleteting Tail ------"<<std::endl;
  printDLL(head);

  return 0;
}

// *  g++ -std=c++17 02-delete-tail.cpp -o 02-delete-tail