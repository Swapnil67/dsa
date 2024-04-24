/**
 * * Delete node from Doubly Linked List
 * * There exists a doubly linked list with nodes containing integer values. 
 * * You are given a specified node of the list which you have to delete.
 * * The node to be deleted is guaranteed not to be the head of the list.
*/

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
  for(int i=1; i<arr.size(); i++) {
    Node* temp = new Node(arr[i], nullptr, prev);
    prev->next = temp;
    prev = temp;
  }
  return head;
}

void printDLL(Node* head) {
  Node* temp = head;
  while(temp != NULL) {
    std::cout<<temp->data<<" ";
    temp = temp->next;
  }
  std::cout<<std::endl;
}


void deleteNode(Node* node) {
  Node* back = node->prev;
  Node* front = node->next;

  if(front != nullptr) {
    back->next = front;
    front->prev = back;
  } 
  else {
    // * Delete the tail
    back->next = nullptr;
  }

  // * Remove unwanted node
  node->next = nullptr;
  node->prev = nullptr;
  delete node;
}

int main() {
  std::vector<int> arr = { 1,2,3,4,5 };
  Node* head = arrayToDLL(arr);

  std::cout<<"------ Before Deleteting Node ------"<<std::endl;
  printDLL(head);

  std::cout<<"------ After Deleteting Node ------"<<std::endl;
  deleteNode(head->next->next);
  printDLL(head);

  return 0;
}
