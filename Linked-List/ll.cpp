/*
* Convert array to from Linked List
*/

#include <iostream>
#include <vector>

class Node {
  public:
    int data;
    Node* next;

    // * constructor
    Node(int d) {
      this->data = d;
      this->next = NULL;
    }
};

// * Converty Array to Linked List
Node* arrayToLL(std::vector<int>arr) {
  Node* head = NULL;
  head = new Node(arr[0]);
  Node* mover = head;
  for(int i=1; i<arr.size(); i++) {
    Node* newNode = new Node(arr[i]);
    mover->next = newNode;
    mover = newNode; 
  }

  return head;
}

// * Print the LL
void printLL(Node* head) {
  Node* temp = head;
  while(temp) {
    std::cout<<temp->data<<std::endl;
    temp = temp->next; 
  }
}

int main() {
  std::vector<int> arr = {1, 2, 3, 4, 5};
  Node* head = arrayToLL(arr);
  Node* temp = head;
  std::cout<<"Elements In LL"<<std::endl;
  printLL(head);
  return 0;
}
