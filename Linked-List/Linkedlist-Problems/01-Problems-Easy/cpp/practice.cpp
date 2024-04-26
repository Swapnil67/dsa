#include<iostream>

class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int d) {
      this->data = d;
      this->next = NULL;
      this->prev = NULL;
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
  for(int i=1; i<arr.size(); i++) {
    Node* newNode = new Node(arr[i], nullptr, prev);
    prev->next = newNode;
    prev = newNode;
  }
  return head;
}

void printDLL(Node* head) {
  Node* temp = head;
  while(temp) {
    std::cout<<temp->data<<" ";
    temp = temp->next;
  }
  std::cout<<std::endl;
}

Node* reverseDLL(Node* head) {
  Node* temp = head;
  Node* back = nullptr;
  while(temp) {
    back = temp->prev;
    temp->prev = temp->next;
    temp->next = back;
    temp = temp->prev;
  }
  return back->prev;
}

int main() {
  std::vector<int> arr = { 1,2,3,4,5,6 };
  Node* head = arrayToDLL(arr);
  printDLL(head);
  head = reverseDLL(head);
  printDLL(head);
  return 0;
}

// * g++ --std=c++17 practice.cpp -o practice && ./practice